#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Snack {

public:
	Snack();
	virtual ~Snack();


	static void PicK_Snack();
	static void Print_Snack(vector<Snack*> _p_snack_basket);
	static int get_count();
	string get_name();
	static string get_last_snack();
	static void set_last_snack(string str);
	virtual void show_info();


protected:
	int price=0;
	string name;
	string maker;
	static int count;
	static string last_snack;


};