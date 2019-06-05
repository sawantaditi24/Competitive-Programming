#include <bits/stdc++.h>
using namespace std;

//Level order traversal

void LOT(Node *root)
{
    if(!root)
      return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *t = q.top();
        q.pop();
        cout<<t->data<<" ";
        if(t->l)
            q.push(t->l);
        if(t->r)
            q.push(t->r);
    }

}

//Reverse Level Order Traversal

void RLOT(Node* root)
{
    stack<Node *>s;
    queue<Node *>q;
    q.push(root);
    Node *t;
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        s.push(t);
        if(t->l)
            q.push(t->l);
        if(t->r)
            q.push(t->r);
    }
    while(!s.empty())
    {
        t = s.top();
        s.pop();
        cout<<t->data<<" ";
    }
}

//Recursive implementation of Spiral Order Traversal of a BT 
//Takes O(N^2)
int height(Node *node)
{
    if(!node)
        return 0;
    int l = height(node->l);
    int r = height(node->r);
    if(l > r)
        return l+1;
    return r + 1;
}

void printSpiral(Node *root)
{
    int h = height(root);
    bool ltr = false;
    for(int i = 1 ; i <= h ; ++i)
    {
        pGL(root, i, ltr);
        ltr = !ltr;
    }
}

void pGL(Node *root, int level, bool ltr)
{
    if(!root)
        return;
    if(level == 1)
        cout<<root->data<<" ";
    else if(level > 1)
    {
        if(ltr)
        {
            pGL(root->left, level - 1, ltr);
            pGL(root->right, level - 1. ltr);
        }
        else
        {
            pGL(root->right, level - 1 , ltr);
            pGL(root->left, level - 1, ltr);
        }
    }
}

//Iterative implementation of Spiral Order Traversal
//Can be done in O(n) time and O(n) extra space 

void printSpiralIterative(Node *root)
{
    if(!root)
        return;
    stack<Node*>s1, s2;
    //s1 is for R-L
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);
        }
        while(!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                s1.push(temp->left);
        
            if(temp->right)
                s1.push(temp->right);
        }
    }
}

/////////////////////////

//InOrder traversal of Binary tree without using recursion

vector<int> InOrder(Node *root)
{
    vector<int> sol;
    stack<Node*> s;
    Node *curr = root;
    bool done = false;
    while(!done)
    {
        if(curr)
        {
            s.push(curr);
            curr = curr->l;
        }
        else
        {
            if(!s.empty())
            {
                curr = s.top();
                s.pop();
                sol.push_back(curr->val);
                curr = curr->r;
            }
            else
                done = 1;
                //If stack goes empty, it means the tree has been traversed
        }
    }
}

///
//Post Order traversal of a tree without recursion using 2 stacks

//Post Order traversal using 2 stacks

void POI(Node *root)
{
    if(!root)
        return;
    stack<Node*> s1, s2;
    s1.push(root);
    Node *t;
    while(!s1.empty())
    {
        t = s1.top();
        s1.pop();
        s2.push(t);
        if(t->l)
            s1.push(t->l);
        if(t->r)
            s1.push(t->r);
    }
    while(!s2.empty())
    {
        t = s2.top();
        s2.pop();
        cout<<t->data<<" ";
    }
}

//Leftmost and Rightmost Nodes at each level of BT 

void printCorner(Node* root)
{
    if(!root)
        return;
        
    queue<Node *>q;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0 ; i < n ; i++)
        {
            Node *temp = q.front();
            q.pop();
            if(i == 0 || i == n-1)
                ans.push_back(temp->key);
            if(temp->left)
                q.push_back(temp->left);
            if(temp->right)
                q.push_back(temp->right);
        }
    }
    for(auto i: ans)
        cout<<i<<" ";
}


///////////////////////////////////////

//Count number of leaf nodes recursively in BT 

int getLeaf(Node* node)
{
    if(!node)
        return 0;
    if(!node->l && !node->r)
        return 1;
    else
        return (getLeaf(node->l) + getLeaf(node->r));
}
/////////

//Average of levels in BT 

void avg(Node *root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int sum = 0, count = 0;
        queue<Node*> temp;
        while(!q.empty())
        {
            Node *n = q.front();
            q.pop();
            sum += n->val;
            count++;
            if(n->l)
                temp->push(n->l);
            if(n->r)
                temp->push(n->r);
        }
        q = temp;
        cout<<sum*1.0/count<<" ";
    }
}

//Deleting a BT without recursion
//Delete is a key word so don't use it as variable or function name
void delTree(Node *root)
{
    if(!root)
        return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
        free(node);
    }
}


