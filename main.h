/*
*  UCF COP3330 Fall 2021 Assignment 5 Solution
*  Copyright 2021 Gabriel Mousa
*/
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;

class Name_Value {
    public:
        int value;
        char name[256];
};

//function declarations
bool checker(vector<Name_Value> vals, char target[256]);
void print_all(vector<Name_Value> vals);

int main() {
    //Create the vars
    vector<Name_Value> vals;
    char tempName[256] = "";
    int tempVal = -1;

    //Checking for the termination 
    while((strncmp(tempName, "NoName",6) != 0) && (tempVal != 0)){

        cin >> tempName >> tempVal; //take in values
        
        
        Name_Value x; 
        x.value = tempVal;
        strcpy(x.name, tempName);
        if(checker(vals, tempName)){
            vals.push_back(x);
        }
    }
    vals.pop_back();

    print_all(vals);


} 

bool checker(vector<Name_Value> vals, char target[256]){
    //returns false and exists program if you were able to find the target string in the vector, otherwise true

    for(int i = 0; i < vals.size(); i++){
        if(strncmp(vals.at(i).name, target, 255) == 0){
            //If you find the target name exit the program with an error message.
            cout << "That name has already been entered";
            exit(EXIT_SUCCESS);
            return false; //Redundant but leaving it in anyways
        }
    }
    return true;
}

void print_all(vector<Name_Value> vals){
    //Prints all the elemnts from a vector

    for(int i = 0; i < vals.size(); i++){
        cout << vals.at(i).name << " " << vals.at(i).value << "\n";
    }

}