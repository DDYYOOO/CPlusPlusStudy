#include"GameObjects.h"


// 플레이어
void Player::Attack(Monster* monster)
{
	// monster->Damaged(AP); : 몬스터가 공격을 받음
	std::cout << "플레이어 공격" << std::endl;
	monster->Damaged(this->AP);

	// 몬스터 죽음 : bool isDead()
	if (monster->IsDead())
	{
		
	}
	else
	{
		
	}

	// 만약 몬스터가 죽었으면 -> 보상(Reward)Has-A 몬스터(Monster)
	// monster->reward->GetExp, GetGold, GetItem
}

void Player::Damaged(int damage)
{
	std::cout << "플레이어가 " << damage << "만큼 공격 받음" << std::endl;
	HP -= damage;


	// 만약 플레이어가 사망했다면 -> 게임오버함수를 호출
	if (IsDead())
	{
		HP = 0;
		std::cout << "플레이어 사망" << std::endl;
		exit(0);
		// 게임종료 함수
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
	std::cout << "획득한 경험치 : " << std::endl;
	this->exp += exp;
}

void Player::GetMoney(int money)
{
	std::cout << "획득한 재화 : " << std::endl;
	this->money += money;
}

std::vector<Item>* Player::GetInventory()
{
	return &inventory;
}

void Player::ShowStatus()
{
	std::cout << "현재 체력 : " << HP << std::endl;
	std::cout << "현재 공격력 : " << AP << std::endl;
	std::cout << "현재 경험치 : " << exp << std::endl;
	std::cout << "----------현재 소지품-------------" << std::endl;
	std::cout << "현재 금액 : " << money << std::endl;
	// 현재 아이템의 최대 수. 배열[i] -> 아이템 번호, 아이템 이름....
	std::cout << "현재 아이템 : " << "함수로 구현(미구현)" << std::endl;

}

// Goblin
void Goblin::Attack(Player* player)
{
	std::cout << "Goblin 공격" << std::endl;
	player->Damaged(AP);
}

void Goblin::Damaged(Player* player)
{
	std::cout << "Goblin이 " << player->GetAP() << "만큼 공격 받음" << std::endl;
	HP -= player->GetAP();	// Player->AP // player.


	// 만약 플레이어가 사망했다면 -> 게임오버함수를 호출
	if (IsDead())
	{
		HP = 0;
		std::cout << "Goblin을 처지했습니다" << std::endl;
		// 보상 아이템 함수
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
	std::cout << "몬스터 처치 보상" << std::endl;
	monsterReward->RewardExp();
	monsterReward->RewardMoney();
	//monsterReward->RewardItem();
}


// Reward
void Reward::RewardItem(std::vector<Item>* inventory)
{
	if (item != nullptr)	// 아이템이 있을 경우에만 플레이어 인벤토리에 추가
	{
		inventory->push_back(*item);
		std::cout << "아이템 획득"<< std::endl;
		item->ShowItemInfo();
	}
}
