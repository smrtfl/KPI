#include <iostream>
#include <fstream>
#include "windows.h"
#include "funcs.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Шляхи до файлів та їх назви
	string path = "text_file.txt";
	string new_path = "new_file.txt";

	input_file(path);
	new_file(path, new_path);

	cout << "\nПочатковий файл:\n";
	output_file(path);
	cout << "\nНовий файл:\n";
	output_file(new_path);
}