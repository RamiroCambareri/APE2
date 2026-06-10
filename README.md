# 💸 Gestión de Gastos
Proyecto grupal desarrollado para la materia **Programación de Computadoras I (PCI)** — UNRN.  
Sistema de gestión de gastos personales por usuario, implementado en **C** con arquitectura multi-archivo.

---

## 📁 Estructura del proyecto
```
.
├── main.c          # Programa principal, menu e inicializacion
├── functions.c     # Implementacion de todas las funciones
├── functions.h     # Prototipos de funciones
└── structs.h       # Definicion de estructuras y constantes
```

---

## 🗂️ Estructuras de datos

### `tipoUsuario`
Representa un usuario del sistema.

| Campo      | Tipo     | Descripción              |
|------------|----------|--------------------------|
| `nombre`   | char[26] | Nombre del usuario       |
| `apellido` | char[26] | Apellido del usuario     |
| `dni`      | int      | DNI del usuario          |
| `ID`       | int      | Identificador único      |

### `tipoCategoria`
Representa una categoría de gasto.

| Campo             | Tipo                        | Descripción             |
|-------------------|-----------------------------|-------------------------|
| `nombreCategoria` | char[MAX_NOMBRE_CATEGORIA+1]| Nombre de la categoría  |
| `IdCategoria`     | int                         | Identificador           |

### `tipoGastos`
Representa un gasto registrado en el sistema.

| Campo        | Tipo           | Descripción                          |
|--------------|----------------|--------------------------------------|
| `IDGasto`    | int            | Identificador del gasto              |
| `gasto`      | float          | Monto del gasto                      |
| `usuario`    | tipoUsuario    | Usuario asociado al gasto            |
| `categoria`  | tipoCategoria  | Categoría del gasto                  |
| `cantGastos` | int[5]         | Cantidad de gastos por categoría     |
| `sumaGastos` | float          | Suma acumulada de gastos             |

### Constantes
```c
#define MAX_USUARIOS          3
#define MAX_NOMBRE_CATEGORIA 20
#define MAX_GASTOS          100
```

---

## ⚙️ Funciones implementadas

### Inicialización
| Función                  | Descripción                                        |
|--------------------------|----------------------------------------------------|
| `inicializar_usuarios()` | Inicializa el vector de usuarios con valores vacios|
| `inicializar_gastos()`   | Inicializa el vector de gastos con valores vacios  |

### Menu principal y perfil
| Función                     | Descripción                                      |
|-----------------------------|--------------------------------------------------|
| `mostrar_menu()`            | Muestra el menu principal y lee la opcion        |
| `mostrar_menu_perfil()`     | Submenu para gestion de usuarios                 |
| `crear_usuarios()`          | Agrega un nuevo usuario al sistema               |
| `eliminar_usuario()`        | Elimina un usuario por ID con corrimiento        |
| `modificar_perfil_usuario()`| Modifica nombre, apellido y DNI de un usuario    |

### Menu de gastos
| Función                  | Descripción                                         |
|--------------------------|-----------------------------------------------------|
| `mostrar_menu_gastos()`  | Submenu para gestion de gastos                      |
| `agregar_gastos()`       | Registra un gasto para un usuario y categoria       |
| `modificar_gastos()`     | Modifica el monto de un gasto por ID                |
| `eliminar_gastos()`      | Elimina un gasto por ID con corrimiento             |

### Reporte y estadisticas
| Función                              | Descripción                                        |
|--------------------------------------|----------------------------------------------------|
| `generar_reporte()`                  | Muestra reporte de gastos de un usuario            |
| `consultar_usuario_reporte()`        | Busca usuario y calcula totales por categoria      |
| `mostrar_menu_calculos_estadisticos()`| Submenu de estadisticas                           |
| `calcular_promedio()`                | Calcula el promedio de gastos de un usuario        |
| `calcular_minimo()`                  | Busca el gasto minimo de un usuario                |
| `calcular_maximo()`                  | Busca el gasto maximo de un usuario                |

---

## 🖥️ Menu del sistema
```
================================
  ---  GESTION DE GASTOS  ---
================================
1 - Menu de Perfil
2 - Menu de Gastos
3 - Generar Reporte
4 - Estadisticas
5 - Salir
```

### Categorias disponibles
1. Comida
2. Transporte
3. Entretenimiento
4. Estudios
5. Varios

---

## 🔧 Compilacion y ejecucion

**Requisitos:** GCC (Linux / MSYS2 en Windows)

```bash
# Compilar
gcc main.c functions.c -o gestion_gastos

# Ejecutar
./gestion_gastos
```

---

## 👥 Integrantes

| Nombre |
|--------|
| Luciano Martinez |
| Ramiro Cambareri |
| Maira Mamani |

---

## 📌 Estado del proyecto

- [x] Inicializacion de estructuras
- [x] Crear / eliminar / modificar usuarios
- [x] Agregar / modificar / eliminar gastos
- [x] Reporte por usuario con detalle por categoria
- [x] Estadisticas: promedio, minimo y maximo por usuario

---

## 🛠️ Proceso de desarrollo

Durante el desarrollo del proyecto se identificaron y corrigieron varios errores con ayuda externa. A continuacion se detallan los principales problemas encontrados y los conceptos aprendidos.

### Bugs corregidos

#### 1. Variable sin inicializar usada como indice
**Funcion:** `agregar_gastos`  
**Error:** La variable `j` se declaraba pero nunca se le asignaba un valor. Al usarla como indice (`users[j]`), accedia a una posicion random de memoria causando **segmentation fault**.  
**Concepto:** En C, una variable declarada pero no inicializada no vale 0 — vale lo que haya en ese espacio de memoria en ese momento (basura). Siempre hay que inicializar las variables antes de usarlas.

#### 2. Mezcla de `gasto->campo` con `gasto[i].campo`
**Funcion:** `agregar_gastos`  
**Error:** Se mezclaban dos formas de acceder al mismo vector. `gasto->campo` es exactamente igual a `gasto[0].campo` — siempre apunta al primer elemento. Esto hacia que los datos de un mismo gasto quedaran repartidos en posiciones distintas del vector.  
**Concepto:** Cuando se trabaja con un vector de structs, hay que elegir un unico indice y usarlo consistentemente para todas las operaciones del mismo elemento.

#### 3. ID del usuario usado como indice del vector
**Funcion:** `agregar_gastos`  
**Error:** Se usaba `users[ID_buscado]` en vez de `users[i]`. El ID de un usuario y su posicion en el vector son cosas distintas — el indice `i` del loop es la posicion real en memoria, no el ID logico.  
**Concepto:** En casi todos los programas el ID no coincide con la posicion. Si se elimina un usuario y se crea uno nuevo, ese usuario puede estar en la posicion 0 pero tener ID 3. Usar el ID como indice accede a la posicion equivocada o fuera del vector.

#### 4. `else` adentro del loop de busqueda
**Funciones:** `eliminar_usuario`, `modificar_perfil_usuario`, `consultar_usuario_reporte`, `calcular_maximo`  
**Error:** El mensaje "no encontrado" estaba dentro del `for`, entonces se imprimia en cada iteracion que no coincidia — antes de terminar de recorrer todo el vector.  
**Concepto:** Todo lo que depende de haber recorrido el vector completo debe ir afuera del loop. El loop es para buscar y comparar; el resultado se muestra despues usando una variable bandera `encontrado`.

#### 5. Inicializar minimo/maximo en 0
**Funciones:** `calcular_minimo`, `calcular_maximo`  
**Error:** `gasto_min` se inicializaba en 0. Si todos los gastos son positivos, ninguno va a ser menor que 0, por lo que la comparacion nunca actualizaba el minimo.  
**Concepto:** La forma correcta de buscar un minimo o maximo es inicializar con el primer elemento del conjunto y comparar el resto contra ese valor.

#### 6. Comparar un array con `> 0`
**Funcion:** `calcular_promedio`  
**Error:** Se intentaba comparar `gasto[i].cantGastos > 0`, pero `cantGastos` es un array. En C, comparar un array con un numero compara la direccion de memoria del array, no su contenido — la condicion siempre era verdadera.  
**Concepto:** Para saber si hay elementos en un array de contadores hay que sumar sus valores primero y comparar el total.

#### 7. Loop de inicializacion con tamaño incorrecto
**Funcion:** `inicializar_gastos`  
**Error:** El loop iteraba solo 5 veces en vez de `MAX_GASTOS` (100). Los 95 elementos restantes quedaban sin inicializar con valores basura en memoria.  
**Concepto:** Siempre usar las constantes definidas (`MAX_GASTOS`) en vez de valores hardcodeados para evitar inconsistencias.

#### 8. Falta de corrimiento al eliminar elementos
**Funciones:** `eliminar_usuario`, `eliminar_gastos`  
**Error:** Al eliminar un elemento solo se borraban sus campos, dejando un hueco en el medio del vector.  
**Concepto:** Al eliminar un elemento de un vector estatico en C, hay que desplazar todos los elementos siguientes una posicion hacia la izquierda y decrementar la dimension logica.

### Conceptos clave aprendidos

| Concepto | Descripcion |
|----------|-------------|
| Dimension logica vs fisica | El vector tiene capacidad fija (fisica) pero solo se usan los primeros N elementos (logica) |
| Punteros como parametros | Pasar `int *diml` permite modificar la variable original desde dentro de una funcion |
| `->` vs `[]` | `ptr->campo` = `ptr[0].campo`, siempre accede al primer elemento |
| ID vs indice | El ID es un identificador logico; el indice es la posicion real en memoria |
| Variable bandera | Usar `int encontrado = 0` para saber si se encontro algo al terminar un loop |
| DRY | No repetir el mismo bloque de codigo N veces; calcular el indice con una variable |
