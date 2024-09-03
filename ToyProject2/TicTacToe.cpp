#include "TicTacToe.h"

bool Board::isNum(std::string& s) 
{
	// 조건 : bMap 안에 있는 데이터가 숫자면 true, 아니면 false
	std::string::const_iterator it = s.begin();
	
	while (it != s.end() && std::isdigit(*it))
	{
		++it;
	}

	//if (s.empty() && it == s.end())
	//	return true;
	//else
	//	return false;
	return !s.empty() && it == s.end();
}

Board::Board()		// size = 3		3x3
{
	size = 3;
	bMap = new std::string * [size];

	// 이차원배열[세로][가로]
	for (int i = 0; i < size; i++)
	{
		bMap[i] = new std::string[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::string num = std::to_string((i * size) + j);
			bMap[i][j] = num;
		}
	}
}

bool Board::Insert_X(int pos)
{
	int col = pos / size;
	int row = pos % size;

	// 숫자를 X로 바꾸겠다	조건 : O or X 없을때만
	if (isNum(bMap[col][row]))
	{
		bMap[col][row] = "X";
		return true;
	}
	else
	{
		return false;
	}
}

bool Board::Insert_O(int pos)
{
	int col = pos / size;
	int row = pos % size;

	if (isNum(bMap[col][row]))
	{
		bMap[col][row] = "O";
		return true;
	}
	else
	{
		return false;
	}
}

std::string Board::Get_Item(int pos) const
{
	int col = (pos / size);
	int row = (pos % size);

	return bMap[col][row];
}

std::string Board::Get_Item(int col, int row) const
{
	return bMap[col][row];
}

void Board::Print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << bMap[i][j] << " ";
		}
	}
}

bool Board::X_Win()
{
	// 1. 가로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bMap[i][j] != "X")
				break;
			if (j == (size - 1))
				return true;
		}
	}
	// 2. 세로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bMap[i][j] != "X")
				break;
			if (i == (size - 1))
				return true;
		}
	}
	// 3. 왼쪽 위 -> 오른쪽 아래 대각 완성
	for (int i = 0; i < size; i++)
	{
		if (bMap[i][i] != "X")
			break;
		if (i == (size - 1))
			return true;
	}
	// 4. 오른쪽 위 -> 왼쪽 아래 대각 완성
	for (int i = 0; i < size; i++)
	{
		if (bMap[(size - 1) - i][i] != "X")
			break;
		if (i == (size - 1))
			return true;
	}

	return false;
}

bool Board::O_Win()
{
	// 1. 가로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bMap[i][j] != "O")
				break;
			if (j == (size - 1))
				return true;
		}
	}
	// 2. 세로줄 완성
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (bMap[i][j] != "O")
				break;
			if (i == (size - 1))
				return true;
		}
	}
	// 3. 왼쪽 위 -> 오른쪽 아래 대각 완성
	for (int i = 0; i < size; i++)
	{
		if (bMap[i][i] != "O")
			break;
		if (i == (size - 1))
			return true;
	}
	// 4. 오른쪽 위 -> 왼쪽 아래 대각 완성
	for (int i = 0; i < size; i++)
	{
		if (bMap[(size - 1) - i][i] != "O")
			break;
		if (i == (size - 1))
			return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
	for (int i = 0; i < b.GetSize(); i++)
	{
		out << std::endl;

		for (int j = 0; j < b.GetSize(); j++)
		{
			out << "----";
		}
		out << "-" << std::endl << "│";

		for (int j = 0; j < b.GetSize(); j++)
		{
			std::string item = b.Get_Item(i, j);
			int len = item.length();

			if (len <= 1)
			{
				out << std::setw(2) << item << std::setw(2) << "│";
			}
			else if (len <= 2)
			{
				out << std::setw(1) << item << std::setw(2) << "│";
			}
			else if (len <= 3)
			{
				out << std::setw(0) << item << std::setw(2) << "│";
			}
		}
	}
	out << std::endl;

	for (int j = 0; j < b.GetSize(); j++)
	{
		out << "----";
	}
	out << " ";
	out << std::endl;

	return out;
}

void Board::GamePlay()
{
	bool xTurn = true;

	while (!X_Win() && !O_Win())
	{
		// X와 O의 턴을 만들어준다
		std::cout << std::string(30, '\n');
		std::cout << *this;		// X의 행동을 update해서 그림을 그려준다

		if (xTurn)
		{
			bool inserted = false;
			while (!inserted)	// Insert_X 정상적으로 true 됐을 때 while문이 종료
			{
				int pos;
				std::cout << "X의 차례 : ";
				std::cin >> pos;
				inserted = Insert_X(pos);
			}
			xTurn = false;
		}
		else if(!xTurn)
		{
			bool inserted = false;
			while (!inserted)
			{
				int pos;
				std::cout << "O의 차례 : ";
				std::cin >> pos;
				inserted = Insert_O(pos);
			}
			xTurn = true;
		}
	}

	if (X_Win())
	{
		std::cout << "X의 승리" << std::endl;
	}
	else
	{
		std::cout << "O의 승리" << std::endl;
	}
}