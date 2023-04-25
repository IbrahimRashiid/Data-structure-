#include<bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <time.h>
using namespace std;
using namespace std::chrono;

void insertionSort (int A[],int n) {
    int i,j;
    for ( i = 0; i < n; ++i) {
        j=i;
        while (j>0&&A[j-1]>A[j]){
            swap(A[j-1],A[j]);
            j--;
        }
    }
}
int binarySearch(int arr[], int elem,
                 int left, int right)
{
    if (right <= left)
        return (elem > arr[left]) ?
               (left + 1) : left;

    int mid = (left + right) / 2;

    if (elem == arr[mid])
        return mid + 1;

    if (elem > arr[mid])
        return binarySearch(arr, elem,mid + 1, right);
    return binarySearch(arr, elem, left,mid - 1);
}

void binaryInsertionSort(int arr[], int n)
{
    int i, posation, j,  choosed;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        choosed = arr[i];


        posation = binarySearch(arr, choosed, 0, j);


        while (j >= posation)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = choosed;
    }
}


int main()
{

    for (int i = 0; i <5 ; ++i) {

        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=rand()%10000;
        }
   auto start1= high_resolution_clock::now();
   insertionSort(a,n);
    auto end1= high_resolution_clock::now();
    auto durTime1=duration_cast<microseconds>(end1-start1);
   cout<<"The running time in insertion sort is : "<<durTime1.count()<<" microseconds"<<endl;
cout<<"______________________________________________________________________________________"<<endl;
    auto start2= high_resolution_clock::now();
    binaryInsertionSort(a,n);
    auto end2= high_resolution_clock::now();
    auto durTime2=duration_cast<microseconds>(end2-start2);
    cout<<"The running time in binary insertion sort is : "<<durTime2.count()<<" microseconds"<<endl;
        cout<<"______________________________________________________________________________________"<<endl;
}
}