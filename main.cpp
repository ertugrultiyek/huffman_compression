#include<iostream>
#include<fstream>
#include<bitset>
#include "tree.hpp"
#include "input.cpp"
#include "encode.cpp"
using namespace std;



int main(){

    string inputStr = "bu 78 karakterden olusan bir stringdir. ascii ile kodlanmis boyutu 632 bitdir.";    // get input data


    freq chrArr[inputStr.size()];
    int len = getInput(chrArr, inputStr);   // get number of unique characters and frequency of them

    Tree agac =  Tree(chrArr, len);         // construct a binary tree to encode the data

    ofstream compressed;
    compressed.open("compressedMsg.bin", ios::app | ios::binary);    // open the output file

    enc table[len];
    int count = 0;
    agac.serializeTree(compressed, agac.root, table, &count, 0, 0b00000000);              // serialize the tree for decoding
    
    cout<<endl<<endl;

    for (int i = 0; i<inputStr.size(); i++){
        encodeMsg(compressed, table, count, inputStr[i]);
    }
    return 0;
}