#pragma once
#include "Snack.h"

class Candy : public Snack {


	
public:
	Candy(string flavor);


	void show_info();
		
public:

	string flavor;
};