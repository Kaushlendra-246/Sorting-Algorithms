#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
        for(int i=0; i<n; i++){
            int j=i;
            while(j>0 && arr[j]<arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
        }
    }

int main(){
    int arr[] = {2,4,1,7,0,5,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr,n); //Take a element and swap it with just before element till it not reach correct position
    //Best case O(n), otherWise O(n*n)

    cout << "Sorted Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}