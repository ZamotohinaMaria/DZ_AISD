#include <stdio.h>
#include <iostream>

using namespace std;

struct Bin
{
	int data;
	Bin* left;
	Bin* right;

	Bin(int data, Bin* left, Bin* right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};


void PrintTree(Bin* root, int level)
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
		
		/*
		// Àœ
		cout << root->data << endl;
		cout << "l-";
		PrintTree(root->left);
		cout << "r-";
		PrintTree(root->right);*/

		/*
		//Àœ 
		PrintTree(root->left);
		PrintTree(root->right);
		cout << root->data;

		//À œ
		PrintTree(root->left);
		cout << root->data;
		PrintTree(root->right);
		*/
	}
}

//Bin* LeftInsert(Bin* root, int x)
//{
//	root->left = new Bin(x, NULL, NULL);
//	return root->left;
//}
//
//Bin* RightInsert(Bin* root, int x)
//{
//	root->right = new Bin(x, NULL, NULL);
//	return root->right;
//}

Bin*  CreateBalanceTree(Bin** root, int n)
{
	Bin* root_tmp = (*root);
	Bin* new_tmp;
	int data;

	if (n == 0)
	{
		root_tmp = NULL;
		return root_tmp;
	}

	//cout << "Input value ";
	//cin >> data;
	new_tmp = new Bin(n, NULL, NULL);
	new_tmp->left = CreateBalanceTree((&new_tmp->left), n / 2);
	new_tmp->right = CreateBalanceTree((&new_tmp->right), n - n / 2 - 1);
	root_tmp = new_tmp;
	return root_tmp;

}

int main()
{
	Bin* root = new Bin(0, NULL, NULL);
	int n = 20;
	CreateBalanceTree(&root, n);
	cout << "-----------" << endl;
	/*LeftInsert(root, 3);
	RightInsert(root, 5);
	LeftInsert(root->left, 4);
	LeftInsert(root->right, 6);
	RightInsert(root->left, 33);
	RightInsert(root->right, 55);*/
	PrintTree(root, 3);
	return 0;
}