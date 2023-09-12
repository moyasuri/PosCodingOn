#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;


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
			return*this;
		}

		/*_width = rect._width;
		_height =rect._height;*/

		// 밑에는 그냥 1로넣어본거야 대입연산자면 이러면안되겟지?

		_width = 1;
		_height = 1;
		return *this;
	}

	float area()
	{
		return this->_width * this->_height;

	}

	float getWidth() {
		return this->_width;
	}
	float getHeight()
	{
		return this->_height;
	}

	void setWidth(float width)
	{
		this->_width = width;
	}
	void setHeight(float height)
	{
		this->_height = height;
	}


private:
	float _width{0}, _height{ 0 };
};


class Box {

public:
	Box() {}

	explicit Box(int i) : m_width(i), m_length(i), m_height(i)
	{}

	Box(int width, int length, int height) : m_width(width), m_length(length), m_height(height)
	{}

	int Volume()
	{
		return m_width * m_length * m_height;
	}

private:
	int m_width{ 0 };
	int m_length{ 0 };
	int m_height{ 0 };
};

int main()
{


	/*{cout << "사각형의 가로와 세로 길이를 입력해주세요. (띄어쓰기로 구분)";
	float width, height;
	cin >> width >> height;

	Rectangle Rect;

	cout << "setWidth" << endl;
	cout << "setHeight" << endl;
	Rect.setWidth(width);
	Rect.setHeight(height);

	cout << "Rect.getWidth() : " << Rect.getWidth() << endl;
	cout << "Rect.getHeight() : " << Rect.getHeight() << endl;


	cout << "area함수 호출 " << endl;
	cout << Rect.area() << endl;;
	}*/

	/*{
	const int const a = 3;
	const int *b = &a;
	
	
	cout << b << endl;
	int c;
	b = &c;
	cout << b;
	}*/

	return 0;

}