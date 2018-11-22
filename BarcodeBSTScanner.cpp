//============================================================================
// Name        : BarcodBSTScanner.cpp
// Author      : Erik Dekker
// Description : Assignment 4: Barcode Scanner using Binary Search Tree
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "Item.h"
#include "BinarySearchTree.h"
using namespace std;

int main(int argc, const char * argv[]) {
	string fileName = "upc_corpus.txt";
	BinarySearchTree<Item> tree; //Constructs Barcode tree
	ifstream inFile;
	inFile.open(fileName);
	string tline;
	string tcode;
	string tdesc;
	istringstream tss;

	cout<<"Populating Tree..."<<endl;
	getline(inFile, tline);
	while(getline(inFile, tline)) {
		tss.clear();
		tss.str(tline);
		getline(tss, tcode, ',');
		getline(tss, tdesc);
		Item i(tcode, tdesc);
		tree.insert(i);
	}
	cout<<"Tree Populated\n"<<endl;


	clock_t treeTime;
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
				Item treeOut;
				treeTime = clock();
				treeOut = tree.search(tbf);
				treeTime = clock() - treeTime;
				cout<<treeOut.getDesc();
				cout << "BST time: " << treeTime << " milliseconds\n" << endl;
			}else{
				cout<<"invalid UPC";
			}
		}else if(input == 'C'){
			cout<<"BST Size? (1-1045913): ";
			cin>>size;
			inFile.clear();
			inFile.seekg(0, ios::beg);
			cout<<"Populating Tree..."<<endl;
			getline(inFile, tline);
			for(int i = 0; i < size; i++){
				getline(inFile, tline);
				tss.clear();
				tss.str(tline);
				getline(tss, tcode, ',');
				getline(tss, tdesc);
				Item it(tcode, tdesc);
				tree.insert(it);
			}
			cout<<"Running Search Test...\n"<<endl;

			inFile.clear();
			inFile.seekg(0, ios::beg);
			getline(inFile, tline);
			worstCase = 0;
			for(int j = 0; j < size; j++){
				getline(inFile, tline);
				tss.clear();
				tss.str(tline);
				getline(tss, tcode, ',');
				Item tbf(tcode);
				Item treeOut;
				treeTime = clock();
				treeOut = tree.search(tbf);
				treeTime = clock() - treeTime;
				if(treeTime > worstCase)
					worstCase = treeTime;
				//cout<<"worstCase: "<<worstCase<<endl;
			}
			cout<<"Worst Case for BST of size "<<size<<": "<<worstCase<<" milliseconds"<<endl;
		}
	}while(input != 'Q');

	return 0;
}
//*/
