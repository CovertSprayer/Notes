//#bits/stdc++.h
#include<iostream>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        size = 0;
    }

    void insert(int val){
        int index = size++;

        arr[index] = val;
        int CI = index;

        while(CI > 0){
            
            int PI = (CI-1)/2;

            if(arr[PI] < arr[CI]){
                swap(arr[PI] , arr[CI]);
                CI = PI;
            }

            else{
                return;
            }
        }

    }

    void deleteFromHeap(){
        if(size == 0){
            return;
        }
        int PI = 0;
        arr[PI] = arr[size-1];
        size--;

        int LCI = 2*PI +1;
        int RCI = 2*PI +2;

        while(LCI < size){
            int MI = PI;
            if(arr[LCI] > arr[MI]){
                MI = LCI;
            }

            if((RCI < size) && (arr[RCI] > arr[MI])){
                MI = RCI;
            }
            if(MI == PI){
                return;
            }

            swap(arr[MI], arr[PI]);
            PI = MI;
            LCI = 2*PI +1;
            RCI = 2*PI +2;

        }
    }

    void print(){
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
    }

    
};

// max heap
void heapify(int arr[], int n, int i){
    int PI = i;
    int LCI = 2*i +1;
    int RCI = 2*i +2;

    while(LCI < n){
        int MI = PI;
        if(arr[MI] < arr[LCI])
            MI = LCI;

        if((RCI < n) && (arr[MI] < arr[RCI]))
            MI = RCI;

        if(MI == PI){
            return;
        }
        swap(arr[MI] ,  arr[PI]);
        PI = MI;
        LCI = 2*PI +1;
        RCI = 2*PI +2;
    }

}

// the arr passed is already head, if not then first create heap
void heapSort(int arr[], int n){

    while(n > 0){
        swap(arr[0], arr[n-1]);
        n--;
        heapify(arr, n, 0);
    }
}

int main(){

    // max heap or priority queue
    priority_queue<int> pq;

    // min heap or priority queue
    priority_queue<int, vector<int>, greater<int>> minPq;

    /*
    heap h;
    h.insert(90);
    h.insert(40);
    h.insert(10);
    h.insert(80);
    h.insert(20);
    h.insert(100);
    h.insert(5);
    cout<<endl;
    h.print();
    h.deleteFromHeap();
    cout<<endl;
    h.print();
    */

    int arr[] = {2, 5, 1, 9, 4, 7};
    int n = 6;

    for(int i=(n/2-1); i>=0; i--)       // why (n/2-1)? coz n/2 nodes are leaf nodes
        heapify(arr, 6, i);
    
    for(int j =0; j<n; j++)
        cout<<arr[j]<<" ";

    heapSort(arr, n);
    cout<<endl;
    for(int j =0; j<n; j++)
        cout<<arr[j]<<" ";
    //cout<<endl<<h.size;
    return 0;
}