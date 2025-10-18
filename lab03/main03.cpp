#include <iostream>
#include <bitset>
int main() {
    unsigned int x, i;
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "i: ";
    std::cin >> i;
    if (x>0 && x<1e9) {

    std::bitset<32> b2 = x;
    //std::cout << b2.to_string() << std::endl;

    x = x | (1 << i);

    std::cout << x << std::endl;
    system("pause");

    return 0;
    }
}


