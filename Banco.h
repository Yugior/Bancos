#ifndef BANCO_H_
#define BANCO_H_

#include "Cuenta.h"
#include <vector>
#include <iostream>
#include <fstream>

class Banco {
private:
    std::vector<Cuenta> cuentas;
public:
    void agregarCuenta(const std::string& nombre, double dinero);
    void listarCuentas() const;

    const std::vector<Cuenta>& getCuentas() const;
    void setCuentas(const std::vector<Cuenta>& nuevasCuentas);

    void guardarCuentas(const std::string& filename) const;
    void cargarCuentas(const std::string& filename);
};

#endif // BANCO_H_
