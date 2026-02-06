#include "graph.h"
#include <fstream>

Graph::Graph(int vertices) : n(vertices) {}

void Graph::addEdge(int u, int v, int w) {
    edges.push_back({u, v, w});
}

int Graph::getVertexCount() const {
    return n;
}

const std::vector<Edge>& Graph::getEdges() const {
    return edges;
}

void Graph::exportToDot(
    const std::string& filename,
    const std::vector<int>& cycle
) const {
    std::ofstream out(filename);
    out << "digraph G {\n";

    for (const auto& e : edges) {
        bool inCycle = false;

        // Проверка, входит ли ребро в цикл
        for (size_t i = 0; i + 1 < cycle.size(); ++i) {
            if (e.from == cycle[i] && e.to == cycle[i + 1]) {
                inCycle = true;
                break;
            }
        }

        out << "    " << e.from << " -> " << e.to
            << " [label=\"" << e.weight << "\"";

        if (inCycle) {
            out << ", color=red";
        }

        out << "];\n";
    }

    out << "}\n";
}

