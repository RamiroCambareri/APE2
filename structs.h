#define MAX_USUARIOS 3
#define MAX_NOMBRE_CATEGORIA 20
#define MAX_GASTOS 100

typedef struct Usuario
{
    char nombre[25 + 1];
    char apellido[25 + 1];
    int dni;
    int ID;
} tipoUsuario;

typedef struct Categoria
{
    char nombreCategoria[MAX_NOMBRE_CATEGORIA + 1]; // se pone + 1 para dejar el espacio para el '\0'
} tipoCategoria;

typedef struct Gastos
{
    int IDGasto;
    float gasto;
    tipoUsuario usuario;
    tipoCategoria categoria;
    int cantGastos[5];
    float sumaGastos;
} tipoGastos;