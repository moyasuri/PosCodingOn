#include <iostream>
#include <string>
#include <vector>
using namespace std;

//int solution(int n) {
//    vector<int> arr;
//
//
//    for (int i = 0;i < n;i++)
//    {
//        if (n % (i + 1) == 0)
//            arr.push_back(i + 1);
//    }
//
//    int sum = 0;
//    for (int i = 0; i < arr.size();i++)
//    {
//        sum += arr[i];
//
//    }
//
//    int answer = sum;
//    return answer;
//}

//string solution(vector<string> arr) {
//
//    vector<string> str;
//    string answer = "";
//    for (vector<string>::iterator it = arr.begin();it != arr.end();++it)
//    {
//        answer += *it;
//    }
//
//
//
//    return answer;
//}

int solution(vector<string> babbling) {

    vector<string> tmp = { "aya", "ye", "woo","ma" };
    vector<int> tmp_n = { 3,2,3,2};

    int cnt = 0;
    
    for (vector<string>::iterator it=babbling.begin(); it != babbling.end();++it)
    {
            int num = 0;
            string temp = *it; //바블링의  순차적인 문자열을 받아온다.
            
            for (int i = 0;i < 4;i++)
            {
                size_t nPos = temp.find(tmp[i]); // 바블링의 문자열이 tmp(aya ye woo ma등)등의 문자열과 일치하는지 확인한다.
                if (nPos != string::npos) {
                    if(temp.size()>=temp.find(tmp[i])+tmp_n[i]+tmp_n[i])
                    {   
                        if (temp.substr(temp.find(tmp[i]) + tmp_n[i], tmp_n[i]) == tmp[i])
                            continue;
                        else
                            num += tmp_n[i];
                    }
                    else
                    {
                        num += tmp_n[i];
                    }
                }
   
            }
            if (num == temp.size())
            {
                cnt++;
            }
    }
    int answer =cnt;
        return answer;
}

//int solution(int n)
//{
//    int answer = 0;
//    
//    string tmp;
//
//    tmp = std::to_string(n);
//
//    
//    vector<int> tmp2;
//    
//    for (int i = 0;i < tmp.length();i++)
//    {   
//        tmp2.push_back(tmp[i] - '0');
//            
//    }
//
//    int sum = 0;
//
//    for (int i : tmp2)
//    {
//        sum += i;
//    }
//    
//
//    return sum;
//}


int solution(vector<int> numbers) {

    vector<int> res;
    vector<int> v(numbers);
    int answer = -1;

    for (int i :v)
    {
        cout << i << endl;
    }


    for (int i = 0; i < v.size() - 1;i++)
    {
        int tmp = i;
        for (int j = i + 1;j < v.size();j++)
        {
            if (v[tmp] >= v[j]) tmp = j;
        }
        swap(v[i], v[tmp]);

    }


    for (int i = 0; i < 10;i++)
    {

        if (v.size() == i)
        {
            v.push_back(i);
            res.push_back(i);
        }

        if (v[i] != i)
        {
            v.insert(v.begin() + i, i);
            res.push_back(i);
        }
    }

    for (int i : res)
    {
        answer += i;
    }

    return answer;
}










void selectionSort(vector<int> v)
{
 

    for (int i = 0; i < v.size() - 1;i++)
    {
        int tmp = i;
        for (int j = i + 1;j < v.size();j++)
        {
            if (v[tmp] >= v[j]) tmp = j;

        }
        swap(v[i], v[tmp]);
    }
}


int main()
{
    //string ttt[] = {"aya", "ye", "woo", "ma"};
    //vector<string> tttt = { "aaayaya",ttt[1],ttt[2],"dsfasd" };
    //solution(tttt);

    vector<int> v = { 0 };

    //for (int i = 0; i < v.size() - 1;i++)
    //{
    //    int tmp = i;
    //    for (int j = i + 1;j < v.size();j++)
    //    {
    //        if (v[tmp] >= v[j]) tmp = j;

    //    }
    //    swap(v[i], v[tmp]);

    //}

    ////for (auto i : v)
    ////{
    ////    cout << i << endl;
    ////}
    //vector<int> res;
    //
    //
    //for (int i=0; i<10;i++)
    //{
    //    //if (v.size()<i+1)
    //    //{
    //    //    v[i+1] == i;
    //    //}
    //    if (v.size() == i)
    //    {
    //        v.push_back(i);
    //        res.push_back(i);
    //    }
    //    if(v[i] != i)
    //    {
    //        v.insert(v.begin() + i, i);
    //        res.push_back(i);
    //        
    //    }


    //}
    //int sum = 0;
    //for (int i : res)
    //{
    // 
    //    sum += i;
    //    cout << sum << endl;
    //}
    
    cout<<  solution(v);
 

}