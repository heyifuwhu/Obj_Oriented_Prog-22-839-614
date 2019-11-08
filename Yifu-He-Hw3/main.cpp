//
//  main.cpp
//  hw3
//
//  Created by Jason Ha on 10/23/19.
//  Copyright © 2019 Jason He. All rights reserved.
//
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include "FileAccess.hpp"
#include "InvertedIndex.hpp"
using namespace std;

int main() {
	// Please, don't use this function !!!!!
	//	generateFileName();
	
//	char pp;
//	ifstream infile("/Users/yifuhe/Desktop/hw3/fin/t9.txt");
//	if(infile.fail()){
//        cerr << "File cound not be opened in addNewfile" << endl;
//        exit(EXIT_FAILURE);
//    }
//	while(!infile.eof()){
//		infile >> pp;
//		if(!isalpha(pp)){
//			cout << pp<<endl;
//		}
//
//	}
	
	// generate the InvertedIndex when running the program
	InvertedIndex tempIndex;
	
	// need user to input the path of fileName.txt
	cout << "Welcome to Inverted Index created by Jason He."<<endl;
	string path;
	// /Users/yifuhe/Desktop/hw3/fileName.txt
    cout << "Enter the path of fileName.txt:" << endl;
	cout <<"For example: /Users/yifuhe/Desktop/hw3/fileName.txt"<<endl;
	cout <<"Input here:"<<endl;
	
    cin >> path;
	vector<string> fileName = getFileName(path);
	string path2;
	// /Users/yifuhe/Desktop/hw3/fin/
	cout << "Enter the path of datasets of file" << endl;
	cout <<"For example: /Users/yifuhe/Desktop/hw3/fin/"<<endl;
	cout <<"Input here:"<<endl;
	cin >> path2;
	for(string item: fileName){
		//cout << item << endl;
		tempIndex.addNewFile(path2,item);
	}
	
    
	cout << "----------------------------------------------"<<endl;
	cout << "Instructions:"<<endl;
	cout << "This program will not differentiate capitalized letter."<<endl;
	int choice;
	while (true){
		cout << "----------------------------------------------"<<endl;
		cout <<"1.Search a word, "<<endl;
		cout <<"2.Search a phrase, e.g. \"financial industry\""<<endl;
		cout <<"3.Search two words in the following format, e.g. \"future and option\""<<endl;
		cout <<"4.Wide card query, e.g.\"fin*\""<<endl;
		cout <<"5.Quit."<<endl;
		cout <<"----------------------------------------------"<<endl;
		cout <<"Enter your choice: ";
		cin >> choice;
		if(choice == 1){
			string word;
			cout << "Enter the word (e.g. \"finance\"): ";
			cin >> word;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			tempIndex.searchWord(word);
		}else if(choice == 2){
			cout << "Enter a phrase, e.g. \"financial industry\":";
			string word,after;
			cin >> word >> after;
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			transform(after.begin(), after.end(), after.begin(), ::tolower);
			tempIndex.searchPhrase(word, after);
		}else if(choice == 3){
			cout << "Enter two words in the following format, e.g. \"future and option\":";
			string word1,AND,word2;
			cin >> word1 >> AND >> word2;
			transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
			transform(word2.begin(), word2.end(), word2.begin(), ::tolower);
			tempIndex.searchTwo(word1,word2);
		}else if(choice == 4){
			cout << "Enter wide card query, e.g.\"fin*\":";
			string word;
			cin >> word;
			transform(word.begin(), word.end()-1, word.begin(), ::tolower);
			tempIndex.searchWide(word);
		}else if(choice == 5){
			cout << "Thanks for choosing the program. See you!" << endl;
			break;
		}else{
			cout << "Wrong choice! Enter the choice agaain" << endl;
		}
	}
	return 0;
}

