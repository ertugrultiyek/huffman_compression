void encodeMsg(ofstream &file, enc *table, int len, char target){
    for (int i = 0; i<len; i++){
        if(target == table[i].c){
            for(int j = table[i].len-1; j>=0; j--)
            file<<table[i].code[j];
        }
    }
    return;
}