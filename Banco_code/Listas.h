#ifndef LISTAS_H_
#define LISTAS_H_

#include "Cuenta.h"
#include <vector>
#include <string>

class Listas {
private:
    void swap(std::vector<Cuenta>&, int, int);
public:
    std::vector<Cuenta> bubbleSortPorDineroAsc(const std::vector<Cuenta>&);
    std::vector<Cuenta> bubbleSortPorDineroDesc(const std::vector<Cuenta>&);
    std::vector<Cuenta> bubbleSortPorNombre(const std::vector<Cuenta>&);
};

#endif // LISTAS_H_
