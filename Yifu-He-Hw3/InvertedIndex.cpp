//
//  InvertedIndex.cpp
//  hw3
//
//  Created by Jason Ha on 10/26/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include "InvertedIndex.hpp"


Node::Node(const string& fileName_,const string& word_,const string& after_)
: fileName(fileName_)
, word(word_)
, after(after_)
, count(1)
{
}

bool Node::operator==(const Node& node2){
    if((fileName == node2.fileName) &&(word == node2.word) &&(after == node2.after)){
        return true;
    }
    return false;
}


void InvertedIndex::addNode(const string& path, const string& word, const string& after){
    if (Index.find(word) != Index.end()){//word exists in the Index
        // find whether the Node exist in the vector<Node>
        vector<Node>::iterator iter;
        Node temp_node(path,word,after);
        iter = find(Index[word].begin(),Index[word].end(),temp_node);
        if(iter != Index[word].end()){ // the temp_node exist in the vector
            (*iter).addcount();
        }else{ // the temp_node doesn't exist in the vector
            Index[word].push_back(temp_node);
        }
    }else{ // word doesn't exist in the Index, add word - vector into Index
        vector<Node> position{Node(path,word,after)};
        Index[word] = position;
    }
}


void InvertedIndex::addNewFile(const string& path, const string& filename){
    //cout << path<<endl;
    
    ifstream infile;
    infile.open(path + filename, ios::in);
    // set the ifstream to make it not skip the whitespace
    infile >> noskipws;
        
    // exit program if ifstream could not open file
    if(infile.fail()){
        cerr << "File cound not be opened in addNewfile" << endl;
        exit(EXIT_FAILURE);
    }
        
    // read char-by-char in order to check the type of char
    char letter;
    string word{""};
    string after{""};
    // put the first word into word
    while(!infile.eof()){
        infile >>letter;
        if(islower(letter)){
            word += letter;
        //}else if(ispunct(letter) || isspace(letter)){
        }else if(!isalpha(letter)){
            break;
        }else if(isupper(letter)){
            word += tolower(letter);
        }else{
         
        }
    }
    
    // access the word after then add the word into index
    while(!infile.eof()){
        infile >> letter;
        if(islower(letter)){
            after += letter;
        //}else if(ispunct(letter) || isspace(letter)){
        }else if(!isalpha(letter)){
        // punctuation followed by white space
            if(after == ""){
                continue;
            }
        //add the word in index
            addNode(filename, word, after);
        // reset after and assign after to word
            word = after;
            after = "";
            //cout <<". ";
        }else if(isupper(letter)){
            after += tolower(letter);
        }
    }
    //cout <<"E ";
    
    // access the last word and save it
    addNode(filename, word, after);
//    if (isalpha(letter)){
//        addNode(filename, word, after);
//        //cout << "1";
//    }else{
//        addNode(filename, word, after);
//        //cout <<"2";
//    }
    
}

void InvertedIndex::searchWord(const string& word){
    // use temp list to count
    map<string,int> temp;
    // use the rank list to cout
    vector<pair<int,string>> rank;
    
    if(Index.find(word) != Index.end()){ // find the word in the Index, begin to count and rank
        cout << word << " is in our system."<< endl;
        // access the vector<Node> and count the word according to filename
        for(Node item : Index[word]){
            // check whether fileName already exist in the
            if(temp.find((item.getfileName())) != temp.end()){
                temp[item.getfileName()] += item.getCount();
            }else{
                temp[item.getfileName()] = item.getCount();
            }
        }
        // search the temp and convert it into rank list
        map<string,int>:: iterator iter;
        iter = temp.begin();
        while(iter!=temp.end()){
            //cout << iter->second<<iter->first;
            rank.push_back(make_pair(iter->second, iter->first));
            iter++;
        }
        // search the rank list and cout
        sort(rank.begin(), rank.end());
        // ascending
//        for(pair<int,string> item: rank){
//            cout << item.second <<"  "<< item.first<<endl;
//        }
        // descending
        for(int i = static_cast<int>(rank.size())-1 ; i >= 0 ; i--){
            cout << rank[i].second <<"  "<< rank[i].first<<endl;
        }
    }else{ // the word no in the Index
        cout << "There is no "<< word <<" in our system. "<< endl;
    }
}


// bonus 1
void InvertedIndex::searchPhrase(const string& word,const string& after){
    // use temp list to count
    map<string,int> temp;
    // use the rank list to cout
    vector<pair<int,string>> rank;
    
        
    if(Index.find(word) != Index.end()){ // find the word in the Index, begin to count and rank
        // access the vector<Node> and count the word according to filename
        for(Node item : Index[word]){
            if(item.getAfter() == after){
                // check whether fileName already exist in the
                if((temp.find((item.getfileName())) != temp.end()) ){
                    temp[item.getfileName()] +=item.getCount();
                }else{
                    temp[item.getfileName()] = item.getCount();
                }
            }
        }
        // check whether temp is empty
        if(temp.empty()){
            cout << "There is no "<< word <<" " << after <<" in our system. "<< endl;
        }else{
            cout << "The phrase of \""<<word <<" " << after << " \" is in our system:"<< endl;
            // search the temp and convert it into rank list
            map<string,int>:: iterator iter;
            iter = temp.begin();
            while(iter!=temp.end()){
                //cout << iter->second<<iter->first;
                rank.push_back(make_pair(iter->second, iter->first));
                iter++;
            }
            // search the rank list and cout
            sort(rank.begin(), rank.end());
            // ascending
        //        for(pair<int,string> item: rank){
        //            cout << item.second <<"  "<< item.first<<endl;
        //        }
            // descending
            for(int i = static_cast<int>(rank.size())-1 ; i >= 0 ; i--){
                cout << rank[i].second <<"  "<< rank[i].first<<endl;
            }
        }
    }else{ // the word no in the Index
        cout << "There is no "<< word <<" " << after <<" in our system. "<< endl;
    }
}

// bouns 2
void InvertedIndex::searchTwo(const string& word1,const string& word2){
    // use temp list to count
    map<string,int> temp1;
    map<string,int> temp2;
    // use the rank list to cout
    vector<pair<int,string>> rank;
    // count word1 in each file
    if(Index.find(word1) != Index.end()){ // find the word in the Index, begin to count and rank
        // access the vector<Node> and count the word according to filename
        for(Node item : Index[word1]){
            // check whether fileName already exist in the
            if(temp1.find((item.getfileName())) != temp1.end()){
                temp1[item.getfileName()] += item.getCount();
            }else{
                temp1[item.getfileName()] = item.getCount();
            }
        }
    }else{
        cout << "There is no pair of \""<< word1 <<" and " << word2<<" \" in our system. 1"<< endl;
        return;
    }
    // use temp2 to compare the number of word1 and word2 in the same file and choose the smaller one
    temp2 = temp1;
    // count word2 in each file
    if(Index.find(word2) != Index.end()){ // find the word in the Index, begin to count and rank
    // access the vector<Node> and count the word according to filename
        for(Node item : Index[word2]){
            // check whether fileName already exist in the
            if(temp2.find((item.getfileName())) != temp2.end()){
                temp2[item.getfileName()] -= item.getCount();
            }
        }
    }else{
        cout << "There is no pair of \""<< word1 <<" and " << word2<<"\" in our system. 2"<< endl;
        return;
    }
    
    // search the temp and convert it into rank list
    map<string,int>:: iterator iter;
    iter = temp2.begin();
    while(iter!=temp2.end()){
        // N(word2) is more than or equal to N(word1), then choose N(word1)
        string cursor = iter->first;
        if(iter->second <= 0){
            rank.push_back(make_pair(temp1[cursor], cursor));
        }else if(iter->second < temp1[cursor]){ // N(word2) is less than or equal to N(word1), then choose N(word2)
            rank.push_back(make_pair(temp2[cursor], cursor));
        }else{//no N(word2) equal to 0, eliminate this case
        }
        iter++;
    }
    if(rank.empty()){
        cout << "There is no pair of \""<< word1 <<" and " << word2<<"\" in our system. 3"<< endl;
    }else{
        cout << "The pair of \"" << word1 <<" and "<<word2<<"\" exists in our system:"<<endl;
        // search the rank list and cout
        sort(rank.begin(), rank.end());
        // ascending
//        for(pair<int,string> item: rank){
//            cout << item.second <<"  "<< item.first<<endl;
//        }
        // descending
        for(int i = static_cast<int>(rank.size())-1 ; i >= 0 ; i--){
            cout << rank[i].second <<"  "<< rank[i].first<<endl;
        }
    }
}
// bonus 3 : wild card search
void InvertedIndex::searchWide(const string& word){
    // target is the wild card word
    int length =static_cast<int>(word.size())-1;
    string target = word.substr(0,length);
    
    map<string,int> temp;
    vector<pair<int,string>> rank;
    
    // search the Index to find wild card word
    map<string,vector<Node>>::iterator iter;
    iter=Index.begin();
    while(iter!=Index.end()){
        string cursor = iter->first;
        // check whether the word cursor is satisfied with the wild card condition
        if(cursor.size()<length){
            iter++;
            continue;
        }
        if(cursor.substr(0,length) == target){
            for(Node item : Index[cursor]){
                // check whether fileName already exist in the
                if(temp.find((item.getfileName())) != temp.end()){
                    temp[item.getfileName()] += item.getCount();
                }else{
                    temp[item.getfileName()] = item.getCount();
                }
            }
        }else{
            // the word cursor is not satisfied with the wild card condition, go to next one
        }
        iter++;
    }
    if(temp.empty()){
        cout <<"wild card \""<<word<<"\" is not in the system."<<endl;
    }else{
        cout <<"wild card \""<<word<<"\" exists in the system."<<endl;
        // search the temp and convert it into rank list
        map<string,int>:: iterator iter2;
        iter2 = temp.begin();
        while(iter2!=temp.end()){
            //cout << iter->second<<iter->first;
            rank.push_back(make_pair(iter2->second, iter2->first));
            iter2++;
        }
        // search the rank list and cout
        sort(rank.begin(), rank.end());
        // ascending
    //        for(pair<int,string> item: rank){
    //            cout << item.second <<"  "<< item.first<<endl;
    //        }
        // descending
        for(int i = static_cast<int>(rank.size())-1 ; i >= 0 ; i--){
            cout << rank[i].second <<"  "<< rank[i].first<<endl;
        }
    }
}
