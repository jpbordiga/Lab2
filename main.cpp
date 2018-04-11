/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: sam
 *
 * Created on April 8, 2018, 3:18 PM
 */

#include <cstdlib>
#include "Process.h"


using namespace std;

/*
 * 
 */
int main() {
	
	std::string fileName = "trace1.txt";

	Process *p = new Process(fileName);

	p->Run();

	delete p;

	return 0;

}
