//#bits/stdc++.h
#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode* left ;
    BinaryTreeNode* right ;

    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

// self written
void printTree(BinaryTreeNode<int>* root){
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

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop(); 

        int leftChildData;
        cout<<"Enter left Child data of "<< front->data <<": ";
        cin>> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        cout<<"Enter right Child data of "<< front->data <<": ";
        int rightChildData;
        cin>> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

int countNodes(BinaryTreeNode<int>* root){
   // int ans =1;
    if(root == NULL){
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return leftCount + rightCount + 1;
}

void postOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void preOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int preS, int preE, int inS, int inE){
    if(inS > inE){
        return NULL;
    }
    int rootData = pre[preS];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
}

// 1 2 3 -1 -1 4 5 -1 -1 -1 -1

int main(){
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    // root->left = node1;
    // root->right = node2;

    BinaryTreeNode<int>* root = takeInput();
    printTree(root);
    // printTree(root);
    // int tNodes= countNodes(root);
    // cout<<endl<<tNodes;
    // delete root;
    
    return 0;
}