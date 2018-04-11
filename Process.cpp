#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include "Process.hpp"

Process::Process(const std::string &traceFileName) {

	std::cout << "1\n";

	//iF = new std::ifstream();

	std::cout << "2\n";

	iF.open(traceFileName);

	std::cout << iF.is_open() << "\n";

	if (iF.fail()) {
		//std::cout << "FAIL\n";
		throw std::runtime_error("ERROR: file not found: " + traceFileName);
	} else {
		std::cout << "4\n";
		
	}

	

}

void Process::Run() {
	
	std::vector<uint8_t> commandMemory;
	std::string currentLine;
	std::string command;

	while (std::getline(iF, currentLine)) {
		
		std::istringstream sstream(currentLine, std::ios::in);

		if (currentLine[0] == '#') {
			std::cout << currentLine << "\n";
		} else {
			
			sstream >> command;

			if (command == "memsize") {
				specifyMemSize(sstream, commandMemory);
			} else if (command == "diff") {
				findDifferentBytes(sstream, commandMemory);
			} else if (command == "store") {
				storeBytes(sstream, commandMemory);
			} else if (command == "replicate") {
				replicateByteValue(sstream, commandMemory);
			} else if (command == "duplicate") {
				duplicateBytes(sstream, commandMemory);
			} else if (command == "print") {
				printBytes(sstream, commandMemory);
			}


		}
	}

}

void Process::specifyMemSize(std::istringstream &sS, std::vector<uint8_t> mem) {

	// fill with zeroes?

	uint8_t size = 0;
	sS >> size;
	mem.reserve(size);
	mem.resize(size);

}

void Process::findDifferentBytes(std::istringstream &sS, std::vector<uint8_t> mem) {

	std::vector<uint8_t> expectedValues;
	uint8_t addr;
	int count = 0;
	uint8_t currentValue = 0;

	while (sS >> currentValue) {
		expectedValues[count] = currentValue;
		count++;
	}

	addr = expectedValues.back();

	for (uint8_t i = 0; i < expectedValues.size() - 1; ++i) { // -1 or -2?

		if (expectedValues[i] != mem[addr + i]) {
			std::cerr << "Error: current value of " << mem[addr + i] << " does not match expected value of " << expectedValues[i];
		}
	
	}

}

void Process::storeBytes(std::istringstream &sS, std::vector<uint8_t> mem) {

	std::vector<uint8_t> copies;
	uint8_t addr;
	int count = 0;
	uint8_t currentValue = 0;

	while (sS >> currentValue) {
		copies[count] = currentValue;
		count++;
	}

	addr = copies.back();

	for (uint8_t i = 0; i < copies.size() - 1; ++i) { // -1 or -2?

		mem[addr + i] = copies[i];

	}

}

void Process::replicateByteValue(std::istringstream &sS, std::vector<uint8_t> mem) {

	uint8_t value = 0;
	uint8_t count = 0;
	uint8_t addr = 0;

	sS >> value;
	sS >> count;
	sS >> addr;

	for (uint8_t i = 0; i < count; ++i) {
		mem[addr + i] = value;
	}

}

void Process::duplicateBytes(std::istringstream &sS, std::vector<uint8_t> mem) {

	uint8_t count = 0;
	uint8_t sourceAddress = 0;
	uint8_t destinationAddress = 0;

	sS >> count;
	sS >> sourceAddress;
	sS >> destinationAddress;

	for (uint8_t i = 0; i < count; ++i) {
		mem[destinationAddress + i] = mem[sourceAddress + i];
	}

}

void Process::printBytes(std::istringstream &sS, std::vector<uint8_t> mem) {

	uint8_t count = 0;
	uint8_t addr = 0;
	int maxLine = 0;

	sS >> count;
	sS >> addr;

	std::cout << addr << "\n";

	for (uint8_t i = 0; i < count; ++i) {
	
		std::cout << mem[addr + i];
		maxLine++;
		if (maxLine == 15) {
			std::cout << "\n";
			maxLine = 0;
		}

	
	}




}