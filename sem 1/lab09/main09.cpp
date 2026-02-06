#include <iostream>

int main() {
    long long num;
    std::cin >> num;
    
    unsigned char* a = reinterpret_cast<unsigned char*>(&num);
    for (int i = 0; i < sizeof(num); ++i) {
        std::cout << static_cast<int>(*(a + i)) << std::endl;
    }
    
    return 0;
}

// Дано целое число типа long long, 
//выведите на экран содержимое каждого из его байтов, 
//используя знания по указателям. Дайте обоснование 
//полученному результату.