#include <iostream>

#include "../include/vector.h"
#include "../include/matrix.h"

using namespace std;

int main()
{

	// Vector tests 
	/*
	vector<float> a(3, 1);
	vector<float> b(3, 2);

	Vector v(a);
	Vector v_prime(v);
	Vector w(b);

	cout << "v: " << v << endl;
	cout << "v': " << v_prime << endl;
	cout << "w: " << w << endl;
	cout << "v + w: " << v + w << endl;
	cout << "v - w: " << v - w << endl;
	cout << "-v: " << -v << endl;
	cout << "v * w': " << v * w << endl;
	cout << "w * 3: " << w * 3 << endl;
	cout << "10 * w: " << 10 * w << endl;
	cout << "New w^t:" << w.transposeNew() << endl;
	w.transpose();
	cout << "w^T:" << w << endl;
	w.transpose();
	cout << "w: " << w << endl << endl;
	*/

	// Matrix tests
	/*
	vector<vector<float>> mat(4);
	int counter = 0;
	for(int i = 0; i < 4; ++i)
	{
		vector<float> row(3);
		for(int j = 0; j < 3; ++j)
		{
			row[j] = counter;
			++counter;
		}
		mat[i] = row;
	}

	Vector one(3, 1);

	Matrix m(3,3, 9);
	Matrix n(mat);
	Matrix p(3,3, 1);

	cout << "3x3 matrix: " << endl;
	cout << m << endl << endl;
	cout << "4x3 matrix: " << endl;
	cout << n << endl << endl;

	n.transpose();
	cout << "3x4 matrix (the 4x3 transposed): " << endl;
	cout << n << endl << endl;

	n.transpose();
	cout << "4x3 matrix (the 3x4 transposed): " << endl;
	cout << n << endl << endl;

	cout << "Matrix matrix multiplication" << endl; 
	cout << n * m << endl << endl;

	cout << "Matrix vector multiplication" << endl;
	cout << p * one << endl;
	*/

	return 0;
}