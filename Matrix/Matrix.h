
#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "MyVector.h"
class Matrix {
private:
    int n = 0;
    int m = 0;
    Vector* data= NULL;
public:
    Matrix(int n = 0, int m = 0);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& v1);
    Matrix operator +(const Matrix& v1);
    Matrix operator-(const Matrix& v1);
    Matrix operator-();
    Matrix& operator+=(const Matrix& v1);
    Matrix& operator-=(const Matrix& v1);
    Matrix operator*(const double c);
    Matrix& operator*=(const double c);
    Vector& operator [](int i);
    Matrix operator *(Matrix v1);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& v1);
    friend std::istream& operator>>(std::istream& in, const Matrix& v1);
    Matrix T();
    void gauss();
    void swap_row(int i,int j);
    bool  is_triangle();
    long long determ();
    double get_track();
    int get_rank();
    ~Matrix();
};
#endif /* Matrix_hpp */
