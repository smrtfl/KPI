#include "MGoods.h"

MGoods::MGoods(string c_name, string c_date, int c_price, int c_amount, string c_transporting, string c_status)
{
	name = c_name;
	date = c_date;
	price = c_price;
	amount = c_amount;
	transporting = c_transporting;
	status = c_status;
}

void MGoods::output()
{
	printf("%s %s %d$ %d %s %s", name.c_str(), date.c_str(), price, amount, transporting.c_str(), status.c_str());
}

string MGoods::get_status()
{
	return status;
}