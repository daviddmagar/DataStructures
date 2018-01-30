#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {

	int length = atoi(argv[1]);
	int counter = 0;
	ifstream inputFile(argv[2]);
	char data;
	string buffer;

	
		
	while(!inputFile.eof()){
		while(counter < length){	
			inputFile.get(data);
			if(isalpha(data)){
				buffer.push_back(data);
				counter++;
			}
			else{
				continue;
			}
			
		}
		cout << buffer << endl;
		buffer.erase(0,1);
		counter = counter-1;	
	}
	
		
	cout << buffer << endl;

//	for (vector<char>::const_iterator i = name.begin(); i != 		name.end(); ++i)
//    std::cout << *i;

//	inputFile.close();

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
