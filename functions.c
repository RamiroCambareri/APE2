#include <stdio.h>
#include "structs.h"
#include "functions.h"
#include <string.h>

// Implementacion de la funcion para mostrar el menu principal
void mostrar_menu(int *opcion)
{
    printf("\n================================");
    printf("\n  ---  GESTION DE GASTOS  ---   ");
    printf("\n================================");
    printf("\n1 - Menu de Perfil");  
    printf("\n2 - Menu de Gastos");  
    printf("\n3 - Generar Reporte"); 
    printf("\n4 - Estadisticas");    
    printf("\n5 - Salir");
    printf("\nSeleccione una opcion: ");
    scanf("%d", opcion);
}

// Implementacion de la funcion para mostrar el submenu de perfil
void mostrar_menu_perfil(tipoUsuario users[], int *diml2)
{
    int eleccion = 0;
    while (eleccion != 5)
    {
        printf("\n--- [SUBMENU PERFIL] ---");
        printf("\n1 - Crear usuario");    
        printf("\n2 - Eliminar usuario"); 
        printf("\n3 - Modificar Perfil"); 
        printf("\n5 - Volver");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &eleccion);
        if (eleccion == 1)
        {
            crear_usuarios(users, diml2);
        }
        else if (eleccion == 2)
        {
            eliminar_usuario(users, diml2);
        }
        else if (eleccion == 3)
        {
            modificar_perfil_usuario(users, diml2);
        }
        else if (eleccion != 5)
        {
            printf("\n Opcion invalida, intente nuevamente\n");
        }
    }
}

void inicializar_usuarios(tipoUsuario users[])
{
    for (int i = 0; i < MAX_USUARIOS; i++)
    {
        users[i].ID = 0;
        users[i].dni = 0;
        users[i].apellido[0] = '\0'; // Inicializamos cada caracter del apellido como vacio
        users[i].nombre[0] = '\0';   // Inicializamos cada caracter del nombre como vacio
    }
}

void inicializar_gastos(tipoGastos gasto[])
{
    for (int i = 0; i < MAX_GASTOS; i++)
    {
        gasto[i].IDGasto = 0;
        gasto[i].gasto = 0;
        gasto[i].sumaGastos = 0;
        for (int j = 0; j < 5; j++)
        {
            gasto[i].cantGastos[j] = 0;
        }
    }
}

void crear_usuarios(tipoUsuario users[], int *diml2)
{
    int id_local = *diml2 + 1; // ID local basado en la dimension logica actual

    if (*diml2 >= MAX_USUARIOS)
    {
        printf("\nNo se pueden agregar mas usuarios. Capacidad maxima alcanzada.\n");
        return;
    }
    else
    {
        int i = *diml2; // Usamos la dimension logica actual para determinar el indice del nuevo usuario
        printf("\nCreando nuevo usuario...\n");
        printf("\nIngrese nombre: ");
        scanf("%s", users[i].nombre);
        printf("\nIngrese apellido: ");
        scanf("%s", users[i].apellido);
        printf("\nIngrese DNI: ");
        scanf("%d", &users[i].dni);
        users[i].ID = id_local;
        printf("\n El usuario creado es: %s %s, DNI: %d, ID: %d\n", users[i].nombre, users[i].apellido, users[i].dni, users[i].ID);
        (*diml2)++;
    }
}

void modificar_perfil_usuario(tipoUsuario users[], int *diml2)
{
    // Implementacion de la funcion para modificar el perfil de un usuario especifico
    printf("\nIngrese ID de usuario a modificar: ");
    int id_buscado;
    scanf("%d", &id_buscado);
    for (int i = 0; i < *diml2; i++)
    {
        if (users[i].ID == id_buscado)
        {
            printf("\nUsuario encontrado, modificando...");
            printf("\nIngrese nuevo nombre: ");
            scanf("%s", users[i].nombre);
            printf("\nIngrese nuevo apellido: ");
            scanf("%s", users[i].apellido);
            printf("\nIngrese nuevo DNI: ");
            scanf("%d", &users[i].dni);
            printf("\nUsuario modificado. Nuevo perfil: %s %s, DNI: %d, ID: %d\n", users[i].nombre, users[i].apellido, users[i].dni, users[i].ID);
            return;
        }
    }
    printf("\nUsuario con ID %d no encontrado.\n", id_buscado);
}

void eliminar_usuario(tipoUsuario users[], int *diml2)
{
    printf("\nIngrese ID de usuario a eliminar: ");
    int id_buscado;
    scanf("%d", &id_buscado);
    for (int i = 0; i < *diml2; i++)
    {
        // busca el id usuario
        if (users[i].ID == id_buscado)
        {
            printf("\nUsuario encontrado, eliminando...");
            // Eliminar usuario (marcar como vacio o reiniciar campos)
            // corrimiento
            for (int j = i; j < (*diml2) - 1; j++)
            {
                users[j] = users[j + 1];
            }
            (*diml2)--;
            printf("\nUsuario eliminado.\n");
            return;
        }
    }
    printf("\nUsuario con ID %d no encontrado\n", id_buscado);
}

// Implementacion de procedimiento mostrar_menu_gastos
void mostrar_menu_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    int eleccion = 0;
    while (eleccion != 5)
    {
        printf("\n--- [SUBMENU GASTOS] ---");
        printf("\n1 - Agregar gasto");    
        printf("\n2 - Modificar gastos"); 
        printf("\n3 - Eliminar gastos");
        printf("\n5 - Volver");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &eleccion);

        if (eleccion == 1)
        {
            agregar_gastos(users, gasto, categorias, diml2, diml3);
        }
        else if (eleccion == 2)
        {
            modificar_gastos(users, gasto, categorias, diml3);
        }
        else if (eleccion == 3)
        {
            eliminar_gastos(users, gasto, diml3);
        }
        else if (eleccion != 5)
        {
            printf("\n Opcion invalida, intente nuevamente\n");
        }
    }
}

void agregar_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    int posicion = (*diml3);
    gasto->IDGasto += 0; // Inicializamos el ID del gasto (puede ser incrementado posteriormente para cada nuevo gasto)

    int ID_buscado;
    int opcion;
    int i, j, aux;

    if (*diml3 >= MAX_GASTOS)
    {
        printf("\nCapacidad maxima de gastos alcanzada.\n");
        return;
    }

    printf("Ingrese su id de usuario: ");
    scanf("%d", &ID_buscado);

    for (i = 0; i < *diml2; i++)
    {
        if (users[i].ID == ID_buscado)
        {
            printf("Usuario valido!");
            printf("Categorias disponibles:\n");
            for (int j = 0; j < 5; j++)
            {
                printf("\n|--- Categoria %d: ", j + 1);
                printf("|");

                printf("%s\n", categorias[j].nombreCategoria);
            }

            printf("\nSeleccione una de las opciones que se muestran en pantalla [6 para salir]: ");
            scanf("%d", &opcion);

            if (opcion >= 1 && opcion <= 5)
            {
                int idx = opcion - 1;
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gasto[posicion].gasto);
                gasto[posicion].IDGasto = posicion + 1;
                gasto[posicion].usuario = users[i];
                gasto[posicion].categoria = categorias[idx];
                gasto[posicion].cantGastos[idx]++;
                gasto[posicion].sumaGastos += gasto[posicion].gasto;
                (*diml3)++;
                printf("\n\tGasto agregado. Categoria: %s, Monto: %.2f\n", categorias[idx].nombreCategoria, gasto[posicion].gasto);
                break;
            }
        }
    }

    ////////  MUESTRA EN PANTALLA EL GASTO REGISTRADO y DEMAS INFORMACION ACERCA DEL GASTO   /////////
    for (int i = 0; i < *diml3; i++)
    {
        printf("\n--- Gasto %d registrado ---\n", i);
        printf("\nID Gasto: %d", gasto[i].IDGasto);
        printf("\nMonto del gasto: %.2f", gasto[i].gasto);
        printf("\nUsuario asociado: %s %s, DNI: %d, ID: %d\n", gasto[i].usuario.nombre, gasto[i].usuario.apellido, gasto[i].usuario.dni, gasto[i].usuario.ID);
        printf("\nCategoria del gasto: %s\n", gasto[i].categoria.nombreCategoria);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////
}

void modificar_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml3)
{
    int id_buscado = 0;
    if (*diml3 == 0)
    {
        printf("\nNo hay gastos registrados. Por favor, agregue un gasto antes de modificar.\n");
    }
    else
    {
        printf("\n Ingrese el ID del gasto a modificar: ");
        scanf("%d", &id_buscado);
        for (int i = 0; i < *diml3; i++)
        {
            if (gasto[i].IDGasto == id_buscado)
            {
                printf("\nGasto encontrado, modificando...");
                printf("\nIngrese nuevo monto del gasto: ");
                scanf("%f", &gasto[i].gasto);
                printf("\nGasto modificado. Nuevo monto: %.2f\n", gasto[i].gasto);
                return;
            }
        }
        printf("\nGasto con ID %d no encontrado.\n", id_buscado);
    }
}

void eliminar_gastos(tipoUsuario users[], tipoGastos gasto[],int *diml3)
{
    int id_buscado;
    if(*diml3 == 0){
        printf("No se ingreso ningun gasto");
        return;
    }
    printf("Ingrese eL ID de usuario: ");
    scanf("%d",&id_buscado);
   
    printf("Ingrese el ID del GASTO a eliminar: ");
    scanf("%d", &id_buscado);
    for (int i = 0; i < *diml3; i++)
    {
        if(gasto[i].IDGasto == id_buscado)
        {
            printf("Gasto encontrado, eliminando...");
            for (int j = i; j < (*diml3) - 1; j++)
            {
                gasto[j] = gasto[j + 1];
            }
            (*diml3)--;
            printf("\nGasto eliminado.\n");
            return;
        }
    }
   printf("\nGasto con ID %d no encontrado.\n", id_buscado);
}

void consultar_usuario_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    int id_buscado;
    float acumulador_total = 0;
    int contadores_locales[5] = {0};
    printf("\nIngrese ID de usuario para generar reporte: ");
    scanf("%d", &id_buscado);
    for (int i = 0; i < *diml2; i++)
    {
        if (users[i].ID == id_buscado)
        {
            printf("\nUsuario encontrado para el reporte: %s %s, DNI: %d, ID: %d\n", users[i].nombre, users[i].apellido, users[i].dni, users[i].ID);
            // ponemos los 5 contadores de categorias en 0
            for (int j = 0; j < *diml3; j++)
            {
                if (gasto[j].usuario.ID == id_buscado)
                {
                    acumulador_total += gasto[j].gasto; // acumulamos el monto real

                    // Recorremos las 5 categorias para comparar el nombre con el del gasto actual
                    for (int k = 0; k < 5; k++)
                    {
                        if (strcmp(gasto[j].categoria.nombreCategoria, categorias[k].nombreCategoria) == 0)
                        {
                            contadores_locales[k]++;
                        }
                    }
                }
            }

            // Imprimimos los resultados finales ya calculados
            printf("\nSuma total gastada: $%.2f\n", acumulador_total);
            printf("\n--- DETALLE POR CATEGORIAS ---\n");
            for (int j = 0; j < 5; j++)
            {
                printf("Cantidad de gastos en categorias %s: %d\n", categorias[j].nombreCategoria, contadores_locales[j]);
            }
            return;
        }
    }
    printf("\nEl usuario con ID %d no existe en el sistema.\n", id_buscado);
}

void generar_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    // Implementacion de la funcion para generar un reporte basado en los gastos y categorias
    printf("\n--- REPORTE DE GASTOS ---\n");
    consultar_usuario_reporte(users, gasto, categorias, diml2, diml3);
}

void mostrar_menu_calculos_estadisticos(tipoGastos gasto[], int *diml3)
{
    int opcion = 0;
    while (opcion != 5)
    {
        printf("\n--- [SUBMENU CALCULOS ESTADISTICOS] ---");
        printf("\n1 - Calcular Promedio general");
        printf("\n2 - Buscar gasto minimo");
        printf("\n3 - Buscar gasto maximo");
        printf("\n5 - Volver");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            calcular_promedio(gasto, diml3);
        }
        else if (opcion == 2)
        {
            calcular_minimo(gasto, diml3);
        }
        else if (opcion == 3)
        {
            calcular_maximo(gasto, diml3);
        }
        else if (opcion != 5)
        {
            printf("\n Opcion invalida, intente nuevamente\n");
        }
    }
}

void calcular_promedio(tipoGastos gasto[], int *diml3)
{
    int ID_buscado;
    float suma_monto = 0;
    int cantidad_gasto = 0;
    float promedio = 0;

    printf("\nIngrese su ID de usuario: ");
    scanf("%d", &ID_buscado);

    for (int i = 0; i < *diml3; i++)
    {
        if (gasto[i].usuario.ID == ID_buscado)
        {
            suma_monto += gasto[i].gasto; // acumulamos el dinero real gastado
            cantidad_gasto++;
        }
    }
    if (cantidad_gasto > 0)
    {
        promedio = suma_monto / cantidad_gasto;
        printf("\n--- ESTADISTICAS DEL USUARIO %d ---", ID_buscado);
        printf("\nSuma total: $%.2f", suma_monto);
        printf("\nCantidad de gastos registrados: %d", cantidad_gasto);
        printf("\nPROMEDIO GENERAL: $%.2f\n", promedio);
    }
    else
    {
        printf("\nEl usuario con ID %d no tiene gastos en el sistema.\n", ID_buscado);
    }
}

void calcular_minimo(tipoGastos gasto[], int *diml3)
{
    int j;
    float gasto_min = 0;
    int ID_buscado;
    int encontrado = 0;

    printf("\nIngrese su ID de usuario: ");
    scanf("%d", &ID_buscado);

    for (j = 0; j < *diml3; j++)
    {
        if (gasto[j].usuario.ID == ID_buscado)
        {
            if (!encontrado)
            {
                gasto_min = gasto[j].gasto; // primer gasto = minimo inicial
                encontrado = 1;
            }
            else if (gasto[j].gasto < gasto_min)
            {
                gasto_min = gasto[j].gasto;
            }
        }
    }

    if (encontrado)
    {
        printf("\nEl gasto minimo es: $%.2f\n", gasto_min);
    }
    else
    {
        printf("\nEl usuario no ingreso ningun gasto.\n");
    }
}

void calcular_maximo(tipoGastos gasto[], int *diml3)
{
    int j;
    float gasto_max = 0;
    int ID_buscado;
    int encontrado = 0;

    printf("\nIngrese su ID de usuario: ");
    scanf("%d", &ID_buscado);

    for (j = 0; j < *diml3; j++)
    {
        if (gasto[j].usuario.ID == ID_buscado)
        {
            if (!encontrado)
            {
                gasto_max = gasto[j].gasto; // primer gasto = minimo inicial
                encontrado = 1;
            }
            else if (gasto[j].gasto > gasto_max)
            {
                gasto_max = gasto[j].gasto;
            }
        }
    }

    if (encontrado)
    {
        printf("\nEl gasto maximo es: $%.2f\n", gasto_max);
    }
    else
    {
        printf("\nEl usuario no ingreso ningun gasto.\n");
    }
}