#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

// ifstream = input file stream

//
//	1. 파일을 열때 사용하는 open 함수
//	
//	함수원형 : void open(const char* fileName, ios_base::openmode mode = ios_base::in);
//	
//	함수원형: void open(const string& fileName, ios_base::openmode mode = ios_base::in);
//	
//	함수설명: 첫번째 인자로 open할 파일 이름이 들어가게 됩니다.
//	
//	두번째 인자로는 오픈할 모드인데요.오픈할 파일을 어떤식으로 사용할지 ? 에 따라 모드를 정하면 됩니다.
//	
//	ios_base::in - 파일을 read할 목적으로 open할 것이다.
//	
//	ios_base::out - 파일에 write할 목적으로 open할 것이다.
//	
//	ios_base::binary - 파일을 바이너리 형태로 open할 것이다.
//	
//	이외에도 ios_base::ate, app, trunc 의 모드가 있습니다.
//	
//	보통의 경우에는 ifstream은 in, ofstream은 out으로 default로 들어가 있기 때문에 따로 넣지 않아도됩니다.


// 2. 열렸는지 확인하는 is_open 함수
//	
// 함수원형 : bool is_open() const;
//	
// 함수설명: 파일이 열렸는지 확인하는 함수 입니다.
//
// 
// 3. 파일을 열었으면 꼭 닫아야죠 close 함수
// 
// 함수원형: void close();
// 
// 함수설명: 파일과의 연결을 닫아버리는 함수 입니다.
// 
// 
// 4. char 하나씩 파일에서 프로그램으로 읽어오는 get 함수

//	함수원형: istream& get(char& c);
//	
//	함수설명: 읽은 파일에서 한char 단위로 일겅서 매개변수로 넣은 c에 넣어주는 함수입니다.
//	
//	간단 사용법 :
//	
//	char c;
//	
//	while (readFile.get(c))
//	
//	{
//	
//		//읽은 char가 c에 들어있습니다.
//	
//		cout << c;
//	
//	}
//	
//	
//	
//	5. char 하나씩 읽으면 감질맛나지, 한줄씩 읽어와볼까 ? getline 함수
//	
//	함수원형 : istream & getline(char* str, streamsize len);
//	
//	함수설명: 한줄씩 문자열을 읽어서 str에 저장해주는 함수입니다.
//	
//	한줄의 기준은 '\n' 문자열의 끝을 알리는 개행 문자가 올때 까지, 혹은 파일의 끝을 알리는 EOF를 만날때 까지 입니다
//	
//	
//	
//	** 위 ifstream::getline() 함수를 사용할때 주의할점은 문자열을 받아오는 형태가 char* 타입이기 때문에 string 타입으로 바로 받을 수 없다는 특징이 있습니다.
//	
//	아 string str 선언해서 str.c_str()을 매개변수로 넣으면 된다구요 ? ?
//	
//	땡입니다.str.c_str()은 string을 const char* 타입으로 변환을 하기 때문에 위 함수 첫번째 매개변수로 사용은 불가능합니다.
//	
//	그럼 바로 string 타입으로 얻어오는 방법이 없나요 ? 아닙니다.있습니다.그것은 아래 예제에서 확인하시죠.
// 
// 
// 
// 
// 
// 6. 그래서 파일의 끝이 어디라고 ? eof 함수
// 
// 함수원형 : bool eof() const;
// 
// 함수설명: 파일의 끝이 나오면 true를 반환하고 아니면 false를 반환합니다.
// 파일을 읽을때 커서가 움직이게 되는데 그 커서가 getline, get 함수를 돌게되면 쭉쭉쭉 뒤로 가게 됩니다.
// eof() 함수가 불리면 커서의 위치를 확인하는 내부 로직에 의해서 파일의 끝에 도착했는지 아닌지를 판단하게 됩니다.
// 그래서, 파일의 끝을 만나게 되면 true를 반환하게 되는것입니다.

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 



int main() {

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

	return 0;
}