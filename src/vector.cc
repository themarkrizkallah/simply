#include <iostream>
#include <vector>

#include "../include/vector.h"

using namespace std;

/* Constructors + Big 5 */

// Constructor #1
Vector::Vector(int n, int x, bool t): t{t}{
	v.assign(n, x);
}

// Constructor #2
Vector::Vector(const vector<float> &a, bool t): t{t}, v{a} {}

// Destructor
Vector::~Vector(){}

// Copy constructor
Vector::Vector(const Vector &other): t{other.t}, v{other.v}{}

// Move constructor
Vector::Vector(Vector &&other): t{std::move(other.t)}, v{std::move(other.v)}{}

// Copy assignment
Vector &Vector::operator=(const Vector &other){
	t = other.t;
	v = other.v;
	return *this;
}

// Move assignment
Vector &Vector::operator=(Vector &&other){
	std::swap(t, other.t);
	std::swap(v, other.v);

	return *this;
}

// Vector operations
Vector Vector::operator+(const Vector &rhs) const{
	const int n1 = this->getDimension();
	const int n2 = rhs.getDimension();

	if(n1 == n2){
		vector<float> sum(n1);

		for(int i = 0; i < n1; ++i) sum[i] = v[i] + rhs.v[i];
		return Vector(sum);

	}else cout << "Cannot add 2 vectors in different dimensions.";

	return Vector(); // Temp
}

// Subtract vectors
Vector Vector::operator-(const Vector &rhs) const{
	const int n1 = this->getDimension();
	const int n2 = rhs.getDimension();

	if(n1 == n2){
		vector<float> diff(n1);

		for(int i = 0; i < n1; ++i) diff[i] = v[i] - rhs.v[i];
		return Vector(diff);

	}else cout << "Cannot subtract 2 vectors in different dimensions.";

	return Vector(); // Temp
}

// Multiply vectors
float Vector::operator*(const Vector &rhs) const{
	const int n1 = this->getDimension();
	const int n2 = rhs.getDimension();

	if(n1 == n2){
		float product = 0;

		for(int i = 0; i < n1; ++i) product += v[i] * rhs.v[i];
		return product;

	}else cout << "Cannot multiply 2 vectors in different dimensions.";

	return 0;
}

// Vector-Real multiplication
Vector Vector::operator*(const float a) const{
	const int n = v.size();
	vector<float> w(n);

	for(int i = 0; i < n; ++i) w[i] = v[i] * a;
	return Vector(w);
}

// Scalar multiplication
Vector operator*(const float a, const Vector &vec){return vec * a;};

// Negate vectors
Vector Vector::operator-() const{
	const int n = v.size();
	vector<float> neg(n);

	for(int i = 0; i < n; ++i) neg[i] = -v[i];

	return Vector(neg);
}

// Transpose current vector
void Vector::transpose(){t = !t;}

// Return a transposed copy of the current vector
Vector Vector::transposeNew() const{return Vector(v, !t);}

/* Utility */

// Returns the element at index i
float Vector::elementAt(const int i) const{
	return v[i];
}

// Returns the vector dimension (n)
int Vector::getDimension() const{
	return v.size();
}

// Returns true if the vector is transposed and false otherwise
bool Vector::isTransposed() const{
	return t;
}

// Prints vectors
ostream &operator<<(std::ostream &out, const Vector &vec){
	const int n = vec.v.size();

	out << '(';
	for(int i = 0; i < n; ++i){
		out << vec.v[i];
		if(i < n - 1) out << ", ";
		else{
			out << ')';
			if(vec.isTransposed()) out << "^T";
		}
	}

	return out;
}