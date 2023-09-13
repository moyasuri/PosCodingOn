#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;

class Snack {
protected:
	int price;
	string name;
	string maker;
	static int count;
public:
	Snack() { count++; }
	virtual ~Snack() { count--; }
	static int get_count() {
		return count;
	}
	string get_name() {
		return name;
	}
	virtual void show_info() {
		cout << "과자입니다~" << endl;
	}
};

int Snack::count = 0;

class Candy : public Snack {
	string flavor;
public:
	Candy(string flavor) {
		this->price = 200;
		this->name = "사탕";
		this->maker = "농심";
		this->flavor = flavor;
	}
	void show_info() {
		cout << flavor << "맛 사탕" << endl;
	}
};

class Chocolate : public Snack {
	string shape;
public:
	Chocolate(string shape) {
		this->price = 1000;
		this->name = "초콜릿";
		this->maker = "롯데";
		this->shape = shape;
	}

	void show_info() {
		cout << shape << "모양 초콜릿" << endl;
	}
};

int main()
{

	// 사탕을 고르면 맛을입력하게
	// 초콜릿을 고르면 모양을 선택하게
	bool loop = true;
	int tmp = 0;
	string str = "";

	vector<Snack*> snack_basket = {};
	// vector<Candy*> snack_basket_Candy = {};
	// vector<Chocolate*> snack_basket_Choco = {};

	while (loop)
	{
		cout << "과자 바구니에 추가할 간식을 고르시오.( 1 : 사탕, 2 : 초콜릿, 0:종료 : ";
		cin >> tmp;

		if (tmp == 1)
		{
			cout << "맛을 입력하세요 : ";
			cin >> str;
			snack_basket.push_back(new Candy(str));

		}
		else if (tmp == 2)
		{
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
	
	


	cout << "과자 바구니에 담긴 간식의 개수는 " << Snack::get_count() << "개 입니다.";

	cout << "과자 바구니에 담긴 간식 확인하기!" << endl;

	for (Snack* snacks : snack_basket)
	{
		snacks->show_info();
	}
	
		
}