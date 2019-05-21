#include<bits/stdc++.h>
using namespace std;

//Implementation of a Linked List

struct Node
{
    int data;
    Node*next;
};

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node *root = NULL;

////////////////////////

//1. Insertion
//Insertion at front
Node* push(int data)
{
    Node *temp = newNode(data);
    temp->data = data;
    temp->next = NULL;
    if(!root)//Empty Linked List
    {
        root = temp;
        return root;
    }
    temp->next = root;
    root = temp;
    return root;
}

//Insertion at end 

Node *append(int data)
{
    Node *newN = newNode(data);
    Node *temp = root;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = newN;
    return root;
}

//Insertion after a given node 

Node *insert(int data, int val)
{
    //We have to insert data after val
    Node *newN = newNode(data);
    Node *temp = root;
    while(temp->next && temp->data!=val)
            temp = temp->next;
    
    if(!temp->next && temp->data != val)
    {
        return NULL;
    }
    else
    {
        newN->next = temp->next;
        temp->next = newN;
    }
    return root;
    
}
//Insertion ends here
/////////////////////////////////////
//2. Deletion
//Deleting first occurence of given key
//DO NOT USE 'delete' as a function name,as it is a keyword
Node *delet(int key)
{
    //key is the value to be deleted
    Node *t1 = root, *t2 = root;
    //t1 is the node to be deleted
    //t2 predecessor to t1
    while(t1 && t1->data != key)
        t1 = t1->next;
    if(!t1)
        return NULL;
    while(t2->next != t1)
        t2 = t2->next;
    t2->next = t1->next;
    free(t1);
        
    
    return root;
}
Node *deleteAt(int pos)
{
    //To delete the element at position denoted by posi
    int count = 1;
    Node *t1 = root, *t2 = root;
    //if posi == 1, we have to delete the first node, and so on 
    while(count < pos && t1)
    {
        t1 = t1->next;
        count++;
    }
    if(!t1)
        return NULL;
    while(t2->next != t1)
        t2 = t2->next;
    t2->next = t1->next;
    free(t1);
    return root;
}

int main()
{
    //root = NULL;
    root = push(1);
    root = push(2);
    root = append(3);
    root  = insert(4,3);
    
    Node *t = root;
    while(t)
    {
        cout<<t->data<<" ";
        t = t -> next;
    }
    cout<<endl;
    root = delet(3);
    //root = append(4);
    root = append(5);
    root = deleteAt(2);
    
    t = root;
    while(t)
    {
        cout<<t->data<<" ";
        t = t -> next;
    }
    return 0;
    
}
