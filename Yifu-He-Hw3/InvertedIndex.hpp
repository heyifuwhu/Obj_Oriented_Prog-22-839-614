//
//  InvertedIndex.hpp
//  hw3
//
//  Created by Jason Ha on 10/26/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef InvertedIndex_hpp
#define InvertedIndex_hpp

#include <iterator>
#include <string>
#include <stdio.h>
#include <vector>
#include <map>
#include "FileAccess.hpp"
using namespace std;


class Node{
private:
    string fileName;
    string word;
    string after;
    unsigned int count;
    
public:
    // constructor
    Node(const string& fileName_,const string& word_,const string& after_);
    
    // overload the operator == for class Node
    bool operator==(const Node& node2);
    
    // addcount
    void addcount(){
        count +=1;
    }
    // accessor
    string getfileName(){
        return fileName;
    }
    string getWord(){
        return word;
    }
    string getAfter(){
        return after;
    }
    unsigned int getCount(){
        return count;
    }
    
};

class InvertedIndex{
private:
    map<string,vector<Node>> Index;
    // add a Node in the Index, which will be used in addNewFile function
    void addNode(const string& fileName_,const string& word,const string& after);
    
public:
    // default constructor
    InvertedIndex(){};
    
    // member function
    // add a new file
    void addNewFile(const string& path,const string& filename);
    
    //search fingle word
    void searchWord(const string& word);
    
    // extra credits
    // search phrase(only two)
    void searchPhrase(const string& word,const string& after);
    // search two word not need to be adjacent
    void searchTwo(const string& word1,const string& word2);
    // wild card search
    void searchWide(const string& word);
};

#endif /* InvertedIndex_hpp */
