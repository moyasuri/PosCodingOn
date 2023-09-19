#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<time.h>
#include <random>



using namespace std;


bool Check_Array(int x[])
{

    int location;
    int value;
    bool chk= false;

    int count = sizeof(x) / sizeof(int);

    for (int i = 0; i < count-1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {

            if (x[i] == x[j])
            {
                location = i;
                value = x[i];

                cout << " 배열의 중복이 발생하였습니다. " << endl;
                cout << " 중복의 위치는 : [ " << location << " ] 값은 : [ " << value << " ] " << endl;
                x[i] = rand() % 45 + 1;
                chk = true;
                return chk;
            }

        }
    }
    cout << " 배열의 중복된 값이 없습니다. " << endl;
}


int main()
{

	
	//srand((unsigned)time(NULL));
 //   int lotto[6] = {};
 //   for (int i = 0;i < 6;i++)
 //   {
 //       lotto[i] = rand() % 45 + 1;
 //   }
	//
 //   
 //   Check_Array(lotto);



 //   for (int i = 0; i < 6;i++)
 //   {
 //       cout << lotto[i] << endl;
 //       
 //   }
	//

    std::srand(time(NULL));

    int lotto[6];
    int check[46] = { 0, };
    int num;
    for (int i = 0; i < 6; i++) {
        do {
            num = std::rand() % 45 + 1;
        } while (check[num] == 1);
        lotto[i] = num;
        check[num] = 1;
    }

    for (auto n : lotto) {
        cout << n << " ";
    }

    return 0;
	


        //std::mt19937 mtRand;

        //for (int i = 0; i < 10; i++)
        //{
        //    std::cout << mtRand() << std::endl;
        //}

        //std::mt19937_64 rng1(std::time(nullptr));
        //std::uniform_int_distribution<__int64> dist1(1, 45);

        //std::cout << "dist1 Min : " << dist1.min() << std::endl;
        //std::cout << "dist1 Max : " << dist1.max() << std::endl;

        //for (int i = 0; i < 10; i++)
        //{
        //    std::cout << dist1(rng1) << std::endl;
        //}
    

}