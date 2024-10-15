#ifndef LISTAS_H_
#define LISTAS_H_

#include <iostream>
#include <fstream>
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

    double getDinero() const { 
        return dinero; 
    }

    // Imprimir cuenta
    void imprime() const {
        std::cout << nombre << " - $" << dinero << std::endl;
    }
};

class Nodo {
public:
    Cuenta cuenta;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(Cuenta c) : cuenta(c), siguiente(nullptr), anterior(nullptr) {}
};

class ListaDobleLigada {
private:
    Nodo* cabeza;
    Nodo* cola;

public:

  
    ListaDobleLigada() : cabeza(nullptr), cola(nullptr) {}

    // Métodos de la lista
    void insertar(const Cuenta& cuenta);
    void mostrarLista() const;
    void guardarCuentasEnArchivo();
    void cargarCuentasDesdeArchivo();  //  Método para cargar desde el archivo
    void ordenarPorNombre();
    void ordenarPorDinero();

    // Funciones de ordenamiento
    void intercambiar(Nodo* a, Nodo* b);
};

// Insertar cuenta en la lista
// Inserta una nueva cuenta al final de la lista.
// Complejidad: O(1) porque se inserta directamente en la cola.
void ListaDobleLigada::insertar(const Cuenta& cuenta) {
    Nodo* nuevo = new Nodo(cuenta);
    if (!cabeza) {
        cabeza = nuevo;
        cola = nuevo;
    } else {
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

// Mostrar la lista de cuentas
// Muestra la lista de cuentas en la consola.
// Complejidad: O(n), ya que recorre toda la lista para imprimir cada cuenta.
void ListaDobleLigada::mostrarLista() const {
    Nodo* actual = cabeza;
    while (actual) {
        actual->cuenta.imprime();
        actual = actual->siguiente;
    }
}


// Guarda las cuentas actuales en el archivo "cuentas.txt".
// Complejidad: O(n), ya que recorre toda la lista para escribir cada cuenta en el archivo.
void ListaDobleLigada::guardarCuentasEnArchivo() {
    std::ofstream archivoSalida("cuentas.txt", std::ios::out);
    Nodo* actual = cabeza;
    while (actual) {
        archivoSalida << actual->cuenta.getNombre() << " " << actual->cuenta.getDinero() << std::endl;
        actual = actual->siguiente;
    }
    archivoSalida.close();
}


// Carga cuentas desde el archivo "cuentas.txt" y las inserta en la lista.
// Complejidad: O(n) donde n es el número de cuentas en el archivo.
void ListaDobleLigada::cargarCuentasDesdeArchivo() {
    std::ifstream archivoEntrada("cuentas.txt");
    if (!archivoEntrada) {
        std::cerr << "Error al abrir el archivo de cuentas." << std::endl;
        return;
    }

    std::string nombre;
    double dinero;
    while (archivoEntrada >> nombre >> dinero) {
        insertar(Cuenta(nombre, dinero));
    }

    archivoEntrada.close();
}

// Ordenar la lista por nombre
// Ordena la lista de cuentas por nombre utilizando el algoritmo de burbuja.
// Complejidad: O(n^2) en el peor de los casos, ya que es una implementación básica de burbuja.
void ListaDobleLigada::ordenarPorNombre() {
    if (!cabeza) return;

    bool intercambio;
    do {
        intercambio = false;
        Nodo* actual = cabeza;
        while (actual->siguiente) {
            if (actual->cuenta.getNombre() > actual->siguiente->cuenta.getNombre()) {
                intercambiar(actual, actual->siguiente);
                intercambio = true;
            }
            actual = actual->siguiente;
        }
    } while (intercambio);
}

// Ordenar la lista por dinero
// Ordena la lista de cuentas por dinero utilizando el algoritmo de burbuja.
// Complejidad: O(n^2) en el peor de los casos, similar al ordenamiento por nombre.
void ListaDobleLigada::ordenarPorDinero() {
    if (!cabeza) return;

    bool intercambio;
    do {
        intercambio = false;
        Nodo* actual = cabeza;
        while (actual->siguiente) {
            if (actual->cuenta.getDinero() > actual->siguiente->cuenta.getDinero()) {
                intercambiar(actual, actual->siguiente);
                intercambio = true;
            }
            actual = actual->siguiente;
        }
    } while (intercambio);
}

// Función auxiliar para intercambiar dos nodos
// Destructor: Libera la memoria de todos los nodos de la lista.
// Complejidad: O(n), donde n es el número de nodos en la lista.
void ListaDobleLigada::intercambiar(Nodo* a, Nodo* b) {
    Cuenta temp = a->cuenta;
    a->cuenta = b->cuenta;
    b->cuenta = temp;
}

#endif // LISTAS_H_
