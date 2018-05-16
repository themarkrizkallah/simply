#include <iostream>
#include <vector>
#include <../include/vector.h>
#include <../include/matrix.h>

using namespace std;

// class Matrix final
// {
// 	std::vector<std::vector<float>> mat;
// public:
// 	Matrix(int n, int m, int x); // Creates an nxm matrix, all elements = x
// 	Matrix(float **a);
// 	~Matrix();

// 	Matrix(const Matrix &other);
//     Matrix(Matrix &&other);
//     Matrix &operator=(const Matrix &other);
//     Matrix &operator=(Matrix &&other);
// 	friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

// 	// Matrix operations
// 	Matrix operator+(const Matrix &rhs) const;
//     Matrix operator-(const Matrix &rhs) const;
//     Matrix operator*(const Matrix &rhs) const;
//     Matrix operator-() const;
//     Matrix transpose() const;

// 	int getRows() const; // Returns the number of rows in the matrix, m
// 	int getCols() const; // Returns the number of columns in the matrix, n
// };

