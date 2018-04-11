#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>

class Process {
public:

	Process(const std::string &traceFileName);
	Process(const Process &orig) = delete;
	Process(Process &&orig) = delete;
	Process operator=(const Process &orig) = delete;
	Process operator=(Process &&orig) = delete;
	virtual ~Process() {
	
		// delete process
	
	}

	void run(std::ifstream &iF);
	void specifyMemSize(std::istringstream &sS, std::vector<uint8_t> mem);
	void findDifferentBytes(std::istringstream &sS, std::vector<uint8_t> mem);
	void storeBytes(std::istringstream &sS, std::vector<uint8_t> mem);
	void replicateByteValue(std::istringstream &sS, std::vector<uint8_t> mem);
	void duplicateBytes(std::istringstream &sS, std::vector<uint8_t> mem);
	void printBytes(std::istringstream &sS, std::vector<uint8_t> mem);

private:

};

#endif
