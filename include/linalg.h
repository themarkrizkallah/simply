#ifndef _LINALG_H_
#define _LINALG_H_
#include <vector>
#include <map>
#include <string>

#include "../include/vector.h"
#include "../include/matrix.h"

class LinAlg final
{
	std::map<std::string, Vector> vecs; // A map to store Vectors
	std::map<std::string, Matrix> mats; // A map to store Matrices
	std::map<std::string, std::string> types; // A map to store the name and type pair

	void consumeVec(); // Create a vector from user input
	void consumeMat(); // Create a matrix from user input
	void make(); // Creates an object from user input

	std::string getType(std::string name) const; // Returns the type that associates with name
	void transpose() const; // Transposes vector or matrix
	void add() const; // Adds vectors and matrices
	void subtract() const; // Subtracts vectors and matrices
	void multiply() const; // Multiplies vectors and matrices
	void negate() const; // Negates vectors and matrices
	void printItem() const; // Prints vectors and matrices

public:
	void run(int argc, char** argv); // Runs the module
};
#endif