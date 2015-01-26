#include "FileNamer.h"

void FileNamer::getFirstPart() {
	std::cout << "Enter the first part of the filename" << std::endl;
	std::cout << "(for example, \"Smith\" is the first part in \"Smith01.jpg\")" << std::endl;
	std::cin >> firstPart;
}

void FileNamer::getSecondPart() {
	std::cout << std::endl;
	std::cout << "Enter the second part of the filename" << std::endl; 
	std::cout << "(for example, \".jpg\" is the second part in \"Smith01.jpg\")" << std::endl;
	std::cin >> secondPart;
}

void FileNamer::getBounds() {
	std::cout << std::endl;
	std::cout << "Enter the lower bound of the number in the filename" << std::endl; 
	std::cout << "(1 is the lower part in the range \"Smith01.jpg - Smith09.jpg\")" << std::endl;
	std::cin >> lowerBound;
	std::cout << "Enter the upper bound of the number in the filename" << std::endl;
	std::cout << "(9 is the upper part in the range \"Smith01.jpg - Smith09.jpg\")" << std::endl;
	std::cin >> upperBound;
}

void FileNamer::getDigits() {
	std::cout << std::endl;
	std::cout << "Enter how many digits you wish for the filename to contains" << std::endl;
	std::cout << "(number two (2) will result in numbers such as 00, 01, 02 etc.)" << std::endl;
	std::cin >> digits;
	std::cout << std::endl;
}

void FileNamer::createFiles() const {
	std::string fileName;
	std::ofstream output;
	for (int i = lowerBound; i <= upperBound; ++i) {
		fileName.append(firstPart);
		if (digits > 1) {
			printFillDigits(i, fileName);
		}
		fileName.append(std::to_string(i) + secondPart);
		output.open(fileName);
		output << std::flush;
		output.close();
		fileName.clear();
	}
}

void FileNamer:: printFillDigits(int currentNumber, std::string &fileName) const {
	int digitsInNumber(0);
	while (currentNumber != 0) {
		currentNumber /= 10;
		digitsInNumber++;
	}
	if (digitsInNumber == 0) digitsInNumber = 1;
	if (digitsInNumber < digits) {
		for (int fillDigit = digitsInNumber; fillDigit < digits; ++fillDigit) {
			fileName.append("0");
		}
	}
}