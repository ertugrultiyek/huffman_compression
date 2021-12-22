#include<iostream>
#include<bitset>
#include<fstream>
using namespace std;
// #include"node.hpp"

void outBuffer(unsigned char *buff, int *count, ifstream &file, bool target){
    *buff <<= 1;
    if(target){
        *buff |= 0b00000001;
    }

    *count = *count +1;
    if (*count == 8){
        file<<*buff;
        *count = 0;
        *buff = 0;
    }
}

int main (){
    ifstream file("compressedMsg.txt");

    unsigned char buff;
    int buffCount=0;

    char c;
    while(file.get(c)){
        for (int i = 7; i>=0; i--){
            outBuffer(&buff, &buffCount, file, (c >> i) & 1);
        }
    }
    return 0;
}