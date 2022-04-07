#include <iostream>
#include "funcs.h"
using namespace std;

int main()
{
	cout << "---YOUR SCHEDULE---\n";
	string path = "todo_list.dat";
	create_list(path);
}