#ifndef LISTAS_H_
#define LISTAS_H_

#include <iostream>
#include <fstream>
#include <string>

// Clase Cuenta: representa una cuenta con un nombre y una cantidad de dinero.
class Cuenta {
private:
    std::string nombre;  // Nombre del titular de la cuenta.
    double dinero;       // Monto de dinero en la cuenta.

public:
    // Constructor para inicializar una cuenta con nombre y dinero.
    Cuenta(std::string nombre, double dinero) : nombre(nombre), dinero(dinero) {}

    // Métodos para obtener los valores privados.
    std::string getNombre() const { 
        return nombre; 
    }

    double getDinero() const { 
        return dinero; 
    }

    // Imprime los detalles de la cuenta (nombre y dinero).
    void imprime() const {
        std::cout << nombre << " - $" << dinero << std::endl;
    }
};

// Clase Nodo: representa un nodo en la lista doblemente ligada.
class Nodo {
public:
    Cuenta cuenta;       // Información de la cuenta almacenada en el nodo.
    Nodo* siguiente;     // Puntero al siguiente nodo en la lista.
    Nodo* anterior;      // Puntero al nodo anterior en la lista.

    // Constructor para inicializar un nodo con una cuenta.
    Nodo(Cuenta c) : cuenta(c), siguiente(nullptr), anterior(nullptr) {}
};

// Clase ListaDobleLigada: implementa una lista doblemente ligada para manejar cuentas.
class ListaDobleLigada {
private:
    Nodo* cabeza;  // Puntero al primer nodo de la lista.
    Nodo* cola;    // Puntero al último nodo de la lista.

    // Divide la lista en dos mitades y devuelve la cabeza de la segunda mitad.
    Nodo* dividirLista(Nodo* cabeza);

    // Fusiona dos listas ordenadas en una sola lista ordenada.
    Nodo* fusionarListas(Nodo* lista1, Nodo* lista2, bool porNombre);

    // Método recursivo para aplicar merge sort en la lista.
    Nodo* mergeSort(Nodo* cabeza, bool porNombre);

public:
    // Constructor para inicializar una lista vacía.
    ListaDobleLigada() : cabeza(nullptr), cola(nullptr) {}

    // Métodos públicos para manejar la lista.
    void insertar(const Cuenta& cuenta);      // Inserta una nueva cuenta en la lista.
    void mostrarLista() const;               // Muestra todas las cuentas en la lista.
    void guardarCuentasEnArchivo();          // Guarda las cuentas en un archivo.
    void cargarCuentasDesdeArchivo();        // Carga las cuentas desde un archivo.
    void ordenarPorNombre();                 // Ordena las cuentas alfabéticamente por nombre.
    void ordenarPorDinero();                 // Ordena las cuentas por el monto de dinero.

    // Destructor para liberar la memoria utilizada por la lista.
    ~ListaDobleLigada();
};

// Implementación de los métodos de ListaDobleLigada

// Inserta una nueva cuenta al final de la lista.
// Si la lista está vacía, el nuevo nodo se convierte en la cabeza y la cola.
// Complejidad: O(1).
void ListaDobleLigada::insertar(const Cuenta& cuenta) {
    Nodo* nuevo = new Nodo(cuenta);
    if (!cabeza) { // Si la lista está vacía.
        cabeza = nuevo;
        cola = nuevo;
    } else { // Inserta al final de la lista.
        cola->siguiente = nuevo;
        nuevo->anterior = cola;
        cola = nuevo;
    }
}

// Muestra todas las cuentas en la lista.
// Recorre la lista desde la cabeza y muestra cada cuenta.
// Complejidad: O(n), donde n es el número de nodos en la lista.
void ListaDobleLigada::mostrarLista() const {
    Nodo* actual = cabeza;
    while (actual) {
        actual->cuenta.imprime();
        actual = actual->siguiente;
    }
}

// Guarda las cuentas en el archivo "cuentas.txt".
// Escribe cada cuenta en una nueva línea del archivo.
// Complejidad: O(n).
void ListaDobleLigada::guardarCuentasEnArchivo() {
    std::ofstream archivoSalida("cuentas.txt", std::ios::out);
    Nodo* actual = cabeza;
    while (actual) {
        archivoSalida << actual->cuenta.getNombre() << " " << actual->cuenta.getDinero() << std::endl;
        actual = actual->siguiente;
    }
    archivoSalida.close();
}

// Carga cuentas desde el archivo "cuentas.txt".
// Cada línea debe tener un nombre y una cantidad de dinero.
// Complejidad: O(n), donde n es el número de líneas en el archivo.
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

// Divide la lista en dos mitades.
// Devuelve un puntero al inicio de la segunda mitad.
Nodo* ListaDobleLigada::dividirLista(Nodo* cabeza) {
    if (!cabeza || !cabeza->siguiente)
        return nullptr;

    Nodo* lento = cabeza;
    Nodo* rapido = cabeza->siguiente;

    while (rapido && rapido->siguiente) {
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }

    Nodo* mitad = lento->siguiente;
    lento->siguiente = nullptr;  // Separa las dos mitades.
    if (mitad)
        mitad->anterior = nullptr;

    return mitad;
}

// Fusiona dos listas ordenadas en una sola lista ordenada.
// Si `porNombre` es true, ordena por nombre; si es false, ordena por dinero.
// Complejidad: O(n), donde n es la suma de los elementos en ambas listas.
Nodo* ListaDobleLigada::fusionarListas(Nodo* lista1, Nodo* lista2, bool porNombre) {
    if (!lista1) return lista2;
    if (!lista2) return lista1;

    Nodo* resultado = nullptr;

    if ((porNombre && lista1->cuenta.getNombre() <= lista2->cuenta.getNombre()) ||
        (!porNombre && lista1->cuenta.getDinero() <= lista2->cuenta.getDinero())) {
        resultado = lista1;
        resultado->siguiente = fusionarListas(lista1->siguiente, lista2, porNombre);
        if (resultado->siguiente)
            resultado->siguiente->anterior = resultado;
    } else {
        resultado = lista2;
        resultado->siguiente = fusionarListas(lista1, lista2->siguiente, porNombre);
        if (resultado->siguiente)
            resultado->siguiente->anterior = resultado;
    }

    return resultado;
}

// Aplica el algoritmo de merge sort a la lista.
// Si `porNombre` es true, ordena por nombre; si es false, por dinero.
// Complejidad: O(n log n).
Nodo* ListaDobleLigada::mergeSort(Nodo* cabeza, bool porNombre) {
    if (!cabeza || !cabeza->siguiente)
        return cabeza;

    Nodo* mitad = dividirLista(cabeza);

    Nodo* izquierda = mergeSort(cabeza, porNombre);
    Nodo* derecha = mergeSort(mitad, porNombre);

    return fusionarListas(izquierda, derecha, porNombre);
}

// Ordena la lista por nombre alfabéticamente.
void ListaDobleLigada::ordenarPorNombre() {
    cabeza = mergeSort(cabeza, true);

    // Actualiza la cola al final de la lista.
    Nodo* actual = cabeza;
    while (actual && actual->siguiente) {
        actual = actual->siguiente;
    }
    cola = actual;
}

// Ordena la lista por monto de dinero en orden ascendente.
void ListaDobleLigada::ordenarPorDinero() {
    cabeza = mergeSort(cabeza, false);

    // Actualiza la cola al final de la lista.
    Nodo* actual = cabeza;
    while (actual && actual->siguiente) {
        actual = actual->siguiente;
    }
    cola = actual;
}

// Destructor: libera toda la memoria utilizada por los nodos de la lista.
ListaDobleLigada::~ListaDobleLigada() {
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

#endif // LISTAS_H_
