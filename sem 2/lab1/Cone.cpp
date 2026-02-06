#include "Cone.hpp"
#include <cmath>
#include <iostream>
#include <exception>

Cone::Cone(double radius, double lenght, double height)  {
    set_r(radius);
    set_l(lenght);
    set_h(height);
}

double Cone::Surface_area() const {
    double s;
    const double pi = std::acos(-1.0);
    s = pi * r_*r_ + pi * r_ * l_;
    return s;
}
double Cone::Volume() const {
    const double pi = std::acos(-1.0);
    return (1.0/3.0) * pi * r_ * r_ * h_;
}

void Cone::set_r(double r) {
    if(r < 0) {
        throw std::invalid_argument("Radius have to be positive");
    }
    r_ = r;
}
void Cone::set_l(double l) {
    if(l < 0) {
        throw std::invalid_argument("Lenght have to be positive");
    }
    l_ = l;
}
void Cone::set_h(double h) {
    if(h < 0) {
        throw std::invalid_argument("Height have to be positive");
    }
    h_ = h;
}

double Cone::get_r() const { 
    return r_; 
}
double Cone::get_l() const { 
    return l_; 
}
double Cone::get_h() const { 
    return h_; 
}
