#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;


int main(int argc, char* argv[]) {

	int length = atoi(argv[1]);
	
	int counter = 0;
	
	cout << length << endl;

	ifstream inputFile(argv[2]);
	
	char data;
	
	char array passValue[] 
	
	vector <char> name(length);
	//Get to first letter in file
	while(!isalpha(data)){
		inputFile.get(data);
		}
	
	
	while(!inputFile.eof()){
				
		while(counter < length){
			cout << data;
			name[counter] = data;
			counter++;
			inputFile.get(data);
			cout << counter << endl;
		}
		
		inputFile.get(data);
		counter = counter -1;

	}
	for (vector<char>::const_iterator i = name.begin(); i != 		name.end(); ++i)
    std::cout << *i;

	inputFile.close();

	return 0;
}

int hashWord(string){

}

int updateWord(string){

}

vector<int> updateConsecutiveWords(string, int){

}

void printTable(){

}
//convertToHash(){

//}
