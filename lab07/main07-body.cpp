#include <iostream>
#include <cmath>
#include "Read-.h"

int main() {
    //ввод
    int dim;
    const int NMax = 100;
    std::cout << "lines/rows:" << std::endl;
    std::cin>> dim;

    int matrix[NMax][NMax];
    Read(matrix, dim);

    /////////////////////////////

    full(matrix,dim);

    //вывод
    out(matrix, dim);

    return 0;
}

/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть столбец, 
не содержащий простых чисел, сумма элементов которого равна 0,
 упорядочить элементы строк по неубыванию абсолютных величин.
*/
