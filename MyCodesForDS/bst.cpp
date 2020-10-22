#include<iostream>
using namespace std;
class node 
{
	public:
	int data;
	node *lchild,*rchild;
	node();

};

node::node()
{
	lchild=NULL;
	rchild=NULL;

}
class bst
{
	node *root;
	public:
	bst()
	{
		root=NULL;
	}
	
	void create();
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	void smallest();
	void greatest();
	int height(node *);
	void search(node *,int);
	node* getroot();
	node* mirror(node *);

};

node* bst::getroot()
{
	return getroot();
}
void bst::create()
{
	char ans;
	node *temp;
	
	do
	{
		temp=new node();
		cout<<"Enter data:";
		cin>>temp->data;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			node *trav,*parent;
			trav=root;
			parent=trav;
			
			while(trav!=NULL)
			{
				if(temp->data<trav->data)
				{
					parent=trav;
					trav=trav->lchild;
				}
				else
				{
					parent=trav;
					trav=trav->rchild;
				
				}
			
			}
			if(temp->data<parent->data)
			{
				parent->lchild=temp;
			}
			else
			{
				parent->rchild=temp;
			}
		}
		cout<<"Add another(y/n)";
		cin>>ans;
		


	
	
	}while(ans=='y'||ans=='Y');

}

void bst::inorder(node *n)
{
	if(n!=NULL)
	{
		cout<<n->data<<" ";
		inorder(n->lchild);
		inorder(n->rchild);
	
	}

}

void bst::preorder(node *n)
{
	if(n!=NULL)
	{
		cout<<n->data<<" ";
		inorder(n->lchild);
		inorder(n->rchild);
	
	}

}

void bst::postorder(node *n)
{
	if(n!=NULL)
	{
		inorder(n->lchild);
		inorder(n->rchild);
		cout<<n->data<<" ";
	
	}

}

void bst::smallest()
{
	node *temp;
	temp=root;
	while(temp->lchild!=NULL)
	{
		temp=temp->lchild;
	}
	cout<<"The smallest element is:"<<temp->data<<" ";
}

void bst::greatest()
{
	node *temp;
	temp=root;
	while(temp->rchild!=NULL)
	{
		temp=temp->rchild;
	}
	cout<<"The greatest element is:"<<temp->data<<" ";

}

int bst::height(node *n)
{
	if(n==NULL)
	{
		return 0;
	}
	int lheight=height(n->lchild);
	int rheight=height(n->rchild);
	if(lheight>rheight)
	{
		return (1+lheight);
	}
	else
	{
		return (1+rheight);
	}
}



void bst::search(node *n,int temp)
{
	if(n!=NULL)
	{
		if(temp<n->data)
		{
			search(n->lchild,temp);
		}
		else if(temp>n->data)
		{
			search(n->rchild,temp);
		}
		else
		{
			cout<<"Entered element found";
		}
	
	
	}
	else
	{
		cout<<"Element not found";
	}
}node *bst::mirror(node *n)
{
	if(n==NULL)
	{
		return 0;
	}
	else
	{
		node *temp;
		mirror(n->lchild);
		mirror(n->rchild);
		
		temp=n->lchild;
		n->lchild=n->rchild;
		n->rchild=temp;
		
		return n;
		
	
	
	}



}


int main()
{
	bst s;
	int ch,a,temp;
	char ans;
	do
	{
		cout<<"1. Create BST 2.Inorder 3.Preorder 4.Postorder 5.Smallest 6.Greatest 7.Height of tree 8.Mirror 9.Search";
		cin>>ch;
		switch(ch)
		{
		case 1:
		{
			s.create();
			break;
		}
		case 2:
		{
		cout<<"Inorder:";
		s.inorder(s.getroot());
		break;
		
		}
		case 3:
		{
		cout<<"Preorder:";
		s.preorder(s.getroot());
		break;
		
		}
		case 4:
		{
			cout<<"Postorder:";
			s.postorder(s.getroot());
			break;
		}
		case 5:
		{
			s.smallest();
			break;
		}
		case 6:
		{
			s.greatest();
			break;
		}
		case 7:
		{
			a=s.height(s.getroot());
			cout<<"Height of the tree is:"<<a;
			break;
		}
		case 8:
		{
			s.mirror(s.getroot());
			s.inorder(s.getroot());
			break;
		}
		case 9:
		{
		cout<<"Enter element to be searched:";
		cin>>temp;
		s.search(s.getroot(),temp);
		break;
		
		}
		}
		cout<<"Do you want to continue";
		cin>>ans;
	
	
	
	
}while(ans=='y');
	
	
	}

	











