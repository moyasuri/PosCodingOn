#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

class Shape
{
public:
	void printinfo()
	{
		cout << "변개수 : " <<this->_edge_num << endl;
		cout << "밑변길이 : "<< this->_b_edge_len << endl;
	}



	void area()
	{

	}

	void getHeight()
	{

	}

public:
	int _edge_num=0;
	float _b_edge_len=0;
};


class Rectangle : public Shape
{
public:
	Rectangle(int edge_num, float b_edge_len, float height)
	{
		_edge_num = edge_num;
		_b_edge_len = b_edge_len;
		_t_edge_len = height;
		cout << "높이는 " << height << endl;
		
	}

	
	void area()
	{
		cout <<"Rec Area : " << _b_edge_len * _t_edge_len << endl;

	}

	void printinfo()
	{
		cout << "Rec Area : " << _b_edge_len * _t_edge_len << endl;
		// cout << "사각형 밑변길이 : " << this->_b_edge_len << endl;
	}
	void printinfo(float w, float h)
	{
		cout << "Rec Area : " << w * h << endl;

	}

public:
	float _t_edge_len=0;
};

class Triangle : public Shape
{

public:
	Triangle(int edge_num, float b_edge_len, float height)
	{
		_edge_num = edge_num;
		_b_edge_len = b_edge_len;
		_height = height;
		cout << "높이는 " << height << endl;
	}

	void area()
	{
		cout <<"Tri Area : " << _b_edge_len * _height / 2 << endl;
	}
	void printinfo()
	{
		cout << "Tri Area : " << _b_edge_len * _height / 2 << endl;
		// cout << "삼각형 밑변길이 : " << this->_b_edge_len << endl;
	}

	void printinfo(float w, float h)
	{
		cout << "Rec Area : " << w * h / 2<< endl;

	}
	

public:
	float _height=0;

};

int main()
{
	Rectangle A(4,10,5);
	A.printinfo(3, 10);
	

	Triangle B(3,10,5);
	B.printinfo(3, 10);
	

}