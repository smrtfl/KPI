#include <iostream>
#include "funcs.h"
using namespace std;

int main()
{
	string path = "todo_list.dat";
	string new_path = "spare_time.dat";

	create_schedule(path);
	read_data(path);

	closest_activity(path);

	rest_info(path, new_path);
	read_data(new_path);

	cout << "\n";
}