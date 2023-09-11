#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;



int main()
{

	string str;
	cin >> str; // 공백 이전까지 문자열 입력
	cout << "str1 : " << str << endl;

	// cin을 하면 abc<enter>  enter를 getline이 한번 받아준거야.
	
	getline(cin, str); // enter 처리


	getline(cin, str); // \n까지 문자열 입력
	
	cout << "str2 : " << str << endl;

	getline(cin, str, 'a');
	
	cout << "str3 : " << str << endl;

	return 0;

	//char a[100], b[100], c[100];
	//cin >> a; // cin은 버퍼에 엔터가 남아있음.

	//// getline 함수는 버퍼에 엔터 포함X
	//cin.getline(b, 100);
	//cin.getline(c, 100);

	//cout << "a: " << a << endl;
	//cout << "b: " << b << endl;
	//cout << "c: " << c << endl;


	return 0;



}