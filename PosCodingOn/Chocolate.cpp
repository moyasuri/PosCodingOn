#include "Chocolate.h"



Chocolate::Chocolate(string shape)
{
	this->price = 1000;
	this->name = "초콜릿";
	this->maker = "롯데";
	this->shape = shape;
}
void Chocolate::show_info() {
	cout << shape << "모양 초콜릿" << endl;
}