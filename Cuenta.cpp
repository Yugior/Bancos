#include "Cuenta.h"

Cuenta::Cuenta(std::string nombre, double dinero) : nombre(nombre), dinero(dinero) {}

std::string Cuenta::getNombre() const { 
    return nombre; 
}

double Cuenta::getDinero() const { 
    return dinero; 
}

bool Cuenta::operator>(const Cuenta& other) const {
    return dinero > other.dinero;
}

bool Cuenta::operator<(const Cuenta& other) const {
    return dinero < other.dinero;
}

bool Cuenta::nombreMayorQue(const Cuenta& other) const {
    return nombre > other.nombre;
}

void Cuenta::imprime() const {
    std::cout << nombre << " - $" << dinero << std::endl;
}
