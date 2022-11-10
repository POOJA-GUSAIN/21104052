#include<iostream>
using namespace std;
int comparisons=0;
int swaps=0;

void swapping(int &a, int &b) {        
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void selectionSort(int *array, int size) {
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i;  
      for(j = i+1; j<size; j++){
         if(array[j] < array[imin])
            {imin = j;}
            comparisons++;
      }
         swap(array[i], array[imin]);
         if(imin!=i){swaps ++;}
   }
}
int main() {
   int n;
   cin >> n;
   int arr[n];          
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   display(arr, n);
   selectionSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
   cout<<"total number of comparisons are "<<comparisons<<endl;
   cout<<"total swappings are "<<swaps<<endl;
}
// Selecting the lowest element requires to see all n elements (hence, n − 1 comparisons) and then swapping it into the first position. 
//Finding the next lowest element requires to see the remaining n − 1 elements and so on
//hence we get totsl of (n − 1) + (n − 2) + ... + 2 + 1 = n(n − 1) / 2 comparisons.
