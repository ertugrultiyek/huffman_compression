#ifndef BUFFER_H
#define BUFFER_H

#include"node.hpp"
/*
try to make file decleration out of the object
*/

class Buffer{
public:
    unsigned char byte;
    int bitCount;

    Buffer();
    void readNext(ifstream &file);
    bool getCommand(ifstream &file);
    char getChar(ifstream &file);
    char decodeChr(Node *root, ifstream &file);
    string decodeMsg(Node *root, ifstream &file);
};

#include "buffer.cpp"

#endif