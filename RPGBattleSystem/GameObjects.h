#pragma once
#include<iostream>
#include<string>
#include<vector>


class Item
{
private:
	std::string Name;
	int index;
public:
	Item() {}
	Item(std::string name, int index) : Name(name), index(index) {}
	void ShowItemInfo()
	{
		std::cout << "아이템 이름 : " << Name << std::endl;
		std::cout << "아이템 번호 : " << index << std::endl;
	}
};


class Reward
{
private:
	int exp;
	int money;
	// 아이템
	Item* item;
public:
	Reward() {}
	Reward(int exp, int money, Item& item) : exp(exp), money(money)
	{
		this->item = new Item();
		this->item = &item;
	}
	~Reward()
	{
		delete item;
	}
	void RewardItem(std::vector<Item>* inventory);
	int RewardMoney() { return money; };
	int RewardExp() { return exp; };

};

// 몬스터와의 전투
// 1. 공격

class Monster;

class Player
{
private:
	// 체력, 공격력
	int HP;
	int AP;
	std::string Name;
	int exp;
	int money;
	std::vector<Item> inventory;	// 가변 배열(배열의 길이를 바꾼다) vector
public:
	// 생성자
	Player() {}
	Player(int hp, int ap, std::string name) : HP(hp), AP(ap), Name(name)
	{
		std::cout << "플레이어 생성" << std::endl;
	}
	// 소멸자
	~Player()  // 동적 할당했을 때 delete
	{
		std::cout << "플레이어 소멸" << std::endl;
	}
	// 공격하다
	void Attack(Monster* monster);
	// 공격받다
	void Damaged(int damage);
	// 사망체크 함수
	bool IsDead();

	int GetAP()
	{
		return AP;
	}
	void GetExp(int exp);
	void GetMoney(int money);
	std::vector<Item>* GetInventory();
	// 플레이어의 현재스텟
	void ShowStatus();
};

// 순수 가상 함수
class Monster
{
protected:
	int HP;
	int AP;
	std::string Name;
	// 보상
	Reward* monsterReward;
public:
	// 생성자
	Monster() {}
	Monster(int hp, int ap) : HP(hp), AP(ap) {}
	// 소멸자
	~Monster() {}
	// 공격하다
	virtual void Attack(Player* player) = 0;
	// 공격받다
	virtual void Damaged(Player* player) = 0;
	// 사망체크 함수
	virtual bool IsDead() = 0;
	// DropReward
	virtual void DorpReward(Player* player) = 0;
};

class Goblin : public Monster
{
public:
	Goblin(int hp, int ap) : Monster(hp, ap)
	{	
		std::cout << "Goblin생성" << std::endl;
	}
	~Goblin() 
	{
		std::cout << "Goblin 소멸" << std::endl;
	}
	void InsertDropItemTable(Reward* rewardPtr)
	{
		monsterReward = new Reward();
		monsterReward = rewardPtr;
	}
	// 공격하다
	void Attack(Player* player);
	// 공격받다
	void Damaged(Player* player);
	// 사망체크 함수
	bool IsDead();
	// DropReward
	void DorpReward(Player* player);
};

