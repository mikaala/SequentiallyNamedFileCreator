#include "FileNamer.h"

using namespace std;

int main() {
	FileNamer fn;
	fn.getFirstPart();
	fn.getSecondPart();
	fn.getBounds();
	fn.getDigits();
	fn.createFiles();
	return 0;
}