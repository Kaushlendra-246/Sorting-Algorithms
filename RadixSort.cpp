#include<iostream>
#include<limits.h>
using namespace std;

void countSort(int arr[],int n,int pos){
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / pos) % 10]++;
    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];


    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / pos) % 10] - 1] = arr[i];
        count[(arr[i] / pos) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

}

void radixSort(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++) maxi = max(maxi,arr[i]);

    for(int pos = 1; maxi/pos != 0; pos *= 10)
        countSort(arr,n,pos);
}

int main(){
    int arr[] = {2,5,432,1,8,0,6,4,78,212,5,65,4,321};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Given Array : ";
    for(auto i : arr){
        cout << i << " "; 
    }
    cout << endl;

    radixSort(arr,n);

    cout << "Sorted Array : ";
    for(auto i : arr){
        cout << i << " "; 
    }
    cout << endl;
}