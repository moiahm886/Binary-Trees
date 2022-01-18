#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* newnode(Node* root, int val)
{
	Node* NewNode = new Node();
	NewNode->data = val;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
}
Node* insertion(Node* root, int val)
{
	if (root == NULL)
	{
		root = newnode(root, val);
		return root;
	}
	else
	{
		if (root->data > val)
		{
			root->left = insertion(root->left, val);
		}
		else if (root->data < val)
		{
			root->right = insertion(root->right, val);
		}
		else
		{
			cout << "Value already exists in tree\n";
		}
	}
	return root;
}
Node * minimumvalue(Node* root)
{
	struct Node* current=root;
	while (current && current->left!=NULL)
	{
		current = root->left;
	}
	return current;
}
Node* deletion(Node* root, int key)
{
	if (root == NULL)
	{
		return root;
	}
	if (key < root->data)
	{
		root->left = deletion(root->left, key);
	}
	else if (key > root->data)
	{
		root->right = deletion(root->right, key);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			return NULL;
		}
		else if (root->left == NULL)
		{
			struct Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		struct Node* temp = minimumvalue(root->right);
		root->data = temp->data;
		root->right = deletion(root->right, temp->data);
	}
	return root;

}

void display(Node* root)
{
	if (root == NULL)
	{

		return;
	}
	else
	{
		display(root->left);
		cout << root->data << "\t";
		display(root->right);
	}
}

int main()
{
	Node* root = NULL;
	root = insertion(root, 34);
	root = insertion(root, 52);
	root = insertion(root, 21);
	root = insertion(root, 9);
	root = insertion(root, 89);
	display(root);
	cout << endl;
	root = deletion(root, 21);
	display(root);
}