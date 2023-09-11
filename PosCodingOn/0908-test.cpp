#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{

	std::ifstream file_read("test_file.txt"); // ���� ���� �� ���⸦ ���ÿ�
	if (file_read.fail()) {
		cout << "���� ����" << endl;
		return -1;
	}

	string file_str = "";
	string line;
	while (std::getline(file_read, line)) { // get_line() file�� ������ �� �پ� �о��
		file_str += line + "\n";
		cout << line << endl;
	}

	file_read.close();

	std::ofstream file;
	// ���α׷��� ����� ���Ͽ� ������ �� �ְ� ���� Ŭ����(program -> file)

	file.open("test_file2.txt");
	//ofstream �⺻��->  std::ios::out (������) | std::ios::trunc (������ ������ ��� �����ϰ� ����)
	//file.open("test_file2.txt", std::ios::out | std::ios::app); // std::ios::app ( ������ ������ �ٿ� �߰� )
	if (file.fail()) {
		cout << "���� ���� ����" << endl;
		//return -1;
	}
	// ���� ������ѿ����� ������ ���� ��� �ڵ����� ������. ���� �ڵ����� �������� �ʾ��� ��� fail()�� true�� ���� ����
	file << file_str; // file_str �� file�� �ۼ�
	file.close();

	return 0;
}