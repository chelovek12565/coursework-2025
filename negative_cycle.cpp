#include "negative_cycle.h"
#include <algorithm>

// Инициализация алгоритма
NegativeCycleFinder::NegativeCycleFinder(const Graph& g)
    : graph(g),
      dist(g.getVertexCount(), 0),
      parent(g.getVertexCount(), -1),
      cycleStart(-1) {}

int NegativeCycleFinder::relaxEdges() {
    int x = -1;
    const auto& edges = graph.getEdges();

    for (const auto& e : edges) {
        if (dist[e.from] + e.weight < dist[e.to]) {
            dist[e.to] = dist[e.from] + e.weight;
            parent[e.to] = e.from;
            x = e.to; // запоминаем вершину улучшения
        }
    }

    return x;
}


// Поиск отрицательного цикла
bool NegativeCycleFinder::findNegativeCycle() {
    int n = graph.getVertexCount();
    int x = -1;

    for (int i = 0; i < n; ++i) {
        x = relaxEdges();
    }

    if (x == -1) {
        return false;
    }

    cycleStart = x;
    return true;
}


// Восстановление цикла отрицательной стоимости
std::vector<int> NegativeCycleFinder::restoreCycle() const {
    int n = graph.getVertexCount();
    int v = cycleStart;

    // Вход внутрь цикл
    for (int i = 0; i < n; ++i) {
        v = parent[v];
    }

    std::vector<int> cycle;
    int cur = v;

    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != v);

    cycle.push_back(v);
    std::reverse(cycle.begin(), cycle.end());

    return cycle;
}
