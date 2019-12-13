//
//  main.cpp
//  sf11
//
//  Created by Jason Ha on 12/13/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <vector>
#include <string>
using namespace std;
//char func(char c1){
//    if(isalpha(c1)){
//        return;
//    }
//    if(isupper(c1))
//        return tolower(c1);
//}

int main(int argc, const char * argv[]) {
    string A = "ABCCBA";
    string B = "ABCDEF";
    string C{A};
    reverse(A.begin(), A.end());
    cout << (A==C) <<endl ;
    
    vector<char> D{'A','B','C'};
    vector<char> res;
    //copy_if( D.begin(), D.end(), res.begin(), [](auto i){return isalpha(i)? tolower(i): ' ';)};
    
    return 0;
}
