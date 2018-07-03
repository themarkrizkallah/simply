#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <vector>

class Vector final
{
	bool t;
	std::vector<float> v;
public:
	// Constructor + Big 5
	Vector(int n=1, int x=0, bool t=false); // Creates a vector in R^n, all elements = x
	Vector(const std::vector<float> &a, bool t=false);
	~Vector();
	Vector(const Vector &other);
    Vector(Vector &&other);
    Vector &operator=(const Vector &other);
    Vector &operator=(Vector &&other);

	// Vector operations
	Vector operator+(const Vector &rhs) const; // Vector addition
    Vector operator-(const Vector &rhs) const; // Vector subtraction
    float operator*(const Vector &rhs) const; // Dot product
    Vector operator*(const float a) const; // Scalar multiplication
    Vector operator-() const; // Vector negation

    // Transposition
    void transpose(); // Transposes the current vector
    Vector transposeNew() const; // Returns a copy of the current vector transposed

    // Utility
    float elementAt(const int i) const; // Returns a copy of the element at index i
    int getDimension() const; // Returns the dimension of the vector, n
	bool isTransposed() const; // Returns whether or not the vector is transposed
	friend std::ostream &operator<<(std::ostream &out, const Vector &vec); // Prints the vector
};

Vector operator*(const float a, const Vector &vec); // Scalar multiplication
#endif
