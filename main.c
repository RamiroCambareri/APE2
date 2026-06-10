#include <stdio.h>
#include <string.h>

#include "structs.h"
#include "functions.h"

// PROGRAMA PRINCIPAL
int main()
{
    int opcion = 0;
    int diml2 = 0; // usuario
    int diml3 = 0; // gastos

    tipoCategoria categorias[5] = {{"Comida"}, {"Transporte"}, {"Entretenimiento"}, {"Estudios"}, {"Varios"}};
    tipoUsuario users[MAX_USUARIOS];
    tipoGastos gasto[MAX_GASTOS];

    inicializar_usuarios(users);
    inicializar_gastos(gasto);

    mostrar_menu(&opcion);
    

    while (opcion != 5)
    {
        if (opcion == 1)
        {
            mostrar_menu_perfil(users, gasto,&diml2,&diml3); // Mostramos el menu perfil para los usuarios
        }
        else if (opcion == 2)
        {
            // Pasamos referencias (&) para que los cambios persistan en el main
            mostrar_menu_gastos(users, gasto, categorias, &diml2, &diml3); // Mostramos el menú de gastos para los usuarios
        }
        else if (opcion == 3)
        {
            generar_reporte(users, gasto, categorias, &diml2,&diml3); // Llamamo a generar reporte para que vean sus gastos los usuarios
        }
        else if (opcion == 4)
        {
            mostrar_menu_calculos_estadisticos(gasto, &diml3); // llamamos al menu de calculos estadisticos
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