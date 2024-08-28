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
		std::cout << "������ �̸� : " << Name << std::endl;
		std::cout << "������ ��ȣ : " << index << std::endl;
	}
};


class Reward
{
private:
	int exp;
	int money;
	// ������
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

// ���Ϳ��� ����
// 1. ����

class Monster;

class Player
{
private:
	// ü��, ���ݷ�
	int HP;
	int AP;
	std::string Name;
	int exp;
	int money;
	std::vector<Item> inventory;	// ���� �迭(�迭�� ���̸� �ٲ۴�) vector
public:
	// ������
	Player() {}
	Player(int hp, int ap, std::string name) : HP(hp), AP(ap), Name(name)
	{
		std::cout << "�÷��̾� ����" << std::endl;
	}
	// �Ҹ���
	~Player()  // ���� �Ҵ����� �� delete
	{
		std::cout << "�÷��̾� �Ҹ�" << std::endl;
	}
	// �����ϴ�
	void Attack(Monster* monster);
	// ���ݹ޴�
	void Damaged(int damage);
	// ���üũ �Լ�
	bool IsDead();

	int GetAP()
	{
		return AP;
	}
	void GetExp(int exp);
	void GetMoney(int money);
	std::vector<Item>* GetInventory();
	// �÷��̾��� ���罺��
	void ShowStatus();
};

// ���� ���� �Լ�
class Monster
{
protected:
	int HP;
	int AP;
	std::string Name;
	// ����
	Reward* monsterReward;
public:
	// ������
	Monster() {}
	Monster(int hp, int ap) : HP(hp), AP(ap) {}
	// �Ҹ���
	~Monster() {}
	// �����ϴ�
	virtual void Attack(Player* player) = 0;
	// ���ݹ޴�
	virtual void Damaged(Player* player) = 0;
	// ���üũ �Լ�
	virtual bool IsDead() = 0;
	// DropReward
	virtual void DorpReward(Player* player) = 0;
};

class Goblin : public Monster
{
public:
	Goblin(int hp, int ap) : Monster(hp, ap)
	{	
		std::cout << "Goblin����" << std::endl;
	}
	~Goblin() 
	{
		std::cout << "Goblin �Ҹ�" << std::endl;
	}
	void InsertDropItemTable(Reward* rewardPtr)
	{
		monsterReward = new Reward();
		monsterReward = rewardPtr;
	}
	// �����ϴ�
	void Attack(Player* player);
	// ���ݹ޴�
	void Damaged(Player* player);
	// ���üũ �Լ�
	bool IsDead();
	// DropReward
	void DorpReward(Player* player);
};

