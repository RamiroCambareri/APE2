#include "structs.h"

//// PROTOTIPOS ////

/* Menu Principal */
void mostrar_menu(int *opcion); 
void mostrar_menu_perfil(tipoUsuario users[], int *diml2); 
void crear_usuarios(tipoUsuario users[], int *diml2); 
void eliminar_usuario(tipoUsuario users[], int *diml2); 
void modificar_perfil_usuario(tipoUsuario users[], int *diml2);

/* Inicializar registros */
void inicializar_usuarios(tipoUsuario users[]); 
void inicializar_gastos(tipoGastos gasto[]);

/* Menu gastos */
void mostrar_menu_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3);
void agregar_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3);
void modificar_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml3); 
void eliminar_gastos(tipoUsuario users[], tipoGastos gasto[],int *diml3);

/* Reporte y Estadisticas */
void generar_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3); 
void mostrar_menu_calculos_estadisticos(tipoGastos gasto[], int *diml3);
void consultar_usuario_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3);
void calcular_promedio(tipoGastos gasto[],int *diml3); 
void calcular_minimo(tipoGastos gasto[], int *diml3);
void calcular_maximo(tipoGastos gasto[], int *diml3);