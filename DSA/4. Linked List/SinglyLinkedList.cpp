//#bits/stdc++.h
#include<iostream>
using namespace std;

class node{
    
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* takeInput(){
    int data;
    cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1){
        node* newNode = new node(data);
        if(head == NULL){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

void insertAtPos(node* &head, int i, int data){
    node* newNode = new node(data);
    node* temp = head;
    int count = 0;

    if(i == 0){
        newNode->next = head;
        head = newNode;
    }
    else{

        while(temp!= NULL && count < i-1){
            temp = temp->next;
            count++;
        }

        if(temp != NULL){
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void deleteAtPos(node* &head, int i){
    node* temp = head;
    int count = 0;

    if(i == 0){
        head = head->next;
        delete temp;
    }
    else{

        while(temp!= NULL && count < i-1){
            temp = temp->next;
            count++;
        }

        if(temp != NULL){
            node* front = temp->next;
            if(front!= NULL){
                temp->next = front->next;
                delete front;
            }
            
        }
    }
}

void insertAtHead(node* &head, int data){

    if(head == NULL){
        node* temp = new node(data);
        head = temp;
    }
    else{
        node* newNode = new node(data);
        newNode->next = head;
        head = newNode;
    }
}

void print(node* head){
    node* temp = head;

    while(temp!= NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
}

int main(){
    node* head = takeInput();

    print(head);
    cout<<endl;

    int i, data;
    // cin>>i>>data;
    // insertAtPos(head, i, data);

    cin>>i;
    deleteAtPos(head, i);

    print(head);

    return 0;
}