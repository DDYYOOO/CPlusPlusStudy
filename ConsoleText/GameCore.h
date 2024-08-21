#pragma once
#include<string>
#include<vector>
#include<iostream>

struct Position
{
	int posX;
	int posY;

	// 연산자 오버로딩 사용
	bool operator == (const Position& otherPos) const
	{
		return posX == otherPos.posX && posY == otherPos.posY;
	}
	
	bool operator != (const Position& otherPos) const
	{
		return !(*this == otherPos);
	}
};


// Commnadparse();
// if(CommandType == North) PlayerState.currentposY 좌표 이동

class Playerstate
{
public:
	int CurrentMapIndex;		// 현재 플레이어가 위치하고 있는 맵 번호
	Position CurrentPosition;	// 현재 플레이어의 입력
	Position NewPosition;		// 입력 받은 플레이어의 위치


};

// ConsoleText 맵 이동 기능
// 현재 맵 정보, 현재 맵의 설명

class MapData
{
public:
	std::string Name;	// Name = "초원";
	std::string Description;  // 이 맵의 정보를 작성
	std::string MapInfo;	  // 맵의 문자 데이터가 저장되어 있다
	unsigned int MapWidth;	  // 맵의 최대 가로 길이
	Position MapPosition;	// 맵마다 시작하는 위치 다르게 하기 위해서 (x, y)
	MapData();
	MapData(std::string Name, std::string Description, std::string MapInfo)
	{
		this->Name = Name;
		this->Description = Description;
		this->MapInfo = MapInfo;
	}

};

class WorldState	// 맵이 여러개 있는 World <- 플레이어가 위치해야할 정보를 담고 있는 클래스
{
public:
	std::vector<MapData> Mapdatas;
};

void InitializeGame(Playerstate& playerstate, WorldState& worldstate);
void RenderGame(Playerstate& playerstate, const WorldState& worldstate);
void GetInput(Playerstate& playerstate, const WorldState& worldstate);
void UpdateGame(Playerstate& playerstate, WorldState& worldstate);
int PositionToIndex(const Position& position, int mapWidth);
bool IsSpaceOutsideMap(const Position& pos, const MapData& currentMap);
bool IsSpaceCanMove(const Position& pos, const MapData& currentMap);