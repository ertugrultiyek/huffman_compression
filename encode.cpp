#include<iostream>
#include<fstream>
#include<bitset>
#include "tree.hpp"
#include "input.cpp"
using namespace std;


void outBuffer(unsigned char *buff, int *count, ofstream &file, bool target){
    *buff <<= 1;
    if(target){
        *buff |= 0b00000001;
    }

    *count = *count +1;
    if (*count == 8){
        cout<<*buff;
        file<<*buff;
        *count = 0;
        *buff = 0;
    }
}

void encodeMsg(ofstream &file, enc *table, int len, char target, unsigned char *buff, int *buffCount){
    for (int i = 0; i<len; i++){
        if(target == table[i].c){
            for(int j = table[i].len-1; j>=0; j--)
                outBuffer(buff, buffCount, file, table[i].code[j]);
                // file<<table[i].code[j];
        }
    }
    return;
}

// int main (){

//     bitset<16> bitler = 0xAB73;
//     unsigned char buffer = 0x00;
//     int count = 0;

//     ofstream compressed;
//     compressed.open("compressedMsg.txt", ios::app | ios::binary);    // open the output file

//     for(int i = 15; i>=0; i--){
//         outBuffer(&buffer, &count, compressed, bitler[i]);
//     }
// }