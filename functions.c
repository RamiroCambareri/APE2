#include <stdio.h>
#include "structs.h"
#include "functions.h"

void mostrar_menu(int *opcion)
{
    printf("\n================================");
    printf("\n     GESTIÓN DE GASTOS          ");
    printf("\n================================");
    printf("\n1 - Menu de Perfil");
    printf("\n2 - Menu de Gastos");
    printf("\n3 - Generar Reporte");
    printf("\n4 - Estadisticas");
    printf("\n5 - Salir");
    printf("\nSeleccione una opcion: ");
    scanf("%d", opcion);
}

void mostrar_menu_perfil(tipoUsuario users[], int *diml2)
{
    int eleccion = 0;
    while (eleccion != 5)
    {
        printf("\n--- [SUBMENÚ PERFIL] ---");
        printf("\n1 - Crear usuario");
        printf("\n2 - Eliminar usuario");
        printf("\n3 - Modificar Perfil");
        printf("\n5 - Volver");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &eleccion);
        if (eleccion == 1)
        {
            // si el nombre esta vacio, se puede crear un nuevo usuario
            // if ((*users).nombre[0] == '\0') {
            crear_usuarios(users, diml2);
        }
        else if (eleccion == 2)
        {
            eliminar_usuario(users, diml2);
        }
        else if (eleccion == 3)
        {
           // generar_reporte(users, gasto, categorias); // Llamamos a la función para generar el reporte
            // modificar_usuario(*users, diml2);
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
        (*diml2)++;
        printf("\ndiml2 ELSE: %d\n", *diml2);
    }

    for (int j = 1; j < MAX_USUARIOS; j++)
    {
        printf("\n--------- RESPORTEEEEEEEEEEEEEEEEEEE--------------\n");
        printf("\n--- Usuario %d ---\n", j);
        printf("\nID CUENTA: %d", users[j].ID);
        printf("\nNOMBRE: %s", users[j].nombre);
        printf("\nAPELLIDO: %s", users[j].apellido);
        printf("\nDNI: %d", users[j].dni);
        printf("\ndiml2 FOR: %d\n", *diml2);
    }

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

// for (int j = i; j < *diml2 - 1; j++) {
//     // ANA, LUZ, LUIS
//     users->ID[j] = users->ID[j + 1];
//     users->dni[j] = users->dni[j + 1];

//     // Para las cadenas de texto (char) usamos strcpy para copiar el contenido
//     strcpy(users->apellido[j], users->apellido[j + 1]);
//     strcpy(users->nombre[j], users->nombre[j + 1]);
// }

// Implementacion de procedimiento mostrar_menu_gastos
void mostrar_menu_gastos(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    int eleccion = 0;
    while (eleccion != 5)
    {
        printf("\n--- [MENU DE GASTOS] ---");
        printf("\n1 - Agregar gasto");
        printf("\n2 - Modificar ultimo gasto");
        printf("\n3 - Eliminar ultimo gasto");
        printf("\n5 - Volver");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &eleccion);

        if (eleccion == 1)
        {
            agregar_gastos(users, gasto, categorias, diml2, diml3);
        }
        else if (eleccion == 2)
        {
            // modificar_gastos(*usuario, gasto[MAX_GASTOS], categoria, dimL);
        }
        else if (eleccion == 3)
        {
            // eliminar_gastos(*usuario, gasto[MAX_GASTOS], categoria, dimL);
        }
        else if (eleccion != 5)
        {
            printf("\n Opcion invalida, intente nuevamente\n");
        }
    }
}

void agregar_gastos(tipoUsuario users[], tipoGastos gastos[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    (*diml3) = (*diml2); // Sincronizamos la dimensión lógica de gastos con la de usuarios para asegurar que cada gasto esté asociado a un usuario válido
    
    int ID_buscado; 
    int opcion;
    int i, j;
    printf("\n\n\n DIMENSION LOGICA 2:: %d", *diml2);
    printf("\nIngrese ID de usuario: ");
    scanf("%d", &ID_buscado);
    
    // Despues crear funcion/procedimiento aparte para validar el ID ingresado [desde linea 186 hasta linea 202]
    if (ID_buscado < 0)
    {
        printf("\nID invalido. Por favor, ingrese un ID positivo.\n");
    }
    if (ID_buscado > (*diml2))
    {
        printf("\nID no encontrado. Por favor, ingrese un ID válido.\n");
    }
    if ((*diml2) == 0)
    {
        printf("\nNo hay usuarios registrados. Por favor, cree un usuario antes de agregar gastos.\n");
    }
    for (i = 0; i < *diml2; i++)
    {
        if (users[i].ID == ID_buscado)
        {
            printf("Usuario valido!");
            printf("Categorias disponibles:\n");
            for (int j = 0; j < 5; j++)
            {
                printf("\n--- Categoria %d ---\n", j + 1);
                
                printf("%s\n", categorias[j].nombreCategoria);
            }
            if (gastos->cantGastos[0] >= MAX_GASTOS)
            {
                printf("\nNo se pueden agregar más gastos. Capacidad máxima alcanzada.\n");
            }

            printf("\nSeleccione una de las opciones que se muestran en pantalla");
            scanf("%d", &opcion);
            if (opcion == 1)
            {
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto); 
                gastos->usuario = users[i];
                gastos->categoria = categorias[0];   // Asignamos la categoría seleccionada (ejemplo: categoría 1)
                gastos->cantGastos[0]++;             // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto; // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f");// Imprimimos el resultado
            } else if (opcion == 2)
            {
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto); 
                gastos->usuario = users[i];
                gastos->categoria = categorias[1];   // Asignamos la categoría seleccionada (ejemplo: categoría 2)
                gastos->cantGastos[1]++;             // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto; // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f");// Imprimimos el resultado
            } else if (opcion == 3)
            {
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto); 
                gastos->usuario = users[i];
                gastos->categoria = categorias[2];   // Asignamos la categoría seleccionada (ejemplo: categoría 3)
                gastos->cantGastos[2]++;             // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto; // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f");// Imprimimos el resultado
            } else if (opcion == 4)
            {
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto); 
                gastos->usuario = users[i];
                gastos->categoria = categorias[3];   // Asignamos la categoría seleccionada (ejemplo: categoría 4)
                gastos->cantGastos[3]++;             // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto; // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f");// Imprimimos el resultado
            } else if (opcion == 5)
            {
                printf("\nIngrese monto del gasto: ");
                scanf("%f", &gastos->gasto); 
                gastos->usuario = users[i];
                gastos->categoria = categorias[4];   // Asignamos la categoría seleccionada (ejemplo: categoría 5)
                gastos->cantGastos[4]++;             // Incrementamos la cantidad de gastos para esa categoría
                gastos->sumaGastos += gastos->gasto; // Sumamos el nuevo gasto al total de gastos
                printf("\nGasto agregado exitosamente. Total gastos en categoría %s: %d. Suma total de gastos: %.2f");// Imprimimos el resultado
            }
        }
        else
        {
            printf("\nID no encontrado. Por favor, ingrese un ID válido.\n");
        }
    }
}

void generar_reporte(tipoUsuario *users, tipoGastos gasto, tipoCategoria categorias)
{
    // Implementación de la función para generar un reporte basado en los gastos y categorías
    printf("\n--- REPORTE DE GASTOS ---\n");
    printf("Usuario: %s %s\n", users->nombre, users->apellido);
    printf("Categoría: %s\n", categorias.nombreCategoria);
    printf("Monto total gastado: %.2f\n", gasto.sumaGastos);
    printf("Cantidad de gastos registrados: %d\n", gasto.cantGastos[0]);
}