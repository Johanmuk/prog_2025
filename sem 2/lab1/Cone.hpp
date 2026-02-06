#pragma once

class Cone {
public:
    Cone() = default;
    ~Cone() = default;
    //Конструктор 
    Cone(double radius, double lenght, double height);

    //Метод
    double Surface_area() const;

    double Volume() const;
    //Сеттер
    void set_r(double r);
    void set_l(double l);
    void set_h(double h);
    //Геттер
    double get_r() const;
    double get_l() const;
    double get_h() const;

private:
    double l_; //Поле
    double r_;
    double h_;
    
};