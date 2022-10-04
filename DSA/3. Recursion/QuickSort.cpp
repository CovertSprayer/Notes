//#bits/stdc++.h
#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){

    int target = arr[s];
    int count = 0;

    for(int i=s+1; i<=e; i++){
        if(target > arr[i])
            count++;
    }

    int targetIndex = s+count;
    swap(arr[s], arr[targetIndex]);

    int i = s, j = e;

    while(i < targetIndex && j > targetIndex){
        while(arr[i] < target){
            i++;
        }

        while(arr[j] >= target){
            j--;
        }

        if(i < targetIndex && j > targetIndex){
            swap(arr[i++] , arr[j--]);
        }
        
    }
    return targetIndex;
}

void quickSort(int arr[], int s, int e){
    if(s>=e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7, 5, 6 };

    quickSort(arr, 0, 7);

    for(int i=0; i<8; i++)
        cout<<arr[i] <<" ";
    return 0;
}