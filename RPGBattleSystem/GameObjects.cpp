#include"GameObjects.h"


// �÷��̾�
void Player::Attack(Monster* monster)
{
	// monster->Damaged(AP); : ���Ͱ� ������ ����
	std::cout << "�÷��̾� ����" << std::endl;
	monster->Damaged(this->AP);

	// ���� ���� : bool isDead()
	if (monster->IsDead())
	{
		
	}
	else
	{
		
	}

	// ���� ���Ͱ� �׾����� -> ����(Reward)Has-A ����(Monster)
	// monster->reward->GetExp, GetGold, GetItem
}

void Player::Damaged(int damage)
{
	std::cout << "�÷��̾ " << damage << "��ŭ ���� ����" << std::endl;
	HP -= damage;


	// ���� �÷��̾ ����ߴٸ� -> ���ӿ����Լ��� ȣ��
	if (IsDead())
	{
		HP = 0;
		std::cout << "�÷��̾� ���" << std::endl;
		exit(0);
		// �������� �Լ�
		// GameManager->GameEnd() or RetunrLobby()
	}
}

bool Player::IsDead()
{
	if (HP <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::GetExp(int exp)
{
	std::cout << "ȹ���� ����ġ : " << std::endl;
	this->exp += exp;
}

void Player::GetMoney(int money)
{
	std::cout << "ȹ���� ��ȭ : " << std::endl;
	this->money += money;
}

std::vector<Item>* Player::GetInventory()
{
	return &inventory;
}

void Player::ShowStatus()
{
	std::cout << "���� ü�� : " << HP << std::endl;
	std::cout << "���� ���ݷ� : " << AP << std::endl;
	std::cout << "���� ����ġ : " << exp << std::endl;
	std::cout << "----------���� ����ǰ-------------" << std::endl;
	std::cout << "���� �ݾ� : " << money << std::endl;
	// ���� �������� �ִ� ��. �迭[i] -> ������ ��ȣ, ������ �̸�....
	std::cout << "���� ������ : " << "�Լ��� ����(�̱���)" << std::endl;

}

// Goblin
void Goblin::Attack(Player* player)
{
	std::cout << "Goblin ����" << std::endl;
	player->Damaged(AP);
}

void Goblin::Damaged(Player* player)
{
	std::cout << "Goblin�� " << player->GetAP() << "��ŭ ���� ����" << std::endl;
	HP -= player->GetAP();	// Player->AP // player.


	// ���� �÷��̾ ����ߴٸ� -> ���ӿ����Լ��� ȣ��
	if (IsDead())
	{
		HP = 0;
		std::cout << "Goblin�� ó���߽��ϴ�" << std::endl;
		// ���� ������ �Լ�
		DorpReward(player);
	}
}

bool Goblin::IsDead()
{
	if (HP <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Goblin::DorpReward(Player* player)
{
	std::cout << "���� óġ ����" << std::endl;
	monsterReward->RewardExp();
	monsterReward->RewardMoney();
	//monsterReward->RewardItem();
}


// Reward
void Reward::RewardItem(std::vector<Item>* inventory)
{
	if (item != nullptr)	// �������� ���� ��쿡�� �÷��̾� �κ��丮�� �߰�
	{
		inventory->push_back(*item);
		std::cout << "������ ȹ��"<< std::endl;
		item->ShowItemInfo();
	}
}
