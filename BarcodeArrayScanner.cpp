//============================================================================
// Name        : BarcodBSTScanner.cpp
// Author      : Erik Dekker
// Description : Assignment 4: Barcode Scanner using Array
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "Item.h"

using namespace std;

int main(int argc, const char * argv[]) {
	string fileName = "upc_corpus.txt";
	ifstream inFile;
	inFile.open(fileName);
	cout<<"Creating Array..."<<endl;
	inFile.clear();
	inFile.seekg(0, ios::beg);
	int count = 0;
	string line;
	string code;
	string desc;
	istringstream ss;
	getline(inFile, line);
	while(getline(inFile, line)){
		count++;
	}
	Item* itemArray = new Item[count];
	cout<<"Array Created. \nPopulating Array..."<<endl;
	inFile.clear();
	inFile.seekg(0, ios::beg);
	getline(inFile, line);
	for(int i = 0; i < count; i++){
		getline(inFile, line);
		ss.clear();
		ss.str(line);
		getline(ss, code, ',');
		getline(ss, desc);
		Item ins(code, desc);
		itemArray[i] = ins;
	}
	cout<<"Array Populated."<<endl;

	clock_t arrayTime;
	clock_t worstCase;
	string UPC;
	int size;
	char input;

	do{
		cout<<"(L) Single UPC Lookup\n(C) Search Comparison\n(Q) Quit\nEnter Command (L/C/Q): ";
		cin>>input;
		if(input == 'L'){
			cout<<"UPC Code: ";
			cin>>UPC;
			if(isdigit(UPC[0])){
				Item tbf(UPC);
				Item arrayOut;
				arrayTime = clock();
				for(int index = 0; index < count; index++){
					if(itemArray[index] == tbf){
						arrayOut = itemArray[index];
						break;
					}
				}
				arrayTime = clock() - arrayTime;
				cout<<arrayOut.getDesc();
				cout << "Array time: " << arrayTime << " milliseconds\n" << endl;
			}else{
				cout<<"invalid UPC";
			}
		}else if(input == 'C'){
			cout<<"Array Size? (1-1045913): ";
			cin>>size;
			inFile.clear();
			inFile.seekg(0, ios::beg);
			cout<<"Populating Array..."<<endl;
			getline(inFile, line);
			for(int j = 0; j < size; j++){
				getline(inFile, line);
				ss.clear();
				ss.str(line);
				getline(ss, code, ',');
				getline(ss, desc);
				Item ins(code, desc);
				itemArray[j] = ins;
			}
			cout<<"Running Search Test...\n"<<endl;
			Item last = itemArray[size - 1];
			inFile.clear();
			inFile.seekg(0, ios::beg);
			getline(inFile, line);
			worstCase = clock();
			for(int k = 0; k < size; k++){
				if(itemArray[k] == last){
				worstCase = clock() - worstCase;
				break;
				}
			}
			cout<<"Worst Case for Array of size "<<size<<": "<<worstCase<<" milliseconds"<<endl;
		}
	}while(input != 'Q');

	return 0;
}


