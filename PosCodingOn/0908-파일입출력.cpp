//#include <iostream>
//#include <fstream>
//using namespace std;
#include <locale.h>




// <fstream> ĆÄŔĎŔť ŔĐ°í, žľ źö ŔÖľľˇĎ °üˇĂ ąâ´ÉŔť ÁŚ°řÇĎ´Â Çě´ő
// .open("ĆÄŔĎ¸í"); // ĆÄŔĎ ż­ąâ
// .is_open(); //ĆÄŔĎ ż­ąâżĄ źş°řÇß´Ů¸é true
// .fail(); // ĆÄŔĎ ż­ąâżĄ ˝ÇĆĐÇß´Ů¸é true
// .close(); ĆÄŔĎ ´Ýąâ


// ifstream
// ĆÄŔĎŔÇ łťżëŔť °ĄÁö°íżÍź­ ÇÁˇÎąŰ¸ĹżĄ ŔÔˇÂÇŇ źö ŔÖ°Ô ľľżÍÁÖ´Â ĹŹˇĄ˝ş

// string str
// file >> str // śçžîž˛ąâ ŔüąîÁö strżĄ ŔúŔĺ


// żŹą¸ÇŇ °ĄÄĄ<<
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

	// ĆÄŔĎ źąžđ°ú, ż­ąâ¸Ś ľűˇÎľűˇÎ

	std::ifstream file_read("hello.txt"); // ĆÄŔĎ źąžđ š× ż­ąâ¸Ś ľż˝ĂżĄ
	if (file_read.fail()) {
		cout << "ĆÄŔĎ žřŔ˝" << endl;
		// return -1;ĆÄŔĎŔĚ žČż­¸Ž°ĹłŞ žřŔťś§ šÝČŻÇŘÁÖ´Â źýŔÚ (ÇÔźö°Ą intÇüŔĚśó °Á -1 šÝČŻÇŘÁŘ°Í)
	}

	string file_str = "";
	string line;
	vector<string> myStr;

	// * Áßżä, vectorśó´Â °łłäŔĚ ŔÚľżŔ¸ˇÎ capa ´ĂˇÁÁÖ´Â°Ô žĆ´Ďśó push_back °°Ŕş ÇÔźö¸Ś §Ŕťś§żĄ¸¸ ŔÚľżŔ¸ˇÎ ´ĂˇÁÁÖ´Â °łłäŔĚžß.
	// ľűśóź­ žĆˇĄżÍ °°Ŕş ˝Ç˝ŔŔť ÇŇś§żĄ´Â assignŔť šÝľĺ˝Ă ÇŘÁŕžßľĹ
	myStr.assign(10, ""); // ąŰŔĚ ¸îÁŮˇÎ łŞ´ľžîÁŽ ŔÖŔťÁö ¸đ¸Ł´Ď 10Ŕť łÖŔ˝
	int k = 0; // string vectorŔÇ ŔÎľŚ˝ş


	while (std::getline(file_read, line)) { // get_line() fileŔÇ łťżëŔť ÇŃ ÁŮžż ŔĐžîżČ
		file_str += line + "\n";
		cout << line << endl;
		myStr[k] = line;
		k++;
	}

	file_read.close();


	//
	//
	//
	//// ÇŇ´çŔť šÝľĺ˝ĂÇŘžßÇŃ´Ů.
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
	// ÇÁˇÎą×ˇĽŔÇ ĂâˇÂŔť ĆÄŔĎżĄ ŔúŔĺÇŇ źö ŔÖ°Ô ľ˝´Â ĹŹˇĄ˝ş(program -> file)
	//
	//file.open("output.txt");
	//ofstream ąâşť°Ş->  std::ios::out (ž˛ąâ¸đľĺ) | std::ios::trunc (ĆÄŔĎŔÇ łťżëŔť ¸đľÎ ťčÁŚÇĎ°í ż­ąâ)
	//file.open("test_file2.txt", std::ios::out | std::ios::app); // std::ios::app ( ĆÄŔĎŔÇ ¸śÁö¸ˇ ÁŮżĄ Ăß°Ą )
	//if (file.fail()) {
	//	cout << "ĆÄŔĎ ż­ąâ ˝ÇĆĐ" << endl;
	//	return -1;
	//}
	// ş¸Ĺë ž˛ąâąÇÇŃżĄź­´Â ĆÄŔĎŔĚ žřŔť °ćżě ŔÚľżŔ¸ˇÎ ťýźşľĘ. ¸¸žŕ ŔÚľżŔ¸ˇÎ ťýźşľÇÁö žĘžŇŔť °ćżě fail()ŔĚ true°Ą łŞżĂ żšÁ¤
	// file << file_str; // file_str Ŕť fileżĄ ŔŰźş
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

	cout << "3¸íŔÇ Č¸żřżĄ ´ëÇŃ ŔĚ¸§ şńšĐšřČŁ¸Ś źřÂ÷ŔűŔ¸ˇÎ ŔÔˇÂÇĎźźżä." << endl;
	cout << "1šřÂ°Č¸żř : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);
	cout << "2šřÂ°Č¸żř : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);
	cout << "3šřÂ°Č¸żř : " ;
	cin >> t_name >> t_pw;
	name.push_back(t_name);
	pw.push_back(t_pw);

	cout << "------------ Č¸żř ¸íşÎ ĆÄŔĎ ŔĐąâ -------------" << endl;



	
	std::ofstream file;
	// ÇÁˇÎą×ˇĽŔÇ ĂâˇÂŔť ĆÄŔĎżĄ ŔúŔĺÇŇ źö ŔÖ°Ô ľ˝´Â ĹŹˇĄ˝ş(program -> file)

	file.open("member.txt");
	if (file.fail()) {
		cout << "ĆÄŔĎ ż­ąâ ˝ÇĆĐ" << endl;
		//return -1;
	}
	// ş¸Ĺë ž˛ąâąÇÇŃżĄź­´Â ĆÄŔĎŔĚ žřŔť °ćżě ŔÚľżŔ¸ˇÎ ťýźşľĘ. ¸¸žŕ ŔÚľżŔ¸ˇÎ ťýźşľÇÁö žĘžŇŔť °ćżě fail()ŔĚ true°Ą łŞżĂ żšÁ¤
	string file_str = "";
	vector<string>::iterator it = name.begin();	
	vector<int>::iterator it2 = pw.begin();
	for (it; it != name.end();it++)
	{
		file_str = file_str + *it + " " + to_string(*it2) + "\n";
		it2++;
	}


	file << file_str; // file_str Ŕť fileżĄ ŔŰźş
	file.close();



	std::ifstream file_read("member.txt"); // ĆÄŔĎ źąžđ š× ż­ąâ¸Ś ľż˝ĂżĄ
	if (file_read.fail()) {
		cout << "ĆÄŔĎ žřŔ˝" << endl;
	}


		file_str = "";
		string line;


		while (std::getline(file_read, line)) { // get_line() fileŔÇ łťżëŔť ÇŃ ÁŮžż ŔĐžîżČ
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
		std::cout << "ŔĚ¸§Ŕť ŔÔˇÂÇĎźźżä.";
		std::cin >> name;

		std::cout << "şńšřŔť ŔÔˇÂÇĎźźżä.";
		std::cin >> pw;

		bool flag = false;
		while (member_file >> str1 >> str2) {
			if (name == str1 && pw == str2) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "ˇÎą×ŔÎ źş°ř";
		else cout << "ˇÎą×ŔÎ ˝ÇĆĐ";

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
		cout << "ĆÄŔĎ žřŔ˝" << endl;
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

	
	cout << "ŔĚ¸§Ŕť ŔÔˇÂÇĎźźżä. ";
	cin >> name_in;
	
	cout << "şńšřŔť ŔÔˇÂÇĎźźżä. ";
	cin >> pw_in;

	bool flag = false; // ˇÎą×ŔÎ źş°ř żŠşÎ¸Ś ´ă´Â şŻźö
	while (member_file >> name >> pw) {
		if (name == name_in && pw == pw_in) {
			flag = true;
			break;
		}
	}
	member_file.close();

	if (flag) {
		std::string tel_in, tel;
		cout << "ˇÎą×ŔÎ źş°ř" << endl;
		cout << "ŔüČ­šřČŁ¸Ś ŔÔˇÂÇĎźźżä. ";
		cin >> tel_in;

		std::ifstream member_tel_file_r("member_tel.txt");
		std::string member_tel_temp = "";

		bool is_modify = false; // ąâÁ¸ Á¤ş¸ źöÁ¤ or Ăß°Ą¸Ś ĆÇ´ÜÇĎ´Â şŻźö
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
	else cout << "ˇÎą×ŔÎ ˝ÇĆĐ";

	
}

void prac23(member_Inf mem_ex)
{
	string name2;
	int pw2;

	cout << "ŔĚ¸§Ŕť ŔÔˇÂÇĎźźżä : ";
	cin >> name2;
	
	cout << "şńšřŔť ŔÔˇÂÇĎźźżä : ";
	cin >> pw2;

	
	
	vector<string>::iterator it = mem_ex._name.begin();
	vector<int>::iterator it2 = mem_ex._pw.begin();

	for (it; it != mem_ex._name.end();it++)
	{
		if (name2 == *it)
		{
			if (pw2 == *it2)
			{
				cout << "ˇÎą×ŔÎ źş°ř" << endl;
				break;
			}
		}
		it2++;

		if (it == mem_ex._name.end() - 1)
		{
			cout << "ˇÎą×ŔÎ ˝ÇĆĐ"<< endl;
			return;
			
		}

	}



	cout << "ŔüČ­šřČŁ¸Ś ŔÔˇÂÇŘÁÖźźżä :";

	string tel_t;
	cin >> tel_t;


	// ÇöŔç ŔüČ­šřČŁşÎ ĆÄŔĎ ŔĐąâ

	std::ifstream file_read("member_tel.txt");

	//if (file_read.fail()) {
	//	cout << "ĆÄŔĎ žřŔ¸´Ď ťýźş" << endl;
	//	std::ofstream file;
	//	
	//	file.open("member_tel.txt");
	//	if (file.fail()) {
	//		cout << "ĆÄŔĎ ż­ąâ ˝ÇĆĐ" << endl;
	//	}
	//}


	member_Inf chk;
	string file_str = "";
	string line;
	
	while (std::getline(file_read, line)) { // get_line() fileŔÇ łťżëŔť ÇŃ ÁŮžż ŔĐžîżČ
		stringstream stream;
		stream.str(line);
		
		while (stream >> line)
		{
			chk._name.push_back(line);
			stream >> line;
			chk._phone.push_back(line);
		}
		// stream.str("");//ĂĘąâČ­
		// stream.clear();
	}

	file_read.close();

	// °°Ŕş ťçś÷ŔĚ ŔÖ´Â°Ą ČŽŔÎÇĎąâ
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
	file << file_str; // file_str Ŕť fileżĄ ŔŰźş
	file.close();

	
	// žřŔ¸¸é ´ŮŔ˝ÁŮżĄ łÖ°í
	// ŔÖŔ¸¸é ŔüČ­šřČŁ °ĽžĆş¸ąâ

	//member_Inf _mem;
	//vector<string> name;
	//vector<int> pw;
	//string t_name;
	//int t_pw;

	//cin >> t_name >> t_pw;








	//std::ofstream file;
	//// ÇÁˇÎą×ˇĽŔÇ ĂâˇÂŔť ĆÄŔĎżĄ ŔúŔĺÇŇ źö ŔÖ°Ô ľ˝´Â ĹŹˇĄ˝ş(program -> file)

	//file.open("member.txt");
	//if (file.fail()) {
	//	cout << "ĆÄŔĎ ż­ąâ ˝ÇĆĐ" << endl;
	//	//return -1;
	//}

	//std::ifstream file_read("hello.txt"); // ĆÄŔĎ źąžđ š× ż­ąâ¸Ś ľż˝ĂżĄ
	//if (file_read.fail()) {
	//	cout << "ĆÄŔĎ žřŔ˝" << endl;
	//	// return -1;ĆÄŔĎŔĚ žČż­¸Ž°ĹłŞ žřŔťś§ šÝČŻÇŘÁÖ´Â źýŔÚ (ÇÔźö°Ą intÇüŔĚśó °Á -1 šÝČŻÇŘÁŘ°Í)
	//}

	//string file_str = "";
	//string line;


	//while (std::getline(file_read, line)) { // get_line() fileŔÇ łťżëŔť ÇŃ ÁŮžż ŔĐžîżČ
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