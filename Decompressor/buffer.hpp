#ifndef BUFFER_H
#define BUFFER_H
/*
try to make file decleration out of the object
*/

class Buffer{
private:

public:
    ifstream file;
    unsigned char byte;
    int bitCount;

    Buffer();
    void readNext();
    bitset<2> getCommand();
    char getChar();
};

Buffer::Buffer(){
    file.open("compressedMsg.txt");
    bitCount = 7;
}

void Buffer::readNext(){
    char temp;
    file.get(temp);
    byte = (unsigned char) temp;
    bitCount = 7;
}

bitset<2> Buffer::getCommand(){
    bitset<2> cmd;
    for (int i = 0; i< 2; i++){
        if(bitCount+1){
            cmd[1-i] = ((byte >> (bitCount-i)) & 0x1);
        }
        else{
            readNext();
            cmd[1-i] = ((byte >> (bitCount-i)) & 0x1);
        }
        bitCount--;
    }
    return cmd;
}

char Buffer::getChar(){
    if(bitCount == 7){
        return((char) byte);
    }
    unsigned char c = 0;
    for(int i = 0; i<8; i++){
        if(bitCount <0){
            readNext();
        }
        if(((byte >> (bitCount-i)) & 0x1))
            c |= 1 << i;
        else
            c &= ~(1 << i);
        bitCount--;
    }
    return((char) byte);
}


#endif