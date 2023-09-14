#include "Candy.h"

Candy::Candy(string flavor) {
	this->price = 200;
	this->name = "사탕";
	this->maker = "농심";
	this->flavor = flavor;
}
void Candy::show_info() {
	cout << flavor << "맛 사탕" << endl;
}