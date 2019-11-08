//
//  FileAccess.cpp
//  hw3
//
//  Created by Jason Ha on 10/24/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "FileAccess.hpp"
using namespace std;


void generateFileName(){
    string path;
    cout << "Enter the path of data file:" << endl;
    cin >> path;
    ofstream fileOutput{path+"/../fileName.txt",ios::out};
    if(!fileOutput){
        cerr << "File cannot be opened during generateFileName." << endl;
        exit(EXIT_FAILURE);
    }
    
    for (const auto& entry : std::__fs::filesystem::directory_iterator(path)){
        cout << entry.path().c_str() <<endl;
        //fileOutput << entry.path().c_str() << endl;
    }
    fileOutput.close();
}

// version 1

//vector<string> getFileName(){
//    string path;
//    cout << "Enter the path of fileName:" << endl;
//    cin >> path;
//    ifstream fileInput{path, ios::in};
//    string file;
//    vector<string> fileNames;
//    if(!fileInput){
//        cerr << "File cannot be opened during getFileName." << endl;
//        exit(EXIT_FAILURE);
//    }
//    while(!fileInput.eof()){
//        fileInput >> file;
//        fileNames.push_back(file);
//        //cout << file <<endl;
//    }
//    fileInput.close();
//    return fileNames;
//}

// version 2
vector<string> getFileName(string path){
    ifstream fileInput{path, ios::in};
    string file;
    vector<string> fileNames;
    if(!fileInput){
        cerr << "File cannot be opened during getFileName." << endl;
        exit(EXIT_FAILURE);
    }
    while(!fileInput.eof()){
        fileInput >> file;
        fileNames.push_back(file);
        //cout << file <<endl;
    }
    fileInput.close();
    return fileNames;
}

