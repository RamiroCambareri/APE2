#include <stdio.h>
#include <string.h>

#include "structs.h"
#include "functions.h"

void debuggear(tipoUsuario users[], tipoGastos gasto[], tipoCategoria categorias[], int *diml2, int *diml3)
{
    printf("\n--- DEBUGGEO DE USUARIOS ---\n");
    for (int i = 0; i < *diml2; i++)
    {
        printf("\nID: %d, Nombre: %s, Apellido: %s, DNI: %d\n", users[i].ID, users[i].nombre, users[i].apellido, users[i].dni);
    }
    printf("\n--- DEBUGGEO DE GASTOS ---\n");
    for (int j = 0; j < *diml3; j++)
    {
        printf("\nID Gasto: %d, Monto: %.2f, Usuario ID: %d\n", gasto[j].IDGasto, gasto[j].gasto, gasto[j].usuario.ID);
    }
    printf("\n--- DEBUGGEO DE CATEGORIAS ---\n");
    for (int k = 0; k < 5; k++)
    {
        printf("\nID Categoria: %d, Nombre Categoria: %s\n", categorias[k].IdCategoria, categorias[k].nombreCategoria);
    }
}

// PROGRAMA PRINCIPAL
int main()
{
    int opcion = 0;
    int diml2 = 0; // usuario
    int diml3 = 0; // gastos
   

    tipoCategoria categorias[5] = {{"Comida"}, {"Transporte"}, {"Entretenimiento"}, {"Estudios"}, {"Varios"}};
    tipoUsuario users[MAX_USUARIOS];
    tipoGastos gasto[MAX_GASTOS];

    // tipoGastos gastos;

    inicializar_usuarios(users);
    // inicializar_categorias(categorias);
    inicializar_gastos(gasto);

    debuggear(users, gasto, categorias, &diml2, &diml3); // Función para debuggear, puedes eliminarla si no es necesaria
    
    mostrar_menu(&opcion);

    while (opcion != 5)
    {
        if (opcion == 1)
        {
            mostrar_menu_perfil(users, &diml2); // Mostramos el perfil del primer usuario
        }
        else if (opcion == 2)
        {
            // Pasamos referencias (&) para que los cambios persistan en el main
            mostrar_menu_gastos(users, gasto, categorias, &diml2, &diml3); // Mostramos el menú de gastos para el primer usuario
        }
        else if (opcion == 3)
        {
            generar_reporte(users, gasto, categorias, &diml2); // Llamamos a la función para generar el reporte del primer usuario y su primer gasto
        }
        else if (opcion == 4)
        {
            mostrar_menu_calculos_estadisticos(gasto, &diml3);
        }
        else if (opcion != 5)
        {
            printf("\n Opcion invalida (el menu es de 1 - 5), intente nuevamente\n");
        }
        mostrar_menu(&opcion);
    }

    printf("\nSaliendo del programa...\n");


    debuggear(users, gasto, categorias, &diml2, &diml3); // Función para debuggear, se puede eliminar si no es necesaria
    return 0;
}
