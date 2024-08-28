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

	// player��ü ���� initialize
	// Monster��ü ����
	// Monster Reward��ü ����
	// Reward Item��ü ����

	Player player(100, 100, "����");
	player.Damaged(10);
	

	Item sword("�ҵ�", 10);
	Reward goblinReward(50, 1000, sword);
	Goblin goblin(50, 5);
	
	int userInput = 0;
	int turn = 1;

	while (1)
	{
		std::cout << "���� ¡������ �ϼ� : " << turn << std::endl;
		std::cout << "1. ����" << std::endl;
		std::cout << "2. ??" << std::endl;
		std::cin >> userInput;

		if (userInput == 1)
		{
			player.Attack(&goblin);
		}

		std::cout << "Goblin����" << std::endl;
		goblin.Attack(&player);

		if (player.IsDead() || goblin.IsDead())
		{
			break;
		}

		turn++;
	}
}