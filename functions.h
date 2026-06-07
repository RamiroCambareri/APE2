#include "structs.h"

// Prototipos

void mostrar_menu(int *opcion);
void mostrar_menu_perfil(tipoUsuario users[], int *diml2);
void inicializar_usuarios(tipoUsuario users[]);
void crear_usuarios(tipoUsuario users[], int *diml2);
void eliminar_usuario(tipoUsuario users[], int *diml2);
void modificar_perfil_usuario(tipoUsuario users, int *diml2);

/* Menu gastos */
void mostrar_menu_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3);
void agregar_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3);
void modificar_gastos(tipoUsuario users, tipoGastos gasto, tipoCategoria categorias, int *dimL);
void eliminar_gastos(tipoUsuario users, tipoGastos gasto, tipoCategoria categorias, int *dimL);

/* Reporte y Estadisticas */
void generar_reporte(tipoUsuario *users, tipoGastos gasto, tipoCategoria categorias);
void mostrar_menu_calculos_estadisticos(tipoGastos gasto);
void calcular_promedio(tipoGastos gasto);
