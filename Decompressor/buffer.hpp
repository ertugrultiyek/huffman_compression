#ifndef BUFFER_H
#define BUFFER_H

#include<iostream>
#include<bitset>
#include<fstream>
using namespace std;

class Buffer{
private:

public:
    unsigned char buff;
    ifstream file;

    Buffer();
    // void readNext();
    // bitset<2> getCommand();
    // char getChar();
};

Buffer::Buffer(){
    file.open("compressed.txt");
    cout<<file.tellg();
}

// void Buffer::readNext(){

// }

// bitset<2> Buffer::getCommand(){

// }

// char Buffer::getChar(){

// }






#endif