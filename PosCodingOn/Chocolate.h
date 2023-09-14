#pragma once
#include "Snack.h"


class Chocolate : public Snack {
	
public:
	Chocolate(string shape);
	

	void show_info();

public:
	string shape;
};
