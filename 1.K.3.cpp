#include <iostream>
#include <vector>
#include <unordered_map>
#include <locale>

using namespace std;

// Функция для добавления ребра в граф
void addEdge(unordered_map<int, vector<int>>& graph, int u, int v) {
    // Добавляем вершину v в список соседей вершины u
    graph[u].push_back(v);
    // Добавляем вершину u в список соседей вершины v (так как граф неориентированный)
    graph[v].push_back(u);
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Создаем пустой граф в виде словаря
    unordered_map<int, vector<int>> graph;

    // Добавляем ребра в граф
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Выводим список соседей для каждой вершины
    for (const auto& pair : graph) {
        int vertex = pair.first;
        const vector<int>& neighbors = pair.second;

        cout << "Соседи вершины " << vertex << ": ";
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
