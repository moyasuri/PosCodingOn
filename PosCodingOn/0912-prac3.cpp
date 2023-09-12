#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

enum e_Player
{
	Knight,
	Mage,
	Archer

};
enum e_Monster
{
	goblin,
	orc,
	dragon
};

enum e_Item
{
	e_hp_portion,
	e_mp_portion,
	e_portal

};

enum e_status_effect
{
	e_poison = 0b00000001,
	e_stun = 0b00000010,
};

enum playerType
{
	e_player,
	e_monster

};

class Client
{
public:
	void Client_On()
	{

		void play_game();

	}


	void play_game()
	{
		srand(time(NULL));

		int tmp_cmd = 0;
		cout << "직업을 선택해주세요 (0)기사, (1)법사, (2) 궁수 " << endl;
		cin >> tmp_cmd;
		Character my_Cha(tmp_cmd);
		// Monster my_Mon;

		int cmd = 0;
		while (_Exit)
		{
			cout << "다음 행동을 알려주세요" << endl;
			// 0 : 종료 1 : att , 2:item  3: skill

		}
	}



public:
	bool _Exit = true;

};

class Item
{
public:

	// item 클래스 선언을 하면
	item[0][0],[1]
	item[1][0],[1] 개수?
	Item()
	{
		vector<Item>
	}

public:
	string  _item_name;
	int _num_item;

};
class Player
{
public:
	Player()
	{

	}


	//void levelup()
	//{
	//	this->_level++;
	//	cout << "level up!!" << endl;
	//	cout << "현재레벨 : " << this->_level << endl;

	//}

	//void Item_root()
	//{
	//	this->_item_num++;
	//	cout << "아이템을 얻었습니다 !" << endl;
	//	cout << "현재 아이템 개수 : " << this->_item_num << endl;

	//}
	void Item_use(e_Item item)
	{
		switch (item)
		{
			case e_hp_portion:
			break;

			case e_mp_portion:
			break;

			case e_portal:
			break;



		}

	}
	void Attack(Player& player, Player& monster)
	{
		if (player._att - monster._defence <= 0)
		{
			player._hp -= 1;
		}
		else
			monster._hp -= (player._att - monster._defence);
		
	}
	// 상태확인을 만들어야되는데 

	short Chk_status_effect(Player& monster)
	{
		if (monster._status_effect && e_poison)
		{
			return e_poison;
		}
		if (monster._status_effect && e_stun)
		{
			return e_stun;
		}
	}

	// 현재상황을 나타내는 프린트 함수가 필요해
	void Chk_Print_status(Player player)
	{
		if(!_player_type)
		{ 
			cout << "현재 플레어의 hp = " << player._hp;
			cout << "현재 플레어의 mp = " << player._mp;
			 // 아이템 개수
		}
		else
		{

		}

	}


	/*void Print_Now()
	{
		cout << "레벨: " << this->_level << endl;
		cout << "현재 아이템 개수: " << this->_item_num << endl;
	}*/


public:
	
	int _player_type=0; // 사람 or 몬스터
	int _max_hp = 0; // 최대 hp
	int _max_mp = 0; // 최대 mp
	int _hp=0; // 현재 hp
	int _mp=0; // 현재 mp
	int _att = 0; // 공격력
	int _defence=0; // 방어력
	short _status_effect = 0b00000000; // 상태이상


};



class Character : public Player
{

public:
	Character(int type)
	{
		
		cout << " 캐릭터가 생성 되었습니다" << endl;
		this->_player_type = 0;

		

		switch (type)
		{
		case Knight:
			this->_hp = 500;
			this->_mp = 0;
			this->_att = 30;
			this->_defence = 10;

			this->_class = Knight;
			cout << "기사 캐릭터가 생성 되었습니다" << endl;
			break;

		case Mage:
			this->_hp = 150;
			this->_mp = 200;
			this->_att = 100;
			this->_defence = 0;
			this->_class = Mage;


			cout << "법사 캐릭터가 생성 되었습니다" << endl;
			break;

		case Archer:
			this->_hp = 250;
			this->_mp = 50;
			this->_att = 50;
			this->_defence = 0;
			this->_class = Archer;


			cout << "궁수 캐릭터가 생성 되었습니다" << endl;
			break;
		}


		this->_player_type = e_player;
	}

	void Attack() {}
	void UseItem() {}
	void UseSkill() {}

	Item i;
	

public:
	int _level = 1; // 레벨
	int _item_num = 0; // 소지아이템
	int _class = 0; // 플레이어 직업
	int _necc_exp = 50; // 필요한 경험치
	int _exp_now = 0;
	int _skill = 0; // 보유 스킬?
};

class Monster : public Player
{
	Monster(int type)
	{

		switch (type)
		{
			case goblin:

				this -> _hp = 30;
				this -> _mp = 0;
				this -> _att = 5;
				this-> _defence = 0;
				this-> _exp = 10;
				this->_status_effect = 0;

				
				cout << "빈약한 고블린이 나타났다!" << endl;
				break;

			case orc:
				this->_hp = 80;
				this->_mp = 20;
				this->_att = 15;
				this->_defence = 3;
				this->_exp = 30;
				this->_status_effect = 0;

				cout << "살기가 느껴지는 오크르가 등장한다!" << endl;
				break;

			case dragon:
				this->_hp = 200;
				this->_mp = 50;
				this->_att = 50;
				this->_defence = 10;
				this->_exp = 100;
				this->_status_effect = 0;

				cout << "짱쌘 투명 드래곤이 강림한다" << endl;
				break;
		}
			

		this->_player_type = e_monster;
	}

public:

	
	int _exp = 0;

};




int main()
{

	Client TalesOfEternia; // 똥겜
	TalesOfEternia.Client_On();


}