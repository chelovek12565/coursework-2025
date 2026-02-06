#ifndef NEGATIVE_CYCLE_H
#define NEGATIVE_CYCLE_H

#include "graph.h"
#include <vector>

// Класс для поиска и восстановления цикла отрицательной стоимости
class NegativeCycleFinder {
private:
    const Graph& graph;      
    std::vector<int> dist;   
    std::vector<int> parent; 
    int cycleStart;          

public:
    NegativeCycleFinder(const Graph& g);

    // Поиск отрицательного цикла (алгоритм Беллмана–Форда)
    bool findNegativeCycle();

    int relaxEdges();

    std::vector<int> restoreCycle() const;
};

#endif
