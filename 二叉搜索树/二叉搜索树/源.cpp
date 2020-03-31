#include<iostream>
using namespace std;

typedef struct node
{
	int value;
	struct node* left;
	struct node* right;
}Node;

typedef struct tree
{
	Node* root;
}Tree;

void insert(Tree* tree,int v)
{
	Node* node = new Node;
	node->value = v;
	node->left  = NULL;
	node->right = NULL;

	if (tree->root == NULL)
		tree->root = node;
	else
	{
		Node* p = new Node;
		p = tree->root;
		while (p != NULL)
		{
			if (v > p->value)
			{
				if (p->right == NULL)
				{
					p->right = node;
					return;
				}
				else
					p = p->right;
			}
			if (v < p->value)
			{
				if (p->left == NULL)
				{
					p->left = node;
					return;
				}
				else
					p = p->left;
			}

		}
	}
}

void inorder(Node* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		cout << node->value << " " << endl;
		inorder(node->right);
	}
}

int main()
{
	int arr[7] = { 6,3,8,2,5,1,7 };
	Tree* tree=new Tree;
	tree->root = NULL;
	for (int i = 0; i < 7; i++)
	{
		insert(tree, arr[i]);
	}

	inorder(tree->root);
	system("pause");
	return 0;
}