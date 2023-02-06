#include <stdio.h>
#include <iostream>

using namespace std;

struct List
{
	int data;
	List* next;
	
	List(int data, List* next)
	{
		this->data = data;
		this->next = next;
	}
};


ostream& operator<< (ostream& out, const List* head)
{
	const List* tmp = head;
	out << "List:" << endl;
	while (tmp)
	{
		out << tmp->data << "  ";
		tmp = tmp->next;
	}
	out << endl;
	return out;
}

void Insert_value(List** head, int val)
{
	//������� � ������
	if (val < (*head)->data)
	{
		List* tmp = new List(val, (*head));
		(*head) = tmp;
		return;
	}
	
	//������� � ��������
	List* tmp1 = *head;
	List* tmp2;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		if (val >= tmp1->data && val <= tmp2->data)
		{
			tmp1->next = new List(val, tmp2);
			return;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	//������� � �����
	if (val > tmp1->data)
	{
		List* tmp = new List(val, NULL);
		tmp1->next = tmp;
		tmp1 = tmp;
	}
}

//��������� � �������� � �����
void Create_List(List** head, int n)
{
	int x;
	List* tmp_h = NULL;
	List* tmp1;
	List* tmp_e = NULL;

	cout << "������ �������� ����� 1" << endl;
	cin >> x;
	tmp_h = new List(x, NULL);
	tmp_e = tmp_h;
	for (int i = 1; i < n; i++)
	{
		cout << "������ �������� ����� " << i + 1 << endl;
		cin >> x;
		tmp1 = new List(x, NULL);
		tmp_e->next = tmp1;
		tmp_e = tmp1;
	}
	*head = tmp_h;
}

//�������� � �������� � ������
//void Create_List(List** head, int n)
//{
//	int x;
//	List* tmp = NULL;
//	List* tmp1;
//	for (int i = 0; i < n; i++)
//	{
//		cout << "������ �������� ����� " << i + 1 << endl;
//		cin >> x;
//		tmp1 = new List(x, tmp);
//		tmp = tmp1;
//	}
//	*head = tmp;
//}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "������� ���������� ��������� � ������" << endl;
	int n;
	cin >> n;
	List* head = NULL;
	Create_List(&head, n);
	cout << head;
	cout << "������� ����������� ��������" << endl;
	int x;
	cin >> x;
	Insert_value(&head, x);
	cout << head;
}