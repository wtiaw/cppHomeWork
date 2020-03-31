#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

typedef struct node {
	string data;
	struct node* left;
	struct node* right;
}Node;

typedef struct tree {
	Node* root;
}Tree;

void CreatTree(Node* &node) {
	Node* p;
	stack<Node*> sta;
	int k;

	node = NULL;
	string str;
	str = "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))";
	//cin >> str;
	for (unsigned i = 0; i < str.size(); i++) {
		switch (str[i])
		{
		case '(':
			sta.push(p);
			k = 1;
			break;
		case ')':
			sta.pop();
			break;
		case ',':
			k = 2;
		default:
			p = new Node;
			p->data = str[i];
			p->left = p->right = NULL;
			if (node == NULL)
				node = p;
			else {
				switch (k)
				{
				case 1:
					sta.top()->left = p;
					break;
				case 2:
					sta.top()->right = p;
					break;
				default:
					break;
				}
			}
			break;
		}
	}
}

void InOrder(Node* node) {
	if (node != NULL) {
		InOrder(node->left);
		cout << node->data;
		InOrder(node->right);
	}
}

void PreOrder(Node* node) {
	if (node != NULL) {
		cout << node->data;
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void PostOrder(Node* node) {
	if (node != NULL) {
		PostOrder(node->left);
		PostOrder(node->right);
		cout << node->data;
	}
}

int Height(Node* node) {
	if (node == NULL)
		return 0;
	int l = Height(node->left);
	int r = Height(node->right);
	cout << node->data << " " << l << " " << r << endl;
	return l > r ? l + 1 : r + 1;

}

Node* Find(Node* node,string goal) {
	Node* p;
	if (node == NULL)
		return NULL;
	else if(node->data == goal)
		return node;
	else{
		p = Find(node->left,goal);
		if (p != NULL)
			return p;
		else
			return Find(node->right,goal);
	}
}

Node* lchild(Node* node) {
	return node->left;
}

Node* rchild(Node* node) {
	return node->right;
}

void Destroy(Node* node) {
	if (node != NULL) {
		Destroy(node->left);
		Destroy(node->right);
		free(node);
	}
}

int main() {
	Tree* tree = new Tree;

	CreatTree(tree->root);

	cout << "先序遍历：";
	PreOrder(tree->root);
	cout << endl;

	cout << "中序遍历：";
	InOrder(tree->root);
	cout << endl;

	cout << "后序遍历：";
	PostOrder(tree->root);
	cout << endl;

	cout << lchild(Find(tree->root, "H"))->data << endl;
	cout << rchild(Find(tree->root, "H"))->data << endl;

	cout << Height(tree->root);

	Destroy(tree->root);

	system("pause");
	return 0;
}