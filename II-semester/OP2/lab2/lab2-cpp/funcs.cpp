#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

struct HM
{
	string hours,
		minutes;
};

struct schedule
{
	string name;
	HM time;
	int duration;
};

void create_list(string file_path)
{
	char start_file;
	int line_count = 0;
	bool add = 1;
	char add_str;

	ifstream fin(file_path, ios::binary);
	fin.read(start_file, 1);
	fin.close();

	ofstream fout(file_path, ios::binary | ios::app);

	if (!fout.is_open())
	{
		cout << "Can't open file :(";
	}
	else
	{
		while (add)
		{
			cout << "\nAdd activity? [y/n]: ";
			cin >> add_str;

			if (add_str == 'y')
			{
				add = 1;
			}
			else
			{
				add = 0;
			}

			if (add)
			{
				schedule a1;

				cout << "Enter name of activity: ";
				cin >> a1.name;
				cout << "Enter start hour: ";
				cin >> a1.time.hours;
				cout << "minute: ";
				cin >> a1.time.minutes;
				cout << "Enter duration: ";
				cin >> a1.duration;

				if (line_count > 0 or start_file.length() > 0)
				{
					fout << "\n";
				}

				fout << "'" << a1.name << "' activity starts at " << a1.time.hours << ":" << a1.time.minutes << " and will last " << a1.duration << " minutes";

				line_count++;
			}
		}
	}

	fout.close();
}