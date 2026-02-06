#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

// Структура, описывающая ориентированное ребро графа
struct Edge {
    int from;    // начальная вершина
    int to;      // конечная вершина
    int weight;  // вес ребра
};

class Graph {
private:
    int n;                       
    std::vector<Edge> edges;

public:
    Graph(int vertices);

    void addEdge(int u, int v, int w);

    int getVertexCount() const;

    const std::vector<Edge>& getEdges() const;

    void exportToDot(
        const std::string& filename,
        const std::vector<int>& cycle
    ) const;
};

#endif
