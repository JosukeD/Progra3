/*

matrix.h y matrix.cpp, contienen la declaración (.h) y definición (.cpp) de la clase matrix

Desarrollar una matriz que permita realizar las siguientes operaciones:

NOTA: No utilizar vectores para su implementación, solo usar memoria dinámica y punteros.

Construcción, Ingreso e impresión de valores
Usar:
    
    // Constructor por parametros
    utec::matrix m1(4, 5);
    // Ingreso de datos
    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = rand() % 100;
        }
    }
    // Impresion de libreria
    std::cout << m1;

Construcción copia y move
Usar:
    
    random_device rd;
    utec::matrix m1(8, 9);
    utec::matrix m2(4, 5);
    uniform_int_distribution<int> dis(0, 100);
     for (size_t i = 0; i < m1.rows(); ++i) 
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    // Copia
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            m2(i, j) = dis(rd);
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl;
    // Move
    std::swap(m1, m2);
    m2(0, 0) = 100;
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl << m3 <<endl;

Comparar matrices
Usar:

    random_device rd;
    utec::matrix m1(8, 9);
    utec::matrix m2(4, 5);
    uniform_int_distribution<int> dis(0, 100);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            m1(i, j) = dis(rd);
    // Copia
    utec::matrix m3 = m1;
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
    m2(i, j) = dis(rd);
    // Comparando matrices
    cout << boolalpha << (m1 == m2) << endl;
    cout << boolalpha << (m3 == m1) << endl;
    cout << boolalpha << (m2 != m3) << endl;


Operaciones entre matrices
Usar:
        SIZE_TYPE rows = 0, cols = 0;
    cin >> rows >> cols;
    utec::matrix m1(rows, cols);
    for (size_t i = 0; i < m1.rows(); ++i)
        for (size_t j = 0; j < m1.cols(); ++j)
            cin >> m1(i, j);
    cin >> rows >> cols;
    utec::matrix m2(rows, cols);
    for (size_t i = 0; i < m2.rows(); ++i)
        for (size_t j = 0; j < m2.cols(); ++j)
            cin >> m2(i, j);
    cin >> rows >> cols;
    utec::matrix m3(rows, cols);
    for (size_t i = 0; i < m3.rows(); ++i)
        for (size_t j = 0; j < m3.cols(); ++j)
            cin >> m3(i, j);
    // Multiplicación entre matrices
    cout << m2 * m3 << endl;
    // Suma de matrices
    auto m4 = m1 + m2;
    cout << m4 << endl;
    // Autoincremento
    m1 *= 5;
    cout << m1 << endl;
    // Multiplicación escalar
    auto m5 = 4 * m1 * 2 + m4;
    cout << m5 << endl;
*/

// que el cpp contenga las definiciones de los métodos de la clase matrix
// que el .h contenga la declaración de la clase matrix

// Realizemos el .h 

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

namespace utec {
    class matrix {
    public:
        using size_type = std::size_t;

        // Constructores
        matrix(size_type rows, size_type cols);
        matrix(const matrix& other);
        matrix(matrix&& other) noexcept;

        // Destructor
        ~matrix();

        // Operadores de asignación
        matrix& operator=(const matrix& other);
        matrix& operator=(matrix&& other) noexcept;

        // Acceso a elementos
        int& operator()(size_type row, size_type col);
        const int& operator()(size_type row, size_type col) const;

        // Obtener dimensiones
        size_type rows() const;
        size_type cols() const;

        // Operadores de comparación
        bool operator==(const matrix& other) const;
        bool operator!=(const matrix& other) const;

        // Operadores aritméticos
        matrix& operator+=(const matrix& other);
        matrix& operator-=(const matrix& other);
        matrix& operator=(const matrix& other);
        matrix& operator=(int scalar);

        // Funciones amigas
        friend std::ostream& operator<<(std::ostream& os, const matrix& m);
        friend matrix operator+(const matrix& lhs, const matrix& rhs);
        friend matrix operator-(const matrix& lhs, const matrix& rhs);
        friend matrix operator*(const matrix& lhs, const matrix& rhs);
        friend matrix operator*(int scalar, const matrix& rhs);
        friend matrix operator*(const matrix& lhs, int scalar);

    private:
        size_type rows, cols;
        int** data;
    };
}

using SIZE_TYPE = utec::matrix::size_type;

#endif // MATRIX_H

// Ahora el cpp

#include "matrix.h"
#include <random>
#include <algorithm>

using namespace std;

// Ingreso e impresion de valores

// Construcción copia y move

// Comparar matrices

// Operaciones entre matrices

//case 2 
matrix& matrix::operator=(const matrix& other) {
        if (this == &other) return *this;

        for (SIZE_TYPE i = 0; i < rows_; ++i) {
            delete[] data_[i];
        }
        delete[] data_;

        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = new int *[rows_];
        for (SIZE_TYPE i = 0; i < rows_; ++i) {
            data_[i] = new int[cols_];
            std::copy(other.data_[i], other.data_[i] + cols_, data_[i]);
        }
        return *this;
    }

/// case 4
matrix matrix::operator+(const matrix& other) const {
        if (rows_ != other.rows_ || cols_ != other.cols_) {
            throw std::invalid_argument("Invalid matrix dimensions");
        }
        matrix result(rows_, cols_);
        for (SIZE_TYPE i = 0; i < rows_; ++i) {
            for (SIZE_TYPE j = 0; j < cols_; ++j) {
                result.data_[i][j] = data_[i][j] + other.data_[i][j];
            }
        }
        return result;
    }

    matrix matrix::operator*(const matrix& other) const {
        if (cols_ != other.rows_) {
            throw std::invalid_argument("Invalid matrix dimensions");
        }
        matrix result(rows_, other.cols_);
        for (SIZE_TYPE i = 0; i < rows_; ++i) {
            for (SIZE_TYPE j = 0; j < other.cols_; ++j) {
                for (SIZE_TYPE k = 0; k < cols_; ++k) {
                    result.data_[i][j] += data_[i][k] * other.data_[k][j];
                }
            }
        }
        return result;
    }
    matrix& matrix::operator*=(int scalar) {
        for (SIZE_TYPE i = 0; i < rows_; ++i) {
            for (SIZE_TYPE j = 0; j < cols_; ++j) {
                data_[i][j] *= scalar;
            }
        }
        return *this;
    }

    matrix operator*(int scalar, const matrix& m) {
        matrix result(m.rows_, m.cols_);
        for (matrix::SIZE_TYPE i = 0; i < m.rows_; ++i) {
            for (matrix::SIZE_TYPE j = 0; j < m.cols_; ++j) {
                result(i, j) = scalar * m.data_[i][j];
            }
        }
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const matrix& m) {
        for (matrix::SIZE_TYPE i = 0; i < m.rows_; ++i) {
            for (matrix::SIZE_TYPE j = 0; j < m.cols_; ++j) {
                os << m.data_[i][j] << ' ';
            }
            os << '\n';
        }
        return os;
    }
