//#include "myfunctions.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int hashWord(const std::string& buffer);

int main(int argc, char* argv[]) {

	//Set word length to command line argument
	int length = atoi(argv[1]);
	
	//Get filepath of genome from command line
	ifstream inputFile(argv[2]);
	
	int counter = 0;	
	char data;
	string buffer;


	//While not end of file
	while(inputFile >> data){
			//if input is letter add to buffer
			if(isalpha(data)){
				buffer.push_back(data);
				counter++;
			}
			//Else skip it
			else continue;
		while(counter < length){
			inputFile >> data;	
			//If input is letter add to buffer			
			if(isalpha(data)){
				buffer.push_back(data);
				counter++;
			}
			//Else skip it
			else continue;
		}
		
		//push to functions
		hashWord(buffer);



		//Erase first character of string
		buffer.erase(0,1);
		//Decriment counter so new character can be pulled i	
		counter = counter - 1;

	}
	inputFile.close();
	return 0;
}

//Get string from file
int hashWord(const std::string& buffer){
	cout << buffer << endl;
	int bufLength = buffer.length();
	int total;
	int addend;
	//iterate through buffer
	for(int i = 0; i < bufLength; i++){
		//convert a to 1
		if(buffer.at(i) == 'a' || buffer.at(i) == 'A'){
			std::cout << 1;
			addend = 1;
		}
		//convert c to 2
		else if(buffer.at(i) == 'c' || buffer.at(i) == 'C'){
			std::cout << 2;
			addend = 2;
		}
		//convert g to 3
		else if(buffer.at(i) == 'g' || buffer.at(i) == 'G'){
			std::cout << 3;
			addend = 3;
		}
		//convert t to 4
		else if(buffer.at(i) == 't' || buffer.at(i) == 'T'){
			std::cout << 4;
			addend = 4;
		}
		//If illegal character return -1 and skip rest of calculations
		else{
			std::cout << endl;
			return -1;
		}
		//binary shift total twice 
		total << 2;
		//or total with the addend
		total = total|addend;
		cout << total << endl;
	}
	//return the total
	return total;
}





int updateWord(string){

}

vector<int> updateConsecutiveWords(string, int){

}

void printTable(){

}

