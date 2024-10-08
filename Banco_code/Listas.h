#ifndef LISTAS_H_
#define LISTAS_H_

#include "Cuenta.h"
#include <vector>

class Listas {
private:
    // Función para intercambiar dos elementos
    void swap(std::vector<Cuenta>& v, int i, int j) {
        Cuenta aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }

public:
    // Ordenar por dinero ascendente usando Bubble Sort
    std::vector<Cuenta> bubbleSortPorDineroAsc(const std::vector<Cuenta>& source) {
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

    // Ordenar por dinero descendente usando Bubble Sort
    std::vector<Cuenta> bubbleSortPorDineroDesc(const std::vector<Cuenta>& source) {
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

    // Ordenar por nombre usando Bubble Sort
    std::vector<Cuenta> bubbleSortPorNombre(const std::vector<Cuenta>& source) {
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
};

#endif // LISTAS_H_
