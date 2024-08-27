#pragma once
#include<iostream>
#include<cstring>


class Player
{
private:
	int HP;
	int AttackPower;
	// 체력, 공격력
public:
	// 생성자
	Player() {}
	Player(int hp, int attackpower)
	{
		HP = hp;
		AttackPower = attackpower;
	}
	// 소멸자
	~Player() {}
	// 공격하다
	void Attack(Monster* monster);
	// 공격받다
	void Damaged(Monster* monster);
};

// 순수 가상 함수
class Monster
{
private:
	int HP;
	int AttackPower;
	std::string Name;
	// 보상
	Reward* monsterReward;
public:
	// 생성자
	Monster() {}
	Monster(int _hp, int _attackpower)
	{
		HP = _hp;
		AttackPower = _attackpower;
	}
	// 소멸자
	~Monster() {}
	// 공격하다
	virtual void Attack() = 0;
	// 공격받다
	virtual void Damaged() = 0;
	// DropReward
	virtual void DorpReward() = 0;
};

class Goblin : public Monster
{
public:
	Goblin() {}
	Goblin(int hp, int attackpower) : Monster(hp, attackpower)
	{
		hp = hp;
		attackpower = attackpower;
	}
	~Goblin() {}
	void Attack() override
};

class Reward
{
private:
	int exp;
	int money;
	// 아이템
	Item* item;
};

class Item
{

};