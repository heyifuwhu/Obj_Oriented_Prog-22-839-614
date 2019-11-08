//
//  FileAccess.hpp
//  hw3
//
//  Created by Jason Ha on 10/24/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#ifndef FileAccess_hpp
#define FileAccess_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
#include <fstream>
using namespace std;

// read the directory of the folder and get all the file name 
void generateFileName();
// read the fileName.txt and return a vector of paths.
vector<string> getFileName(string path);

#endif /* FileAccess_hpp */
