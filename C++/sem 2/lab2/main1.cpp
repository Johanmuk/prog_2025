#include <iostream>
#include "Matrix.hpp"

int main()
{
    Matrix M(4, 3);
    M.set_Element(0, 2, 88);
    std::cout << M.get_Element(0, 2, 88) << std::endl;
    M.print();

    M = M;

    Matrix B(4, 3);
    std::cout << B.get_Element(1, 0, 6) << std::endl;
    B = M;
    B.set_Element(1, 0, 6);
    std::cout << B.get_Element(1, 0, 6) << std::endl;
    B.print();
    

}

//1 2 3 4 5 6 7 8 9


//1 2 3 4 
//4 5 6 7
//7 8 9 10

//[2][2] -> 6
// i  j

//2*4 + 2
//i*col+j

//i*m+j


//Создайте класс, описывающий матрицу размерами NxM. 
//Не забывайте про принципы абстракции и инкапсуляции.
//В классе реализуйте конструктор копирования, 
//оператор присваивания копированием и деструктор. 
//Продемонстрируйте использование вашего класса.
