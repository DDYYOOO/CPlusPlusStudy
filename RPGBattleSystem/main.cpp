#include"GameObjects.h"
#include<iostream>


// monster calss -> �߻� Ŭ������ ������
// reward class -> ����ġ(int), ��(int), ������(������ ��ȣ...)���
// IS-A, HAS-A

// player <-> monster battle system
// battle calss. bool End() : �÷��̾ �׾��� ��, ���Ͱ� �׾��� ��, �÷��̾ �������� ��
// ���� �ݺ�(������ �� bool)
// 1. playerTurn; (1)����, (2)���, (3)����
// NextTurn
// 2. monsterTurn (1)����

// ���Ͱ� ������ monster class HAS-A -> reward DropItem()
// player.GetItem(monster* m1);

int main()
{
	std::cout << "RPGBattleSystem" << std::endl;

	// 1. ���� ����



	// 2. ���� ���� �÷���


	// phase1. Map adventure (���� ���ƴٴϴ� ���) (Step++ RandomEncount : SRand(5 ~ 25))
	// Ư�� Ÿ���� ������ ���Ͷ� �������� ������ ���� �Լ��� ������

	// phase2. player vs monster(���͸� �ϳ� �����, �� ���� ������ �ٸ� varitaion�� ���͸� ����)

	// player��ü ���� initilize
	// Monster��ü ����
	// Monster Reward��ü ����
	// Reward Item��ü ����

	Player* p1 = new Player();
	Monster* m1 = new Monster();
}