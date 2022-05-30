#include "FGoods.h"

FGoods::FGoods(string c_name, string c_date, int c_price, int c_amount, string c_end_date)
{
	name = c_name;
	date = c_date;
	price = c_price;
	amount = c_amount;
	end_date = c_end_date;
}

void FGoods::output()
{
	printf("%s %s %d$ %d %s", name.c_str(), date.c_str(), price, amount, end_date.c_str());
}

int FGoods::overdue_check()
{
	istringstream date_stream(end_date);
	vector<int> ed;
	string date_el;
	while (getline(date_stream, date_el, '.')) {
		if (!date_el.empty())
		{
			ed.push_back(stoi(date_el));
		}
	}

	SYSTEMTIME curr_date;
	GetLocalTime(&curr_date);

	if (ed[2] < curr_date.wYear)
	{
		return 1;
	}
	else if (ed[2] == curr_date.wYear)
	{
		if (ed[1] < curr_date.wMonth)
		{
			return 1;
		}
		else if (ed[1] == curr_date.wMonth)
		{
			if (ed[0] <= curr_date.wDay)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}