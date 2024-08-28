#include"GameObjects.h"
#include<iostream>


// monster calss -> 추상 클래스로 만들어라
// reward class -> 경험치(int), 돈(int), 아이템(아이템 번호...)드랍
// IS-A, HAS-A

// player <-> monster battle system
// battle calss. bool End() : 플레이어가 죽었을 때, 몬스터가 죽었을 때, 플레이어가 도주했을 때
// 무한 반복(전투의 끝 bool)
// 1. playerTurn; (1)공격, (2)방어, (3)도주
// NextTurn
// 2. monsterTurn (1)공격

// 몬스터가 죽으면 monster class HAS-A -> reward DropItem()
// player.GetItem(monster* m1);

int main()
{
	std::cout << "RPGBattleSystem" << std::endl;

	// 1. 게임 시작



	// 2. 메인 게임 플레이


	// phase1. Map adventure (맵을 돌아다니는 기능) (Step++ RandomEncount : SRand(5 ~ 25))
	// 특정 타일을 밟으면 몬스터랑 조우할지 안할지 랜덤 함수를 돌린다

	// phase2. player vs monster(몬스터를 하나 만들고, 그 몬스터 같지만 다른 varitaion된 몬스터를 구현)

	// player객체 생성 initialize
	// Monster객체 생성
	// Monster Reward객체 생성
	// Reward Item객체 생성

	Player player(100, 100, "오잉");
	player.Damaged(10);
	

	Item sword("소드", 10);
	Reward goblinReward(50, 1000, sword);
	Goblin goblin(50, 5);
	
	int userInput = 0;
	int turn = 1;

	while (1)
	{
		std::cout << "현재 징행중인 턴수 : " << turn << std::endl;
		std::cout << "1. 공격" << std::endl;
		std::cout << "2. ??" << std::endl;
		std::cin >> userInput;

		if (userInput == 1)
		{
			player.Attack(&goblin);
		}

		std::cout << "Goblin차례" << std::endl;
		goblin.Attack(&player);

		if (player.IsDead() || goblin.IsDead())
		{
			break;
		}

		turn++;
	}
}