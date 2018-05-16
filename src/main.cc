#include <iostream>

#include <../include/vector.h>

using namespace std;

int main()
{
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
	cout << "w: " << w << endl;

	return 0;
}