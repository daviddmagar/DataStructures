#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int wordCount
ifstream inputFile
std::vector<string> inputData;
char data;

int main(int argc, char* argv[]) {
	inputFile.open(argv[2]);
	string buffer;
	
	while(!inputFile.eof()){		
		inputFile.get(data);

		if(data == '\n'){
			continue;
		}
		buffer.push_back(data)



	
