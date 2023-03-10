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

Tree* Poisk_Prev(Tree* root, int val)
{
	while (root)
	{
		if (root->left != NULL && (root->left)->data == val) return root;
		if (root->right != NULL && (root->right)->data == val) return root;
		if (root->data < val) root = root->right;
		else if (root->data > val) root = root->left;
	}
	return NULL;
}

bool DeleteEl(Tree* root, int val)
{
	Tree* tmp = Poisk(root, val);

	if (tmp == NULL) return false;

	if (tmp->left != NULL && tmp->right != NULL)
	{
		Tree* tmp_max = tmp->left;
		int max_val = tmp_max->data;
		while (tmp_max)
		{
			if (tmp_max->data > max_val) max_val = tmp_max->data;
			if (tmp_max->right == NULL) tmp_max = tmp_max->left;
			else tmp_max = tmp_max->right;
		}
		tmp_max = Poisk(tmp, max_val);
		DeleteEl(tmp, max_val);
		tmp->data = max_val;
		return true;
	}

	if (tmp == root)
	{
		if (tmp->left == NULL && tmp->right == NULL)
		{
			delete tmp;
			tmp = NULL;
		}
		//------------------------------------------------------------
		if (tmp->left != NULL && tmp->right == NULL)
		{
			Tree* tmp_del = tmp;
			tmp = tmp->left;
			delete tmp_del;
			tmp_del = NULL;
		}
		if (tmp->left == NULL && tmp->right != NULL)
		{
			Tree* tmp_del = tmp;
			tmp = tmp->right;
			delete tmp_del;
			tmp_del = NULL;
		}
	}

	Tree* prev_tmp = Poisk_Prev(root, val);
	cout << "Prev data:" << prev_tmp->data;

	if (tmp->left == NULL && tmp->right == NULL)
	{
		if ((prev_tmp->left)->data == val)
		{
			prev_tmp->left = NULL;
			delete tmp;
		}
		if ((prev_tmp->right)->data == val)
		{
			prev_tmp->right = NULL;
			delete tmp;
		}
		tmp = NULL;
		return true;
	}
	//------------------------------------------------------------
	if (tmp->left != NULL && tmp->right == NULL)
	{
		if (prev_tmp->data > val) prev_tmp->left = tmp->left;
		if (prev_tmp->data < val) prev_tmp->right = tmp->left;
		delete tmp;
		tmp = NULL;
		return true;
	}
	if (tmp->right != NULL && tmp->left == NULL)
	{
		if (prev_tmp->data > val) prev_tmp->left = tmp->right;
		if (prev_tmp->data < val) prev_tmp->right = tmp->right;
		delete tmp;
		tmp = NULL;
		return true;
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
		cout << "Input new value, ? " << i << endl;
		cin >> x;
		while (TreeInsert(root, x) == false)
		{
			cout << "This value is exist. Please, input new value" << endl;
			cin >> x;
		}
	}
	cout << endl;
	PrintTree(root, 3);
	cout << "Input element to delete it" << endl;
	cin >> x;
	DeleteEl(root, x);
	cout << endl;
	PrintTree(root, 3);

	return 0;
}