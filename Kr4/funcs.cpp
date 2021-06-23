#pragma once
#include "header.h"

using namespace std;

buyer::buyer() {
	first_name = new char[strlen("none") + 1];
	strcpy(first_name, "none");
	last_name = new char[strlen("none") + 1];
	strcpy(last_name, "none");
	tel = 0;
	base_discount = 0;
}
buyer::buyer(char* entered_first_name, char* entered_last_name, int entered_tel, float entered_base_discount) {
	first_name = new char[strlen(entered_first_name) + 1];
	strcpy(first_name, entered_first_name);
	first_name = new char[strlen(entered_last_name) + 1];
	strcpy(first_name, entered_last_name);
	tel = entered_tel;
	base_discount = entered_base_discount;
}
buyer::~buyer() {
	delete[] first_name;
	delete[] last_name;
}
float buyer::get_base_discount() {
	return base_discount;
}

retired_buyer::retired_buyer() {
	discount = 0;
}
retired_buyer::retired_buyer(char* entered_first_name, char* entered_last_name, int entered_tel, float entered_base_discount, float entered_discount)
:buyer(entered_first_name, entered_last_name, entered_tel, entered_base_discount) {
	discount = entered_discount;
	
}
retired_buyer::~retired_buyer() {

}
float retired_buyer::get_discount() {
	return discount;
}

vip_buyer::vip_buyer() {
	discount = 0;
	cat = nullptr;
}
vip_buyer::vip_buyer(char* entered_first_name, char* entered_last_name, int entered_tel, float entered_base_discount, float entered_discount, category* entered_cat)
:buyer(entered_first_name, entered_last_name, entered_tel, entered_base_discount) {
	discount = entered_discount;
	cat = entered_cat;
}
vip_buyer::~vip_buyer() {

}
int vip_buyer::get_category() {
	return cat->code;
}
float vip_buyer::get_discount() {
	return discount;
}


product::product() {
	code = 0;
	name = new char[strlen("none") + 1];
	strcpy(name, "none");
	price = 0;
	cat = nullptr;
}
product::product(int entered_code, char* entered_name, float entered_price, category* entered_cat) {
	code = entered_code;
	name = new char[strlen(entered_name) + 1];
	strcpy(name, entered_name);
	price = entered_price;
	cat = entered_cat;
}
product::~product() {
	delete[] name;
}
 int product::get_category() {
	 return cat->code;
}
 float product::get_price() {
	 return price;
 }

category::category() {
	code = 0;
	name = new char[strlen("none") + 1];
	strcpy(name, "none");
}
category::category(int entered_code, char* entered_name) {
	code = entered_code;
	name = new char[strlen(entered_name) + 1];
	strcpy(name, entered_name);
}
category::~category() {
	delete[] name;
}

float get_vip_discount(vip_buyer* buy, product* prod) {
	if (buy->get_category() == prod->get_category())
		return buy->get_discount();
	else
		return buy->get_base_discount();
}