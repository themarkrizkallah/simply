#ifndef _LINALG_H_
#define _LINALG_H_
#include <vector>
#include <map>
#include <string>

#include "../include/vector.h"
#include "../include/matrix.h"

class LinAlg final
{
	const std::vector<std::string> commands {"vector", "matrix", "transpose"};

	std::map<std::string, Vector> vecs;
	std::map<std::string, Matrix> mats;
	std::map<std::string, std::string> types;

	void consumeVec();
	void consumeMat();
	void make();

	std::string getType(std::string name) const;
	void matchCommand(std::string &s, int &n) const;
	void transpose() const;
	void add() const;
	void subtract() const;
	void multiply() const;
	void printItem() const;

public:
	void run(int argc, char** argv);
};
#endif