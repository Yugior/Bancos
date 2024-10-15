#ifndef CUENTA_H_
#define CUENTA_H_

#include <iostream>
#include <string>

class Cuenta {
private:
    std::string nombre;
    double dinero;

public:
    // Constructor de Cuenta
    Cuenta(std::string nombre, double dinero) : nombre(nombre), dinero(dinero) {}

    // Getters
    std::string getNombre() const { 
        return nombre; 
    }

    double getSa() const { 
        return dinero; 
    }

    // Operadores de comparación
    bool operator>(const Cuenta& other) const {
        return dinero > other.dinero;
    }

    bool operator<(const Cuenta& other) const {
        return dinero < other.dinero;
    }

    bool nombreMayorQue(const Cuenta& other) const {
        return nombre > other.nombre;
    }

    // Imprimir cuenta
    void imprime() const {
        std::cout << nombre << " - $" << dinero << std::endl;
    }
};

#endif // CUENTA_H_
