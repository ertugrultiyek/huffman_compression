#include<iostream>
#include<fstream>
#include<bitset>
#include "tree.hpp"
#include "input.cpp"
using namespace std;

ofstream compressed;

int main(){

    string inputStr = "input string sikistirilacak";    // get input data


    freq chrArr[inputStr.size()];
    int len = getInput(chrArr, inputStr);   // get number of unique characters and frequency of them

    Tree agac =  Tree(chrArr, len);         // construct a binary tree to encode the data

    enc table[len];
    int count = 0;

    // compressed.open("compressedMsg.txt", ios_base::app);    // open the output file
    agac.serializeTree(agac.root, table, &count, 0, 0b00000000);              // serialize the tree for decoding
    
    cout<<endl<<endl;

    for (int i = 0; i<count; i++){
        cout<< table[i].c << "\t:\t"<<table[i].code<<endl;
    }
    return 0;
}