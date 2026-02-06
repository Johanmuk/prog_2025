#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(const size_t n, const size_t m) : n_(n), m_(m), data_(new int[n*m]){
    std::fill(data_, data_ + n * m, 0);
}
Matrix::~Matrix() {
    delete[] data_;
}

Matrix::Matrix(const Matrix& other) {
    n_ = other.n_;
    m_ = other.m_;
    data_ = new int [n_*m_];
    std::copy(other.data_, other.data_ + (n_ * m_), data_);
}

Matrix& Matrix::operator=(const Matrix& other){
    if (this == &other) {
        return *this;
    }
    delete[] data_;
    n_ = other.n_;
    m_ = other.m_;
    data_ = new int [n_*m_];
    std::copy(other.data_, other.data_ + (n_ * m_), data_);
    return *this;
}

void Matrix::print() const {
    for (size_t i = 0; i < n_; ++i){  //строки
        for (size_t j = 0; j < m_; ++j){  //столбцы
            std::cout << data_[i * m_ + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::set_Element(size_t row, size_t col, int value) {
    data_[row * m_ + col] = value;
} // строка - столбец - что записываем

int Matrix::get_Element(size_t row, size_t col, int value){
    return data_[row * m_ + col];
}