//#bits/stdc++.h
#include<iostream>
using namespace std;



void MERGE(int* &arr, int l, int mid, int r){
    int n = r-l+1, n1 = mid-l+1, n2 = r-mid;
    int temp[n];


    int i = 0, j = mid+1, k = 0;
    while(i<n1 && j<n2){
        if (arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
        
    }
    while (i<n1)
    {
        temp[k++] = arr[i++];
    }
    while (j<n2)
    {
        temp[k++] = arr[j++];
    }


    for (int i = 0; i < n; i++){
        arr[i] = temp[i];
    }

}

void Merge(int a[], int l, int mid, int r){
    int n1 = mid - l +1;
    int n2 = r - mid;

    int a1[n1];
    int a2[n2];

    for (int i = 0; i < n1; i++)
    {
        a1[i] = a[l+i];
    }
    
    for (int i = 0; i < n2; i++)
    {
        a2[i] = a[i+mid+1];
    }
    int i,j,k =l;
    i = j = 0;
    while(i<n1 && j<n2){
        if (a1[i]<a2[j]){
            a[k++] = a1[i++];
        }
        else{
            a[k++] = a2[j++];
        }
        
    }
    while (i<n1)
    {
        a[k++] = a1[i++];
    }
    while (j<n2)
    {
        a[k++] = a2[j++];
    }
    

}




void MergeSort(int a[], int l, int r){
    if (l>=r){
        return;
    }

    int mid = (l+r)/2;
    MergeSort(a, l, mid);
    MergeSort(a, mid+1, r);

    Merge(a,l,mid,r);

}

int main(){
    
    int arr[10]= {2,7,10,3,1,5,0};
    MergeSort(arr, 0, 6);
    for (int i = 0; i < 7; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}