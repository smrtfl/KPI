#include <iostream>
#include <cstring>
#include <vector>
#include "MGoods.h"
#include "FGoods.h"
using namespace std;

void init_goods(vector<MGoods>& mg, vector<FGoods>& fg)
{
	string item_name, item_date, item_transportation, item_location, item_end_date;
	int item_price, item_amount;

	int n;
	cout << "Amount of manufacture goods: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Item name: ";
		cin >> item_name;
		cout << "Item manufacture date (dd.mm.yyyy): ";
		cin >> item_date;
		cout << "Item price: ";
		cin >> item_price;
		cout << "Item amount: ";
		cin >> item_amount;
		cout << "Item transportation method: ";
		cin >> item_transportation;
		cout << "Item location (warehouse, store): ";
		cin >> item_location;

		MGoods m_obj(item_name, item_date, item_price, item_amount, item_transportation, item_location);
		mg.push_back(m_obj);

		cout << endl;
	}

	int m;
	cout << "Amount of food goods: ";
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cout << "Item name: ";
		cin >> item_name;
		cout << "Item manufacture date (dd.mm.yyyy): ";
		cin >> item_date;
		cout << "Item price: ";
		cin >> item_price;
		cout << "Item amount: ";
		cin >> item_amount;
		cout << "Item end date (dd.mm.yyyy): ";
		cin >> item_end_date;

		FGoods f_obj(item_name, item_date, item_price, item_amount, item_end_date);
		fg.push_back(f_obj);

		cout << endl;
	}
}

void output_goods(vector<MGoods>& mg, vector<FGoods>& fg)
{
	cout << "Manufacture goods:\n";
	for (int i = 0; i < mg.size(); i++)
	{
		mg[i].output();
		cout << endl;
	}

	cout << "\nFood goods:\n";
	for (int i = 0; i < fg.size(); i++)
	{
		fg[i].output();
		cout << endl;
	}
}

void calculations(vector<MGoods>& mg, vector<FGoods>& fg)
{
	int total_price = 0;
	for (int i = 0; i < fg.size(); i++)
	{
		if (fg[i].overdue_check() == 1)
		{
			total_price += fg[i].sum_price();
		}
	}

	printf("\nTotal price of expired food goods: %d$", total_price);

	total_price = 0;
	for (int i = 0; i < mg.size(); i++)
	{
		if (mg[i].get_status() == "warehouse")
		{
			total_price += mg[i].sum_price();
		}
	}
	printf("\nTotal price of manufacture goods in warehouse: %d$", total_price);
}