#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

//int solution(vector<string> babbling) {
//
//    vector<string> Words = { "aya", "ye", "woo","ma" };
//    vector<int> Words_Cnt = { 3,2,3,2 };
//    vector<string> Rep = { "000","00","000","00" };
//
//  
//    int tot_Words_Cnt = 0;
//
//    for (vector<string>::iterator it = babbling.begin(); it != babbling.end();++it)
//    {
//
//        string str_bab = *it; //�ٺ���  �������� ���ڿ��� �޾ƿ´�.
//        
//        int sum = 1;
//
//        
//        for (int i = 0;i < 4;i++)
//        {
//    
//         
//                size_t nPos = str_bab.find(Words[i]); // �ٺ��� ���ڿ��� (aya ye woo ma)�� ���ڿ��� ��ġ�ϴ��� Ȯ���Ѵ�.
//                if (nPos != string::npos) {
//                    if (str_bab.size() - str_bab.find(Words[i]) >= 2 * Words_Cnt[i])
//                    {
//                        if (str_bab.substr(str_bab.find(Words[i]) + Words_Cnt[i], Words_Cnt[i]) == Words[i])
//                        {
//                            break;    // ī��Ʈ�ϸ�ȵ�
//                        }
//                        else
//                            str_bab.replace(nPos, Words_Cnt[i], Rep[i]);
//                    }
//                    else
//                    {
//                        str_bab.replace(nPos, Words_Cnt[i], Rep[i]);
//                    }
//                }
//                else
//                {
//                    continue;
//                }
//
//  
//
//            
//        }
//        for (char i : str_bab)
//        {
//            sum *= isdigit(i);
//        }
//        if (sum)
//        {
//            tot_Words_Cnt++;
//        }
//
//
//    }
//
//
//    int answer = tot_Words_Cnt;
//    return answer;
//}


//string solution(string s) {
//
//    if (s[0] > 96 && s[0] < 123)
//    {
//        s[0] = toupper(s[0]);
//    }
//    for (int i = 1; i < s.size();i++)
//    {
//
//        if (s[i - 1] == ' ')
//        {
//            if (s[i] > 96 && s[0] < 123)
//            {
//                s[0] = toupper(s[0]);
//            }
//        }
//        if (s[i] > 64 && s[i] < 91)
//        {
//            s[i] = tolower(s[i]);
//        }
//    }
//    string answer = s;
//    return answer;
//}


string solution(string s)
{


    string my_string = s;
    vector<string> mys;
    string word;
    int space_cnt = 0;
    int space_cnt_b = 0;
    for (char c : my_string)
    {
 

        if (c != ' ') // ������ �ƴϸ�.
        {
            space_cnt = 0;
            word += c; // word�� ĳ���͸� �߰��ϰڴ�.
            if (space_cnt_b >= 1) 
            {
                string temp;
                temp.append(space_cnt_b, ' ');
                mys.push_back(temp);
                
            }
          
        }
        else // �����̶��  > �󸶸�ŭ ������ �ִ��� Ȯ���غ��� �Ѵ�.
        {
            space_cnt++; // �����̴ϱ� ī��Ʈ�� �÷�
            if (space_cnt_b == 0) { // ī��Ʈ�� 1�̶�� ó���̴ϱ� �켱 ��Ʈ���� ���� �Է���
                mys.push_back(word); // mys�� word�� �Է��Ѵ�. 
                word = ""; // word�� �ʱ�ȭ ����
            }

        }
        space_cnt_b = space_cnt;
    }


    vector<string> mys_re;
    for (string str : mys)
    {
        if (str[0] > 96 && str[0] < 123)
        {
            str[0] = toupper(str[0]);
        }

        for (int i = 1;i < str.size();i++)
        {
            if (str[i] > 96 && str[i] < 123)
            {
                str[i] = toupper(str[i]);
            }
            if (str[i] > 64 && str[i] < 91)
            {
                str[i] = tolower(str[i]);
            }
        }
        mys_re.push_back(str);
    }

    string a = mys_re[0];

    for (int i = 1; i < mys_re.size();i++)
    {
        a = a + " " + mys_re[i];
    }


    return a;
 
}


int main()
{


    //vector<string> WordsT = { "ayaayayeayawooma", "ye", "woo","ma" };
    //solution(WordsT);


    //string abc = "0123456789";

    //cout << abc.size() << endl;

    //cout << abc.find("123") << endl;

    //vector<string> str;

    //string  t = "10203";
    //string  p = "15";
    //int k = p.size(); // p�� ���ڰ���
    //int answer = 0;
    //for (int i = 0; i < t.size() - (k-1) ;i++)
    //{
    //    str.push_back(t.substr(i, k));
    //}

    //for (string str_ : str)
    //{
    //    if (str_ <= p)
    //    {
    //        answer++;
    //    }
    //}

    //cout << answer;

    string my_string = "3people unFollowed me";


    cout << solution(my_string) << endl;


    // string temp;
    //temp.append(3, ' ');


    
       
}