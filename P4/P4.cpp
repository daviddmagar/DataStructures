#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>




using namespace std;


int totalCount;
ifstream inputFile;
char data;

int main(int argc, char* argv[]) {
    pair <string,string> diagram;
    inputFile.open(argv[1]);
    string buffer;
    string prevWord;
    vector <string> words;
    vector < pair<string,string>> words2;
    int uniqueWords = 0;
    int biagrams = 0;
    int wordCount = 0;
	string word;
	int occurences = 0;
	int counter = 1;
	
	while(inputFile >> buffer) {
		if(counter%2 = 0){
			word = buffer;
		}
		else{
			occurences = buffer;
		}
		counter++;
		cout << buffer << endl;
	}
}

		
		

