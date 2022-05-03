#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct HM
{
	char hours[255],
		minutes[255];
};

struct schedule
{
	char name[255];
	HM time;
	char duration[255];
};

struct spare_time
{
	HM start_time,
		end_time;
};

void read_data(string file_path)
{
	ifstream fin(file_path, ios::binary);

	schedule out_data;
	spare_time out_st;
	HM out_rest;

	int data_count = 0;
	int el_count = 0;

	if (!fin.is_open())
	{
		printf("Can't open '%s' file :(", file_path.c_str());
	}
	else
	{
		if (file_path.compare("todo_list.dat") == 0) // output for to-do list
		{
			cout << "-----SCHEDULE FOR TODAY-----\n";
			while (fin.read((char*)&out_data, sizeof(schedule)))
			{
				cout << left << setw(7) << out_data.name;
				cout << left << setw(7) << "" << out_data.time.hours << ":" << out_data.time.minutes;
				cout << left << setw(7) << "" << out_data.duration << " minutes\n";
			}
		}
		else // output for info about spare time
		{
			cout << "\n-----SPARE TIME-----";

			while (fin.read((char*)&out_st, sizeof(spare_time)))
			{
				data_count++;
			}

			fin.clear();
			fin.seekg(0);

			while (fin.read((char*)&out_st, sizeof(spare_time)))
			{
				el_count++;

				if (strcmp(out_st.start_time.hours, "0") == 0)
				{
					sprintf_s(out_st.start_time.hours, "%s", "00");
				}
				else if (strcmp(out_st.start_time.minutes, "0") == 0)
				{
					sprintf_s(out_st.start_time.minutes, "%s", "00");
				}
				else if (strcmp(out_st.end_time.hours, "0") == 0)
				{
					sprintf_s(out_st.end_time.hours, "%s", "00");
				}
				else if (strcmp(out_st.end_time.minutes, "0") == 0)
				{
					sprintf_s(out_st.end_time.minutes, "%s", "00");
				}

				printf("\n%s:%s - %s:%s", out_st.start_time.hours, out_st.start_time.minutes, out_st.end_time.hours, out_st.end_time.minutes);
			}

			fin.clear();
			fin.seekg(0);

			while (fin.read((char*)&out_rest, sizeof(HM)))
			{
				if (stoi(out_rest.hours) <= 11)
				{
					printf("\nTotal: %s hours %s min", out_rest.hours, out_rest.minutes);
				}
			}
		}
	}

	fin.close();
}

void sort_schedule(string fp)
{
	schedule a;
	int el_count = 0;

	ifstream fin(fp, ios::in | ios::binary);

	if (!fin.is_open())
	{
		printf("Can't open '%s' file :(", fp.c_str());
	}
	else
	{
		ofstream fout("temp.dat", ios::out | ios::binary);

		if (!fout.is_open())
		{
			printf("Can't open 'temp.dat' file :(");
		}
		else
		{
			while (fin.read((char*)&a, sizeof(schedule)))
			{
				fout.write((char*)&a, sizeof(schedule));
			}
		}

		fout.close();
	}

	fin.close();

	fin.open("temp.dat", ios::in | ios::binary);

	if (!fin.is_open())
	{
		printf("Can't open 'temp.dat' file :(");
	}
	else
	{
		while (fin.read((char*)&a, sizeof(schedule)))
		{
			el_count++;
		}

		fin.clear();
		fin.seekg(0);

		int* min_arr = new int[el_count];
		el_count = 0;
		while (fin.read((char*)&a, sizeof(schedule)))
		{
			min_arr[el_count] = stoi(a.time.hours) * 60 + stoi(a.time.minutes);
			el_count++;
		}

		for (int k = 0; k < el_count - 1; ++k)
		{
			for (int i = 0; i < el_count - k - 1; ++i)
			{
				if (min_arr[i] > min_arr[i + 1])
				{
					int temp = min_arr[i];
					min_arr[i] = min_arr[i + 1];
					min_arr[i + 1] = temp;
				}
			}
		}

		ofstream fout(fp, ios::out | ios::binary);

		if (!fout.is_open())
		{
			printf("Can't open '%s' file :(", fp.c_str());
		}
		else
		{
			fin.clear();
			fin.seekg(0);

			for (int i = 0; i < el_count; i++)
			{
				fin.clear();
				fin.seekg(0);

				while (fin.read((char*)&a, sizeof(schedule)))
				{
					if (stoi(a.time.hours) * 60 + stoi(a.time.minutes) == min_arr[i])
					{
						fout.write((char*)&a, sizeof(schedule));
					}
				}
			}
		}

		fout.close();
	}

	fin.close();

	remove("temp.dat");
}

void create_schedule(string file_path)
{
	schedule a;
	bool add = 1;
	char add_str = ' ';
	int el_count = 0;

	ifstream fin(file_path, ios::in | ios::binary);

	if (!fin.is_open())
	{
		cout << "-----CREATE YOUR SCHEDULE------";
	}
	else
	{
		read_data(file_path);
		cout << "\n-----ADD NEW ACTIVITIES------";
	}

	fin.close();

	ofstream fout(file_path, ios::out | ios::binary | ios::app);

	if (!fout.is_open())
	{
		printf("Can't open '%s' file :(", file_path.c_str());
	}
	else
	{
		while (add)
		{
			cout << "\nAdd an activity? [y] ";
			cin >> add_str;

			if (add_str == 'y' || add_str == 'Y')
			{
				add = 1;
			}
			else
			{
				add = 0;
			}

			if (add) // adding new activity
			{
				cout << "Enter name: ";
				cin >> a.name;
				cout << "Enter start hour (hh): ";
				cin >> a.time.hours;
				cout << "minute (mm): ";
				cin >> a.time.minutes;
				cout << "Enter duration (minutes): ";
				cin >> a.duration;

				fout.write((char*)&a, sizeof(schedule));
			}
			else
			{
				cout << "\n";
			}
		}
	}

	fout.close();

	sort_schedule(file_path);
}

void closest_activity(string file_path)
{
	HM current;

	int diff_min = 1440, next_diff_min; // difference in time between 2 activities
	int data_count = 0;
	int el_count = 0;

	cout << "\n-----CLOSEST ACTIVITY-----\nEnter current time:\n";
	cout << "hours (hh): ";
	cin >> current.hours;
	cout << "minutes (mm): ";
	cin >> current.minutes;

	schedule closest;

	ifstream fin(file_path, ios::binary);

	if (!fin.is_open())
	{
		printf("Can't open '%s' file :(", file_path.c_str());
	}
	else
	{
		while (fin.read((char*)&closest.name, sizeof(closest.name)))
		{
			data_count++;

			if (data_count % 2 == 0 && data_count % 4 != 0)
			{
				el_count++;
			}
		}

		for (int i = 0; i < el_count; i++)
		{
			fin.clear();
			fin.seekg(0);

			while (fin.read((char*)&closest, sizeof(schedule)))
			{
				if (stoi(closest.time.hours) > stoi(current.hours) || (stoi(closest.time.hours) == stoi(current.hours) && stoi(closest.time.minutes) > stoi(current.minutes)))
				{
					next_diff_min = (stoi(closest.time.hours) * 60) - (stoi(current.hours) * 60) + stoi(closest.time.minutes) - stoi(current.minutes);
					if (next_diff_min >= 0 && next_diff_min <= diff_min)
					{
						diff_min = next_diff_min;
					}
				}
			}
		}

		fin.clear();
		fin.seekg(0);

		while (fin.read((char*)&closest, sizeof(schedule)))
		{
			next_diff_min = (stoi(closest.time.hours) * 60) - (stoi(current.hours) * 60) + stoi(closest.time.minutes) - stoi(current.minutes);

			if (next_diff_min == diff_min) // output the closest activity
			{
				printf("\nClosest activity is '%s' at %s:%s\n", closest.name, closest.time.hours, closest.time.minutes);
			}
		}
	}

	fin.close();
}

void rest_info(string file_path, string new_fp)
{
	schedule a;
	spare_time info_st;
	HM rest_time;

	int rest_hours = 0, rest_min = 0; // general rest time
	int curr_min = 0, prev_min = 780;
	int last_count = 0, el_count = 0;

	ifstream fin(file_path, ios::binary);

	if (!fin.is_open())
	{
		printf("Can't open '%s' file :(", file_path.c_str());
	}
	else
	{
		ofstream fout(new_fp, ios::binary);

		if (!fout.is_open())
		{
			printf("Can't open '%s' file :(", new_fp.c_str());
		}
		else
		{
			while (fin.read((char*)&a, sizeof(schedule)))
			{
				last_count++;
			}

			fin.clear();
			fin.seekg(0);

			while (fin.read((char*)&a, sizeof(schedule)))
			{
				el_count++;

				curr_min = (stoi(a.time.hours) * 60) + stoi(a.time.minutes);
				if (el_count == last_count)
				{
					for (int i = prev_min; i < 1440; i++)
					{
						if (i < curr_min || i >= curr_min + stoi(a.duration))
						{
							rest_min++;
						}
					}

					// write to file spare time interval (same below)
					sprintf_s(info_st.start_time.hours, "%s", to_string(prev_min / 60).c_str());
					sprintf_s(info_st.start_time.minutes, "%s", to_string(prev_min % 60).c_str());
					sprintf_s(info_st.end_time.hours, "%s", to_string(curr_min / 60).c_str());
					sprintf_s(info_st.end_time.minutes, "%s", to_string(curr_min % 60).c_str());

					fout.write((char*)&info_st.start_time, sizeof(info_st.start_time));
					fout.write((char*)&info_st.end_time, sizeof(info_st.end_time));

					prev_min = curr_min + stoi(a.duration);

					if (prev_min < 1440)
					{
						sprintf_s(info_st.start_time.hours, "%s", to_string(prev_min / 60).c_str());
						sprintf_s(info_st.start_time.minutes, "%s", to_string(prev_min % 60).c_str());
						sprintf_s(info_st.end_time.hours, "%s", "23");
						sprintf_s(info_st.end_time.minutes, "%s", "59");

						fout.write((char*)&info_st.start_time, sizeof(info_st.start_time));
						fout.write((char*)&info_st.end_time, sizeof(info_st.end_time));
					}
				}
				else
				{
					for (int i = prev_min; i < curr_min + stoi(a.duration); i++)
					{
						if (i < curr_min)
						{
							rest_min++;
						}
					}

					if (curr_min >= 780)
					{
						sprintf_s(info_st.start_time.hours, "%s", to_string(prev_min / 60).c_str());
						sprintf_s(info_st.start_time.minutes, "%s", to_string(prev_min % 60).c_str());
						sprintf_s(info_st.end_time.hours, "%s", to_string(curr_min / 60).c_str());
						sprintf_s(info_st.end_time.minutes, "%s", to_string(curr_min % 60).c_str());

						fout.write((char*)&info_st.start_time, sizeof(info_st.start_time));
						fout.write((char*)&info_st.end_time, sizeof(info_st.end_time));
					}

					if (curr_min + stoi(a.duration) >= 780)
					{
						prev_min = curr_min + stoi(a.duration);
					}
				}
			}

			rest_hours = rest_min / 60;
			rest_min %= 60;

			// write to file amount of spare time
			sprintf_s(rest_time.hours, "%s", to_string(rest_hours).c_str());
			sprintf_s(rest_time.minutes, "%s", to_string(rest_min).c_str());

			fout.write((char*)&rest_time, sizeof(rest_time));
		}

		fout.close();
	}

	fin.close();
}