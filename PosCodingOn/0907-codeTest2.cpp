#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {

    vector<string> Words = { "aya", "ye", "woo","ma" };
    vector<int> Words_Cnt = { 3,2,3,2 };
    
    int tot_Words_Cnt = 0;

    for (vector<string>::iterator it = babbling.begin(); it != babbling.end();++it)
    {

        string str_bab = *it; //바블링의  순차적인 문자열을 받아온다.
        int cha_cnt = 0;
        for (int i = 0;i < 4;i++)
        {
            int index_Point = 0;
            int index_Point_pre = 0;
            bool conti = true;
            while (conti)
            {
                size_t nPos = str_bab.find(Words[i],index_Point); // 바블링의 문자열이 (aya ye woo ma)의 문자열과 일치하는지 확인한다.
                if (nPos != string::npos) {


                    if (str_bab.size() - str_bab.find(Words[i]) >= 2 * Words_Cnt[i])
                    {
                        if (str_bab.substr(str_bab.find(Words[i]) + Words_Cnt[i], Words_Cnt[i]) == Words[i])
                            break;
                        else
                            index_Point_pre = index_Point;
                            index_Point += str_bab.find(Words[i]) + Words_Cnt[i];
                            cha_cnt += Words_Cnt[i];
                    }
                    else
                    {
                        index_Point_pre = index_Point;
                        index_Point += str_bab.find(Words[i]) + Words_Cnt[i];
                        cha_cnt += Words_Cnt[i];
                    }
                }
                else
                {
                    break;
                }

                if (index_Point == index_Point_pre)
                {
                    conti = false;
                }
                else
                    index_Point_pre = index_Point;
               
            }
        }
        if (cha_cnt == str_bab.size())
        {
            tot_Words_Cnt++;
        }
    }


    int answer = tot_Words_Cnt;
    return answer;
} 

int main()
{


    vector<string> WordsT = { "aya", "ye", "woo","ma" };
    solution(WordsT);
}