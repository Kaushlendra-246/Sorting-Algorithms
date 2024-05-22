#include<iostream>
using namespace std;

// void bubbleSort(int *arr, int n){  //Best case O(n), otherWise O(n*n)
//     for(int i=0; i<n; i++){
//         int check = 0;
//         for(int j=0; j<n-i-1; j++){
//             if(arr[j] > arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//                 check = 1;
//             }
//         }
//         if(check == 0) break;
//     }
// }

//By Recursion
void bubbleSort(int *arr,int n){
    if(n == 0) return;

    for(int j=0; j<n; j++){
        if(arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }

    bubbleSort(arr,n-1);
}

int main(){
    int arr[] = {2,4,1,7,0,5,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    bubbleSort(arr,n); //push maximum at last

    cout << "Sorted Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}