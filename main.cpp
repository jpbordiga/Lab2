#include <iostream>
#include "Process.hpp"

using namespace std;

int main() {
	
	std::string fileName = "trace1.txt";

	Process *p = new Process(fileName);

	p->Run();

	p->~Process();

	return 0;

}