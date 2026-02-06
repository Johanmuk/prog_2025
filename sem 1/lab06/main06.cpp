#include <iostream>
#include <cmath>
#define N 20000
#define Z 100

int Multpl(int x) {
    int mult = 1;
    while (x>0) {
        mult *= x%10;
        x /= 10;
    }
    return mult;
}

int Sipml(int x) {
    if (x < 2) {
        return 0;
    }
    for (int i=2; i<= sqrt(x); ++i){
        if (x% i == 0) {
            return 0;
        }
    }
    return 1;
}


int main() {
    /*
    std::cout << "1)" << std::endl;
    int n,a;
    std::cin>>n;
    int x[n];
    for (int i = 0; i<n; ++i) {
        std::cin>>a;
        x[i] = a;
        
    }
    bool is_any_12 = true;

    for (int i = 0; i<n; ++i) {
        int tmp = x[i];
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
                if (x[j] > x[o]) {
                    std::swap(x[j], x[o]);
                }
            }
        }
    }

    std::cout << "Result: " << std::endl;
    for (int i = 0; i<n; ++i) { 
        std::cout << x[i] << std::endl;
    }
    */ 
    /*

    //////////////////////////////////////////////////

    std::cout << "2): " << std::endl;
    std::cout << "Sequence: " << std::endl;
    int n;
    std::cin>>n;
    int x[N], prod[N], sum[N];
    for (int i = 0; i<n; ++i) {
        std::cin>>x[i];
        int tmp = x[i]; 
        int multipl = 1;
        int summ = 0;
            while (tmp>0) {
            multipl *= tmp % 10;
            summ += tmp % 10;
            tmp /= 10;
            }
        prod[i] = multipl;
        sum[i] = summ;
    }
    for (int j =0; j<n; ++j) {
        for (int i = 0; i<n-j-1; ++i) {
        if (prod[i] > prod[i+1]) {
        std::swap(x[i], x[i+1]);
        std::swap(prod[i], prod[i+1]);
        std::swap(sum[i], sum[i+1]);
        } else if (prod[i] == prod[i+1]) {
            if (sum[i] > sum[i+1]) {
                std::swap(x[i], x[i+1]);
                std::swap(prod[i], prod[i+1]);
                std::swap(sum[i], sum[i+1]);
            } else if (sum[i] == sum[i+1]) {
                if (x[i] > x[i+1]) {
                    std::swap(x[i], x[i+1]);
                    std::swap(prod[i], prod[i+1]);
                    std::swap(sum[i], sum[i+1]);
                }
            }
        }
        }
    }
    std::cout << "Result: " << std::endl;
    for (int i = 0; i<n; ++i) { 
        std::cout << x[i] << std::endl;
    }
    
    */
   /*
    std::cout << "3): " << std::endl;
    int lines, rows;
    const int NMax = 100;
    std::cout << "lines/rows " << std::endl;
    std::cin>> lines;
    std::cin>> rows;

    int matrix[NMax][NMax];
    std::cout << "matrix" << std::endl;
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    int RowNumb = 0;
    int MinCount3 = INT_MAX;
    for (int i = 0; i<rows; ++i) {
        int count3 = 0;
        for (int j=0; j<lines; ++j) {
            // Проверка на 3ку в конце числа
            int tmp = abs(matrix[j][i]);
            while (tmp>0) {
                if (tmp%10==3) {
                    count3 += 1;
                }
                tmp /= 10;
            }
            if (count3 <=3 MinCount3) {
                MinCount3 = count3;
                RowNumb = i;
            }
        }
    }
    //нашли столбец с меньшим колвом 3-ек
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (j!=RowNumb) {
                matrix[i][j] = -17;
            }
        }
    }
    std::cout << "result" << std::endl;
    for (int i = 0; i<lines; ++i) {
        for (int j = 0; j<rows; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    */

    std::cout << "4): " << std::endl;
    int n;
    int x[N];
    std::cin >> n;

    for (int i = 0; i<n; ++i) {
        std::cin>> x[i];
    }
    // функция - Multpl
    // 1 - удалить кратные 70
    int i = 0;
    int j = 0;

    while (i<n) {
        if (Multpl(x[i])%70 != 0) {
            x[j] = x[i];
            ++i;
            ++j;
        } else {
            ++i;
        }
    }
    n = j;
    for (int i = 0; i<n; ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << "\n";

    int cntsipml = 0;
    for (int f =0; f < n; ++f) {
        if (Sipml(x[f]) == 1) {
            cntsipml += 1;
        }
    }
    // продублировать простые
    int k = n + cntsipml - 1;
    int tmp = k;
    int f = n - 1;
    while (f>=0) {
        if (Sipml(x[f]) == 1) {
            x[k] = x[f];
            x[k-1] = x[f];
            k -=2;
        } else {
            x[k] = x[f];
            --k;
            
        }
        --f;
    }


    std::cout << "RESULT: " << std::endl;
    for (int i = 0; i<tmp + 1; ++i) {
        std::cout << x[i] << '\t';
    }

    return 0;

}

/*
4. 
Сначала введите последовательность. Затем удалите и продублируйте элементы. Затем 
выведите полученную 
последовательность (каждый элемент по одному разу). 
Используйте в программе только один массив. 
Дана последовательность натуральных чисел {Aj}j=1...n 
(n<=10000). Удалить из последовательности числа, произведение 
цифр которых кратно 70, а среди оставшихся продублировать 
простые числа.
*/

