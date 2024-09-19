#include "Banco.h"

void Banco::agregarCuenta(const std::string& nombre, double dinero) {
    cuentas.push_back(Cuenta(nombre, dinero));
}

void Banco::listarCuentas() const {
    if (cuentas.empty()) {
        std::cout << "No hay cuentas registradas.\n";
        return;
    }
    std::cout << "Cuentas del banco:\n";
    for (const auto& cuenta : cuentas) {
        cuenta.imprime();
    }
}

const std::vector<Cuenta>& Banco::getCuentas() const {
    return cuentas;
}

void Banco::setCuentas(const std::vector<Cuenta>& nuevasCuentas) {
    cuentas = nuevasCuentas;
}

void Banco::guardarCuentas(const std::string& filename) const {
    std::ofstream archivo(filename);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para guardar las cuentas.\n";
        return;
    }
    for (const auto& cuenta : cuentas) {
        archivo << cuenta.getNombre() << " " << cuenta.getDinero() << "\n";
    }
    archivo.close();
}

void Banco::cargarCuentas(const std::string& filename) {
    std::ifstream archivo(filename);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para cargar las cuentas.\n";
        return;
    }
    std::string nombre;
    double dinero;
    cuentas.clear();
    while (archivo >> nombre >> dinero) {
        agregarCuenta(nombre, dinero);
    }
    archivo.close();
}
