#include<iostream>
#include<fstream>
using namespace std;


int main(){
    
    ifstream file("compressedMsg.txt");

    bitset<1> bit;
    char c;
    while (file.get(c)){
    unsigned char flags = (unsigned char) c;
        for (int i = 7; i >= 0; --i){
                cout << ((flags >> i) & 0x1);
            }
        }
    
    }