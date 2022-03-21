#ifndef MyVector_h
#define MyVector_h
#include <initializer_list>
class Vector {
private:
    int n = 0;
    double* corr = nullptr;
public:
    Vector (int num = 0);
    Vector(std::initializer_list<int>a);
    Vector(const Vector& other);
    void resize(int size);
    Vector& operator=(const Vector& v1);
    Vector operator +(const Vector& v1);
    Vector operator-(const Vector& v1);
    Vector& operator+=(const Vector& v1);
    Vector& operator-=(const Vector& v1);
    Vector operator*(const double c);
    Vector& operator*=(const double c);
    double  dot(const Vector& v1);
    double& operator [](int i);
    int size();
    ~Vector();
};
#endif /* MyVector_h */
