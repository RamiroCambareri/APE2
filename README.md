
# 💸 Gestión de Gastos

Proyecto grupal desarrollado para la materia **Programación de Computadoras I (PCI)** — UNRN.  
Sistema de gestión de gastos personales por usuario, implementado en **C** con arquitectura multi-archivo.

---

## 📁 Estructura del proyecto

```
.
├── main.c          # Programa principal, menú e inicialización
├── functions.c     # Implementación de todas las funciones
├── functions.h     # Prototipos de funciones
└── structs.h       # Definición de estructuras y constantes
```

---

## 🗂️ Estructuras de datos

### `tipoUsuario`
Representa un usuario del sistema.

| Campo      | Tipo    | Descripción              |
|------------|---------|--------------------------|
| `nombre`   | char[25]| Nombre del usuario       |
| `apellido` | char[25]| Apellido del usuario     |
| `dni`      | int     | DNI del usuario          |
| `ID`       | int     | Identificador único      |

### `tipoCategoria`
Representa una categoría de gasto.

| Campo             | Tipo                       | Descripción          |
|-------------------|----------------------------|----------------------|
| `nombreCategoria` | char[MAX_NOMBRE_CATEGORIA] | Nombre de la categoría |

### `tipoGastos`
Representa los gastos registrados en el sistema.

| Campo         | Tipo          | Descripción                                 |
|---------------|---------------|---------------------------------------------|
| `gasto`       | float         | Monto del último gasto ingresado            |
| `usuario`     | tipoUsuario   | Usuario asociado al gasto                   |
| `categoria`   | tipoCategoria | Categoría del gasto                         |
| `cantGastos`  | int[MAX_GASTOS]| Cantidad de gastos por categoría           |
| `sumaGastos`  | float         | Suma total de gastos                        |

### Constantes

```c
#define MAX_USUARIOS          3
#define MAX_NOMBRE_CATEGORIA 20
#define MAX_GASTOS          100
```

---

## ⚙️ Funciones implementadas

### Inicialización
| Función | Descripción |
|--------|-------------|
| `inicializar_usuarios()` | Inicializa el arreglo de usuarios con valores vacíos |

### Menú principal y perfil
| Función | Descripción |
|--------|-------------|
| `mostrar_menu()` | Muestra el menú principal y lee la opción del usuario |
| `mostrar_menu_perfil()` | Submenú para gestión de usuarios |
| `crear_usuarios()` | Agrega un nuevo usuario al sistema |
| `eliminar_usuario()` | Elimina un usuario por ID |

### Menú de gastos
| Función | Descripción |
|--------|-------------|
| `mostrar_menu_gastos()` | Submenú para gestión de gastos |
| `agregar_gastos()` | Registra un gasto para un usuario y categoría |

### Reporte y estadísticas
| Función | Descripción |
|--------|-------------|
| `generar_reporte()` | Muestra un reporte de gastos de un usuario |

---

## 🖥️ Menú del sistema

```
================================
     GESTIÓN DE GASTOS
================================
1 - Menu de Perfil
2 - Menu de Gastos
3 - Generar Reporte
4 - Estadisticas
5 - Salir
```

### Categorías disponibles
1. Comida
2. Transporte
3. Entretenimiento
4. Estudios
5. Varios

---

## 🔧 Compilación y ejecución

**Requisitos:** GCC (Linux / MSYS2 en Windows)

```bash
# Compilar
gcc main.c functions.c -o gestion_gastos

# Ejecutar
./gestion_gastos
```

---

## 👥 Integrantes

| Nombre | Legajo |
|--------|--------|
|        |        |
|        |        |
|        |        |

---

## 📌 Estado del proyecto

- [x] Inicialización de usuarios
- [x] Crear / eliminar usuarios
- [x] Agregar gastos por categoría
- [x] Reporte básico
- [ ] Modificar usuario
- [ ] Modificar / eliminar gastos
- [ ] Estadísticas (promedio, etc.)