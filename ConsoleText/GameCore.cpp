#include "GameCore.h"
#include"Parser.h"

void InitializeGame(Playerstate& playerstate, WorldState& worldstate)
{
	std::cout << "??? ���� ���Ű��� ȯ���մϴ�" << std::endl;
	std::cout << "�� ���� ���� �߰� ������ �Է����ּ��� " << std::endl;

	playerstate.CurrentMapIndex = 0;
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
		map.MapWidth = 8;
		map.MapPosition.posX = 3;
		map.MapPosition.posY = 3;

		worldstate.Mapdatas.push_back(map);
	}
	// 1
	{
		std::string MapInfo =
			"###..###"
			"#......#"
			"#.%....#"
			"#......#"
			"###..###";
		MapData map = MapData("����", "��â�� ������ �ѷ� �׿� �ִ�. ������ ���̷� ������ �� �ִ� ���� ���δ�", MapInfo);
		map.MapWidth = 8;
		map.MapPosition.posX = 3;
		map.MapPosition.posY = 2;

		worldstate.Mapdatas.push_back(map);
	}
	// 2
	{
		std::string MapInfo =
			"###..###"
			"#.#....#"
			"#...##.#"
			"##...#.#"
			"###..###";
		MapData map = MapData("����", "���ϰ� �Ĺ����� ���� �ִ�", MapInfo);
		map.MapWidth = 8;
		map.MapPosition.posX = 0;
		map.MapPosition.posY = 0;

		worldstate.Mapdatas.push_back(map);
	}
	// 3
	{
		std::string MapInfo =
			"###..###"
			"#.#....#"
			"#...##.#"
			"##...#.#"
			"###..###";
		MapData map = MapData("�縷", "�����ϰ� Ȳ���� �𷡸��� �ִ�", MapInfo);
		map.MapWidth = 8;
		map.MapPosition.posX = 0;
		map.MapPosition.posY = 0;

		worldstate.Mapdatas.push_back(map);
	}
}

void RenderGame(Playerstate& playerstate, const WorldState& worldstate)
{
	// string mpastring = WorldState map�迭 -> vector[0]
	// mapstring += (playerstate.currentPosition, "@")

	MapData currentMap = worldstate.Mapdatas[playerstate.CurrentMapIndex];	// ���� �÷��̾��� ��ġ�� �� ������ �����ϰ� �ִ� Ŭ����
	
	std::string mapstring = "";			// ���� �׸��� ���� stringŬ���� ����
	unsigned int currentSpace = 0;

	while (currentSpace < currentMap.MapInfo.size())		// map ���ڿ��� ��ü�� �ݺ��ؼ� Ȯ�� 
	{
		char playerToDisplay = currentMap.MapInfo[currentSpace]; // �÷��̾��� �Է��� ���� ���� 
		
		if (currentSpace == PositionToIndex(playerstate.CurrentPosition, currentMap.MapWidth))
		{
			playerToDisplay += '@';
		}
		mapstring += playerToDisplay;

		if (currentSpace % currentMap.MapWidth == (currentMap.MapWidth - 1))
		{
			mapstring += '\n';
		}
		currentSpace++;
	}

	std::cout << mapstring.c_str() << std::endl;	// �ʿ� ����Ǿ� �ִ� ���ڿ��� ��� �Ǵ� �� ���� Ȯ�� -> ���ڵ��� ���๮�ڰ� ���� �Ǿ����� �ʴ�.
}

void GetInput(Playerstate& playerstate, const WorldState& worldstate)
{
	std::cout << "���� �ൿ�� �Է�" << std::endl;
	std::cout << "-> ";
	ConsoleTextCommand command = ParseCommand();	// cout :: �����͸� �Է�

	if (command.commandType == CommandTypeNorth)
	{
		playerstate.NewPosition.posY = playerstate.CurrentPosition.posY - 1;
	}
	else if (command.commandType == CommandTypeSouth)
	{
		playerstate.NewPosition.posY = playerstate.CurrentPosition.posY + 1;
	}
	else if (command.commandType == CommandTypeWest)
	{
		playerstate.NewPosition.posX = playerstate.CurrentPosition.posX + 1;
	}
	else if (command.commandType == CommandTypeEast)
	{
		playerstate.NewPosition.posX = playerstate.CurrentPosition.posX - 1;
	}
	else if (command.commandType == CommandTypeInventory)
	{
		// playerstateŬ���� bool��� ���� ����
		// WantToInventory = true; Update -> 
	}

	std::cout << std::endl;
}

void UpdateGame(Playerstate& playerstate, WorldState& worldstate)
{
	MapData currentMap = worldstate.Mapdatas[playerstate.CurrentMapIndex];

	if (IsSpaceOutsideMap(playerstate.NewPosition, currentMap))		// ���� Ż������ �� ���� �������ִ� ����
	{
		int newRoomIndex = 0;
		int playerExitType = 0; // 0, 1, 2, 3
		Position targetMapPos = currentMap.MapPosition;

		if (playerstate.NewPosition.posX < 0)
		{
			// �������� Ż��
			targetMapPos.posX--;
			playerExitType = 1;
		}
		else if (playerstate.NewPosition.posX >= (int)currentMap.MapWidth)
		{
			// �������� Ż��
			targetMapPos.posX++;
			playerExitType = 2;
		}
		else if (playerstate.NewPosition.posY < 0)
		{
			// �������� Ż��
			targetMapPos.posY--;
			playerExitType = 3;
		}
		else if (playerstate.NewPosition.posY >= (int)currentMap.MapWidth)
		{
			// �������� Ż��
			targetMapPos.posY++;
			playerExitType = 4;
		}

		bool foundMap = false;

		for (int i = 0; i < worldstate.Mapdatas.size(); i++)
		{
			if (worldstate.Mapdatas[0].MapPosition == targetMapPos)
			{
				foundMap = true;
				newRoomIndex = i;
				break;
			}
		}

		if (foundMap == true)
		{
			playerstate.CurrentMapIndex = newRoomIndex;
		}
		else
		{
			std::cout << "Ż���ϴ� �ʿ� �ش��ϴ� ������ �����ϴ�" << std::endl;
			playerstate.NewPosition = playerstate.CurrentPosition;
		}
	}

	// �̵��� �Ұ����� ���� : ���� ���� ��, �������� ���� ��....

	// �̵��� �����ϸ� ���� ��ü�� NewPosition���� ����
	if (IsSpaceCanMove(playerstate.NewPosition, currentMap))
	{
		playerstate.CurrentPosition = playerstate.NewPosition;
	}
	else
	{
		std::cout << "�̵��� �� ���� �����Դϴ�" << std::endl;
		playerstate.NewPosition = playerstate.CurrentPosition;		// �÷��̾ ������ �� ���� ������ NewPosition�� CurrentPosition�� ����
	}

	// �̵��� �����ϸ� ���� ��ġ�� NewPosition ����
	playerstate.CurrentPosition = playerstate.NewPosition;
}

int PositionToIndex(const Position& position, int mapWidth)
{
	return position.posY * mapWidth + position.posX;
}

// ���� Ż���ϸ� �ٸ� ���� ������ ���
bool IsSpaceOutsideMap(const Position& pos, const MapData& currentMap)
{
	
	return pos.posY < 0 ||															// Y�� �ִ� ���� ���� ���� �� (�ֿܼ����� ���ڰ� �������� ����)
		   pos.posX < 0 ||															// X�� 0���� ���� ��
		   pos.posY >= (int)(currentMap.MapInfo.size() / currentMap.MapWidth) ||	// Y�� ���� ���̺��� Ŭ ��
		   pos.posX >= (int)(currentMap.MapWidth);									// X�� �� ���̺��� Ŭ ��
}

bool IsSpaceCanMove(const Position& pos, const MapData& currentMap)
{
	int spaceIndex = PositionToIndex(pos, currentMap.MapWidth);
	
	char currentSpace = currentMap.MapInfo[spaceIndex];

	//if (currentSpace == '.')		���� �ڵ� �����̶� ���� �ڵ�
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	return currentSpace == '.';
}

