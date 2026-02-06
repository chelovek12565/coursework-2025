#include <iostream>
#include <fstream>
#include "graph.h"
#include "negative_cycle.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Введите имя входного файла\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    int n, m;
    in >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        in >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    NegativeCycleFinder finder(graph);

    if (finder.findNegativeCycle()) {
        auto cycle = finder.restoreCycle();

        std::ofstream out("cycle.txt");
        out << "Найден цикл отрицательной стоимости:\n";
        for (int v : cycle) {
            out << v << " ";
        }
        out << "\n";

        graph.exportToDot("cycle.dot", cycle);
        std::cout << "Отрицательный цикл найден.\n";
    } else {
        std::ofstream out("cycle.txt");
        out << "Цикл отрицательной стоимости не найден\n";
        std::cout << "Отрицательный цикл не найден.\n";
        graph.exportToDot("cycle.dot", std::vector<int>(0, 0));
    }

    return 0;
}
