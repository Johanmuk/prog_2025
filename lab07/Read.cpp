#include <iostream>
#include "Read-.h"

void Read(int matrix[100][100], int dim) {
    std::cout << "matrix" << std::endl;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void out(int matrix[100][100], int dim) {
    //вывод
    std::cout << "RESULT" << std::endl;
    for (int i = 0; i<dim; ++i) {
        for (int j = 0; j<dim; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

bool Sipml(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i=2; i<= sqrt(x); ++i){
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int Sumss(int x) {
    int sum = 0;
    while (x>0) {
        sum += x%10;
        x /= 10;
    }
    return sum;
}

bool sumCol(int dim, int matrix[100][100], int j){
    int smchk = 0;
    for (int i = 0; i < dim; ++i) {
        smchk+= matrix[i][j];
    }
    return smchk==0;
}

bool allNotPrime(int dim, int matrix[100][100], int j){
    int kkts = 0;
    for (int i = 0; i<dim; ++i) {
        if (!Sipml(abs(matrix[i][j]))){
            kkts +=1;
        }
    }
    return kkts==dim;
}

void switchh(int dim, int matrix[100][100]) {
                for (int j = 0; j < dim; ++j) {
                        for (int i = 0; i<dim; ++i) {
                            for (int j = 0; j<dim-1; ++j) {
                                if (abs(matrix[i][j]) > abs(matrix[i][j+1])) {
                                    std::swap(matrix[i][j], matrix[i][j+1]);
                                }
                            }
                        }  
                }
}

void full(int matrix[100][100], int dim) {
    for (int j = 0; j<dim; ++j) {
        if (allNotPrime(dim, matrix, j) && sumCol(dim, matrix, j)) {
            switchh(dim, matrix);
            break;
        }
    }
}

/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть столбец, 
не содержащий простых чисел, сумма элементов которого равна 0,
 упорядочить элементы строк по неубыванию абсолютных величин.
*/
