# Reporte general

|
|
|

# Cambios que faltan o se necesitan:

|
|---- Se puede agregar una opcion mas que dentro del submenu de perfil, que muestre todos los perfiles en pantalla para saber que perfiles hay, etc.agregar
|
|








# Errores encontrados en APE2 — Gestión de Gastos

---

## 1. Segfault en `agregar_gastos` — variable `j` sin inicializar

### ¿Qué pasó?
En C, cuando declarás una variable dentro de una función pero no le asignás ningún valor, esa variable **no vale 0** — vale lo que haya en ese espacio de memoria en ese momento (basura). Eso se llama **comportamiento indefinido**.

En `agregar_gastos` declararon `int i, j, aux;` al principio pero `j` nunca recibe un valor. Después lo usan acá:

```c
gasto[i].usuario = users[j];  // j vale basura → accede a una posición random del vector
```

Si `j` vale por ejemplo 47000, `users[47000]` está muy afuera del vector que solo tiene 3 posiciones. Eso es un **segmentation fault** — el programa intentó leer memoria que no le pertenece.

### ¿Por qué funcionó las primeras veces y falló en la cuarta?
Porque el valor basura de `j` en las primeras ejecuciones casualmente apuntaba a memoria "segura" (no causaba crash), pero en la cuarta llamada la pila de ejecución tenía otro valor basura que sí caía fuera del rango permitido.

### Corrección
Usar `usuario_encontrado` (el índice real del usuario hallado en el loop) en vez de `j`:

```c
// MAL
gasto[i].usuario = users[j];  // j no fue inicializado

// BIEN
gasto[pos].usuario = users[usuario_encontrado];  // índice real del usuario
```

---

## 2. Segfault en `agregar_gastos` — mezcla de `gasto[i]` y `gasto->`

### ¿Qué pasó?
`gasto->campo` es exactamente lo mismo que `gasto[0].campo` — siempre accede al **primer elemento** del vector. Pero en el código mezclaban `gasto[i]` con `gasto->` para el mismo gasto, lo que hace que parte de los datos se guarden en la posición `i` y parte en la posición `0`.

```c
// todo mezclado — parte va a gasto[i], parte a gasto[0]
scanf("%f", &gasto->gasto);          // escribe en gasto[0]
gasto[i].usuario = users[j];         // escribe en gasto[i]
gasto->cantGastos[2]++;              // escribe en gasto[0]
gasto[i].sumaGastos += gasto->gasto; // lee de gasto[0] pero suma en gasto[i]
```

Esto provoca que los datos queden mezclados entre posiciones distintas del vector, y eventualmente alguna escritura cae fuera del rango permitido.

### Corrección
Usar **un solo índice consistente** para todas las operaciones del mismo gasto:

```c
int pos = *diml3;  // posición del nuevo gasto

scanf("%f", &gasto[pos].gasto);
gasto[pos].usuario = users[usuario_encontrado];
gasto[pos].cantGastos[idx]++;
gasto[pos].sumaGastos += gasto[pos].gasto;
```

---

## 3. `calcular_promedio` — comparar un array con `> 0`

### ¿Qué pasó?
`cantGastos` es un array de enteros (`int cantGastos[MAX_GASTOS]`), no un solo número. En C, cuando comparás un array con un número así:

```c
if (gasto[i].cantGastos > 0)
```

Lo que realmente estás comparando es la **dirección de memoria** del array (no su contenido) contra 0. Una dirección de memoria casi nunca es 0, así que esa condición siempre es verdadera, sin importar si hay gastos o no.

### Corrección
Sumar todos los elementos del array primero para obtener el total real:

```c
int total = 0;
for (int k = 0; k < 5; k++) {
    total += gasto[i].cantGastos[k];
}
if (total > 0) {
    *promedio = gasto[i].sumaGastos / total;
}
```

---

## 4. `calcular_minimo` — usar `j` después de que el loop terminó

### ¿Qué pasó?
Después del loop `for (j = 0; j < *diml3; j++)`, cuando el loop termina normalmente, `j` queda con el valor `*diml3` (el valor que hizo que la condición fuera falsa y se saliera). Ese índice está **fuera del vector**.

```c
for (j = 0; j < *diml3; j++) {
    // ...buscar mínimo...
}
// acá j == *diml3 → fuera del vector
printf("\n El gasto minimo es: %.2f", gasto[j].gasto);  // acceso inválido
```

Si `*diml3` es 4, el loop itera con j = 0, 1, 2, 3 y cuando j llega a 4 sale. Pero después `gasto[4]` puede estar fuera del rango o tener basura.

### Corrección
Usar la variable `gasto_min` que ya estaban calculando correctamente dentro del loop:

```c
printf("\n El gasto minimo es: %.2f", gasto_min);  // variable correcta
```

---
---

## 6. `eliminar_usuario` — mezcla de `users[i]` y `users->`

### ¿Qué pasó?
Mismo problema que en `agregar_gastos`. Después de encontrar al usuario en la posición `i`, parte de la limpieza se hace sobre `users[i]` y parte sobre `users->` (que es `users[0]`):

```c
users[i].ID = 0;          // borra el ID del usuario encontrado ✓
users->dni = 0;           // borra el DNI del usuario 0, no del i ✗
users->apellido[0] = '\0'; // borra el apellido del usuario 0 ✗
users->nombre[0] = '\0';   // borra el nombre del usuario 0 ✗
```

Si el usuario a eliminar es el de posición 1 o 2, su DNI, nombre y apellido **no se borran**. En cambio se borran los del usuario 0 aunque no sea el que se quiso eliminar.

Además falta el **corrimiento** del vector — si no se desplazan los elementos, queda un "hueco" en el medio con datos mezclados.

### Corrección
Usar `users[i]` consistentemente y agregar el corrimiento:

```c
for (int j = i; j < *diml2 - 1; j++) {
    users[j].ID       = users[j + 1].ID;
    users[j].dni      = users[j + 1].dni;
    strcpy(users[j].nombre,   users[j + 1].nombre);
    strcpy(users[j].apellido, users[j + 1].apellido);
}
(*diml2)--;
```

---

## Resumen general

| # | Función | Error | Consecuencia |
|---|---------|-------|--------------|
| 1 | `agregar_gastos` | Variable `j` sin inicializar | Segfault al acceder a `users[j]` |
| 2 | `agregar_gastos` | Mezcla de `gasto[i]` y `gasto->` | Datos en posiciones incorrectas, segfault |
| 3 | `calcular_promedio` | Comparar array con `> 0` | Condición siempre verdadera |
| 4 | `calcular_minimo` | Usar `j` fuera del loop | Acceso a posición inválida del vector |
| 5 | `mostrar_menu_calculos_estadisticos` | `opcion` sin inicializar | Comportamiento indefinido al entrar al while |
| 6 | `eliminar_usuario` | Mezcla de `users[i]` y `users->` | Borra datos del usuario 0 en vez del buscado |





































# Errores APE2 v2 — Explicados para aprender

---

<!-- ## Error 1 — `agregar_gastos`: usar el ID como índice del vector
**Línea aprox: 170**

### ¿Qué pasó?
```c
gasto[posicion].usuario = users[ID_buscado];  // MAL
```

Acá están confundiendo dos cosas distintas: el **ID del usuario** y la **posición en el vector**.

Imaginá que el vector de usuarios es como una fila de cajones numerados desde 0:

```
cajón 0 → Ana  (ID: 1)
cajón 1 → Luis (ID: 2)
cajón 2 → Luz  (ID: 3)
```

Si el usuario ingresa ID = 1, `users[1]` accede al cajón número 1, que es **Luis**, no Ana. Pero Ana tiene ID 1 y está en el cajón 0. El ID es el "nombre" del usuario, el índice es "dónde está guardado en memoria".

Cuando buscás con el `for`, la variable `i` te dice exactamente en qué cajón está ese usuario. Eso es lo que tenés que usar:

```c
gasto[posicion].usuario = users[i];  // BIEN — i es la posición real
``` -->

### ¿Por qué es importante esta distinción?
Porque en casi todos los programas el ID no coincide con la posición. Si eliminás al usuario 1 y creás uno nuevo, ese nuevo usuario queda en la posición 0 pero puede tener ID 3. Si usás el ID como índice, accedés a la posición equivocada o directamente fuera del vector (segfault).

---

## Error 2 — `agregar_gastos`: mezcla de `gasto->` con `gasto[i]` y `gasto[posicion]`
**Líneas aprox: 172–180**

### ¿Qué pasó?
```c
scanf("%f", &gasto->gasto);          // escribe en gasto[0]
gasto[posicion].usuario = users[i];  // escribe en gasto[posicion]
gasto->cantGastos[0]++;              // escribe en gasto[0]
gasto[i].sumaGastos += gasto->gasto; // lee de gasto[0], suma en gasto[i]
```

`gasto->campo` es exactamente igual a `gasto[0].campo`. Siempre apunta al **primer elemento** del vector, sin importar qué valor tenga `i` o `posicion`.

Entonces los datos del mismo gasto quedan repartidos en tres posiciones distintas:
- El monto en `gasto[0]`
- El usuario en `gasto[posicion]`  
- La suma en `gasto[i]`

Es como si llenás un formulario pero escribís el nombre en la hoja 1, el DNI en la hoja 3 y el teléfono en la hoja 2. El formulario queda incompleto e inconsistente.

### ¿Cómo debería hacerse?
Elegir **un solo índice** y usarlo para todo. En este caso `posicion` es el correcto porque representa el lugar del nuevo gasto:

```c
scanf("%f", &gasto[posicion].gasto);
gasto[posicion].IDGasto = posicion + 1;
gasto[posicion].usuario = users[i];
gasto[posicion].categoria = categorias[idx];
gasto[posicion].cantGastos[idx]++;
gasto[posicion].sumaGastos += gasto[posicion].gasto;
(*diml3)++;
```

---

## Error 3 — `agregar_gastos`: 5 bloques `if/else if` idénticos
**Líneas aprox: 155–220**

### ¿Qué pasó?
Cada rama del `if` hace exactamente lo mismo, solo cambia el número de categoría:

```c
if (opcion == 1) {
    ...categorias[0]... cantGastos[0]...
} else if (opcion == 2) {
    ...categorias[1]... cantGastos[1]...
} // ... y así 5 veces
```

Esto no es un error que rompe el programa, pero es un problema de **mantenibilidad**. Si mañana quieren cambiar cómo se guarda el gasto, tienen que cambiar el mismo código en 5 lugares. Si se olvidan de cambiar uno, queda inconsistente.

### ¿Cómo evitarlo?
La observación clave es que `opcion 1 → índice 0`, `opcion 2 → índice 1`, etc. Siempre es `opcion - 1`. Eso se llama **calcular el índice**:

```c
if (opcion >= 1 && opcion <= 5) {
    int idx = opcion - 1;  // una sola variable hace el trabajo de los 5 bloques
    scanf("%f", &gasto[posicion].gasto);
    gasto[posicion].categoria = categorias[idx];
    gasto[posicion].cantGastos[idx]++;
    // ... resto igual para todos
}
```

En programación existe el principio **DRY** (Don't Repeat Yourself — No te repitas). Si el mismo bloque de código aparece más de una vez, casi siempre se puede reemplazar por un loop o una variable calculada.

---

## Error 4 — `calcular_minimo`: lógica de inicialización y condiciones al revés
**Líneas aprox: 290–310**

### ¿Qué pasó?
```c
float gasto_min = 0;  // inicializa en 0

for (j = 0; j < *diml3; j++) {
    if (gasto[j].usuario.ID == ID_buscado) {
        gasto_min = gasto[j].gasto;
        printf("\nEl usuario no ingreso ningun gasto\n");  // mensaje al revés
        break;
    } else if (gasto[j].gasto < gasto_min) {   // compara contra 0
        gasto_min = gasto[j].gasto;
        break;
    }
}
```

Hay dos problemas acá:

**Problema A — el mensaje está al revés:** El primer `if` encuentra al usuario y guarda su gasto, pero imprime "no ingresó ningún gasto". Es exactamente el mensaje contrario al que debería mostrar.

**Problema B — inicializar el mínimo en 0 no funciona:** Si todos los gastos son positivos (como $500, $1200, $300), ninguno va a ser menor que 0. El `else if (gasto[j].gasto < gasto_min)` nunca va a ser verdadero porque 500 > 0, 1200 > 0, 300 > 0.

La forma correcta de buscar un mínimo es:
1. Tomar el **primer elemento** como mínimo inicial
2. Comparar el resto contra ese valor

```c
int encontrado = 0;

for (int j = 0; j < *diml3; j++) {
    if (gasto[j].usuario.ID == ID_buscado) {
        if (!encontrado) {
            gasto_min = gasto[j].gasto;  // primer gasto del usuario = mínimo inicial
            encontrado = 1;
        } else if (gasto[j].gasto < gasto_min) {
            gasto_min = gasto[j].gasto;  // si encontramos uno menor, actualizamos
        }
    }
}

// el resultado se muestra DESPUÉS de recorrer todo
if (encontrado) {
    printf("\nEl gasto minimo es: $%.2f\n", gasto_min);
} else {
    printf("\nEl usuario no ingreso ningun gasto.\n");
}
```

---

## Error 5 — `calcular_maximo`: el `if` de resultado está adentro del loop
**Líneas aprox: 340–360**

### ¿Qué pasó?
```c
for (j = 0; j < *diml3; j++) {
    if (gasto[j].usuario.ID == ID_buscado) {
        // ...comparar máximo...
    }

    if (encontrado == 1) {           // ← este if está DENTRO del for
        printf("El maximo es...");
        return;
    } else {
        printf("No ingresó gastos");  // ← en la primera iteración que no coincide, sale
        return;
    }
}
```

El `if (encontrado == 1)` está dentro del `for`, entonces en **cada iteración** del loop evalúa si encontró o no. En la primera iteración que el ID no coincide, entra al `else`, imprime "no ingresó gastos" y sale con `return` — sin haber recorrido el resto del vector.

Pensalo así: si tenés 4 gastos y el del usuario buscado es el último, el programa va a decir "no ingresó gastos" después de mirar solo el primer elemento.

### ¿Por qué pasa esto?
Es el mismo error clásico que el `else` en `eliminar_usuario` y en `modificar_perfil_usuario`. La regla es:

> **Todo lo que depende de haber recorrido el vector completo debe ir AFUERA del loop.**

El loop es para buscar/comparar. El resultado se muestra después:

```c
for (j = 0; j < *diml3; j++) {
    // solo búsqueda acá adentro
}
// resultado acá afuera, cuando ya recorrimos todo
if (encontrado) { ... }
```

---

<!-- ## Error 6 — `mostrar_menu_calculos_estadisticos`: `scanf` antes de mostrar el menú
**Línea aprox: 255**

### ¿Qué pasó?
```c
int opcion;
scanf("%d", &opcion);   // ← lee ANTES de mostrar el menú
while (opcion != 5) {
    printf("\n1 - Promedio");
    printf("\n2 - Minimo");
    ...
```

El programa le pide al usuario que ingrese un número **antes de mostrarle las opciones disponibles**. El usuario ve la pantalla en blanco esperando un input sin saber qué tiene que escribir.

Además `opcion` no está inicializada, así que si por alguna razón el `scanf` falla o se salta, `opcion` vale basura y el `while` puede entrar a cualquier rama.

### ¿Cómo debería hacerse?
Primero mostrar, después leer. Y siempre inicializar las variables:

```c
int opcion = 0;           // siempre inicializar
while (opcion != 5) {
    printf("\n1 - Promedio");
    printf("\n2 - Minimo");
    printf("\nSeleccione: ");
    scanf("%d", &opcion);  // lee DESPUÉS de mostrar
    // ...
}
``` -->

---

## Error 7 — `consultar_usuario_reporte`: el `else` adentro del loop
**Línea aprox: 270**

### ¿Qué pasó?
```c
for (int i = 0; i < *diml2; i++) {
    if (users[i].ID == id_buscado) {
        // mostrar reporte
        return;
    } else {
        printf("\nUsuario con ID %d no encontrado.\n", id_buscado);  // ← adentro del loop
    }
}
```

Si hay 3 usuarios y el buscado es el último, el programa imprime "no encontrado" 2 veces antes de encontrarlo. Es el mismo patrón del error 5.

La solución es la bandera `encontrado` afuera del loop, que ya están usando bien en otras funciones.

---

## Resumen de patrones que se repiten

| Patrón | Dónde aparece | Regla |
|--------|--------------|-------|
| ID usado como índice | `agregar_gastos` | El índice `i` del loop es la posición real, no el ID |
| Mezcla de `->` con `[]` | `agregar_gastos`, `eliminar_usuario` | Elegir un índice y usarlo en todo |
| `else` adentro del loop | `consultar_usuario_reporte`, `calcular_maximo`, `modificar_perfil_usuario`, `eliminar_usuario` | El resultado va afuera del loop |
| Variable sin inicializar | `mostrar_menu_calculos_estadisticos` | Siempre inicializar con un valor base |
| Mínimo/máximo iniciado en 0 | `calcular_minimo`, `calcular_maximo` | Inicializar con el primer elemento, no con 0 |
| Código repetido N veces | `agregar_gastos` | Calcular el índice con una variable en vez de copiar bloques |