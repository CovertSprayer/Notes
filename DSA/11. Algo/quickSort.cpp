//#bits/stdc++.h
#include<iostream>
using namespace std;

int partition(int arr[], int l, int r){
    int x = arr[l];
    int count =0, n = l+r;
    for (int i = 0; i < n; i++){
        if(x>arr[l+i]){
            count++;
        }
    }
    // for (int i = 0; i < count; i++){
    //     arr[l+i] = arr[l+i+1];
    // }
    
    arr[l] = arr[l+count];
    arr[l+count] = x;
    int target = l+count;

    int i=l, j=r;
    while (i<target && j>target)
    {
        if(arr[i]<x){
            i++;
        }
        else if(arr[j]>x){
            j--;
        }
        else{
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }

    }
    return target;
    
    
    
}

void quickSort(int a[], int l, int r){
    if(l>=r){
        return;
    }

    int c = partition(a, l, r);
    quickSort(a, l, c-1);
    quickSort(a, c+1, r);
}

int main(){
    
    int arr[10]= {2,7,10,3,1,5,0};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}