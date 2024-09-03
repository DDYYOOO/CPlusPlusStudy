#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>

// 틱택토 게임
// 보드판	3x3  격자판(0 ~ 8)을 만들어야한다 -> 클래스로 표현 class Board
// 기능 1 : 플레이어가 돌을 그린다 = X or O - insert_X, insert_O  
// 기능 2 : win_X, win_O
// 승리 조건 : 가로줄 완성, 세로줄 완성, 대각선(왼쪽 오른아래), 대각선(오른 왼쪽아래)

// 사용하기 좋은 함수
// std::cin >> input; 숫자인지 아닌지 판별, std::isdigit();
// std::settw() 가로의 길이를 일정하게 맞추어 주는 함수
// 포인터를 클래스로 표현한 것 -> iterator
// 문자열을 클래스로 표현한 것 -> string

class Board
{
	// bMap 들어있는 데이터가 숫자인지 아닌지 체크하는 함수
	bool isNum(std::string& s);
private:
	int size;	// 크기 3
	std::string** bMap;// 2차원 배열[세로][가로] 
public:
	Board();
	~Board() {}
	
	void GamePlay();

	// 2차원 배열에 데이터를 넣는 함수
	bool Insert_X(int pos);
	bool Insert_O(int pos);
	
	// 2차원 배열 안에 데이터가 있는지 없는지 체크하는 함수
	std::string Get_Item(int pos) const;
	std::string Get_Item(int col, int row) const;

	// 보드판에 들어있는 값을 출력해주는 함수
	void Print();

	
	bool X_Win();
	bool O_Win();

	int GetSize() const { return size; }

};

// std::cout 함수를 이용해서 클래스를 출력
std::ostream& operator<<(std::ostream& out, const Board& b);