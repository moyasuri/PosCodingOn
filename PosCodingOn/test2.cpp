#include <iostream>
#include <string>
#include <sstream> 

using namespace std;

bool inputstr(string*);
bool chknum(string*);


int main()
{

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

	//string str1 = "1D2S#10S";
	//string str2 = "1111DAWV2S#10S";
	//stringstream ss1(str1);
	//stringstream ss2(str2);



	/*cout << ss1.get() << " ";
	cout << ss1.get() << " ";
	cout << ss1.get() << " ";
	cout << ss1.get() << " ";
	cout << ss1.get() << " ";*/


	bool chk = true;
	
	while (chk)
	{
		getline(cin, *str);
		
		
		if (chknum(str))
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

bool chknum(string *ss)
{
	bool result = true;

	stringstream ss_t(*ss);
	char t;


	while(ss_t>> t)
	{
		if (t<48 || t>57)
		{
			result = false;
			break;
		}


		
	}

	return result;
}