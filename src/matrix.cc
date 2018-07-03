#include <iostream>
#include <vector>
#include <../include/vector.h>
#include <../include/matrix.h>

using namespace std;

// Constructor + Big 5
Matrix::Matrix(int m, int n, int x)
{
	mat.assign(m, vector<float>(n, x));
}

Matrix::Matrix(const vector<vector<float>> &a): mat{a}{}

Matrix::~Matrix(){}

Matrix::Matrix(const Matrix &other): mat{other.mat}{}

Matrix::Matrix(Matrix &&other): mat{std::move(other.mat)}{}

Matrix &Matrix::operator=(const Matrix &other)
{
	mat = other.mat;
	return *this;
}

Matrix &Matrix::operator=(Matrix &&other)
{
	std::swap(mat, other.mat);
	return *this;
}

// Matrix operations
Matrix Matrix::operator+(const Matrix &rhs) const
{
	const int m1 = mat.size();
	const int n1 = mat[0].size();

	const int m2 = rhs.mat.size();
	const int n2 = rhs.mat[0].size();

	if(m1 == m2 && n1 == n2)
	{
		vector<vector<float>> sum(m1, vector<float>(n1));

		for(int i = 0; i < m1; ++i) for(int j = 0; j < n1; ++j) sum[i][j] = mat[i][j] + rhs.mat[i][j];

		return Matrix(sum);

	}else cout << "Cannot add 2 matrices in different dimensions." << endl;

	return Matrix(); // Temp
}

Matrix Matrix::operator-(const Matrix &rhs) const
{
	const int m1 = mat.size();
	const int n1 = mat[0].size();

	const int m2 = rhs.mat.size();
	const int n2 = rhs.mat[0].size();

	if(m1 == m2 && n1 == n2)
	{
		vector<vector<float>> diff(m1, vector<float>(n1));

		for(int i = 0; i < m1; ++i) for(int j = 0; j < n1; ++j) diff[i][j] = mat[i][j] - rhs.mat[i][j];

		return Matrix(diff);

	}else cout << "Cannot subtract 2 matrices in different dimensions." << endl;

	return Matrix(); // Temp
}

// Matrix-Matrix multiplication
Matrix Matrix::operator*(const Matrix &rhs) const
{
	const int m1 = mat.size();
	const int n1 = mat[0].size();

	const int m2 = rhs.mat.size();
	const int n2 = rhs.mat[0].size();

	vector<vector<float>> prod(m1, vector<float>(n2));

	if(n1 == m2)
	{
		for(int i = 0; i < m1; ++i)
		{
			for(int j = 0; j < n2; ++j)
			{
				for(int k = 0; k < m2; ++k) prod[i][j] += mat[i][k] * rhs.mat[k][j];
			}
		}
	}else cout << "Cannot multiply matrices" << endl;

	return Matrix(prod);
}

Matrix Matrix::operator*(const float a) const
{
	const int m = mat.size();
	const int n = mat[0].size();

	vector<vector<float>> prod(m, vector<float>(n));

	for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) prod[i][j] = mat[i][j] * a;

	return Matrix(prod);
}

Matrix Matrix::operator-() const
{
	const int m = mat.size();
	const int n = mat[0].size();

	vector<vector<float>> neg(m, vector<float>(n));

	for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) neg[i][j] = -mat[i][j];

	return Matrix(neg);
}

Vector Matrix::operator*(const Vector &rhs) const
{
	const int m = mat.size();
	const int n = mat[0].size();

	vector<float> prod(m);

	if(n == rhs.getDimension())
	{
		for(int i = 0; i < m; ++i)
		{
			float sum = 0;
			for(int j = 0; j < n; ++j) sum += mat[i][j] * rhs.elementAt(j);
			prod[i] = sum;
		}

	}else cout << "Cannot multiply a matrix and a vector in different dimensions" << endl;

	return Vector(prod);
}

// Transposition
void Matrix::transpose()
{
	const int m = mat.size();
	const int n = mat[0].size();

	vector<vector<float>> trans(n, vector<float>(m));

	for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) trans[j][i] = mat[i][j];

	mat = trans;
}

Matrix Matrix::transposeNew() const
{
	const int m = mat.size();
	const int n = mat[0].size();

	vector<vector<float>> trans(n, vector<float>(m));

	for(int i = 0; i < m; ++i) for(int j = 0; j < n; ++j) trans[j][i] = mat[i][j];

	return Matrix(trans);
}

// Utility
int Matrix::getRows() const {
	return mat.size();
}

int Matrix::getCols() const
{
	return mat[0].size();
}

ostream &operator<<(ostream &out, const Matrix &matrix)
{
	const int m = matrix.mat.size();
	const int n = matrix.mat[0].size();

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j) out << matrix.mat[i][j] << ' ';
		if(i != (m - 1)) out << endl;
	}

	return out;
}

Matrix operator*(const float a, const Matrix &mat)
{
	return mat * a;
}