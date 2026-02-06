#include <iostream>
#include <cmath>


int main() {
    double x1, y1, r1, x2, y2, r2;
    std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    const double PI = acos(-1.0);

    double S1 = PI * r1 * r1;
    double S2 = PI * r2 * r2;

    double dx = x1 - x2;
    double dy = y1 - y2;
    double d = sqrt(dx * dx + dy * dy);

    double S_inter = 0.0;

    //Не пересекаются
    if (d >= r1 + r2) {
        S_inter = 0;
    }
    // Один внутри другого
    else if (d <= fabs(r1 - r2)) {
        // пересечение = площадь меньшего круга
        S_inter = PI * std::min(r1, r2) * std::min(r1, r2);
    }
    // Частичное пересечение
    else {
        double alpha = acos((d*d + r1*r1 - r2*r2) / (2*d*r1));
        double beta  = acos((d*d + r2*r2 - r1*r1) / (2*d*r2));
        double part = 0.5 * sqrt((-d+r1+r2)*(d+r1-r2)*(d-r1+r2)*(d+r1+r2));
        S_inter = r1*r1*alpha + r2*r2*beta - part;
    }

    double total = S1 + S2 - S_inter;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    std::cout << total;

    return 0;
}
