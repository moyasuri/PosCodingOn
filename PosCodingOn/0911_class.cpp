#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

int Add(int a, int b) 
{
	return a + b;
}
float Add(float a, float b)
{
	return a + b;
}

class Rectangle {
public:
	
	// 대입과 복사 생성자가 나뉘어진 이유가 뭘까?
	Rectangle() {}
	Rectangle(float x, float y) : _width(x), _height(y) // 바람직한 초기화 방법
	{}
	Rectangle(const Rectangle& rect)
	{
		this->_width = rect._width;
		this->_height = rect._height;
		cout << "복사 생성자" << endl;
	}

	Rectangle& operator=(const Rectangle& rect) // = 오퍼레이터 재정의 오버라이딩
	{
		cout << " operator = " << endl;
		if (this == &rect)
		{
			return* this;
		}

		/*_width = rect._width;
		_height =rect._height;*/

		// 장난치기

		_width = 1;
		_height =1;
		return *this;
	}

	float area()
	{
		return this->_width * this->_height;

	}

public:
	float _width{0}, _height{ 0 };
};


class Box{

public:
	Box() {} 

	explicit Box(int i) : m_width(i), m_length(i), m_height(i) 
	{}

	Box(int width, int length, int height) : m_width(width), m_length(length), m_height(height)
	{}

	int Volume()
		{	return m_width * m_length * m_height;	}

private:
	int m_width{ 0 };
	int m_length{ 0 };
	int m_height{ 0 };
};
class Cat
{


public:
	Cat();
	Cat(string name, int age)
	{
		this->_name = name;
		this->_age = age;
	}

public:
	string getName() {
		return _name;
	}
	int getAge()
	{
		return this->_age;
	}

	void setName(string name)
	{
		this->_name = name;
	}
	void setAge(int age)
	{
		this->_age = age;
	}
private:
	string _name;
	int _age;


};
class Myclass {

public:
	int add(int _x, int _y)
	{
		return (this->_x + this->_y);
	}

public:
	int _x = 1;
	int _y = 1;
	

};

//struct Rectangle {
//
//	// ctrl + . 으로 함수를 추가할 수 있다.
//
//public:
//	float width, height, sum;
//
//	float SumP()
//	{
//		sum = width* height;
//		return sum;
//	}
//	
//
//
//	Rectangle() = default;
//};
//
//void prac1()
//{
//	Rectangle R;
//	cout << "가로, 세로 길이를 입력하세요.";
//	cin >> R.width >> R.height;
//	cout << "넓이는 : " << R.SumP();
//	
//}

int main()
{


	cout << "사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분)";
	float width, height;
	cin >> width >> height;
	
	


	// Rectangle A(width,height);
	// Rectangle B(A); 밑도 복사생성자 
	// Rectangle B = A; 

	cout << "1에서 복사한 변수의 area함수 호출 " << endl;
	// cout << B.area() << endl;


	Rectangle C;
	// C = B;
	cout << "3에서 복사한 변수의 area함수 호출 " << endl;
	cout << C.area() << endl;

	
	
	// Add(float(3.1), float(3.2)); 오버로드
	



	//Myclass A;
	//A.add(5, 5);
	//prac1();

	
	
	Cat a("lala",4);
	a.setAge(5);

	
	


	return 0;

}