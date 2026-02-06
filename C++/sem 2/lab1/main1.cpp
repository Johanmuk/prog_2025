#include <iostream>
#include <cmath>
#include "Cone.hpp"

int main()
{
    double r, l, h;
    std::cout << "Radius/lenght/height" << std::endl;
    std::cin >> r >> l >> h;
    
    try {
        const Cone cone(r, l, h);
        //cone.set_r(r);
        //cone.set_h(h);
        //cone.set_l(l);
        std::cout << cone.Surface_area() << std::endl;
        std::cout << cone.Volume() << std::endl;

        //std::cout << cone.get_h() << std::endl;
    } catch(const std::invalid_argument& ex) {
        std::cerr << ex.what() << std::endl;
    }

}
