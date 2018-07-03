#include <iostream>
#include <vector>
#include <../include/vector.h>

using namespace std;

// Constructor + Big 5
Vector::Vector(int n, int x, bool t): t{t}
{
	v.assign(n, x);
}

Vector::Vector(const vector<float> &a, bool t): t{t}, v{a} {}

Vector::~Vector(){}

Vector::Vector(const Vector &other): t{other.t}, v{other.v}{}

Vector::Vector(Vector &&other): t{std::move(other.t)}, v{std::move(other.v)}{}

Vector &Vector::operator=(const Vector &other)
{
	t = other.t;
	v = other.v;
	return *this;
}

Vector &Vector::operator=(Vector &&other)
{
	std::swap(t, other.t);
	std::swap(v, other.v);

	return *this;
}

// Vector operations
Vector Vector::operator+(const Vector &rhs) const
{
	const int n1 = this->getDimension();
	const int n2 = rhs.getDimension();

	if(n1 == n2)
	{
		vector<float> sum(n1);

		for(int i = 0; i < n1; ++i) sum[i] = v[i] + rhs.v[i];
		return Vector(sum);

	}else cout << "Cannot add 2 vectors in different dimensions.";

	return Vector(); // Temp
}

Vector Vector::operator-(const Vector &rhs) const
{
	const int n1 = this->getDimension();
	const int n2 = rhs.getDimension();

	if(n1 == n2)
	{
		vector<float> diff(n1);

		for(int i = 0; i < n1; ++i) diff[i] = v[i] - rhs.v[i];
		return Vector(diff);

	}else cout << "Cannot subtract 2 vectors in different dimensions.";

	return Vector(); // Temp
}

float Vector::operator*(const Vector &rhs) const
{
	const int n1 = this->getDimension();
	const int n2 = rhs.getDimension();

	if(n1 == n2)
	{
		float product = 0;

		for(int i = 0; i < n1; ++i) product += v[i] * rhs.v[i];
		return product;

	}else cout << "Cannot multiply 2 vectors in different dimensions.";

	return 0;
}

Vector Vector::operator*(const float a) const
{
	const int n = v.size();
	vector<float> w(n);

	for(int i = 0; i < n; ++i) w[i] = v[i] * a;
	return Vector(w);
}

Vector operator*(const float a, const Vector &vec){return vec * a;};

Vector Vector::operator-() const
{
	const int n = v.size();
	vector<float> neg(n);

	for(int i = 0; i < n; ++i) neg[i] = -v[i];

	return Vector(neg);
}

// Transposition
void Vector::transpose(){t = !t;}

Vector Vector::transposeNew() const{return Vector(v, !t);}

// Utility
float Vector::elementAt(const int i) const
{
	return v[i];
}

int Vector::getDimension() const
{
	return v.size();
}

bool Vector::isTransposed() const
{
	return t;
}

ostream &operator<<(std::ostream &out, const Vector &vec)
{
	const int n = vec.v.size();

	out << '(';
	for(int i = 0; i < n; ++i)
	{
		out << vec.v[i];
		if(i < n - 1) out << ", ";
		else
		{
			out << ')';
			if(vec.isTransposed()) out << "^T";
		}
	}

	return out;
}
