#include "Matrix.h"
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
Matrix Matrix::operator*(const Matrix& v1) {
	Matrix res(n, v1.m);
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < m; ++k) {
			for (int j = 0; j < v1.m; ++j) {
				res[i][j] += data[i][k] * v1.data[k][j];
			}
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
	if (n != m) return -1e9 + 7;
	double res = 0;
	for (int i = 0; i < n; ++i) {
		res += data[i][i];
	}
	return res;
}
int  Matrix::get_rank() {
	double sum;
	int cnt=0;
	if (n != m) return -1e9 + 7;
	for (int i = 0; i < n; ++i) {
		sum = 0;
		for (int j = 0; j < m; ++j) {
			sum += data[i][j];
		}
		if (sum != 0) cnt++;
	}
	return cnt;
}
Matrix::~Matrix() {
	delete[]data;
}



