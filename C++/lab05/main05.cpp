#include <iostream>

int main() {
    /*
    std::cout << "1) sequence:" << std::endl;
    int n,a;
    std::cin>>n;
    int s = 0;
    int mensh = INT_MAX;
    int prprpr = -1;

    for (int i = 0; i<n; ++i) {
        std::cin>>a;
        if (a%10!=1) {
            s += a;
            if ( a<mensh) {
                mensh = a;
                prprpr = i;
            }
        }
        
    }
    if (prprpr!=-1) {
        std::cout << s << std::endl;
        std::cout << mensh << std::endl;
        std::cout << prprpr << std::endl;
    } else {
        std::cout << "error" << std::endl;
    }
    */


    int ch,n ;
    int aw = 0;
    int mxx = INT_MAX;
    std::cin >> n;
    int pr = 0;

    for (int i = 0; i<=9; ++i ) {
        ch = n;
        aw = 0;
        while (ch!=0) {
            if (ch%10 == i) {
                aw+=1;
            }
            ch = ch/10;
        }
        if (mxx > aw && aw!=0) {
            mxx = aw;
            pr = i;
        }

    }
    if (mxx>0) {
        std::cout << pr << std::endl;
    }
    return 0;
}

/*
1. Дана последовательность натуральных чисел {Aj}. Найти сумму 
чисел, не заканчивающихся цифрой 1, наименьшее из таких чисел и 
номер этого числа в последовательности. 
2. Дано натуральное число N (N<10^9). Найти наименее часто 
встречающуюся цифру числа N. Если таких чисел несколько, 
выведите любое.
*/

