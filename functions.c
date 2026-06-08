#include <stdio.h>
#include "structs.h"
#include "functions.h"

// Implementación de la función para mostrar el menú principal
void mostrar_menu(int *opcion)
{
    printf("\n================================");
    printf("\n     GESTIÓN DE GASTOS          ");
    printf("\n================================");
    printf("\n1 - Menu de Perfil");  // hehco
    printf("\n2 - Menu de Gastos");  // hecho
    printf("\n3 - Generar Reporte"); // hecho
    printf("\n4 - Estadisticas");    // hacer
    printf("\n5 - Salir");
    printf("\nSeleccione una opcion: ");
    scanf("%d", opcion);
}

// Implementación de la función para mostrar el submenú de perfil
void mostrar_menu_perfil(tipoUsuario users[], int *diml2)
{
    int eleccion = 0;
    while (eleccion != 5)
    {
        printf("\n--- [SUBMENÚ PERFIL] ---");
        printf("\n1 - Crear usuario");    // hecho
        printf("\n2 - Eliminar usuario"); // hecho
        printf("\n3 - Modificar Perfil"); // hacer
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
        users[i].ID = -1;
        users[i].dni = 0;
        users[i].apellido[0] = '\0'; // Inicializamos el apellido como vacío
        users[i].nombre[0] = '\0';   // Inicializamos el nombre como vacío
    }
}

void crear_usuarios(tipoUsuario users[], int *diml2)
{
    int id_local = *diml2 + 1; // ID local basado en la dimensión lógica actual

    if (*diml2 >= MAX_USUARIOS)
    {
        printf("\nNo se pueden agregar más usuarios. Capacidad máxima alcanzada.\n");
        return;
    }
    else
    {
        int i = *diml2; // Usamos la dimensión lógica actual para determinar el índice del nuevo usuario
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
        // printf("\ndiml2 ELSE: %d\n", *diml2); para depurar
    }

    // for (int j = 1; j < MAX_USUARIOS; j++)
    // {
    //     printf("\n--------- RESPORTEEEEEEEEEEEEEEEEEEE--------------\n");
    //     printf("\n--- Usuario %d creado ---\n", j);
    //     printf("\nID CUENTA: %d", users[j].ID);
    //     printf("\nNOMBRE: %s", users[j].nombre);
    //     printf("\nAPELLIDO: %s", users[j].apellido);
    //     printf("\nDNI: %d", users[j].dni);
    //     printf("\ndiml2 FOR: %d\n", *diml2);
    // }

    /* DEPURAR DIMENSION LOGICA */
    // printf("\ndiml2: %d\n", *diml2);
}

void eliminar_usuario(tipoUsuario users[], int *diml2)
{
    // int id_local = *diml2 + 1;

    printf("\nIngrese ID de usuario a eliminar: ");
    int id_buscado;
    scanf("%d", &id_buscado);
    for (int i = 0; i < *diml2; i++)
    {

        if (users[i].ID == id_buscado)
        {
            printf("\nUsuario encontrado, eliminando...");
            // Eliminar usuario (marcar como vacío o reiniciar campos)
            users[i].ID = 0;
            users->dni = 0;
            users->apellido[0] = '\0';
            users->nombre[0] = '\0';
            (*diml2)--;
            printf("\nUsuario eliminado. Nueva dimensión lógica: %d\n", *diml2);
        }
        else
        {
            printf("\nUsuario con ID %d no encontrado.\n", id_buscado);
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// CORRIMIENTO DE USUARIOS PARA LA FUNCION ELIMINAR USUARIOS (NO FUNCIONA CORRECTAMENTE, REVISAR)
/////////////////////////////////////////////////////////////////////////////////////////////////

// for (int j = i; j < *diml2 - 1; j++) {
//     // ANA, LUZ, LUIS
//     users->ID[j] = users->ID[j + 1];
//     users->dni[j] = users->dni[j + 1];

//     // Para las cadenas de texto (char) usamos strcpy para copiar el contenido
//     strcpy(users->apellido[j], users->apellido[j + 1]);
//     strcpy(users->nombre[j], users->nombre[j + 1]);
// }

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

// Implementacion de procedimiento mostrar_menu_gastos
void mostrar_menu_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    int eleccion = 0;
    while (eleccion != 5)
    {
        printf("\n--- [MENU DE GASTOS] ---");
        printf("\n1 - Agregar gasto");    // hecho
        printf("\n2 - Modificar gastos"); // hacer
        printf("\n3 - Eliminar gastos");  // hacer
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
            //  eliminar_gastos();
        }
        else if (eleccion != 5)
        {
            printf("\n Opcion invalida, intente nuevamente\n");
        }
    }
}

// if (ID_buscado < 0){
//     printf("\nID invalido. Por favor, ingrese un ID positivo.\n");
//     return ID_buscado; // 0 -> no se encontro
// }
// if (ID_buscado > (*diml2)){
//     printf("\nID no encontrado. Por favor, ingrese un ID válido.\n");
//     return ID_buscado;
// }
// if ((*diml2) == 0){
//     printf("\nNo hay usuarios registrados. Por favor, cree un usuario antes de agregar gastos.\n");
//     return 0;
// }

void agregar_gastos(tipoUsuario users[], tipoGastos gastos[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    (*diml3) = (*diml2);  // Sincronizamos la dimensión lógica de gastos con la de usuarios para asegurar que cada gasto esté asociado a un usuario válido
    gastos->IDGasto += 0; // Inicializamos el ID del gasto (puede ser incrementado posteriormente para cada nuevo gasto)

    int ID_buscado;
    int opcion;
    int i, j, aux;
    // printf("\n DIMENSION LOGICA 2:: %d\n", *diml2);

    printf("Ingrese su id a buscar: ");
    scanf("%d", &ID_buscado);
    // Despues crear funcion/procedimiento aparte para validar el ID ingresado [desde linea 186 hasta linea 202]
    // if ((ID_buscado < 0) && (ID_buscado > (*diml2)) && ((*diml2) == 0))
    // {
    //     printf("\nID invalido. Por favor, ingrese un ID positivo.\n");
    // }
    // else if (ID_buscado > (*diml2))
    // {
    //     printf("\nID no encontrado. Por favor, ingrese un ID válido.\n");
    // }
    // else if ((*diml2) == 0)
    // {
    //     printf("\nNo hay usuarios registrados. Por favor, cree un usuario antes de agregar gastos.\n");
    // }

    for (i = 0; i < *diml2; i++)
    {
        if (users[i].ID == ID_buscado)
        {
            printf("Usuario valido!");
            printf("Categorias disponibles:\n");
            for (int j = 0; j < 5; j++)
            {
                printf("\n--- Categoria: %d", j + 1);

                printf("%s\n", categorias[j].nombreCategoria);
            }
            if (gastos->cantGastos[0] >= MAX_GASTOS)
            {
                printf("\nNo se pueden agregar más gastos. Capacidad máxima alcanzada.\n");
            }

            printf("\nSeleccione una de las opciones que se muestran en pantalla: ");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                gastos->IDGasto = gastos->IDGasto + 1;
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto);
                gastos->usuario = users[i];
                gastos->categoria = categorias[0];                                                                     // Asignamos la categoría seleccionada (ejemplo: categoría 1)
                gastos->cantGastos[0]++;                                                                               // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto;                                                                   // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f"); // Imprimimos el resultado
            }
            else if (opcion == 2)
            {
                gastos->IDGasto = gastos->IDGasto + 1; // Incrementamos el ID del gasto para el próximo gasto
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto);
                gastos->usuario = users[i];
                gastos->categoria = categorias[1];                                                                     // Asignamos la categoría seleccionada (ejemplo: categoría 2)
                gastos->cantGastos[1]++;                                                                               // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto;                                                                   // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f"); // Imprimimos el resultado
            }
            else if (opcion == 3)
            {
                gastos->IDGasto = gastos->IDGasto + 1;
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto);
                gastos->usuario = users[i];
                gastos->categoria = categorias[2];                                                                     // Asignamos la categoría seleccionada (ejemplo: categoría 3)
                gastos->cantGastos[2]++;                                                                               // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto;                                                                   // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f"); // Imprimimos el resultado
            }
            else if (opcion == 4)
            {
                gastos->IDGasto = gastos->IDGasto + 1;
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto);
                gastos->usuario = users[i];
                gastos->categoria = categorias[3];                                                                     // Asignamos la categoría seleccionada (ejemplo: categoría 4)
                gastos->cantGastos[3]++;                                                                               // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto;                                                                   // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f"); // Imprimimos el resultado
            }
            else if (opcion == 5)
            {
                gastos->IDGasto = gastos->IDGasto + 1;
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto);
                gastos->usuario = users[i];
                gastos->categoria = categorias[4];                                                                     // Asignamos la categoría seleccionada (ejemplo: categoría 5)
                gastos->cantGastos[4]++;                                                                               // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto;                                                                   // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f"); // Imprimimos el resultado
            }
        (*diml3)++;
        return;
        }
        else
        {
            printf("\nID no encontrado. Por favor, ingrese un ID válido.\n");
        }
    }

    // dasd
    ////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////
    printf("\nDIMENSION LOGICA 3:: %d\n", *diml3); // Para depurar la dimensión lógica de gasto
    for (int i = 0; i < *diml3; i++)
    {
        printf("\n--- Gasto %d registrado ---\n", i);
        printf("\nID Gasto: %d", gastos[i].IDGasto);
        printf("\nMonto del gasto: %.2f", gastos[i].gasto);
        printf("\nUsuario asociado: %s %s, DNI: %d, ID: %d\n", gastos[i].usuario.nombre, gastos[i].usuario.apellido, gastos[i].usuario.dni, gastos[i].usuario.ID);
        printf("\nCategoría del gasto: %s\n", gastos[i].categoria.nombreCategoria);
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////
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
                // Actualizamos la suma total de gastos para reflejar el cambio[]
                if (gasto[i].sumaGastos >= gasto[i].gasto)
                {
                    gasto[i].sumaGastos -= gasto[i].gasto; // Restamos el monto anterior del gasto modificado
                }
                else if (gasto[i].sumaGastos < gasto[i].gasto)
                {
                    gasto[i].sumaGastos += gasto[i].gasto; // Sumamos el nuevo monto del gasto modificado
                }
                else
                {
                    printf("\nError al modificar el gasto. Por favor, intente nuevamente.\n");
                }

                // gasto[i].sumaGastos; // Reiniciamos la suma total de gastos
                // for (int j = 0; j < *diml3; j++)
                // {
                //     gasto[i].sumaGastos += gasto[j].gasto; // Recalculamos la suma total de gastos después de la modificación
                // }
            }
            else
            {
                printf("\nGasto con ID %d no encontrado.\n", id_buscado);
            }
        }
    }
}

void modificar_perfil_usuario(tipoUsuario users[], int *diml2)
{
    // Implementación de la función para modificar el perfil de un usuario específico
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
        }
        else
        {
            printf("\nUsuario con ID %d no encontrado.\n", id_buscado);
        }
    }
}

void consultar_usuario_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2)
{
    int id_buscado;
    printf("\nIngrese ID de usuario para generar reporte: ");
    scanf("%d", &id_buscado);
    for (int i = 0; i < *diml2; i++)
    {
        if (users[i].ID == id_buscado)
        {
            printf("\nUsuario encontrado para el reporte: %s %s, DNI: %d, ID: %d\n", users[i].nombre, users[i].apellido, users[i].dni, users[i].ID);
            printf("\nSuma total: %2.f\n", gasto[i].sumaGastos);
            for (int j = 0; j < 5; j++)
            {
                printf("Cantidad de gastos en categoría %s: %d\n", categorias[j].nombreCategoria, gasto[j].cantGastos[i]);
            }
            return; // Cortamos el bucle porque ya lo encontramos y para no mostrar el printf diciendo que no se contro el usuario
        }
    }
    printf("\nUsuario con ID %d no encontrado para el reporte.\n", id_buscado);
}

void generar_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2)
{
    // Implementación de la función para generar un reporte basado en los gastos y categorías
    printf("\n--- REPORTE DE GASTOS ---\n");
    consultar_usuario_reporte(users, gasto, categorias, diml2);
    // printf("Usuario: %s %s\n", users->nombre, users->apellido);
    // printf("Categoría: %s\n", categorias->nombreCategoria);
    // printf("Monto total gastado (SumaGastos): %.2f\n", gasto->sumaGastos);
    // printf("ID gasto: %d\n", gasto->IDGasto);
    // printf("Cantidad de gastos registrados: %d\n", gasto->cantGastos[0]);
    // printf("Ultimo gasto registrado: %.2f\n", gasto->gasto);
}

void mostrar_menu_calculos_estadisticos(tipoUsuario users[],tipoGastos gasto[], int *diml2,int *diml3,float *promedio)
{
    int opcion;
    while (opcion != 5)
    {
        printf("\n--- [ESTADISTICAS] ---");
        printf("\n1 - Calcular Promedio general");
        printf("\n2 - Buscar gasto minimo");
        printf("\n3 - Buscar gasto maximo");
        printf("\n5 - Volver");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            calcular_promedio(users, gasto, diml2,promedio);
        }
        else if (opcion == 2)
        {
            calcular_minimo(users, gasto, diml2, diml3);
        }
        else if (opcion == 3)
        {
            //calcular_maximo(gastos);
        }
        else if (opcion != 5)
        {
            printf("\n Opcion invalida, intente nuevamente\n");
        }
    }
}

void calcular_promedio(tipoUsuario users[], tipoGastos gasto[], int *diml2,float *promedio)
{
    int i;
    int ID_buscado;

    printf("\nIngrese su ID de usuario");
    scanf("%d", &ID_buscado);
    for (i = 0; i < *diml2; i++)
    {

        if (users[i].ID== ID_buscado)
        {
            if (gasto[i].cantGastos > 0)
            {
                (*promedio) = (gasto->sumaGastos / gasto[i].cantGastos[i]);
                printf("\nUsuario:%d", users[i].ID);
                // printf("\nSuma total: $%.2f", gastos->sumaGastos);
                // printf("\nCantidad de gastos registrados: %d", gastos->cantGastos);
                printf("\nPROMEDIO GENERAL: $%.2f\n", *promedio);
            }
        }
    }
}

void calcular_minimo(tipoUsuario users[], tipoGastos gasto[],  int *diml2,int *diml3)
{
    int i; // usuarios
    int j; // gastos
    float gasto_min = gasto[0].gasto;
    int ID_buscado;

    printf("\n Ingrese su ID de usuario");
    scanf("%d", &ID_buscado);
    for (i = 0; i < *diml2; i++)// recorre vector de usuarios buscando el ID de ese usuario ingresado
    {
        if (users[i].ID == ID_buscado)
        {
        for (j = 0; j < *diml3; j++)
            {
                if (gasto[j].usuario.ID == ID_buscado)
                {
                    if (gasto[j].gasto < gasto_min)
                    {
                        gasto_min = gasto[j].gasto;
                    }else{
                        printf("\nError\n");
                    }
                    
                 }
            }
             printf("\n El gasto minimo es: %.2f", gasto[j].gasto);   // aca
        }
    }
    
}
