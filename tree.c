#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};q	
typedef struct node tree;
tree *root=NULL;
void insert(int e)
{
	tree *p, *x;
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->data=e;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		p=root;
		while(p!=NULL)
		{
			x=p;
			if(p->data<e)
			{
				p=p->right;
			}
			else
			{
				p=p->left;
			}
		}
		if(x->data<e)
		{
			x->right=(tree *)malloc(sizeof(tree));
			x->right->data=e;
			x->right->left=NULL;
			x->right->right=NULL;
		}
		else
		{
			x->left=(tree *)malloc(sizeof(tree));
			x->left->data=e;
			x->left->left=NULL;
			x->left->right=NULL;
		}
	}
}
void delete(int e)
{
	tree *p, *x, *t;
	p=NULL;
	x=root;
	while(x!=NULL)
	{
		if(x->data==e)
		{
			break;
		}
		else if(x->data>e)
		{
			p=x;
			x=x->left;
		}
		else if(x->data<e)
		{
			p=x;
			x=x->right;
		}
	}
	if(x==NULL)
	{
		printf("Element not found");
	}
	else
	{
		if(x->left==NULL && x->right==NULL)
		{
			if(x==root)
			{
				root=NULL;
			}
			else if(p->right==x)
			{
				p->right=NULL;
			}
			else 
			{
				p->left=NULL;
			}
		}
		else if(x->left==NULL || x->right==NULL)
		{
			if(x==root)
			{
				root=(x->right!=NULL)?x->right:x->left;
			}
			else if(p->left==x)
			{
				if(p->left->left!=NULL)
				{
					p->left=x->left;
				}
				else
				{
					p->left=x->right;
				}
			}
			else if(p->right==x)
			{
				if(p->right=x->right)
				{
					p->right=x->right;
				}
				else
				{
					p->right=x->left;
				}
			}
		}
		else
		{
			tree *t=x->right;
			while(t->left!=NULL)
			{
				t=t->left;
			}
			delete(t->data);
			x->data=t->data;
		}
	}
}
void inorder(tree *t)
{
	inorder(t->left);
	printf("%d" ,t->data);
	inorder(t->right);
}
void main()
{
	insert(20);
	insert(22);
	inorder(root);
	delete(20);
}
