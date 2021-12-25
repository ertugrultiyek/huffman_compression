#ifndef BUFFER_H
#define BUFFER_H

#include"node.hpp"
/*
try to make file decleration out of the object
*/

class Buffer{
private:

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

Buffer::Buffer(){
    bitCount = -1;
}

void Buffer::readNext(ifstream &file){
    char temp;
    file.get(temp);
    byte = (unsigned char) temp;
    bitCount = 7;
}

bool Buffer::getCommand(ifstream &file){
    bool cmd;
    if(bitCount<0){
        readNext(file);
    }
    cmd = ((byte >> (bitCount)) & 0x1);
    bitCount--;
    return cmd;
}

char Buffer::getChar(ifstream &file){
    if(bitCount < 0){
        readNext(file);
        bitCount = -1;
        return((char) byte);
    }
    else if(bitCount == 7){
        bitCount = -1;
        return((char) byte);
    }
    unsigned char c = 0;
    for(int i = 7; i>=0; i--){
        if(bitCount <0){
            readNext(file);
        }
        if(((byte >> (bitCount)) & 0x1))
            c |= 1 << i;
        else
            c &= ~(1 << i);
        bitCount--;
    }
    return((char) c);
}

char Buffer::decodeChr(Node *root, ifstream &file){
    if(root == nullptr){
        return 'e';
    }
    if(root->left==nullptr){
        return root->item;
    }
    if(getCommand(file))
        return decodeChr(root->right, file);
    else
        return decodeChr(root->left, file);
}

string Buffer::decodeMsg(Node *root, ifstream &file){
    string msg = "";
    for(char c = decodeChr(root, file); (int)c != 0; c = decodeChr(root, file)){
        msg += c;
    }
    return msg;
}

#endif