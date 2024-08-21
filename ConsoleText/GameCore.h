#pragma once
#include<string>
#include<vector>
#include<iostream>

struct Position
{
	int posX;
	int posY;

	// ������ �����ε� ���
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
// if(CommandType == North) PlayerState.currentposY ��ǥ �̵�

class Playerstate
{
public:
	int CurrentMapIndex;		// ���� �÷��̾ ��ġ�ϰ� �ִ� �� ��ȣ
	Position CurrentPosition;	// ���� �÷��̾��� �Է�
	Position NewPosition;		// �Է� ���� �÷��̾��� ��ġ


};

// ConsoleText �� �̵� ���
// ���� �� ����, ���� ���� ����

class MapData
{
public:
	std::string Name;	// Name = "�ʿ�";
	std::string Description;  // �� ���� ������ �ۼ�
	std::string MapInfo;	  // ���� ���� �����Ͱ� ����Ǿ� �ִ�
	unsigned int MapWidth;	  // ���� �ִ� ���� ����
	Position MapPosition;	// �ʸ��� �����ϴ� ��ġ �ٸ��� �ϱ� ���ؼ� (x, y)
	MapData();
	MapData(std::string Name, std::string Description, std::string MapInfo)
	{
		this->Name = Name;
		this->Description = Description;
		this->MapInfo = MapInfo;
	}

};

class WorldState	// ���� ������ �ִ� World <- �÷��̾ ��ġ�ؾ��� ������ ��� �ִ� Ŭ����
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