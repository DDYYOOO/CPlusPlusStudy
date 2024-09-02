#include "TicTacToe.h"

Board::Board()
{
	size = 3;
	bMap;
}

void Board::Insert_X(int pos)
{
	pos;
}

void Board::Insert_Y(int pos)
{

}

std::string Board::Get_Item(int pos)
{
	return std::string();
}

bool Board::X_Win()
{
	return false;
}

bool Board::O_Win()
{
	return false;
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
	// TODO: 여기에 return 문을 삽입합니다.
}

void Board::GamePlay()
{
	while (1)
	{
		// 게임이 종료되면 승리를 선언하고 메인화면으로 돌아간다. 게임을 종료
	}
}