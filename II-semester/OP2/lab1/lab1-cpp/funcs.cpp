#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"
using namespace std;

//��������� ���� � �������� ����� � �����
void input_file(string file_path)
{
	ofstream fout;
	string str;
	char exit = 5; //Ctrl - E = 5
	int line_count = 0; //�������� �����

	fout.open(file_path); //��������� � ��������� ����

	if (!fout.is_open())
	{
		cout << "�������! ��������� ������� ���� :(";
	}
	else
	{
		cout << "Press CTRL + E to stop. Input text in file:\n";
		while (str.find(exit) == string::npos)
		{
			getline(cin, str);

			if (str.find(exit) == string::npos && !str.empty())
			{
				if (line_count > 0)
				{
					fout << "\n";
				}
				fout << str;
			}
			line_count++;
		}
	}

	fout.close();
}

//��������� ����� ���� � ���������� � ����� ���
void new_file(string file_path, string new_fp)
{
	ofstream fout;
	ifstream fin;
	string str;
	string word; //������ ����� �����
	int line_count = 0;

	fin.open(file_path);
	fout.open(new_fp); //��������� ����� ����

	if (!fin.is_open())
	{
		cout << "�������! ��������� ������� ���� '" << file_path << "' :(";
	}
	else
	{
		while (!fin.eof()) //���������� ����������
		{
			getline(fin, str);

			string del = " "; //���������
			int start = 0; //������� �����
			int end = str.find(del); //����� �����

			while (end != -1) {
				start = end + del.length();
				end = str.find(del, start);
			}
			
			word = str.substr(start, end - start);

			if (line_count > 0)
			{
				fout << "\n";
			}

			fout << "'" << word[0] << "' - " << str; //������ �����
			line_count++;
		}
	}

	fout.close();
	fin.close();
}

// ��������� ����� �����
void output_file(string file_path)
{
	ifstream fin;
	string str;

	fin.open(file_path);
	if (!fin.is_open())
	{
		cout << "�������! ��������� ������� ���� '" << file_path << "' :(";
	}
	else
	{
		while (!fin.eof())
		{
			getline(fin, str);
			cout << str << "\n";
		}
	}
	fin.close();
}