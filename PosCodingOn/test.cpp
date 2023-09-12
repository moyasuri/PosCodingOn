#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

bool inputstr(string*);
bool chknum(string);

int main()
{
//	string s = "Police say two people are suspected of\
// trying to create a shortcut for their construction work.\
//The two have been detained and the case is under further investigation.\
//The 38-year-old man and 55-year-old woman were working near the affected area, \
//the 32nd Great Wall.";
//
//	cout <<"문자열길이:" << s.size() << endl;
//	cout <<"100번째문자:"<< s[100] << endl;
//	cout <<"처음 two가 나오는 인덱스" << s.find("two") << endl;
//	cout <<"두번째 two가 나오는 인덱스"<< s.find("two", 12) << endl;
//	cout <<"*" << s[6] <<"*"<<s[7];

	string str,str2;
	
	inputstr(&str);
	inputstr(&str2);

	cout << " 붙이기 " << endl;
	cout << str + str2 << endl;

	cout << " 합 " << endl;
	cout << stoi(str) + stoi(str2) << endl;



}



bool inputstr(string* str)
{
	bool chk = true;
	
	while (chk)
	{
		getline(cin, *str);

		if (chknum(*str))
		{
			chk = false;
			cout << *str << " -> OK" << endl;

		}
		else
		{
			cout << *str << " -> NO" << endl;
			
		}

	}

	return chk;
}

bool chknum(string str)
{
	bool result = true;

	// for(str
	for (int i = 0;i < str.size();i++)
	{
		if (!isdigit(str[i]))
			result = false;
	
	}

	return result;
}
