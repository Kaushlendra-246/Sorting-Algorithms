#include<iostream>
#include<vector>
using namespace std;

void mergArr(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    //1st Arr = low to mid
    //2nd Arr = mid+1 to high
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=0,j=low; i<temp.size(); i++,j++){
        arr[j] = temp[i];
    }
}

void mergSort(vector<int> &arr,int low,int high){
    if(low == high) return;
    int mid = (low + high)/2;
    mergSort(arr,low,mid);
    mergSort(arr,mid+1,high);
    mergArr(arr,low,mid,high);
}

int main(){
    vector<int> arr = {2,5,3,8,0,1,5,8};
    int n = arr.size();

    cout<<"Given Array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "; 
    }
    cout<<endl;
    
    mergSort(arr,0,n-1);
    cout<<"Sorted Array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" "; 
    }
    return 0;
}