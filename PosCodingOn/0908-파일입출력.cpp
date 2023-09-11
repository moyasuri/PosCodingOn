//#include <iostream>
//#include <fstream>
//using namespace std;
#include <locale.h>




// <fstream> 파일을 읽고, 쓸 수 있도록 관련 기능을 제공하는 헤더
// .open("파일명"); // 파일 열기
// .is_open(); //파일 열기에 성공했다면 true
// .fail(); // 파일 열기에 실패했다면 true
// .close(); 파일 닫기


// ifstream
// 파일의 내용을 가지고와서 프로글매에 입력할 수 있게 도와주는 클래스

// string str
// file >> str // 띄어쓰기 전까지 str에 저장


// 연구할 가치<<
// ifstream x
// x>>name>>tel

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <sstream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class member_Inf
{
public:
	vector<string> _name;
	vector<int> _pw;
	vector<string> _phone;
};

void prac0()
{
	// std::ifstream file_read;
	// file_read.open("test_file.txt");   

	// 파일 선언과, 열기를 따로따로

	std::ifstream file_read("hello.txt"); // 파일 선언 및 열기를 동시에
	if (file_read.fail()) {
		cout << "파일 없음" << endl;
		// return -1;파일이 안열리거나 없을때 반환해주는 숫자 (함수가 int형이라 걍 -1 반환해준것)
	}

	string file_str = "";
	string line;
	vector<string> myStr;

	// * 중요, vector라는 개념이 자동으로 capa 늘려주는게 아니라 push_back 같은 함수를 썻을때에만 자동으로 늘려주는 개념이야.
	// 따라서 아래와 같은 실습을 할때에는 assign을 반드시 해줘야돼
	myStr.assign(10, ""); // 글이 몇줄로 나뉘어져 있을지 모르니 10을 넣음
	int k = 0; // string vector의 인덱스


	while (std::getline(file_read, line)) { // get_line() file의 내용을 한 줄씩 읽어옴
		file_str += line + "\n";
		cout << line << endl;
		myStr[k] = line;
		k++;
	}

	file_read.close();


	//
	//
	//
	//// 할당을 반드시해야한다.
	//
	//file_str = "";
	//
	//for (vector<string>::reverse_iterator it = myStr.rbegin(); it !=myStr.rend() ;it++)
	//{
	//	if(*it!="")
	//	file_str += *it + "\n";
	//}
	//
	//
	//std::ofstream file;
	// 프로그램의 출력을 파일에 저장할 수 있게 돕는 클래스(program -> file)
	//
	//file.open("output.txt");
	//ofstream 기본값->  std::ios::out (쓰기모드) | std::ios::trunc (파일의 내용을 모두 삭제하고 열기)
	//file.open("test_file2.txt", std::ios::out | std::ios::app); // std::ios::app ( 파일의 마지막 줄에 추가 )
	//if (file.fail()) {
	//	cout << "파일 열기 실패" << endl;
	//	return -1;
	//}
	// 보통 쓰기권한에서는 파일이 없을 경우 자동으로 생성됨. 만약 자동으로 생성되지 않았을 경우 fail()이 true가 나올 예정
	// file << file_str; // file_str 을 file에 작성
	//file.close();
	//
}

member_Inf prac1()
{

	member_Inf _mem;
	vector<string> name;
	vector<int> pw;
	string t_name;
	int t_pw;

	cout << "3명의 회원에 대한 이름 비밀번호를 순차적으로 입력하세요." << endl;
	cout << "1번째회원 : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);
	cout << "2번째회원 : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);
	cout << "3번째회원 : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);

	cout << "------------ 회원 명부 파일 읽기 -------------" << endl;



	
	std::ofstream file;
	// 프로그램의 출력을 파일에 저장할 수 있게 돕는 클래스(program -> file)

	file.open("member.txt");
	if (file.fail()) {
		cout << "파일 열기 실패" << endl;
		//return -1;
	}
	// 보통 쓰기권한에서는 파일이 없을 경우 자동으로 생성됨. 만약 자동으로 생성되지 않았을 경우 fail()이 true가 나올 예정
	string file_str = "";
	vector<string>::iterator it = name.begin();	
	vector<int>::iterator it2 = pw.begin();
	for (it; it != name.end();it++)
	{
		file_str = file_str + *it + " " + to_string(*it2) + "\n";
		it2++;
	}


	file << file_str; // file_str 을 file에 작성
	file.close();



	std::ifstream file_read("member.txt"); // 파일 선언 및 열기를 동시에
	if (file_read.fail()) {
		cout << "파일 없음" << endl;
	}


		file_str = "";
		string line;


		while (std::getline(file_read, line)) { // get_line() file의 내용을 한 줄씩 읽어옴
			file_str += line + "\n";
			cout << line << endl;
		}

		file_read.close();

		_mem._name =  name;
		_mem._pw =  pw;

	
		return _mem;
}
void t_prac2()
{
//#include <iostream>
//#include <fstream>
//#include <string>
//
//	using std::cout;
//	using std::cin;
//	using std::endl;
//	using std::getline;
//	using std::string;

		std::ifstream member_file;
		std::string name, pw, str1, str2;
		member_file.open("member.txt");
		std::cout << "이름을 입력하세요.";
		std::cin >> name;

		std::cout << "비번을 입력하세요.";
		std::cin >> pw;

		bool flag = false;
		while (member_file >> str1 >> str2) {
			if (name == str1 && pw == str2) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "로그인 성공";
		else cout << "로그인 실패";

		member_file.close();

		
	
}
void t_ex()
{


	
	std::ofstream file("example.txt", std::ios::in | std::ios::out); // Open the file for both reading and writing

	if (!file) {
		std::cerr << "Error opening file." << std::endl;
		//return 1;
	}

	// Seek to a specific position in the file (byte offset)
	std::streampos positionToModify = 10; // Change this to your desired position
	file.seekp(positionToModify, std::ios::beg);

	// Write new data at the specified position
	//std::string newData = "This is the new data.";
	std::string newData = "This";
	file.write(newData.c_str(), newData.length());

	// Close the file
	file.close();

	std::cout << "Data modified successfully." << std::endl;

}

bool checkFileOpen(std::ifstream& file) {
	if (file.fail()) return false;
	else return true;
}

bool checkFileOpen(std::ofstream& file) {
	if (file.fail()) {
		cout << "파일 없음" << endl;
		return false;
	}
	else return true;
}

void t_prac3()
{
	std::ifstream member_file;
	std::string name, pw, name_in, pw_in;

	member_file.open("member.txt");
	if (!checkFileOpen(member_file))
	{
		// return -1;

	}

	
	cout << "이름을 입력하세요. ";
	cin >> name_in;
	
	cout << "비번을 입력하세요. ";
	cin >> pw_in;

	bool flag = false; // 로그인 성공 여부를 담는 변수
	while (member_file >> name >> pw) {
		if (name == name_in && pw == pw_in) {
			flag = true;
			break;
		}
	}
	member_file.close();

	if (flag) {
		std::string tel_in, tel;
		cout << "로그인 성공" << endl;
		cout << "전화번호를 입력하세요. ";
		cin >> tel_in;

		std::ifstream member_tel_file_r("member_tel.txt");
		std::string member_tel_temp = "";

		bool is_modify = false; // 기존 정보 수정 or 추가를 판단하는 변수
		if (!member_tel_file_r.fail()) {
			while (member_tel_file_r >> name >> tel) {
				std::string line = name + " ";
				if (name == name_in) {
					line += tel_in;
					is_modify = true;
				}
				else line += tel;
				member_tel_temp += line + "\n";
			}
			member_tel_file_r.close();
		}

		std::ofstream member_tel_file_w;

		if (is_modify) {
			member_tel_file_w.open("member_tel.txt");
			member_tel_file_w << member_tel_temp;
		}
		else {
			member_tel_file_w.open("member_tel.txt", std::ios::app);
			member_tel_file_w << name_in + " " + tel_in + "\n";
		}

		member_tel_file_w.close();
	}
	else cout << "로그인 실패";

	
}

void prac23(member_Inf mem_ex)
{
	string name2;
	int pw2;

	cout << "이름을 입력하세요 : ";
	cin >> name2;
	
	cout << "비번을 입력하세요 : ";
	cin >> pw2;

	
	
	vector<string>::iterator it = mem_ex._name.begin();
	vector<int>::iterator it2 = mem_ex._pw.begin();

	for (it; it != mem_ex._name.end();it++)
	{
		if (name2 == *it)
		{
			if (pw2 == *it2)
			{
				cout << "로그인 성공" << endl;
				break;
			}
		}
		it2++;

		if (it == mem_ex._name.end() - 1)
		{
			cout << "로그인 실패"<< endl;
			return;
			
		}

	}



	cout << "전화번호를 입력해주세요 :";

	string tel_t;
	cin >> tel_t;


	// 현재 전화번호부 파일 읽기

	std::ifstream file_read("member_tel.txt");

	//if (file_read.fail()) {
	//	cout << "파일 없으니 생성" << endl;
	//	std::ofstream file;
	//	
	//	file.open("member_tel.txt");
	//	if (file.fail()) {
	//		cout << "파일 열기 실패" << endl;
	//	}
	//}


	member_Inf chk;
	string file_str = "";
	string line;
	
	while (std::getline(file_read, line)) { // get_line() file의 내용을 한 줄씩 읽어옴
		stringstream stream;
		stream.str(line);
		
		while (stream >> line)
		{
			chk._name.push_back(line);
			stream >> line;
			chk._phone.push_back(line);
		}
		// stream.str("");//초기화
		// stream.clear();
	}

	file_read.close();

	// 같은 사람이 있는가 확인하기
	bool chk_iden = true;
	for (int i=0; i<mem_ex._name.size();i++)
	{
		for (int j = 0; j < chk._name.size();j++)
		{
			if (mem_ex._name[i] == chk._name[j])
			{
				chk._phone[j] = tel_t;
				chk_iden = false;
			}
		}
	}
	if (chk_iden)
	{
		chk._name.push_back(name2);
		chk._phone.push_back(tel_t);
	}

	file_str = "";
	line = "";
	std::ofstream file;

	file.open("member_tel.txt");

	for(int i =0; i<chk._name.size();i++)
	{
		file_str += chk._name[i] +" " + chk._phone[i] + "\n";
		
	}
	file << file_str; // file_str 을 file에 작성
	file.close();

	
	// 없으면 다음줄에 넣고
	// 있으면 전화번호 갈아보기

	//member_Inf _mem;
	//vector<string> name;
	//vector<int> pw;
	//string t_name;
	//int t_pw;

	//cin >> t_name >> t_pw;








	//std::ofstream file;
	//// 프로그램의 출력을 파일에 저장할 수 있게 돕는 클래스(program -> file)

	//file.open("member.txt");
	//if (file.fail()) {
	//	cout << "파일 열기 실패" << endl;
	//	//return -1;
	//}

	//std::ifstream file_read("hello.txt"); // 파일 선언 및 열기를 동시에
	//if (file_read.fail()) {
	//	cout << "파일 없음" << endl;
	//	// return -1;파일이 안열리거나 없을때 반환해주는 숫자 (함수가 int형이라 걍 -1 반환해준것)
	//}

	//string file_str = "";
	//string line;


	//while (std::getline(file_read, line)) { // get_line() file의 내용을 한 줄씩 읽어옴
	//	file_str += line + "\n";
	//	cout << line << endl;
	//}

}

int main(){

	setlocale(LC_ALL, "Korean");

	member_Inf ex;
	ex = prac1();
	prac23(ex);




	return 0;
}