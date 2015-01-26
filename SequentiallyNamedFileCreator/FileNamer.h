#pragma once
#include <iostream>
#include <string>
#include <fstream>

class FileNamer {
	friend std::ofstream& operator<<(std::ofstream &os, const FileNamer &fileNamer);
public:
	void getFirstPart();
	void getSecondPart();
	void getBounds();
	void getDigits();
	void createFiles() const;
private:
	void printFillDigits(int currentNumber, std::string &fileName) const;
	std::string firstPart, secondPart;
	int lowerBound, upperBound, digits;
};

