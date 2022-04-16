#include "Matrix.hpp"
Matrix::Matrix(int n_, int m_) {
    n = n_;
    m = m_;
    data = new Vector[n];
    for (int i = 0; i < n; ++i) data[i] = Vector(m);
}
Matrix::Matrix(const Matrix& other) {
    m = other.m;
    n = other.n;
    delete[] data;
    data = new Vector[n];
    for (int i = 0; i < n; ++i) {
        data[i] = other.data[i];
    }
}


Matrix& Matrix::operator=(const Matrix& v1) {
    if (this == &v1) return *this;
    this->n = v1.n;
    this->m = v1.m;
    delete[]this->data;
    data = new Vector[v1.n];
    for (int i = 0; i < n; ++i) {
        this->data[i] = v1.data[i];
    }
    return *this;

}
Matrix Matrix::operator +(const Matrix& v1) {
    Matrix res(v1.n,v1.m);
    for (int i = 0; i < n; ++i) {
        res.data[i] = this->data[i] + v1.data[i];
    }
    return res;
}
Matrix Matrix::operator-(const Matrix& v1) {
    Matrix res(v1.n, v1.m);
    for (int i = 0; i < n; ++i) {
        res.data[i] = this->data[i] - v1.data[i];
    }
    return res;

}
Matrix& Matrix::operator+=(const Matrix& v1) {
    for (int i = 0; i < n; ++i) {
        this->data[i] += v1.data[i];
    }
    return *this;
}
Matrix& Matrix::operator-=(const Matrix& v1) {
    for (int i = 0; i < n; ++i) {
        this->data[i] -= v1.data[i];
    }
    return *this;

}
Matrix Matrix::operator*(const double c) {
    Matrix res(n,m);
    for (int i = 0; i < n; ++i) {
        res.data[i] = this->data[i] * c;
    }
    return res;
}
Matrix& Matrix::operator*=(const double c) {
    for (int i = 0; i < n; ++i) {
        this->data[i] *= c;
    }
    return *this;
}
Vector& Matrix::operator[](int i) {
    return data[i];
}
Matrix Matrix::operator*(Matrix v1) {
    v1=v1.T();
    Matrix res(n,v1.n);
    for (int i=0;i<n;++i){
        for (int j=0;j<v1.n;++j){
            res[i][j]=data[i].dot(v1.data[j]);
        }
    }
    return res;
}
std::ostream& operator <<(std::ostream& out, const Matrix& v1) {
    for (int i = 0; i < v1.n; ++i) {
        std::cout << v1.data[i] << "\n";
    }
    return out;
}
std::istream& operator >>(std::istream& in, const Matrix& v1) {
    for (int i = 0; i < v1.n; ++i) {
        std::cin >> v1.data[i];
    }
    return in;
}
Matrix Matrix::operator-() {
    Matrix tmp(*this);
    tmp *= -1;
    return tmp;
}
double Matrix::get_track() {
    if (get_rank() != m) return -1e9 + 7;
   // int rank=get_rank();
    double res = 0;
    for (int i = 0; i < get_rank(); ++i) {
        res += data[i][i];
    }
    return res;
}
int Matrix::get_rank() {
    Matrix tmp(*this);
    if (!tmp.is_triangle()){
        tmp.gauss();
    }
    //std::cout<<tmp;
    double sum;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += tmp.data[i][j];
        }
        if (sum != 0) cnt++;
    }
    return cnt;
}
long long Matrix::determ(){
    Matrix tmp(*this);
    if (!tmp.is_triangle()){
        tmp.gauss();
    }
    int rank=tmp.get_rank();
    if (rank!=m){
        return 0;
    }
    long long res=1;
    for(int i=0;i<rank;++i){
        res*=tmp.data[i][i];
    }
    return res;
}
Matrix Matrix::T(){
    Matrix tmp(m,n);
    for(int i=0;i<m;++i){
        for (int j=0;j<n;++j){
            tmp[i][j]=data[j][i];
        }
    }
    return tmp;
}
void Matrix::gauss(){
    for (int i=0;i<m;++i){
        int id_min=i;
        int mmin=data[id_min][i];
        for (int j=i+1;j<n;++j){
            if (std::fabs(data[j][i])<mmin){
                mmin=data[j][i];
                id_min=j;
            }
        }
        //std::cout<<data[i][id_min]<<" ";
        if(std::fabs(data[i][id_min])<1e-10){
            data[i][id_min]=0;
            swap_row(i, n-1);
        }
        if (id_min!=i){
            swap_row(i, id_min);
        }
        for (int j=i+1;j<n;++j){
            double f=data[j][i]/data[i][i];
            for (int k=i+1;k<m;++k){
                data[j][k]-=data[i][k]*f;
            }
            data[j][i]=0;
        }
    }
    for(int i=0;i<n;++i){
        if (data[i][i]<0) data[i][i]*=-1;
    }
}
bool Matrix::is_triangle(){
    for (int j=0;j<m;++j){
        for (int i=j+1;i<n;++i){
            if (data[i][j]) return false;
        }
    }
    return true;
}
void Matrix::swap_row(int i,int j){
    for (int p=0;p<m;++p) std::swap(data[i][p], data[j][p]);
}
Matrix::~Matrix() {
    delete[]data;
}


