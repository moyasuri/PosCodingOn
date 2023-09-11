//#include <iostream>
//#include <fstream>
//using namespace std;
#include <locale.h>




// <fstream> ������ �а�, �� �� �ֵ��� ���� ����� �����ϴ� ���
// .open("���ϸ�"); // ���� ����
// .is_open(); //���� ���⿡ �����ߴٸ� true
// .fail(); // ���� ���⿡ �����ߴٸ� true
// .close(); ���� �ݱ�


// ifstream
// ������ ������ ������ͼ� ���α۸ſ� �Է��� �� �ְ� �����ִ� Ŭ����

// string str
// file >> str // ���� ������ str�� ����


// ������ ��ġ<<
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

	// ���� �����, ���⸦ ���ε���

	std::ifstream file_read("hello.txt"); // ���� ���� �� ���⸦ ���ÿ�
	if (file_read.fail()) {
		cout << "���� ����" << endl;
		// return -1;������ �ȿ����ų� ������ ��ȯ���ִ� ���� (�Լ��� int���̶� �� -1 ��ȯ���ذ�)
	}

	string file_str = "";
	string line;
	vector<string> myStr;

	// * �߿�, vector��� ������ �ڵ����� capa �÷��ִ°� �ƴ϶� push_back ���� �Լ��� ���������� �ڵ����� �÷��ִ� �����̾�.
	// ���� �Ʒ��� ���� �ǽ��� �Ҷ����� assign�� �ݵ�� ����ߵ�
	myStr.assign(10, ""); // ���� ���ٷ� �������� ������ �𸣴� 10�� ����
	int k = 0; // string vector�� �ε���


	while (std::getline(file_read, line)) { // get_line() file�� ������ �� �پ� �о��
		file_str += line + "\n";
		cout << line << endl;
		myStr[k] = line;
		k++;
	}

	file_read.close();


	//
	//
	//
	//// �Ҵ��� �ݵ���ؾ��Ѵ�.
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
	// ���α׷��� ����� ���Ͽ� ������ �� �ְ� ���� Ŭ����(program -> file)
	//
	//file.open("output.txt");
	//ofstream �⺻��->  std::ios::out (������) | std::ios::trunc (������ ������ ��� �����ϰ� ����)
	//file.open("test_file2.txt", std::ios::out | std::ios::app); // std::ios::app ( ������ ������ �ٿ� �߰� )
	//if (file.fail()) {
	//	cout << "���� ���� ����" << endl;
	//	return -1;
	//}
	// ���� ������ѿ����� ������ ���� ��� �ڵ����� ������. ���� �ڵ����� �������� �ʾ��� ��� fail()�� true�� ���� ����
	// file << file_str; // file_str �� file�� �ۼ�
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

	cout << "3���� ȸ���� ���� �̸� ��й�ȣ�� ���������� �Է��ϼ���." << endl;
	cout << "1��°ȸ�� : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);
	cout << "2��°ȸ�� : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);
	cout << "3��°ȸ�� : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);

	cout << "------------ ȸ�� ��� ���� �б� -------------" << endl;



	
	std::ofstream file;
	// ���α׷��� ����� ���Ͽ� ������ �� �ְ� ���� Ŭ����(program -> file)

	file.open("member.txt");
	if (file.fail()) {
		cout << "���� ���� ����" << endl;
		//return -1;
	}
	// ���� ������ѿ����� ������ ���� ��� �ڵ����� ������. ���� �ڵ����� �������� �ʾ��� ��� fail()�� true�� ���� ����
	string file_str = "";
	vector<string>::iterator it = name.begin();	
	vector<int>::iterator it2 = pw.begin();
	for (it; it != name.end();it++)
	{
		file_str = file_str + *it + " " + to_string(*it2) + "\n";
		it2++;
	}


	file << file_str; // file_str �� file�� �ۼ�
	file.close();



	std::ifstream file_read("member.txt"); // ���� ���� �� ���⸦ ���ÿ�
	if (file_read.fail()) {
		cout << "���� ����" << endl;
	}


		file_str = "";
		string line;


		while (std::getline(file_read, line)) { // get_line() file�� ������ �� �پ� �о��
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
		std::cout << "�̸��� �Է��ϼ���.";
		std::cin >> name;

		std::cout << "����� �Է��ϼ���.";
		std::cin >> pw;

		bool flag = false;
		while (member_file >> str1 >> str2) {
			if (name == str1 && pw == str2) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "�α��� ����";
		else cout << "�α��� ����";

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
		cout << "���� ����" << endl;
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

	
	cout << "�̸��� �Է��ϼ���. ";
	cin >> name_in;
	
	cout << "����� �Է��ϼ���. ";
	cin >> pw_in;

	bool flag = false; // �α��� ���� ���θ� ��� ����
	while (member_file >> name >> pw) {
		if (name == name_in && pw == pw_in) {
			flag = true;
			break;
		}
	}
	member_file.close();

	if (flag) {
		std::string tel_in, tel;
		cout << "�α��� ����" << endl;
		cout << "��ȭ��ȣ�� �Է��ϼ���. ";
		cin >> tel_in;

		std::ifstream member_tel_file_r("member_tel.txt");
		std::string member_tel_temp = "";

		bool is_modify = false; // ���� ���� ���� or �߰��� �Ǵ��ϴ� ����
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
	else cout << "�α��� ����";

	
}

void prac23(member_Inf mem_ex)
{
	string name2;
	int pw2;

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> name2;
	
	cout << "����� �Է��ϼ��� : ";
	cin >> pw2;

	
	
	vector<string>::iterator it = mem_ex._name.begin();
	vector<int>::iterator it2 = mem_ex._pw.begin();

	for (it; it != mem_ex._name.end();it++)
	{
		if (name2 == *it)
		{
			if (pw2 == *it2)
			{
				cout << "�α��� ����" << endl;
				break;
			}
		}
		it2++;

		if (it == mem_ex._name.end() - 1)
		{
			cout << "�α��� ����"<< endl;
			return;
			
		}

	}



	cout << "��ȭ��ȣ�� �Է����ּ��� :";

	string tel_t;
	cin >> tel_t;


	// ���� ��ȭ��ȣ�� ���� �б�

	std::ifstream file_read("member_tel.txt");

	//if (file_read.fail()) {
	//	cout << "���� ������ ����" << endl;
	//	std::ofstream file;
	//	
	//	file.open("member_tel.txt");
	//	if (file.fail()) {
	//		cout << "���� ���� ����" << endl;
	//	}
	//}


	member_Inf chk;
	string file_str = "";
	string line;
	
	while (std::getline(file_read, line)) { // get_line() file�� ������ �� �پ� �о��
		stringstream stream;
		stream.str(line);
		
		while (stream >> line)
		{
			chk._name.push_back(line);
			stream >> line;
			chk._phone.push_back(line);
		}
		// stream.str("");//�ʱ�ȭ
		// stream.clear();
	}

	file_read.close();

	// ���� ����� �ִ°� Ȯ���ϱ�
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
	file << file_str; // file_str �� file�� �ۼ�
	file.close();

	
	// ������ �����ٿ� �ְ�
	// ������ ��ȭ��ȣ ���ƺ���

	//member_Inf _mem;
	//vector<string> name;
	//vector<int> pw;
	//string t_name;
	//int t_pw;

	//cin >> t_name >> t_pw;








	//std::ofstream file;
	//// ���α׷��� ����� ���Ͽ� ������ �� �ְ� ���� Ŭ����(program -> file)

	//file.open("member.txt");
	//if (file.fail()) {
	//	cout << "���� ���� ����" << endl;
	//	//return -1;
	//}

	//std::ifstream file_read("hello.txt"); // ���� ���� �� ���⸦ ���ÿ�
	//if (file_read.fail()) {
	//	cout << "���� ����" << endl;
	//	// return -1;������ �ȿ����ų� ������ ��ȯ���ִ� ���� (�Լ��� int���̶� �� -1 ��ȯ���ذ�)
	//}

	//string file_str = "";
	//string line;


	//while (std::getline(file_read, line)) { // get_line() file�� ������ �� �پ� �о��
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