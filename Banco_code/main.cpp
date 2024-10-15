#include <iostream>
#include <cstdlib>
#include "Listas.h"

void limpiarTerminal() {
    system("clear || cls"); // Limpiar la consola (dependiendo del sistema operativo)
}

void mostrarMenu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Agregar cuenta" << std::endl;
    std::cout << "2. Mostrar cuentas" << std::endl;
    std::cout << "3. Guardar cuentas en archivo" << std::endl;
    std::cout << "4. Ordenar cuentas por nombre" << std::endl;
    std::cout << "5. Ordenar cuentas por dinero" << std::endl;
    std::cout << "6. Salir" << std::endl;
}

int main() {
    ListaDobleLigada lista;
    lista.cargarCuentasDesdeArchivo(); // Cargar las cuentas desde el archivo al inicio

    int opcion;
    std::string nombre;
    double dinero;

    do {
        mostrarMenu();
        std::cout << "Elige una opción: ";
        std::cin >> opcion;
        limpiarTerminal(); // Limpiar la terminal después de cada opción

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el nombre de la cuenta: ";
                std::cin >> nombre;
                std::cout << "Ingrese la cantidad de dinero: ";
                std::cin >> dinero;
                lista.insertar(Cuenta(nombre, dinero));
                break;
            case 2:
                std::cout << "Cuentas:" << std::endl;
                lista.mostrarLista();
                break;
            case 3:
                lista.guardarCuentasEnArchivo();
                std::cout << "Cuentas guardadas en archivo." << std::endl;
                break;
            case 4:
                lista.ordenarPorNombre();
                std::cout << "Cuentas ordenadas por nombre:" << std::endl;
                lista.mostrarLista(); // Mostrar la lista después de ordenar
                break;
            case 5:
                lista.ordenarPorDinero();
                std::cout << "Cuentas ordenadas por dinero:" << std::endl;
                lista.mostrarLista(); // Mostrar la lista después de ordenar
                break;
            case 6:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida, intenta nuevamente." << std::endl;
                break;
        }
        std::cout << std::endl;
    } while (opcion != 6);

    return 0;
}
