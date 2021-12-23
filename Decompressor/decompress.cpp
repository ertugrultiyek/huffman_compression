#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#include"buffer.hpp"
#include"Tree.hpp"


int main(){
    ifstream file;
    file.open("compressedMsg.txt");
    Buffer reader = Buffer();

    Tree agac = Tree(&reader, file);

    // cout<<reader.decodeChr(agac.root, file);

    return 0;
}