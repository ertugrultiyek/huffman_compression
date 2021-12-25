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

    string output = reader.decodeMsg(agac.root, file);

    ofstream outFile;
    outFile.open("decompressedMsg.txt", ios::out);
    outFile<<output;
    outFile.close();

    cout<<"MESSAGE:"<<endl<<endl;
    cout<<output;
    cout<<endl<<endl<<"output is saved to file 'decompressedMsg.txt'";
    cout<<endl<<"please hit any key to close the program";
    cin.get();

    return 0;
}