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

		int cmd;
		while (_Exit)
		{
			cout << "다음 행동을 알려주세요" << endl;


		}
	}



public:
	bool _Exit = true;

};

class Item
{
public:

	Item()
	{

	}

public:
	string _I_name;
	int _effect;


};
class Player
{
public:
	Player()
	{

	}


	void levelup()
	{
		this->_level++;
		cout << "level up!!" << endl;
		cout << "현재레벨 : " << this->_level << endl;

	}

	void Item_root()
	{
		this->_item_num++;
		cout << "아이템을 얻었습니다 !" << endl;
		cout << "현재 아이템 개수 : " << this->_item_num << endl;

	}
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

	void Print_Now()
	{
		cout << "레벨: " << this->_level << endl;
		cout << "현재 아이템 개수: " << this->_item_num << endl;
	}


public:
	
	int _player_type=0;
	int _max_hp = 0;
	int _max_mp = 0;
	int _hp=0;
	int _mp=0;
	int _att = 0;
	int _defence=0;
	int _level = 1;
	int _item_num = 0;
	short _status_effect = 0;
	int _class = 0 ;
	int _skill = 0 ;
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
			cout << "기사 캐릭터가 생성 되었습니다" << endl;
			break;

		case Mage:
			this->_hp = 150;
			this->_mp = 200;
			this->_att = 100;
			this->_defence = 0;
			cout << "법사 캐릭터가 생성 되었습니다" << endl;
			break;

		case Archer:
			this->_hp = 250;
			this->_mp = 50;
			this->_att = 50;
			this->_defence = 0;
			cout << "궁수 캐릭터가 생성 되었습니다" << endl;
			break;
		}


		this->_player_type = e_player;
	}

	Item i;
	

	
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
				cout << "빈약한 고블린이 나타났다!" << endl;
				break;

			case orc:
				this->_hp = 80;
				this->_mp = 20;
				this->_att = 15;
				this->_defence = 3;
				cout << "살기가 느껴지는 오크르가 등장한다!" << endl;
				break;

			case dragon:
				this->_hp = 200;
				this->_mp = 50;
				this->_att = 50;
				this->_defence = 10;
				cout << "짱쌘 투명 드래곤이 강림한다" << endl;
				break;
		}
			

		this->_player_type = e_monster;
	}


};




int main()
{

	string name;

	cout << "이름을 입력해주세요 : ";
	cin >> name;

	Character player(name);

	
	
	


}