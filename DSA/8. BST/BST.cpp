//#bits/stdc++.h
#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node* left; 
    Node* right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

};

Node* minValue(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

void printTree(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    if(root->left!= NULL)
    cout<<"L"<<root->left->data;

    if(root->right!= NULL)
    cout<<"R"<<root->right->data;
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

vector<int> morrisTraversal(Node* root){
    vector<int> inOrder;
    Node* curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            inOrder.push_back(curr->data);
            curr = curr->right;
        }
        else{

            Node* prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }

            else{
                inOrder.push_back(curr->data);
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return inOrder;
}

Node* insertIntoBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
    
}

Node* deleteFromBST(Node* root, int data){
    if(root == NULL){
        return root;
    }

    if(data == root->data){

        if(root->left == NULL && root->right == NULL){
            Node* temp = NULL;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

       if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        if(root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }

    else if(data > root->data){
        root->right = deleteFromBST(root->right, data);
        return root;
    }

    else{
        root->left = deleteFromBST(root->left, data);
        return root;
    }
    
}

//10 8 21 7 27 5 4 3 -1

int main(){
    
    Node* root = NULL;

    takeInput(root);
    printTree(root);
    cout<<endl << "minValue: "<<minValue(root)->data;
    cout<<endl << "maxValue: "<<maxValue(root)->data;
    cout<<endl<<endl;
    deleteFromBST(root, 7);
    printTree(root);
    cout<<endl;

    vector<int> morrisInOrder = morrisTraversal(root); 

    for(auto i: morrisInOrder){
        cout<<i<<" ";
    }
    return 0;
}