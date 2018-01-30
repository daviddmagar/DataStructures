//#include "myfunctions.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int hashWord(const std::string& buffer);

int main(int argc, char* argv[]) {

	int length = atoi(argv[1]);
	int counter = 0;
	ifstream inputFile(argv[2]);
	char data;
	string buffer;
	inputFile.get(data);

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
		
		//push to functions
		hashWord(buffer);


		//Erase first character of string
		buffer.erase(0,1);
		inputFile.get(data);
		//Decriment counter so new character can be pulled i	
		counter = counter - 1;	
		

	}
	cout << "got here too" << endl;
	inputFile.close();
	return 0;
}

int hashWord(const std::string& buffer){
	int bufLength = buffer.length();
	int total;
	int addend;
	for(int i = 0; i < bufLength; i++){
		if(buffer.at(i) == 'a' || buffer.at(i) == 'A'){
			std::cout << 1;
			addend = 1;
		}
		else if(buffer.at(i) == 'c' || buffer.at(i) == 'C'){
			std::cout << 2;
			addend = 2;
		}
		else if(buffer.at(i) == 'g' || buffer.at(i) == 'G'){
			std::cout << 3;
			addend = 3;
		}
		else if(buffer.at(i) == 't' || buffer.at(i) == 'T'){
			std::cout << 4;
			addend = 4;
		}
		else{
			std::cout << endl;
			//return -1;
		}
		total << 2;
		total = total|addend;
		cout << total << endl;
	}
	
	return 0;
}





int updateWord(string){

}

vector<int> updateConsecutiveWords(string, int){

}

void printTable(){

}

