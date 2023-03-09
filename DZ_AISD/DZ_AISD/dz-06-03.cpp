#include <stdio.h>
#include <iostream>

using namespace std;

struct Tree
{
	int data;
	Tree* left;
	Tree* right;

	Tree(int data, Tree* left, Tree* right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};


void PrintTree(Tree* root, int level)
{
	if (root)
	{
		if (root)
		{
			PrintTree(root->right, level + 1);
			for (int i = 0; i < level; i++) cout << "   ";
			cout << root->data << endl;
			PrintTree(root->left, level + 1);
		}
	}
}

bool TreeInsert(Tree* root, int val)
{
	while (root)
	{
		if (val < root->data)
		{
			if (root->left == NULL)
			{
				root->left = new Tree(val, NULL, NULL);
				return true;
			}
			else
				root = root->left;
		}
		if (val > root->data)
		{
			if (root->right == NULL)
			{
				root->right = new Tree(val, NULL, NULL);
				return true;
			}
			else 
				root = root->right;
		}
		if (val == root->data)
		{
			cout << "The value is exist";
			return false;
		}
	}
}

Tree* Poisk(Tree* root, int val)
{
	while (root)
	{
		if (root->data == val) return root;
		if (root->data < val) root = root->right;
		if (root->data > val) root = root->left;
	}
	return NULL;
}

bool DeleteEl(Tree** root, int val)
{
	Tree* root_tmp = *root;
	while (root_tmp)
	{
		Tree* tmp = Poisk(root_tmp, val);
		Tree* tmp_del = NULL;
		if (tmp == NULL) return false;

		if (tmp->left == NULL && tmp->right == NULL)
		{
			delete root_tmp;
			root_tmp = NULL;
			return true;
		}

		if (tmp->left != NULL && tmp->right == NULL)
		{
			Tree* tmp1 = root_tmp->left;
			root_tmp = tmp_del;
			delete tmp_del;
			root_tmp = tmp1;
			return true;
		}
	}
}



int main()
{
	cout << "Input root value: ";
	int x;
	cin >> x;
	Tree* root = new Tree(x, NULL, NULL);
	for (int i = 0; i < 10; i++)
	{
		cout << "Input new value, ¹ " << i << endl;
		cin >> x;
		while (TreeInsert(root, x) == false)
		{
			cout << "This value is exist. Please, input new value" << endl;
			cin >> x;
		}
	}
	PrintTree(root, 3);
	cout << endl << root->data;
	cout << "Input element to delete it" << endl;
	cin >> x;
	DeleteEl(&root, x);
	cout << root->data;
	PrintTree(root, 3);

	return 0;
}