#include <iostream>
#include <cmath>

int main() {
    /*
    std::cout << "1)" << std::endl;
    int n;
    std::cin>>n;
    int *din_arr = new int [n];
    for (int i = 0; i<n; ++i) {
        std::cin>> din_arr[i];
        
    }
    bool is_any_12 = true;

    for (int i = 0; i<n; ++i) {
        int tmp = din_arr[i];
        int sum = 0;
        while (tmp>0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum==12) {
            is_any_12 = false;
            break;
        }
    }

    if ( is_any_12) {
        for (int j = 0; j<n; ++j) {
            for (int o = j + 1; o<n; ++o) {
                if (din_arr[j] > din_arr[o]) {
                    std::swap(din_arr[j], din_arr[o]);
                }
            }
        }
    }

    std::cout << "Result: " << std::endl;
    for (int i = 0; i<n; ++i) { 
        std::cout << *(din_arr+i) << std::endl;
    }
    delete [] din_arr;
    */
    
    std::cout << "3): " << std::endl;
    int* lines = new int;
    int* rows = new int;

    std::cout << "lines/rows " << std::endl;
    std::cin>> *lines >> *rows;


    int** matrix = new int*[*lines];
    for (int i = 0; i < *lines; ++i) {
        matrix[i] = new int[*rows];
    }

    std::cout << "matrix" << std::endl;
    for (int i = 0; i < *lines; ++i) {
        for (int j = 0; j < *rows; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    int* RowNumb = new int (0);
    int* MinCount3 = new int (INT_MAX);
    for (int i = 0; i< *rows; ++i) {
        int* count3 =new int (0);
        for (int j=0; j< *lines; ++j) {
            // Проверка на 3ку в конце числа
            int tmp = abs(matrix[j][i]);
            while (tmp>0) {
                if (tmp%10==3) {
                    *count3 += 1;
                }
                tmp /= 10;
            }
        }
        if (*count3 <= *MinCount3 ) {
                *MinCount3 = *count3;
                *RowNumb = i;
        }
        delete count3;
    }
    //нашли столбец с меньшим колвом 3-ек
    for (int i = 0; i < *lines; ++i) {
        for (int j = 0; j < *rows; ++j) {
            if (j!= *RowNumb) {
                matrix[i][j] = -17;
            }
        }
    }
    std::cout << "result" << std::endl;
    for (int i = 0; i< *lines; ++i) {
        for (int j = 0; j< *rows; ++j) {
            std::cout << *(*(matrix + i) + j) << "\t";
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < *lines; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete lines;
    delete rows;
    delete RowNumb;
    delete MinCount3;
    
    

    return 0;
}

// Переделайте задания 1 и 3 из задачи №6 вашего варианта таким 
//образом, чтобы в них использовались только динамические массивы.
//Не допускайте утечек памяти (memory leaks).