#include "GameCore.h"
#include"Parser.h"

void InitializeGame(Playerstate& playerstate, WorldState& worldstate)
{
	std::cout << "??? 섬에 오신것을 환영합니다" << std::endl;
	std::cout << "이 섬에 대한 추가 정보를 입력해주세요 " << std::endl;

	playerstate.CurrentMapIndex = 0;
	playerstate.CurrentPosition.posX = playerstate.NewPosition.posX = 3;
	playerstate.CurrentPosition.posY = playerstate.NewPosition.posY = 3;
	
	// 맵에 대한 정보
	// 0
	{
		std::string MapInfo =
			"###..###"
			"#......#"
			"#......#"
			"#......#"
			"########";
		MapData map = MapData("초원", "경치가 아름다운 곳이다. 앞에 이동할 수 있는 문이 보이는 것 같다", MapInfo);
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
		MapData map = MapData("숲속", "울창한 수림에 둘러 쌓여 있다. 나뭇잎 사이로 지나갈 수 있는 길이 보인다", MapInfo);
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
		MapData map = MapData("정글", "습하고 식물들이 많이 있다", MapInfo);
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
		MapData map = MapData("사막", "건조하고 황량한 모래만이 있다", MapInfo);
		map.MapWidth = 8;
		map.MapPosition.posX = 0;
		map.MapPosition.posY = 0;

		worldstate.Mapdatas.push_back(map);
	}
}

void RenderGame(Playerstate& playerstate, const WorldState& worldstate)
{
	// string mpastring = WorldState map배열 -> vector[0]
	// mapstring += (playerstate.currentPosition, "@")

	MapData currentMap = worldstate.Mapdatas[playerstate.CurrentMapIndex];	// 현재 플레이어의 위치한 방 정보를 저장하고 있는 클래스
	
	std::string mapstring = "";			// 맵을 그리기 위한 string클래스 변수
	unsigned int currentSpace = 0;

	while (currentSpace < currentMap.MapInfo.size())		// map 문자열의 전체를 반복해서 확인 
	{
		char playerToDisplay = currentMap.MapInfo[currentSpace]; // 플레이어의 입력을 받을 변수 
		
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

	std::cout << mapstring.c_str() << std::endl;	// 맵에 저장되어 있는 문자열이 출력 되는 것 까지 확인 -> 문자들의 개행문자가 포함 되어있지 않다.
}

void GetInput(Playerstate& playerstate, const WorldState& worldstate)
{
	std::cout << "다음 행동을 입력" << std::endl;
	std::cout << "-> ";
	ConsoleTextCommand command = ParseCommand();	// cout :: 데이터를 입력

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
		// playerstate클래스 bool멤버 변수 선언
		// WantToInventory = true; Update -> 
	}

	std::cout << std::endl;
}

void UpdateGame(Playerstate& playerstate, WorldState& worldstate)
{
	MapData currentMap = worldstate.Mapdatas[playerstate.CurrentMapIndex];

	if (IsSpaceOutsideMap(playerstate.NewPosition, currentMap))		// 맵을 탈출했을 때 맵을 변경해주는 조건
	{
		int newRoomIndex = 0;
		int playerExitType = 0; // 0, 1, 2, 3
		Position targetMapPos = currentMap.MapPosition;

		if (playerstate.NewPosition.posX < 0)
		{
			// 서쪽으로 탈출
			targetMapPos.posX--;
			playerExitType = 1;
		}
		else if (playerstate.NewPosition.posX >= (int)currentMap.MapWidth)
		{
			// 동쪽으로 탈출
			targetMapPos.posX++;
			playerExitType = 2;
		}
		else if (playerstate.NewPosition.posY < 0)
		{
			// 북쪽으로 탈출
			targetMapPos.posY--;
			playerExitType = 3;
		}
		else if (playerstate.NewPosition.posY >= (int)currentMap.MapWidth)
		{
			// 남쪽으로 탈출
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
			std::cout << "탈출하는 맵에 해당하는 정보가 없습니다" << std::endl;
			playerstate.NewPosition = playerstate.CurrentPosition;
		}
	}

	// 이동이 불가능한 조건 : 벽이 있을 때, 아이템이 있을 때....

	// 이동이 가능하면 현재 위체를 NewPosition으로 변경
	if (IsSpaceCanMove(playerstate.NewPosition, currentMap))
	{
		playerstate.CurrentPosition = playerstate.NewPosition;
	}
	else
	{
		std::cout << "이동할 수 없는 공간입니다" << std::endl;
		playerstate.NewPosition = playerstate.CurrentPosition;		// 플레이어가 움직일 수 없기 때문에 NewPosition을 CurrentPosition로 변경
	}

	// 이동이 가능하면 현재 위치를 NewPosition 변경
	playerstate.CurrentPosition = playerstate.NewPosition;
}

int PositionToIndex(const Position& position, int mapWidth)
{
	return position.posY * mapWidth + position.posX;
}

// 맵을 탈출하면 다른 맵이 나오는 기능
bool IsSpaceOutsideMap(const Position& pos, const MapData& currentMap)
{
	
	return pos.posY < 0 ||															// Y가 최대 높이 보다 작을 때 (콘솔에서는 숫자가 작을수록 높다)
		   pos.posX < 0 ||															// X가 0보다 작을 때
		   pos.posY >= (int)(currentMap.MapInfo.size() / currentMap.MapWidth) ||	// Y가 최저 높이보다 클 때
		   pos.posX >= (int)(currentMap.MapWidth);									// X가 맵 길이보다 클 때
}

bool IsSpaceCanMove(const Position& pos, const MapData& currentMap)
{
	int spaceIndex = PositionToIndex(pos, currentMap.MapWidth);
	
	char currentSpace = currentMap.MapInfo[spaceIndex];

	//if (currentSpace == '.')		밑의 코드 한줄이랑 같은 코드
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	return currentSpace == '.';
}

