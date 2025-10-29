#include <iostream>
#include "out.h"

int out(int matrix[100][100], int dim) {
    //вывод
    std::cout << "RESULT" << std::endl;
    for (int i = 0; i<dim; ++i) {
        for (int j = 0; j<dim; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return ;
}