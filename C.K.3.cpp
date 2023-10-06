#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Функция для проверки, является ли данное множество вершин кликой
bool isClique(const vector<vector<int>>& graph, const set<int>& clique) {
    for (int u : clique) {
        for (int v : clique) {
            if (u != v && find(graph[u].begin(), graph[u].end(), v) == graph[u].end()) {
                return false;
            }
        }
    }
    return true;
}

// Рекурсивная функция для поиска наибольшей клики
void findMaxClique(const vector<vector<int>>& graph, set<int>& currentClique, set<int>& maxClique, int vertex) {
    // Попробовать добавить текущую вершину в клику
    currentClique.insert(vertex);

    // Проверить, является ли текущая клика более большой
    if (currentClique.size() > maxClique.size() && isClique(graph, currentClique)) {
        maxClique = currentClique;
    }

    // Рекурсивно исследовать соседей текущей вершины
    for (int neighbor : graph[vertex]) {
        if (neighbor > vertex) {  // Проверка на дублирование рёбер
            findMaxClique(graph, currentClique, maxClique, neighbor);
        }
    }

    // Удалить текущую вершину из клики и вернуться назад
    currentClique.erase(vertex);
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int n = 5;  // Количество вершин
    vector<vector<int>> graph(n);

    // Добавление рёбер в граф (пример данных)
    graph[0] = { 1, 2 };
    graph[1] = { 0, 2, 3 };
    graph[2] = { 0, 1, 3 };
    graph[3] = { 1, 2, 4 };
    graph[4] = { 3 };

    set<int> currentClique;
    set<int> maxClique;

    // Начнем с каждой вершины в качестве начальной вершины для клики
    for (int i = 0; i < n; ++i) {
        findMaxClique(graph, currentClique, maxClique, i);
    }

    cout << "Наибольшая клика: ";
    for (int vertex : maxClique) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
