#include "Snack.h"
#include "Chocolate.h"
#include "Candy.h"


class Chocolate;
class Candy;

Snack::Snack() { count++; };
Snack::~Snack() { count--; };

void Snack::PicK_Snack()
{
	bool loop = true;
	int tmp = 0;
	string str = "";

	vector<Snack*> snack_basket = {};

	while (loop)
	{
		cout << "과자 바구니에 추가할 간식을 고르시오.( 1 : 사탕, 2 : 초콜릿, 0 : 종료 ) : ";
		cin >> tmp;


		if (tmp == 1)
		{
			Snack::set_last_snack("사탕");
			cout << "맛을 입력하세요 : ";
			cin >> str;
			snack_basket.push_back(new Candy(str));

		}
		else if (tmp == 2)
		{
			Snack::set_last_snack("초콜릿");
			cout << "모양을 입력하세요 : ";
			cin >> str;
			snack_basket.push_back(new Chocolate(str));

		}
		else if (tmp == 0)
		{
			loop = false;
		}
		else
		{
			cout << "0~2사이에 숫자를 입력하세요" << endl;
		}
		str = "";

		

	}
	Print_Snack(snack_basket);
}
void Snack::Print_Snack(vector<Snack*> _p_snack_basket)
{
	cout << "과자 바구니에 담긴 간식의 개수는 " << Snack::get_count() << "개 입니다.";

	cout << "과자 바구니에 담긴 간식 확인하기!" << endl;

	for (Snack* snacks : _p_snack_basket)
	{
		snacks->show_info();
	}

	cout << "마지막으로 추가한 간식은? ";
	cout << Snack::get_last_snack() << endl;
}
int Snack::get_count() {
	return count;
}
string Snack::get_name() {
	return name;
}
string Snack::get_last_snack() {

	return last_snack;
}
void Snack::set_last_snack(string str) {
	last_snack = str;
}
void Snack::show_info() {
	cout << "과자입니다~" << endl;
}
