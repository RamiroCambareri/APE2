#include <stdio.h>
#include <string.h>

#include "structs.h"
#include "functions.h"

// PROGRAMA PRINCIPAL
int main()
{
    int opcion = 0;
    int dimL = 0;
    int diml2 = 0;
    int diml3 = 0;
    tipoCategoria categorias[5] = {{"Comida"}, {"Transporte"}, {"Entretenimiento"}, {"Estudios"}, {"Varios"}};
    tipoUsuario users[MAX_USUARIOS];
    tipoGastos gastos[MAX_GASTOS];

    // tipoGastos gastos;

    inicializar_usuarios(users);
    
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
            mostrar_menu_gastos(users, gastos, categorias, &diml2, &diml3); // Mostramos el menú de gastos para el primer usuario
        }
        else if (opcion == 3)
        {
            generar_reporte(users, gastos[0], categorias[0]); // Llamamos a la función para generar el reporte del primer usuario y su primer gasto
            // generar_reporte(users, gastos, categorias[0]);
        }
        else if (opcion == 4)
        {
            // mostrar_menu_calculos_estadisticos(gastos);
        }
        else if (opcion != 5)
        {
            printf("\n Opcion invalida (el menu es de 1 - 5), intente nuevamente\n");
        }
        mostrar_menu(&opcion);
    }

    printf("\nSaliendo del programa...\n");

    return 0;
}
