#include "MyVector.h"
Vector::Vector (int num){
    n = num;
    corr = new double[n];
    for (int i = 0; i < n; ++i) corr[i] = 0;
}
Vector::Vector(std::initializer_list<int>a) {
    n = int(a.size());
    corr = new double[n];
    for (int i = 0; i < n; ++i) {
        corr[i] = *(a.begin() + i);
    }
}
Vector::Vector(const Vector& other){
    n = other.n;
    corr = new double[n];
    for (int i = 0; i < n; i++){
        corr[i] = other.corr[i];
    }
}
void Vector::resize(int size) {
    double* n_s=new double[size];
    for (int i=0;i<this->n;++i){
        n_s[i]=this->corr[i];
    }
    for (int i=this->n+1;i<size;++i){
        n_s[i]=0;
    }
    delete [] this->corr;
    this->corr=n_s;
    
}
Vector& Vector::operator=(const Vector& v1) {  // a = a
    if (this == &v1) return *this;
    this->n = v1.n;
    delete[]this->corr;
    corr = new double[v1.n];
    for (int i = 0; i < n; ++i) {
        this->corr[i] = v1.corr[i];
    }
    return *this;
}
Vector Vector::operator +(const Vector& v1) {
    Vector res(v1.n);
    for (int i = 0; i <= n; ++i) {
        res.corr[i] = this->corr[i] + v1.corr[i];
    }
    return res;
}
Vector Vector::operator-(const Vector& v1) {
    Vector res(v1.n);
    for (int i = 0; i <= n; ++i) {
        res.corr[i] = this->corr[i] - v1.corr[i];
    }
    return res;
}
Vector& Vector::operator+=(const Vector& v1) {
    for (int i = 0; i <= n; ++i) {
        this->corr[i] += v1.corr[i];
    }
    return *this;
}
Vector& Vector::operator-=(const Vector& v1) {
    for (int i = 0; i <= n; ++i) {
        this->corr[i] -= v1.corr[i];
    }
    return *this;
}
Vector Vector::operator*(const double c) {
    Vector res(n);
    for (int i = 0; i <= n; ++i) {
        res.corr[i] = this->corr[i] * c;
    }
    return res;
}
Vector& Vector::operator*=(const double c) {
    for (int i = 0; i <= n; ++i) {
        this->corr[i]*=c;
    }
    return *this;
}
double  Vector::dot(const Vector& v1) {
    double res = 0;
    for (int i = 0; i < n; ++i) {
        res += this->corr[i] * v1.corr[i];
    }
    return res;
}
double& Vector::operator [](int i) {
    return this->corr[i];
}
std::ostram& operator <<(ostream& out,const Vector& v1){
    for (int i=0;i<v1.n;++i){
        cout<<v1.corr[i]<<" ";
    }
    return out;
}    
int Vector::size() {
    return this->n;
}
Vector::~Vector() {
    delete[] corr;
}
