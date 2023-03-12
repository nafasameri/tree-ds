// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
using namespace std;


class node
{
public:
	int Data;
	node *RChild;
	node *LChild;

	node(int x, node *l, node *r)
	{
		Data = x;
		LChild = l;
		RChild = r;
	}
};

class Tree
{
public:
	int recCount(node *root)
	{
		if (root == NULL)
			return 0;
		else
			1 + recCount(root->LChild) + recCount(root->RChild);
	}

	int recH(node *root)
	{
		if (root == NULL || root->LChild == NULL && root->RChild == NULL)
			return 0;
		else
		{
			int H1 = recH(root->LChild);
			int H2 = recH(root->RChild);
			int H = H1 > H2 ? H1 : H2;
			return 1 + H;
		}
	}

	node *Copy(node *root)
	{
		if (root == NULL)
			return NULL;
		else
		{
			node *m = new node(root->Data, NULL, NULL);
			m->LChild = Copy(root->LChild);
			m->RChild = Copy(root->RChild);
		}
	}

	node *RevCopy(node *root)
	{
		if (root == NULL)
			return NULL;
		else
		{
			node *m = new node(root->Data, NULL, NULL);
			m->LChild = Copy(root->RChild);
			m->RChild = Copy(root->LChild);
		}
	}

	void PrintInOrder(node *root)
	{
		if (root != NULL)
		{
			PrintInOrder(root->LChild);
			cout << root->Data;
			PrintInOrder(root->RChild);
		}
	}

	void PrintPreOrder(node *root)
	{
		if (root != NULL)
		{
			cout << root->Data;
			PrintPreOrder(root->LChild);
			PrintPreOrder(root->RChild);
		}
	}
	
	void PrintPostOrder(node *root)
	{
		if (root != NULL)
		{
			PrintPostOrder(root->LChild);
			PrintPostOrder(root->RChild);
			cout << root->Data;
		}
	}

	node *minBST(node *root)
	{
		node *m = root;
		while (m->LChild != NULL)
			m = m->LChild;
		return m;
	}

	node *maxBST(node *root)
	{
		node *m = root;
		while (m->RChild != NULL)
			m = m->RChild;
		return m;
	}

	bool recBSTSearch(node *root, int x)
	{
		if (root == NULL)
			return false;
		else
			if (root->Data == x)
				return true;
			else if (root->Data < x)
				return recBSTSearch(root->RChild, x);
			else
				return recBSTSearch(root->RChild, x);
	}

	bool BSTSearch(node *root, int x)
	{
		node *m = root;
		while (m != NULL)
		{
			if (m->Data == x)
				return true;
			else if (m->Data < x)
				m = m->RChild;
			else if (m->LChild)
				m = m->LChild;
		}
		return false;
	}

	node *InsertBST(node *root, int x)
	{
		node *m = root;
		node *n = NULL;
		while (m != NULL)
		{
			n = m;
			if (m->Data < x)
				m = m->RChild;
			else
				m = m->LChild;
		}
		node *newn = new node(x, NULL, NULL);
		if (n->Data < newn->Data)
			n->RChild = newn;
		else
			n->LChild = newn;
		return root;
	}

	node *BeforeInOrder(node *root)
	{
		if (root->LChild != NULL)
		{
			node *m = root->LChild;
			while (m->RChild != NULL)
				m = m->RChild;
			return m;
		}
	}

	node *NextInOrder(node *root)
	{
		if (root->RChild != NULL)
		{
			node *m = root->RChild;
			while (m->LChild != NULL)
				m = m->LChild;
			return m;
		}
	}

	int degree(node *root)
	{

	}

	void DeleteBST(node *root,node *n)
	{
		node *par = NULL;

		int deg = degree(n);

	}
};

class maxHeap
{
public:
	void Insert(int a[], int &n, int x)
	{
		n++;
		a[n - 1] = x;
		int i = n - 1;
		while (true)
		{
			if (i == 0)
				break;
			if (a[i] < a[(i - 1) / 2])
				break;
			swap(a[i], a[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	int Delete(int a[], int &n)
	{
		int value = a[0];
		a[0] = a[n - 1];
		n--;
		int i = 0, j = 1;
		while (true)
		{
			if (j >= n)
				break;
			if (a[j] < a[j + 1])
				j++;
			if (a[i] < a[j])
			{
				swap(a[i], a[j]);
				i = j;
				j = 2 * i + 1;
			}
			else
				break;
		}
		return value;
	}

	void Heapfiy(int a[], int n, int i)
	{
		int large = -1;
		int L = 2 * i + 1;
		int R = 2 * i + 2;
		if (L < n && R < n)
			large = a[L] > a[R] ? L : R;
		else if (L < n)
			large = L;
		if (large == -1)
			return;
		else if (a[i] > a[large])
			return;
		else
		{
			swap(a[i], a[large]);
			Heapfiy(a, n, large);
		}
	}

	void HeapSort(int a[], int n)
	{
		int i;
		for (i = (n - 1) / 2; i >= 0; i--)
			Heapfiy(a, n, i);
		for (int j = n; j >= 0; j--)
		{
			swap(a[0], a[j]);
			Heapfiy(a, j, 0);
		}
	}


};


void main()
{
}

