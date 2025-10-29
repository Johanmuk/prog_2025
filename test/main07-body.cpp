#include <iostream>
#include <cmath>
#include "Read.h"
#include "out.h"

int Sumss(int x) {
    int sum = 0;
    while (x>0) {
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int Sipml(int x) {
    if (x <= 1) {
        return 0;
    }
    for (int i=2; i<= sqrt(x); ++i){
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    //ввод
    int dim;
    const int NMax = 100;
    std::cout << "lines/rows:" << std::endl;
    std::cin>> dim;

    int matrix[NMax][NMax];
    Read(matrix, dim);

    /////////////////////////////

    for (int j = 0; j<dim; ++j) {
        int kkts = 0;
        for (int i = 0; i<dim; ++i) {
            if (Sipml(abs(matrix[i][j])) ==0){
                kkts +=1;
            }
        }
        if (kkts == dim ) {
            int smchk = 0;
            for (int i = 0; i < dim; ++i) {
                smchk+= matrix[i][j];
            }
            if (smchk==0) {
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
        } else {
            std::cout << "RESULT" << std::endl;
            for (int i = 0; i<dim; ++i) {
                for (int j = 0; j<dim; ++j) {
                std::cout << matrix[i][j] << "\t";
                }
                std::cout << std::endl;
            }
            
        }
        break;


    }


    //вывод
    std::cout << "RESULT" << std::endl;
    for (int i = 0; i<dim; ++i) {
        for (int j = 0; j<dim; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. Если в матрице есть столбец, 
не содержащий простых чисел, сумма элементов которого равна 0,
 упорядочить элементы строк по неубыванию абсолютных величин.
*/
