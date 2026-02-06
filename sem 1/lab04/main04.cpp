#include <iostream>

int main() {
    int a, b, c;
    std::cout << "1) ";
    std::cin >> a >> b >> c;
    if ((a+b)%c==0 && c%b==0) {
        std::cout << (a+b)/c - c/b << std::endl;
    } else if ((a+b)%c==0 && c%b!=0) {
        std::cout << (a+b)/c + c*b << std::endl;
    } else {
        std::cout << a - b + c << std::endl;
    }

    int n;
    std::cout << "2) ";
    std::cin >> n ;

    switch(n) {
        case 0: std::cout << " OD disk "; break;
        case 1: std::cout << "poshemuchka"; break;
        case 2: std::cout << "Ride The Lighting Vinyl Disk"; break;
        case 3: std::cout << "Ultra Paradise Monster"; break;
        case 4: std::cout << "Kizyaka"; break;
        default: std::cout << "error" << std::endl;
    }

    
    int x;
    std::cout << "3) ";
    std::cin >> x;
    if (x == -1) {
        std::cout << "Negative number" << std::endl;
    } else if (x == 1) {
        std::cout << "Positive number" << std::endl;
    } else {
        std::cout << "Unknown value" << std::endl;
    }

    return 0;
}

