#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <vector>

class Vector;

class Matrix final
{
	std::vector<std::vector<float>> mat;
public:
	// Constructor + Big 5
	Matrix(int m=2, int n=2, int x=0); // Creates an nxm matrix, all elements = x
	Matrix(const std::vector<std::vector<float>> &a);
	~Matrix();
	Matrix(const Matrix &other);
    Matrix(Matrix &&other);
    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other);

	// Matrix operations
	Matrix operator+(const Matrix &rhs) const; // Matrix addition
    Matrix operator-(const Matrix &rhs) const; // Matrix subtraction
    Matrix operator*(const Matrix &rhs) const; // Matrix-Matrix multiplication
    Matrix operator*(const float a) const;  // Scalar multiplication
    Matrix operator-() const; // Matrix negation

    Vector operator*(const Vector &rhs) const; // Matrix-Vector multiplication

    // Transposition
    void transpose(); // Transposes the current matrix
    Matrix transposeNew() const; // Returns a copy of the current matrix transposed

    // Utility
	int getRows() const; // Returns the number of rows in the matrix, m
	int getCols() const; // Returns the number of columns in the matrix, n
	friend std::ostream &operator<<(std::ostream &out, const Matrix &m);
};

Matrix operator*(const float a, const Matrix &mat); // Scalar multiplication
#endif