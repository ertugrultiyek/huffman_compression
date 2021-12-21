typedef struct {
    char c;
    int f;
} freq;

freq* str;
int len=0;

void swap(freq* a, freq* b) 
{ 
    char c = a->c;
    int f = a->f; 
    a->c = b->c; 
    a->f = b->f; 
    b->c = c; 
    b->f = f; 
} 

int partition ( int low, int high) 
{ 
    int pivot = str[high].f; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (str[j].f < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&str[i], &str[j]); 
        } 
    } 
    swap(&str[i + 1], &str[high]); 
    return (i + 1); 
} 

void quickSort(int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(low, pi - 1); 
        quickSort(pi + 1, high); 
    } 
} 