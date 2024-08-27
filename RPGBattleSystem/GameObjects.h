#pragma once
#include<iostream>
#include<cstring>


class Player
{
private:
	int HP;
	int AttackPower;
	// ü��, ���ݷ�
public:
	// ������
	Player() {}
	Player(int hp, int attackpower)
	{
		HP = hp;
		AttackPower = attackpower;
	}
	// �Ҹ���
	~Player() {}
	// �����ϴ�
	void Attack(Monster* monster);
	// ���ݹ޴�
	void Damaged(Monster* monster);
};

// ���� ���� �Լ�
class Monster
{
private:
	int HP;
	int AttackPower;
	std::string Name;
	// ����
	Reward* monsterReward;
public:
	// ������
	Monster() {}
	Monster(int _hp, int _attackpower)
	{
		HP = _hp;
		AttackPower = _attackpower;
	}
	// �Ҹ���
	~Monster() {}
	// �����ϴ�
	virtual void Attack() = 0;
	// ���ݹ޴�
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
	// ������
	Item* item;
};

class Item
{

};