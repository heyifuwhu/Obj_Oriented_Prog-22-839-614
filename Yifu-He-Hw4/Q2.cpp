//
//  main.cpp
//  q2
//
//  Created by Jason Ha on 9/28/19.
//  Copyright © 2019 Jason He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> List;
    string name;
    int option;
    while(true){
        cout<<"1.Insert a name\n"<<"2.Delete a name\n"<<"3.Print all name\n"<<"4.Exit"<<endl<<endl;
        cin >> option;
        switch (option) {
            case 1:{
                cout << "Enter a name to insert: ";
                cin >> name;
                List.push_back(name);
                break;
            }
            case 2:{
                cout << "Enter a name to Delete: ";
                cin >> name;
                List.erase(remove(List.begin(),List.end(),name),List.end());
                break;
            }
            case 3:{
                cout << "Stored names: "<< endl;
                for(string elem: List){
                    cout << elem <<" ";
                }
                cout <<"\n\n";
                break;
            }
            case 4:{
                cout <<"Bye"<<endl;
                return 0;
            }
            default:
                break;
        }
    }
}
