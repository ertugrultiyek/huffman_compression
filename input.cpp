// #include<iostream>
// using namespace std;


//  int len=0;

void swap(freq* a, freq* b) 
{ 
    char c = a->c;
    int f = a->f; 
    a->c = b->c; 
    a->f = b->f; 
    b->c = c; 
    b->f = f; 
} 

int partition (freq *chr, int low, int high) 
{ 
    int pivot = chr[high].f; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (chr[j].f < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&chr[i], &chr[j]); 
        } 
    } 
    swap(&chr[i + 1], &chr[high]); 
    return (i + 1); 
} 

void quickSort(freq *chr, int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(chr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(chr, low, pi - 1); 
        quickSort(chr, pi + 1, high); 
    } 
} 

int getFreq(freq *chr, string inputStr){
    int chrCount = 0;
    for (int i = 0; i<inputStr.size(); i++){
        cout<<inputStr[i];
        bool flg = false;
        for(int j = 0; j<= chrCount; j++){
            if(chr[j].c == inputStr[i]){
                chr[j].f++;
                flg = true;
            }
        }
        if(!flg){
            chr[chrCount].c = inputStr[i];
            chr[chrCount].f = 1;
            chrCount++;
        }
    }
    cout<<endl;
    return chrCount;
}

int getInput(freq* chr, string inputStr){

    int chrCount = getFreq(chr, inputStr);

    quickSort(chr, 0, chrCount-1);

    return chrCount;
}