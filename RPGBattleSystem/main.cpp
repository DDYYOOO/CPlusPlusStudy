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

	// player객체 생성 initilize
	// Monster객체 생성
	// Monster Reward객체 생성
	// Reward Item객체 생성

	Player* p1 = new Player();
	Monster* m1 = new Monster();
}