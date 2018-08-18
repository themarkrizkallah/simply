#include <iostream>
#include <vector>
#include <map>
#include <string>

#include "../include/vector.h"
#include "../include/matrix.h"
#include "../include/linalg.h"

using namespace std;

const string MAKE = "make";
const string MAT = "matrix";
const string VEC = "vector";
const string TRANSPOSE = "transpose";
const string PRINT = "print";
const string ADD = "add";
const string SUBTRACT = "subtract";
const string MULTIPLY = "multiply";

void LinAlg::consumeVec()
{
	string name;
	int n;
	float x;

	cout << "Vector name: ";
	cin >> name;

	cout << "Vector dimension (n): ";
	cin >> n;

	vector<float> v(n);

	for(int i = 0; i < n; ++i)
	{
		if(!(cin >> x))
        {
            if(cin.eof()) break;
            cin.clear();
            cin.ignore();
        }
        else v[i] = x;
	}

	cout << "Vector entered." << endl << endl;

	Vector vec(v);
	vecs[name] = vec;
	types[name] = VEC;
}

void LinAlg::consumeMat()
{
	string name;
	int n, m;
	float x;

	cout << "Matrix name: ";
	cin >> name;

	cout << "Number of columns (n): ";
	cin >> n;

	cout << "Number of rows (m): ";
	cin >> m;

	vector<vector<float>> v(m, vector<float>(n));

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(!(cin >> x))
	        {
	            if(cin.eof()) break;
	            cin.clear();
	            cin.ignore();
	        }
	        else v[i][j] = x;
		}
	}

	cout << "Matrix entered." << endl << endl;

	Matrix mat(v);
	mats[name] = mat;
	types[name] = MAT;
}

void LinAlg::make()
{
	string type;
	cin >> type;

	if(type == VEC) consumeVec();
	else if(type == MAT) consumeMat();
	else cout << "Invalid type." << endl << endl;
}

string LinAlg::getType(string name) const 
{
	return types.at(name);
}

void LinAlg::transpose() const
{
	string name, type;

	cin >> name;
	type = types.at(name);

	if(type == VEC)
	{
		Vector vec(vecs.at(name));
		vec.transpose();

		cout << name << " transposed:" << endl;
		cout << vec << endl << endl;
	}
	else if(type == MAT)
	{
		Matrix mat(mats.at(name));
		mat.transpose();

		cout << name << " transposed:" << endl;
		cout << mat << endl << endl;
	}
}

void LinAlg::add() const
{
	string name1, name2, type1, type2;

	cin >> name1;
	cin >> name2;

	type1 = types.at(name1);
	type2 = types.at(name2);

	if(type1 == VEC && type2 == VEC)
	{
		Vector lhs(vecs.at(name1));
		Vector rhs(vecs.at(name2));

		cout << name1 << ":" << endl;
		cout << lhs << endl;

		cout << name2 << ":" << endl;
		cout << rhs << endl;

		cout << name1 << " + " << name2 << ":" << endl;
		cout << lhs + rhs << endl << endl;
	}
	else if(type1 == MAT && type2 == MAT)
	{
		Matrix lhs(mats.at(name1));
		Matrix rhs(mats.at(name2));

		cout << name1 << ":" << endl;
		cout << lhs << endl;

		cout << name2 << ":" << endl;
		cout << rhs << endl;

		cout << name1 << " + " << name2 << ":" << endl;
		cout << lhs + rhs << endl << endl;
	}
	else
	{
		cout << "Cannot add matrices and vectors." << endl;
	}
}

void LinAlg::subtract() const
{
	string name1, name2, type1, type2;

	cin >> name1;
	cin >> name2;

	type1 = types.at(name1);
	type2 = types.at(name2);

	if(type1 == VEC && type2 == VEC)
	{
		Vector lhs(vecs.at(name1));
		Vector rhs(vecs.at(name2));

		cout << name1 << ":" << endl;
		cout << lhs << endl;

		cout << name2 << ":" << endl;
		cout << rhs << endl;

		cout << name1 << " - " << name2 << ":" << endl;
		cout << lhs - rhs << endl << endl;
	}
	else if(type1 == MAT && type2 == MAT)
	{
		Matrix lhs(mats.at(name1));
		Matrix rhs(mats.at(name2));

		cout << name1 << ":" << endl;
		cout << lhs << endl;

		cout << name2 << ":" << endl;
		cout << rhs << endl;

		cout << name1 << " - " << name2 << ":" << endl;
		cout << lhs - rhs << endl << endl;
	}
	else
	{
		cout << "Cannot subtract matrices and vectors." << endl;
	}
}

void LinAlg::multiply() const
{
	string name1, name2, type1, type2;

	cin >> name1;
	cin >> name2;

	type1 = types.at(name1);
	type2 = types.at(name2);

	if(type1 == VEC && type2 == VEC)
	{
		Vector lhs(vecs.at(name1));
		Vector rhs(vecs.at(name2));

		cout << name1 << ":" << endl;
		cout << lhs << endl;

		cout << name2 << ":" << endl;
		cout << rhs << endl;

		cout << name1 << " * " << name2 << ":" << endl;
		cout << lhs * rhs << endl << endl;
	}
	else if(type1 == MAT && type2 == MAT)
	{
		Matrix lhs(mats.at(name1));
		Matrix rhs(mats.at(name2));

		cout << name1 << ":" << endl;
		cout << lhs << endl;

		cout << name2 << ":" << endl;
		cout << rhs << endl;

		cout << name1 << " * " << name2 << ":" << endl;
		cout << lhs * rhs << endl << endl;
	}
	else if(type1 == MAT && type2 == VEC)
	{
		Matrix lhs(mats.at(name1));
		Vector rhs(vecs.at(name2));

		cout << name1 << ":" << endl;
		cout << lhs << endl;

		cout << name2 << ":" << endl;
		cout << rhs << endl;

		cout << name1 << " * " << name2 << ":" << endl;
		cout << lhs * rhs << endl << endl;
	}
	else
	{
		cout << "Cannot multiply this matrix and vector." << endl;
	}
}

void LinAlg::printItem() const
{
	string name, type;

	cin >> name;
	type = types.at(name);

	if(type == VEC)
	{
		Vector vec(vecs.at(name));

		cout << "Vector " << name << ":" << endl;
		cout << vec << endl << endl;
	}
	else if(type == MAT)
	{
		Matrix mat(mats.at(name));

		cout << "Matrix " << name << ":" << endl;
		cout << mat << endl << endl;
	}
}

void LinAlg::run(int argc, char** argv)
{
	string command;

	while(cin >> command)
	{
		if(cin.eof()) break;

		if(command == MAKE)
		{
			make();
		}
		else if(command == TRANSPOSE)
		{
			transpose();
		}
		else if(command == ADD)
		{
			add();
		}
		else if(command == SUBTRACT)
		{
			subtract();
		}
		else if(command == MULTIPLY)
		{
			multiply();
		}
		else if(command == PRINT)
		{
			printItem();
		}
	}
}