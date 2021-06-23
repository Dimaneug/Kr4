#ifndef KR4_FUNC_H
#define KR4_FUNC_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <clocale>
#include <list>
#include <algorithm>

using namespace std;

class buyer {

private:
	char* first_name;
	char* last_name;
	int tel;
	float base_discount;

public:
	buyer();
	buyer(char* entered_first_name, char* entered_last_name, int entered_tel, float entered_base_discount);
	~buyer();
	float get_base_discount();
};

class retired_buyer : public buyer {
private:
	float discount;
public:
	retired_buyer();
	retired_buyer(char* entered_first_name, char* entered_last_name, int entered_tel, float entered_base_discount, float discount);
	~retired_buyer();
	float get_discount();
};

class vip_buyer : public buyer {
private:
	float discount;
	category* cat;
public:
	vip_buyer();
	vip_buyer(char* entered_first_name, char* entered_last_name, int entered_tel, float entered_base_discount,
		float entered_discount, category* entered_cat);
	~vip_buyer();
	int get_category();
	float get_discount();
	
};

class product {
private:
	int code;
	char* name;
	float price;
	category* cat;
public:
	product();
	product(int entered_code, char* entered_name, float entered_price, category* entered_cat);
	~product();
	int get_category();
	float get_price();
};

class category {
private:
	int code;
	char* name;
	friend class product;
	friend class vip_buyer;
public:
	category();
	category(int entered_code, char* entered_name);
	~category();
};

float get_vip_discount(vip_buyer* buy, product* prod);

#endif