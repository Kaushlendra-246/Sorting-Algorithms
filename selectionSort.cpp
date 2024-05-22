#include<iostream>
using namespace std;

// void selectionSort(int arr[],int n){
//         for(int i=0; i<=n-2; i++){
//             int min = i;
//             //Select minimum index
//             for(int j=i; j<=n-1; j++){
//                 if(arr[j] < arr[min]) min = j;
//             }
//             //Swap
//             int temp = arr[i];
//             arr[i] = arr[min];
//             arr[min] = temp;
//         }
//     }

//Using Recursion
void selectionSort(int arr[],int start,int n){
    if(start >= n) return;

    int min = start;
        //Select minimum index
        for(int j=start; j<=n-1; j++){
            if(arr[j] < arr[min]) min = j;
        }
        //Swap
        int temp = arr[start];
        arr[start] = arr[min];
        arr[min] = temp;

    selectionSort(arr,start+1,n);
}

int main(){
    int arr[] = {2,4,1,7,0,5,8,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr,0,n); //push minimum at the front

    cout << "Sorted Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}