#include<iostream>
#include<fstream>
#include "tree.hpp"
#include "input.cpp"
using namespace std;

ofstream compressed;

int main(){

    string inputStr = "input string sikistirilacak";    // get input data


    freq chrArr[inputStr.size()];
    int len = getInput(chrArr, inputStr);   // get number of unique characters and frequency of them

    Tree agac =  Tree(chrArr, len);         // construct a binary tree to encode the data

    compressed.open("compressedMsg.txt", ios_base::app);    // open the output file
    agac.serializeTree(agac.root);              // serialize the tree for decoding

    return 0;
}