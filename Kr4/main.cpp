#include "header.h"

int main() {

	setlocale(LC_ALL, "Russian");
	char buff[4096], buff1[4096];
	strcpy(buff, "sweet");
	category sweet(123213, buff);
	strcpy(buff, "ice_cream");
	product ice_cream(123141, buff, 112, &sweet);
	strcpy(buff, "chocolate");
	product chocolate(412345, buff, 85, &sweet);
	strcpy(buff, "Ivan");
	strcpy(buff1, "Ivanov");
	buyer common(buff, buff1, 89163895690, 0.05);
	strcpy(buff, "Alexey");
	strcpy(buff1, "Samigulin");
	retired_buyer retired(buff, buff1, 89164927409, 0.05, 0.15);
	strcpy(buff, "Anton");
	strcpy(buff1, "Subbotin");
	vip_buyer vip(buff, buff1, 89162938405, 0.05, 0.2, &sweet);
	cout << "Стоимость ice_cream для обычного покупателя\t" << ice_cream.get_price() * (1 - common.get_base_discount()) << endl;
	cout << "Стоимость ice_cream для пенсионера\t" << ice_cream.get_price() * (1 - retired.get_discount()) << endl;
	cout << "Стоимость ice_cream для вип\t" << ice_cream.get_price() * (1 - get_vip_discount(&vip, &ice_cream)) << endl;

	return 0;
}