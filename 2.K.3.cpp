#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int n = 4;  // Количество вершин
    int m = 5;  // Количество рёбер

    // Упакованный массив матрицы инцидентности (пример данных)
    std::vector<std::vector<int>> incMatrix = {
        {1, 0, 0, 0, 0},
        {-1, 1, 0, 0, 0},
        {0, -1, 1, 0, 0},
        {0, 0, -1, 1, 0}
    };

    // Перебор рёбер
    for (int j = 0; j < m; ++j) {
        std::cout << "Ребро " << j + 1 << " инцидентно вершинам: ";
        for (int i = 0; i < n; ++i) {
            if (incMatrix[i][j] == 1) {
                std::cout << i + 1 << " (начало) ";
            }
            else if (incMatrix[i][j] == -1) {
                std::cout << i + 1 << " (конец) ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
