#include<iostream>
using namespace std;

int placePivot(int arr[],int left,int right){
    int pivot = arr[left]; //here we take left as pivot
    int i = left, j = right;
    while(i<j){
        while(arr[i] <= pivot && i <= right-1) i++;
        while(arr[j] > pivot && j >= left+1) j--;
        if(i<j) swap(arr[i],arr[j]); 
    }
    swap(arr[left],arr[j]);
    return j;
}

void quickSort(int arr[],int left,int right){
    if(left < right){ //Array have more then one element
        int partitionIdx = placePivot(arr,left,right);
        quickSort(arr,left,partitionIdx-1);
        quickSort(arr,partitionIdx+1,right);
    }
}

int main(){
    //int arr[] = {2,6,4,3,1,8,0,7,4,63,42,2,45,55,34,21};
    int arr[] = {5,3,2,1,7,6,8,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Given Array : "; 
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;

    quickSort(arr,0,n-1);

    cout << "Sorted Array : "; 
    for(auto it : arr){
        cout << it << " ";
    }
}