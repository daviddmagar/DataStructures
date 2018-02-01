//#include "myfunctions.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int hashWord(std::string);
int updateWord(std::string);
vector<int> updateConsecutiveWords(std::string, int);
void printTable();
vector<int> hashConsecutiveWords(string, int);
vector<int> updateConsecutiveWords(string, int);


//Globals
int length;
ifstream inputFile;
std::vector<int> storageTable;

int main(int argc, char* argv[]) {
	
	
	//Set word length to command line argument
	length = atoi(argv[1]);
	int maxLength = 4;
	
	for(int i = length; i > 1; i--){
		maxLength = maxLength*4;
		}
		

	
	storageTable.resize(maxLength);
	
	
	
	
	
	
	
	//Get filepath of genome from command line
	inputFile.open(argv[2]);
	
	int counter = 0;	
	char data;
	int returnedHash;
	string buffer;


	//While not end of file
	while(!inputFile.eof()){
			//if input is letter add to buffer
			inputFile.get(data);
			if(data == '\n'){
				continue;
			}
				
				buffer.push_back(data);
				counter++;
			
			
		while(buffer.size() < length){
			inputFile.get(data);
			if(data == '\n'){
				continue;
			}
			if(inputFile.eof()){
				break;	
			}
			//If input is letter add to buffer			
			buffer.push_back(data);
			counter++;

		}
		
		//push to functions
		returnedHash = updateWord(buffer);
		if(!(returnedHash == -1)){
			storageTable.at(returnedHash) = storageTable.at(returnedHash) + 1;
			vector<int> returnedHashes = updateConsecutiveWords(buffer, returnedHash);
			cout << returnedHashes.size() << endl;
			for(int i = 0; i < returnedHashes.size(); i++){
				storageTable.at(returnedHashes.at(i)) = storageTable.at(returnedHashes.at(i)) + 1;
			}
			buffer.erase(0, length);
			cout << buffer << endl;
		}


		//Erase first character of string
		buffer.erase(0,1);
		//Decriment counter so new character can be pulled i	
		counter = counter - 1;

	}
	
	printTable();
	inputFile.close();
	return 0;
}



//Get string from file
int hashWord(std::string buffer){
	int bufLength = buffer.length();
	int total = 0;
	int addend = 0;
	//iterate through buffer
	for(int i = 0; i < bufLength; i++){
		//convert a to 1
		if(buffer.at(i) == 'a' || buffer.at(i) == 'A'){
			addend = 0;
		}
		//convert c to 2
		else if(buffer.at(i) == 'c' || buffer.at(i) == 'C'){
			addend = 1;
		}
		//convert g to 3
		else if(buffer.at(i) == 'g' || buffer.at(i) == 'G'){
			addend = 2;
		}
		//convert t to 4
		else if(buffer.at(i) == 't' || buffer.at(i) == 'T'){
			addend = 3;
		}
		//If illegal character return -1 and skip rest of calculations
		else{
			return -1;
		}
		//binary shift total twice 
		total = total << 2;
		//or total with the addend
		total = total|addend;
	}
	//return the total
	return total;
}





int updateWord(std::string buffer){
	int hashbuffer = hashWord(buffer);
	return hashbuffer;
}

vector<int> updateConsecutiveWords(string buffer, int hashBuffer){
	vector<int> namesTable = hashConsecutiveWords(buffer, hashBuffer);
	return namesTable;
}

vector<int> hashConsecutiveWords(string name, int passedHash){
	vector<int> namesTable;
	char temp;
	int tempNum;

	while(!inputFile.eof()){
			inputFile.get(temp);
	
			if(temp == '\n'  || inputFile.eof()){
				continue;
			}
			temp = toupper(temp);
			
			//if input is letter add to buffer
			if(temp == 'A'){
				tempNum = 0;
			}
			else if(temp == 'C'){
				tempNum = 1;
			}
			else if(temp == 'G'){
				tempNum = 2;
			}
			else if(temp == 'T'){
				tempNum = 3;
			}
			else{

				return namesTable;
			}
			
			
			name.erase(0,1);
			name = name + temp;	
			
			//minimum mask for word length two, 15 = 1111	
			int mask = 15; 
			
			//minimal mask for word length as per specs
			if(length > 2){
				int updateMask = length-2;
				for(int i = 0; i < updateMask; i++){
					//shift for 
					mask = mask << 2; //shift needed for length of name
					mask = mask | 3; //3 = 0011
					}
				}
			
			passedHash = passedHash << 2; //scoot over for next letter
			passedHash = passedHash | tempNum; //binary add of new char
			passedHash = passedHash & mask; //get rid of leading numbers
			namesTable.push_back(passedHash);		
	}
					cout << namesTable.size() << endl;
	return namesTable;

	
	
}
	

void printTable(){
	
	string word = "";
	int mask = 3;//binary 0011
	int tempStore = 0;
	int hash = 0;
	
	for(int i =0; i < storageTable.size(); i++){
		if(storageTable.at(i) != 0){
			hash = i;
			for(int x = 0; x < length; x++){
				tempStore = hash & mask;
				if(tempStore == 0)
					word.insert(0, "A");
				else if(tempStore == 1)
					word.insert(0, "C");
				else if(tempStore == 2)
					word.insert(0, "G");
				else if(tempStore == 3)
					word.insert(0, "T");
				hash = hash >> 2;
				
				tempStore = 0;
				}
				
				
				cout << word << " " << storageTable.at(i) << endl;
				word = "";
			}
		}
			
	}

