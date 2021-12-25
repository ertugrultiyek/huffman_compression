#include "sources/encode.cpp"



int main(){
    unsigned char buffer = 0x00;
    int buffCount = 0;


    string inputStr = "abcabcddeeabceeeeddee";    // get input data
    inputStr.push_back(0x00);

    ofstream unc;
    unc.open("uncompressed.txt", ios::out);    // open the output file
    unc<<inputStr;
    unc.close();

    freq chrArr[inputStr.size()];
    int len = getInput(chrArr, inputStr);   // get number of unique characters and frequency of them

    Tree agac =  Tree(chrArr, len);         // construct a binary tree to encode the data

    ofstream compressed;
    compressed.open("compressedMsg.txt", ios::out | ios::binary);    // open the output file

    enc table[len];
    int count = 0;
    agac.serializeTree(compressed, agac.root, table, &count, 0, 0b00000000, &buffer, &buffCount);              // serialize the tree for decoding


    for (int i = 0; i<inputStr.size(); i++){
          encodeMsg(compressed, table, count, inputStr[i], &buffer, &buffCount);
    }
		if(buffCount != 0){
			for(int i = 8-buffCount; i>=1; i--){
				outBuffer(&buffer, &buffCount, compressed, false);
			}
		}
    compressed.close();
    return 0;
}
