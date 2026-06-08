#include "structs.h"

// Prototipos

void mostrar_menu(int *opcion); // HECHO
void mostrar_menu_perfil(tipoUsuario users[], int *diml2); // HECHO
void inicializar_usuarios(tipoUsuario users[]); // HECHO
void crear_usuarios(tipoUsuario users[], int *diml2); // HECHO
void eliminar_usuario(tipoUsuario users[], int *diml2); // HECHO
void modificar_perfil_usuario(tipoUsuario users[], int *diml2);

/* Menu gastos */
// FALTA ARREGLAR EL ID, NO LO DETECTA BIEN, HAY QUE VER COMO HACERLO PARA QUE DETECTE BIEN EL ID, PORQUE SI NO SE PUEDE MODIFICAR NI ELIMINAR LOS GASTOS PORQUE NO DETECTA EL ID, HAY QUE VER COMO HACERLO PARA QUE DETECTE BIEN EL ID, PORQUE SI NO SE PUEDE MODIFICAR NI ELIMINAR LOS GASTOS PORQUE NO DETECTA EL ID, HAY QUE VER COMO HACERLO PARA QUE DETECTE BIEN EL ID, PORQUE SI NO SE PUEDE MODIFICAR NI ELIMINAR LOS GASTOS PORQUE NO DETECTA EL ID
void mostrar_menu_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3); // HECHO 
void agregar_gastos(tipoUsuario users[], tipoGastos gastos[], tipoCategoria categorias[], int *diml2, int *diml3); // HECHO 
void modificar_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml3); // HECHO 
void eliminar_gastos(tipoUsuario users, tipoGastos gasto, tipoCategoria categorias, int *dimL);

/* Reporte y Estadisticas */
void generar_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2); // HECHO
void mostrar_menu_calculos_estadisticos(tipoUsuario users[], tipoGastos gastos[], int *diml2, int *diml3, float *promedio); //HECHO
void consultar_usuario_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2); // HECHO
void calcular_promedio(tipoUsuario users[], tipoGastos gasto[], int *diml2,float *promedio);//HECHO
void calcular_minimo(tipoUsuario users[], tipoGastos gasto[], int *diml2, int *diml3);
// void calcular_maximo(tipoGastos gasto[]);