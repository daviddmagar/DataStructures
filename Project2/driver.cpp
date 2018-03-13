#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int wordCount;
ifstream inputFile;
char data;

int main(int argc, char* argv[]) {
	inputFile.open(argv[1]);
	string buffer;
    cout << "Welcome ";
	
	while(!inputFile.eof()){
		inputFile.get(data);
		if(!isalpha(data)){
            cout << buffer << endl;
			inputFile.get(data);
			buffer.clear();
		}
		buffer.push_back(data);
	}
	
	return 0;
}
			
		
		
		
		



	
