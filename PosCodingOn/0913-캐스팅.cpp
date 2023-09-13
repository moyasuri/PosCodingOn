#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Person {
public:
	virtual void intro() {
		cout << "사람입니다~" << endl;
	}
	virtual ~Person()
	{

	}
};

class Student : public Person {
	string name;

public:
	Student(string name) {
		this->name = name;
	}
	void intro() {
		cout << name << "학생입니다." << endl;
	}

	void learn() {
		cout << "배웁니다." << endl;
	}
};

class Teacher : public Person {
	string name;

public:
	Teacher(string name) {
		this->name = name;
	}
	void intro() {
		cout << name << "선생입니다." << endl;
	}

	void teach() {
		cout << "가르칩니다." << endl;
	}
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
		this->_flavour = str1;
		this->name = str2;

	}
	void showInfo()
	{
		cout << this->_flavour << " 맛입니다~" << endl;
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

	void showInfo()
	{
		cout <<this->_shape << "모양입니다~" << endl;
	}
	string _shape;
	// 모양 가격 상품이름 제조회사
};



int main()
{



	
	//// Person* p = new Student(); // 업캐스팅
	//// Student* stu = (Student*)p; // 다운 캐스팅

	//Candy a("자두", "신호등"); 

	////Candy* pc1 = new Candy("자두","신호등");
	////Candy c1("자두","신호등"); // 포인터아닌거 #2
	////Candy* pc1 = &c1; //#2   #1이랑 #2랑 똑같은거다
	//Candy b("사과", "츄파");


	//Chocolate c("사각", "가나");
	//Chocolate d("삼각", "킷캣");

	//vector<Snack*> snackBasket;
	//snackBasket.push_back(&a);
	//snackBasket.push_back(&b);
	//snackBasket.push_back(&c);
	//snackBasket.push_back(&d);

	//for (Snack* snack : snackBasket)
	//{
	//	cout << snack->getName() << endl;

	//}

	
	//((Candy*)snackBasket[0])->showinfo(); // Candy * = Snack*
	//cout << ((Candy*)snackBasket[0])->flavour << endl;
	//((Candy*)snackBakset[0]->flavour;


	//
	//Candy* a= new Candy("자두", "신호등");
	//Candy* b= new Candy("사과", "츄파");

	//Chocolate* c = new Chocolate("사각", "가나");
	//Chocolate* d = new Chocolate("삼각", "킷캣");
	//
	//Snack **snackBasket = new Snack*[4];

	//for (int i = 0; i < 4;i++)
	//{
	//	snackBasket[i] = new Snack;
	//}


	//snackBasket[0] = a; // 데이터가 잘리지 않는다, 포인터기 때문에,
	//snackBasket[1] = b;
	//snackBasket[2] = c;
	//snackBasket[3] = d;

	//for (int i=0; i<4;i++)
	//{
	//		snackBasket[i]->showInfo(); // 함수 포인터관련해서 알필요가 있는거네
	//		// 업캐스팅해서 아무것도 남지 않을거같은데 virtual을 했기때문에 자동으로
	//		// 자식의 함수를 찾아준다.. 무엇이 근거로 된걸까?
	//}
	//
	//cout << ((Candy*)snackBasket[0])->_flavour << endl;
	//((Candy*)snackBasket[0])->_flavour;

	//cout << ((Chocolate*)snackBasket[0])->_shape << endl;
	//((Chocolate*)snackBasket[0])->_shape;

	//Chocolate* derivedPtr = dynamic_cast<Chocolate*>(snackBasket[0]);
	//cout << derivedPtr << endl;

	//Candy* derivedPtr2 = dynamic_cast<Candy*>(snackBasket[0]);
	//cout << derivedPtr2 << endl;

	//if (derivedPtr2) {
	//	cout << derivedPtr2->_flavour << endl;
	//}


	Person* plist[3];
	string names[3];
	cout << "3명의 이름을 입력해주세요.(선생님, 학생, 학생)" << endl;
	cin >> names[0] >> names[1] >> names[2];

	Teacher* T1 = new Teacher(names[0]);
	Student* S1 = new Student(names[1]);
	Student* S2 = new Student(names[2]);

	plist[0] = T1;
	plist[1] = S1;
	plist[2] = S2;


	for (auto p : plist)
	{
		p->intro();
	}
		
	((Teacher*)plist[0])->teach();
	((Student*)plist[1])->learn();
	((Student*)plist[2])->learn();
	

	delete T1;
	delete S1;
	delete S2;



}







