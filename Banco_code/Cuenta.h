#ifndef CUENTA_H_
#define CUENTA_H_

#include <string>
#include <iostream>

class Cuenta {
private:
    std::string nombre;
    double dinero;
public:
    Cuenta(std::string nombre, double dinero);
    
    std::string getNombre() const;
    double getDinero() const;

    bool operator>(const Cuenta& other) const;
    bool operator<(const Cuenta& other) const;
    bool nombreMayorQue(const Cuenta& other) const;

    void imprime() const;
};

#endif // CUENTA_H_
