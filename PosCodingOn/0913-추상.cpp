#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;


// 추상 메소드 (순수 가상 함수)
// 함수의 원형만 존재하고 내용이 없는 메소드

// c++에서의 정확한 워딩은 "순수 가상 함수"
// 순수워딩이 중요

// 추상 클래스로는 인스턴스를 생성할 수 없다.
// 추상 클래스를 상속받은 자식클래스는 추상 메소드를 모두 구현해야한다.
// 만약 구현하지 않는다면, 자식 클래스 또한 추상클래스가 된다.

// 다형성
// 같은 대상이라도 문맥이나 상황에 따라 다르게 사용할 수 있다는 원리

class Person {

};

class Student : public Person {

};

class Reserarcher : public Person{

};

class Snack {
protected:
	int price;
	string name;
	string maker;
public:
	Snack() { }
	string getName() {
		return name;
	}
	virtual void showInfo() {
		cout << name << " 과자입니다~" << endl;
	}


};
class Candy : public Snack
{
public:
	Candy(string str1, string str2)
	{
		this->_flavour =str1;
		this->name  =str2;
		
	}
	void showInfo()
	{

	}
	string _flavour;
	// 맛 가격 상품이름 제조회사

};
class Chocolate : public Snack
{

public:
	Chocolate(string str1, string str2)
	{
		this->_shape = str1;
		this->name = str2;

		
	}

	string _shape;
	// 모양 가격 상품이름 제조회사
};

class Myclass
{
public:
	// 순수 가상함수의 예
	virtual void sleep() = 0; // 내용이 없다는걸 확인하기 위해서
};
//class Student : public Myclass
//{
//public:
//	void sleep() { cout << "10시 취짐" << endl; }
//
//};
class Shape 
{
protected:
	virtual void draw() = 0;

};
class Circle : public Shape
{
public:
	void draw()
	{
		cout << "Circle" << endl;
	}

};
class Rect : public Shape
{
public:
	void draw()
	{
		cout << "Rect" << endl;
	}

};
class Triangle : public Shape
{
public:
	void draw()
	{
		cout << "Triangle" << endl;
	}

};

int main(void)
{
	// Student myc;



	Candy a("자두", "신호등");
	Candy b("사과", "츄파");

	Chocolate c("사각", "가나");
	Chocolate d("삼각", "킷캣");
	Snack snackBasket[4];


	snackBasket[0] = a;
	snackBasket[1] = b;
	snackBasket[2] = c;
	snackBasket[3] = d;


	for (Snack s : snackBasket)
	{
		cout << s.getName() << endl;
	}


}