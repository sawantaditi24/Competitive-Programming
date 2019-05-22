#include<bits/stdc++.h>
using namespace std;

//////////////////////////////////
//Implementation of BST
struct Node
{
    int data;
    Node *l, *r;
};

struct Node *root = NULL;

Node * newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->l = temp->r = NULL;
    return temp;
}


//1. Insertion

Node *insert(Node* root, int data)
{
    Node *temp = newNode(data);
    if(!root)
    {
        root = temp;
        return root;
    }
    if(data < root->data)
        root->l = insert(root->l, data);
    else
        root->r = insert(root->r, data);
    return root;    
}
//////////////////

//2. In Order

void inOrder(Node* root)
{
    if(root)
    {
        inOrder(root->l);
        cout<<root->data<<" ";
        inOrder(root->r);
    }
}
///////////////////////

//3. Search

bool search(Node *node, int key)
{
    if(!node)
        return false;
    if(node->data == key)
        return true;
    if(key < node->data)
        return search(node->l, key);
    else
        return search(node->r, key);
}
////////////

//Deletion
Node *inSuc(Node *node)
{
    Node *c = node;
    while(c && c->l)
    {
        c = c->l;
    }
    return c;
}

Node *delet(Node *node, int key)
{
    if(!node)
        return node;
    if(key < node->data)
        node->l = delet(node->l, key);
    else if(key > node->data)
        node->r = delet(node->r, key);
    /*
    else//node->data == key
    {
        if(!node->l)
        {
            Node *temp = node->r;
            free(node);
            return temp;
        }
        else if(!node->r)
        {
            Node *temp = node->l;
            free(node);
            return temp;
        }
        //If control has come here, that means that the node to be deleted has both r and l children
        //Therefore the node will be replaced by the inOrder successor, 
        //which is the leftmost element of the right subtree
        Node *temp = inSuc(node->r);
        node->data = temp->data;
        node->r = delet(node->r, temp->data);
        //So technically, the node to be deleted is still present, however its data has been modified
        //So it looks like it has been deleted, which works for us 
    }
     */
    else
    {
        Node *succParent = node->r;
        Node *succ = node->r;
        while(succ->l && succ)
        {
            succParent = succ;
            succ = succ->l;
        }
        succParent->l = succ->r;
        node->data = succ->data;
        delete succ;
        return node;
    }
    return node;
}
//Main Method
int main()
{
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 4);
    cout<<"In Order traversal: "<<endl;
    inOrder(root);
    cout<<endl;
    if(search(root, 2))
        cout<<"2 exists in the tree."<<endl;
    root = delet(root, 2);
    inOrder(root);
    return 0;
}
