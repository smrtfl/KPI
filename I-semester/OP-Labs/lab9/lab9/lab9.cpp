#include <iostream>
#include <stdio.h>
#include <string>
#include "windows.h"
using namespace std;

//��������� �������
void input(char**, int);
int words(char**, int, int);
void output(char**, int, int);
void palindromes(char**, int, int);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int n = 255; //��������� ������
	char** str = new char* [n]; //����������� ������ �����
	for (int i = 0; i < n; i++)
	{
		str[i] = new char[n];
	}
	int word_count = 0; //ʳ������ ���

	input(str, n);

	word_count = words(str, n, word_count);
	cout << "\n������ ��� � �����: " << word_count;

	cout << "\n�� ����� �����: ";
	output(str, n, word_count);

	cout << "\n�����-���������: ";
	palindromes(str, n, word_count);
}

//������� ����� � ������
void input(char** s, int n1)
{
	cout << "������ �����: ";
	cin.getline(*s, n1);
}

//������ �� ����� � �����
int words(char** s, int n1, int w_c)
{
	int word_start = 0; //������� ������� �����

	for (int i = 0; i < n1; i++)
	{
		if (s[0][i] == ' ' and s[0][i + 1] == '\0')
		{
			s[0][i] = '\0';
		}

		if ((s[0][i] == ' ' and s[0][i + 1] != ' ') or (s[0][i] == '\0' and s[0][i + 1] != '\0'))
		{	
			for (int k = 0; k < i - word_start; k++)
			{
				s[w_c][k] = s[0][word_start + k];
				s[w_c][i - word_start] = '\0';
				if (s[w_c][k] == ' ')
				{
					s[w_c][k] = '\0';
				}
			}
			w_c++;
			word_start = i + 1;
		}
	}

	return w_c;//��������� ������� ���
}

//�������� ����� � �������
void output(char** s, int n1, int w_c)
{
	cout << "[";
	for (int i = 0; i < w_c; i++)
	{
		if (i == w_c - 1)
		{
			cout << s[i];
		}
		else cout << s[i] << ", ";
	}
	cout << "]\n";
}

//������ �� �����-���������, �� �������, � �������� �� � �������
void palindromes(char** s, int n1, int w_c)
{
	int len; //������� �����
	int count = 0; //˳������� ���������
	bool cond; //�����

	cout << "[ ";
	for (int i = 0; i < w_c; i++)
	{
		len = strlen(s[i]);
		cond = true;
		for (int j = 0; j < len / 2; j++)
		{
			if (s[i][j] != s[i][len - j - 1])
			{
				cond = false;
			}
		}
		if (cond == true)
		{
			cout << s[i] << " ";
			count++;
		}
	}

	cout << "]\n";

	cout << "������ ��� ��������: " << count << endl;
}