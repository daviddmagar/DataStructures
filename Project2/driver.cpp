#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int wordCount
ifstream inputFile
char data;

int main(int argc, char* argv[]) {
	inputFile.open(argv[2]);
	string buffer;
	
	while(!inputFile.eof()){
		inputFile.get(data);
		cout << buffer;
		if(!isalpha[data]){
			inputFile.get(data);
			buffer.clear();
		}
		buffer.push_back(data);
	}
	
	return 0
}
			
		
		
		
		



	
