#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"
using namespace std;

//Створюємо файл і записуємо текст в нього
void input_file(string file_path)
{
	ofstream fout;
	string str;
	char exit = 5; //Ctrl - E = 5
	int line_count = 0; //лічильник рядків

	fout.open(file_path); //створюємо і відкриваємо файл

	if (!fout.is_open())
	{
		cout << "Помилка! Неможливо відкрити файл :(";
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

//Створюємо новий файл і переносимо у нього дані
void new_file(string file_path, string new_fp)
{
	ofstream fout;
	ifstream fin;
	string str;
	string word; //останнє слово рядку
	int line_count = 0;

	fin.open(file_path);
	fout.open(new_fp); //створюємо новий файл

	if (!fin.is_open())
	{
		cout << "Помилка! Неможливо відкрити файл '" << file_path << "' :(";
	}
	else
	{
		while (!fin.eof()) //построкове зчитування
		{
			getline(fin, str);

			string del = " "; //роздільник
			int start = 0; //початок слова
			int end = str.find(del); //кінець слова

			while (end != -1) {
				start = end + del.length();
				end = str.find(del, start);
			}
			
			word = str.substr(start, end - start);

			if (line_count > 0)
			{
				fout << "\n";
			}

			fout << "'" << word[0] << "' - " << str; //додаємо літеру
			line_count++;
		}
	}

	fout.close();
	fin.close();
}

// Виведення вмісту файлу
void output_file(string file_path)
{
	ifstream fin;
	string str;

	fin.open(file_path);
	if (!fin.is_open())
	{
		cout << "Помилка! Неможливо відкрити файл '" << file_path << "' :(";
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