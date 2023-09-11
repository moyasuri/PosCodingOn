#include <iostream>
#include <string>
#include <sstream> 

using namespace std;


int main()
{
	string s = "Codingon";
	
	s[0]=tolower(s[0]);
	cout << s << endl;
	cout << s.substr(s.find("ding"), 4) << endl;
	s.replace(2, 4, "oooo");
	cout << s<<endl;
	s.erase(2, 5);
	cout << s;

}