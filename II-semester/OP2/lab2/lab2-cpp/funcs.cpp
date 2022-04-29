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

void create_schedule(string file_path)
{
	cout << "-----CREATE YOUR SCHEDULE------";

	schedule a;
	bool add = 1;
	char add_str = ' ';

	ofstream fout(file_path, ios::out | ios::binary | ios::app);

	if (!fout.is_open())
	{
		cout << "\nCan't open your file :(";
	}
	else
	{
		while (add)
		{
			cout << "\nAdd an activity? [y/n] ";
			cin >> add_str;

			if (add_str == 'y' || add_str == 'Y')
			{
				add = 1;
			}
			else
			{
				add = 0;
			}

			if (add)
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
}

void read_data(string file_path)
{
	ifstream fin(file_path, ios::binary);

	schedule out_data;
	spare_time out_st;
	HM out_rest;
	
	int data_count = 0;
	int el_count = 0;

	if (file_path.compare("todo_list.dat") == 0)
	{
		cout << "-----SCHEDULE FOR TODAY-----\n";
		while (fin.read((char*)&out_data, sizeof(schedule)))
		{
			cout << left << setw(7) << out_data.name;
			cout << left << setw(7) << "" << out_data.time.hours << ":" << out_data.time.minutes;
			cout << left << setw(7) << "" << out_data.duration << " minutes\n";
		}
	}
	else
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

	fin.close();
}

void closest_activity(string file_path)
{
	HM current;

	int diff_min = 1440, next_diff_min;
	int data_count = 0;
	int el_count = 0;

	cout << "\n-----CLOSEST ACTIVITY-----\nEnter current time:\n";
	cout << "hours (hh): ";
	cin >> current.hours;
	cout << "minutes (mm): ";
	cin >> current.minutes;

	schedule closest;

	ifstream fin(file_path, ios::binary);

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

		if (next_diff_min == diff_min)
		{
			printf("\nClosest activity is '%s' at %s:%s\n", closest.name, closest.time.hours, closest.time.minutes);
		}
	}

	fin.close();
}

void rest_info(string file_path, string new_fp)
{
	schedule a;
	spare_time info_st;
	HM rest_time;

	int rest_hours = 0, rest_min = 0;
	int curr_min = 0, prev_min = 780;
	int last_count = 0, el_count = 0;

	ifstream fin(file_path, ios::binary);
	ofstream fout(new_fp, ios::binary);

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

			sprintf_s(info_st.start_time.hours, "%s", to_string(prev_min / 60).c_str());
			sprintf_s(info_st.start_time.minutes, "%s", to_string(prev_min % 60).c_str());
			sprintf_s(info_st.end_time.hours, "%s", to_string(curr_min / 60).c_str());
			sprintf_s(info_st.end_time.minutes, "%s", to_string(curr_min % 60).c_str());

			fout.write((char*)&info_st, sizeof(info_st));

			if (curr_min + stoi(a.duration) >= 780)
			{
				prev_min = curr_min + stoi(a.duration);
			}
		}
	}

	rest_hours = rest_min / 60;
	rest_min %= 60;

	sprintf_s(rest_time.hours, "%s", to_string(rest_hours).c_str());
	sprintf_s(rest_time.minutes, "%s", to_string(rest_min).c_str());

	fout.write((char*)&rest_time, sizeof(rest_time));

	fout.close();
	fin.close();
}