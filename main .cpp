#include "Banco.h"
#include "Listas.h"
#include <iostream>
#include <string>

int main() {
    Banco banco;
    Listas lista;
    int opcion;
    const std::string archivoCuentas = "cuentas.txt";

    // Cargar cuentas desde el archivo al iniciar
    banco.cargarCuentas(archivoCuentas);

    do {
        std::cout << "----- Banco -----\n";
        std::cout << "1. Crear cuenta\n";
        std::cout << "2. Listar cuentas\n";
        std::cout << "3. Ordenar cuentas por dinero ascendente\n";
        std::cout << "4. Ordenar cuentas por dinero descendente\n";
        std::cout << "5. Ordenar cuentas por nombre\n";
        std::cout << "6. Guardar cuentas\n";
        std::cout << "7. Cargar cuentas\n";
        std::cout << "8. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre;
                double dinero;
                std::cout << "Ingrese el nombre del titular: ";
                std::cin >> nombre;
                std::cout << "Ingrese la cantidad de dinero: ";
                std::cin >> dinero;
                banco.agregarCuenta(nombre, dinero);
                std::cout << "Cuenta creada exitosamente.\n";
                break;
            }
            case 2: {
                banco.listarCuentas();
                break;
            }
            case 3: {
                std::vector<Cuenta> cuentasOrdenadas = lista.bubbleSortPorDineroAsc(banco.getCuentas());
                banco.setCuentas(cuentasOrdenadas);
                std::cout << "Cuentas ordenadas por dinero ascendente:\n";
                banco.listarCuentas();
                break;
            }
            case 4: {
                std::vector<Cuenta> cuentasOrdenadas = lista.bubbleSortPorDineroDesc(banco.getCuentas());
                banco.setCuentas(cuentasOrdenadas);
                std::cout << "Cuentas ordenadas por dinero descendente:\n";
                banco.listarCuentas();
                break;
            }
            case 5: {
                std::vector<Cuenta> cuentasOrdenadas = lista.bubbleSortPorNombre(banco.getCuentas());
                banco.setCuentas(cuentasOrdenadas);
                std::cout << "Cuentas ordenadas por nombre:\n";
                banco.listarCuentas();
                break;
            }
            case 6: {
                banco.guardarCuentas(archivoCuentas);
                std::cout << "Cuentas guardadas exitosamente.\n";
                break;
            }
            case 7: {
                banco.cargarCuentas(archivoCuentas);
                std::cout << "Cuentas cargadas exitosamente.\n";
                break;
            }
            case 8: {
                std::cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                std::cout << "Opción no válida.\n";
                break;
            }
        }
    } while (opcion != 8);

    // Guardar cuentas antes de salir
    banco.guardarCuentas(archivoCuentas);

    return 0;
}
