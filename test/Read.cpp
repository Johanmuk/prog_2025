#include <iostream>
#include "Read.h"

void Read(int matrix[100][100], int dim) {
    std::cout << "matrix" << std::endl;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}



/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть столбец, 
не содержащий простых чисел, сумма элементов которого равна 0,
 упорядочить элементы строк по неубыванию абсолютных величин.
*/
