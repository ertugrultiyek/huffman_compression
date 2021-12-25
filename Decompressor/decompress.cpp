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

    // for(int i = 0; i<21*8; i++){
    //     cout << reader.getCommand(file);
    // }

    Tree agac = Tree(&reader, file);



    cout<<reader.decodeMsg(agac.root, file);


    return 0;
}