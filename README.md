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
