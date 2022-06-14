#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree t;
	int n;

	cout << "Enter positive integer n: ";
	cin >> n;

	t.insert(n); // tree root is n
	t.insert(2); // first level siblings are 2

	for (int i = 3; i <= n; i++)
	{
		t.insert(i); // insert next levels in the tree
	}

	cout << "\nTree output:\n";
	t.output();
	t.destroy_tree();
}