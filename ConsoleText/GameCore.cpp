#include "GameCore.h"

void InitializeGame(Playerstate& playerstate, WorldState& worldstate)
{
	std::cout << "??? ���� ���Ű��� ȯ���մϴ�" << std::endl;
	std::cout << "�� ���� ���� �߰� ������ �Է����ּ��� " << std::endl;

	playerstate.CurrentPosition.posX = playerstate.NewPosition.posX = 3;
	playerstate.CurrentPosition.posY = playerstate.NewPosition.posY = 3;
	
	// �ʿ� ���� ����
	// 0
	{
		std::string MapInfo =
			"###..###"
			"#......#"
			"#......#"
			"#......#"
			"########";
		MapData map = MapData("�ʿ�", "��ġ�� �Ƹ��ٿ� ���̴�. �տ� �̵��� �� �ִ� ���� ���̴� �� ����", MapInfo);
		map.MapPosition.posX = 0;
		map.MapPosition.posY = 0;

		worldstate.Mapdatas.push_back(map);
	}

	//
	{

	}

	//
	{

	}
}
