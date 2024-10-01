#include "Listas.h"

// Intercambia dos elementos en un vector
void Listas::swap(std::vector<Cuenta>& v, int i, int j) {
    Cuenta aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Ordena por dinero ascendente usando Bubble Sort
std::vector<Cuenta> Listas::bubbleSortPorDineroAsc(const std::vector<Cuenta>& source) {
    std::vector<Cuenta> v(source);
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
    return v;
}

// Ordena por dinero descendente usando Bubble Sort
std::vector<Cuenta> Listas::bubbleSortPorDineroDesc(const std::vector<Cuenta>& source) {
    std::vector<Cuenta> v(source);
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
    return v;
}

// Ordena por nombre alfabético usando Bubble Sort
std::vector<Cuenta> Listas::bubbleSortPorNombre(const std::vector<Cuenta>& source) {
    std::vector<Cuenta> v(source);
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j].nombreMayorQue(v[j + 1])) {
                swap(v, j, j + 1);
            }
        }
    }
    return v;
}
