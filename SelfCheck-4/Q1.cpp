//
//  main.cpp
//  sf4
//
//  Created by Jason Ha on 9/28/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include <random>
#include <iomanip>
#include <array>
#include <ctime>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    default_random_engine generator(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomInt(1,6);
    
    const size_t arraySize(13);
    array<unsigned int,arraySize> freq{};
    array<unsigned int,arraySize> expe{0,0,1,2,3,4,5,6,5,4,3,2,1};
    
    
    for(unsigned int roll{0}; roll < 12'000'000; roll++){
        ++freq[randomInt(generator)+randomInt(generator)];
    }
    cout << setw(5) << "Sum" << setw(10) << "Total" << setw(13) << "Expected" << setw(13) << "Actual" << endl;
    for(size_t num{2}; num<=12; num++){
        cout << setw(5) << num << setw(10) << freq[num] << setprecision(5)<< setw(13) << 100.0 * expe[num] / 36 <<"%" << setprecision(5) << setw(13) << 1.0 * freq[num]/12'000'0<<"%" <<endl;
    }
    return 0;
}
