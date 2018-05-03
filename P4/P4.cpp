#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <sstream>




using namespace std;


int totalCount;
ifstream inputFile;
char data;

struct Node {
	string name;
	int occur;
};



int main(int argc, char* argv[]) {
    pair <string,string> diagram;
    inputFile.open(argv[1]);
    string buffer;
	string word;
    string number;
	int occurences = 0;
	int counter = 1;
	int x, y = 0;
	int nodeNum = 0;
	
	while(inputFile >> buffer) {
		if(counter%2 == 0){
			word = buffer;
			Node word1.name = word;
		}
		else{			
			stringstream toNum(buffer);
            toNum >> occurences;
			Node word1.occur = buffer;            
		}

		
		cout << word1.name << endl;
		cout << word1.occur << endl;
		counter++;
//		cout << buffer << endl;
	}
}

		
		

