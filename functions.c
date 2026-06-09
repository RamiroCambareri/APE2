#include <stdio.h>
#include "structs.h"
#include "functions.h"

// Implementación de la función para mostrar el menú principal
void mostrar_menu(int *opcion)
{
    printf("\n================================");
    printf("\n  ---  GESTIÓN DE GASTOS  ---   ");
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
        users[i].ID = 0;
        users[i].dni = 0;
        users[i].apellido[0] = '\0'; // Inicializamos cada carácter del apellido como vacío
        users[i].nombre[0] = '\0';   // Inicializamos cada carácter del nombre como vacío
    }
}

void inicializar_categorias(tipoCategoria categorias[])
{
    for (int i = 0; i < MAX_NOMBRE_CATEGORIA; i++)
    {
        categorias[i].IdCategoria = 0;
        for (int j = 0; j < MAX_NOMBRE_CATEGORIA; j++)
        {
            categorias[i].nombreCategoria[0] = '\0'; // SI HAY ERROR ES EL [0] ""
        }
    }
}

void inicializar_gastos(tipoGastos gasto[])
{
    for (int i = 0; i < MAX_GASTOS; i++)
    {
        gasto[i].IDGasto = 0;
        gasto[i].gasto = 0;
        gasto[i].sumaGastos = 0;
        for (int j = 0; j < MAX_GASTOS; j++)
        {
            gasto[i].cantGastos[j] = 0;
        }
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
            users[i].dni = 0;
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

void agregar_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    // (*diml3) = (*diml2); // Sincronizamos la dimensión lógica de gastos con la de usuarios para asegurar que cada gasto esté asociado a un usuario válido
    int posicion = (*diml3);
    gasto->IDGasto += 0; // Inicializamos el ID del gasto (puede ser incrementado posteriormente para cada nuevo gasto)

    int ID_buscado;
    int opcion;
    int i, j, aux;

    // printf("\n DIMENSION LOGICA 2:: %d\n", *diml2);

    printf("Ingrese su id a buscar: ");
    scanf("%d", &ID_buscado);

    for (i = 0; i < *diml2; i++)
    {
        if (users[i].ID == ID_buscado)
        {
            printf("Usuario valido!");
            printf("Categorias disponibles:\n");
            for (int j = 0; j < 5; j++)
            {
                printf("\n--- Categoria %d: ", j + 1);

                printf("%s\n", categorias[j].nombreCategoria);
            }
            if (gasto->cantGastos[0] >= MAX_GASTOS)
            {
                printf("\nNo se pueden agregar más gastos. Capacidad máxima alcanzada.\n");
            }

            printf("\nSeleccione una de las opciones que se muestran en pantalla:(prsione 6 para salir): ");
            scanf("%d", &opcion);

            if (opcion >= 1 && opcion <= 5)
            {
                int idx = opcion - 1;
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gasto[posicion].gasto);                 // ✓ posicion
                gasto[posicion].IDGasto = posicion + 1;              // ✓ posicion
                gasto[posicion].usuario = users[i];                  // ✓ posicion
                gasto[posicion].categoria = categorias[idx];         // ✓ posicion
                gasto[posicion].cantGastos[idx]++;                   // ✓ posicion
                gasto[posicion].sumaGastos += gasto[posicion].gasto; // ✓ posicion
                (*diml3)++;
                printf("\n\tGasto agregado. Categoria: %s, Monto: %.2f\n",
                       categorias[idx].nombreCategoria, gasto[posicion].gasto);
                break;
            }
        }
    }

    //////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
    printf("\nDIMENSION LOGICA 3:: %d\n", *diml3); // Para depurar la dimensión lógica de gasto
    for (int i = 0; i < *diml3; i++)
    {
        printf("\n--- Gasto %d registrado ---\n", i);
        printf("\nID Gasto: %d", gasto[i].IDGasto);
        printf("\nMonto del gasto: %.2f", gasto[i].gasto);
        printf("\nUsuario asociado: %s %s, DNI: %d, ID: %d\n", gasto[i].usuario.nombre, gasto[i].usuario.apellido, gasto[i].usuario.dni, gasto[i].usuario.ID);
        printf("\nCategoría del gasto: %s\n", gasto[i].categoria.nombreCategoria);
    }
    //////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////
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
                printf("Cantidad de gastos en categoría %s: %d\n", categorias[j].nombreCategoria, gasto[i].cantGastos[j]);
            }
            return; // Cortamos el bucle porque ya lo encontramos y para no mostrar el printf diciendo que no se contro el usuario
        }
        else
        {
            printf("\nUsuario con ID %d no encontrado para el reporte.\n", id_buscado);
        }
    }
}

void generar_reporte(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2)
{
    // Implementación de la función para generar un reporte basado en los gastos y categorías
    printf("\n--- REPORTE DE GASTOS ---\n");
    consultar_usuario_reporte(users, gasto, categorias, diml2);
}

void mostrar_menu_calculos_estadisticos(tipoGastos gasto[], int *diml3)
{
    int opcion = 0;
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
    float suma_total = 0;
    float promedio;

    printf("\nIngrese su ID de usuario: ");
    scanf("%d", &ID_buscado);
    
    for (int i = 0; i < *diml3; i++)
    {
        if (gasto[i].usuario.ID == ID_buscado)
        {
            float total = 0;
            for (int k = 0; k < 5; k++)
            {
                total += gasto[i].cantGastos[k];
            }
            if (total > 0)
            {
                promedio = gasto[i].sumaGastos / total;
            }
            if (gasto[i].cantGastos > 0)
            {
                // gasto->sumaGastos / gasto[i].cantGastos[i];
                printf("\nUsuario:%d", gasto[i].usuario.ID);
                printf("\nSuma total: $%.2f", gasto[i].sumaGastos);                  //
                printf("\nCantidad de gastos registrados: %d", gasto[i].cantGastos); //
                printf("\nPROMEDIO GENERAL: $%.2f\n", promedio);
            }
            else
            {
                printf("El usuario con ID %d no tiene gastos en el sistema\n", ID_buscado);
            }
        }
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
                gasto_min = gasto[j].gasto; // primer gasto = mínimo inicial
                encontrado = 1;
            }
            else if (gasto[j].gasto < gasto_min)
            { // ← adentro del if del ID
                gasto_min = gasto[j].gasto;
            }
        }
    } // ← cierra el for

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
                gasto_max = gasto[j].gasto; // primer gasto = mínimo inicial
                encontrado = 1;
            }
            else if (gasto[j].gasto > gasto_max)
            { // ← adentro del if del ID
                gasto_max = gasto[j].gasto;
            }
        }
    } // ← cierra el for

    if (encontrado)
    {
        printf("\nEl gasto maximo es: $%.2f\n", gasto_max);
    }
    else
    {
        printf("\nEl usuario no ingreso ningun gasto.\n");
    }
}
