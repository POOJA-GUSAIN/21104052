#include <iostream>
using namespace std;

int comparisons=0;
int swaps=0;

void bubbleSort(int array[], int n)
{

    for (int step = 0; step < n; ++step)
    {

        for (int i = 0; i < n - step; ++i)
        {
            if (array[i] > array[i + 1])
            {

                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swaps++;
            }
            comparisons++;
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "  " << array[i];
    }
    cout << "\n";
}

int main()
{ int n;
   cin >> n;
   int arr[n];          
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   printArray(arr, n);
   cout << "Array after Sorting: ";
   bubbleSort(arr, n);
   printArray(arr, n);
   cout<<"total number of comparisons are "<<comparisons<<endl;
   cout<<"total swappings are "<<swaps<<endl;
}
//In bubble sort, comparisons are only performed between adjacent elements in the array. The elements are swapped if they are in the wrong order.
//Total number of comparisons in bubble sort is (n - 1) + (n - 2) + (n-3) +(n-4) +(n-5) ….....(2) + (1) = n(n - 1)/2 
