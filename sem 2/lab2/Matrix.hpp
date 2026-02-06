#pragma once

class Matrix {

public:
    Matrix(const size_t n, const size_t m);

    ~Matrix();

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    void print() const;
    void set_Element(size_t row, size_t col, int value);
    int get_Element(size_t row, size_t col, int value);
    

private:
    size_t n_; // строки
    size_t m_; //стлбцы
    int* data_;

};