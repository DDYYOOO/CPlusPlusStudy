#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<iomanip>

// ƽ���� ����
// ������	3x3  ������(0 ~ 8)�� �������Ѵ� -> Ŭ������ ǥ�� class Board
// ��� 1 : �÷��̾ ���� �׸��� = X or O - insert_X, insert_O  
// ��� 2 : win_X, win_O
// �¸� ���� : ������ �ϼ�, ������ �ϼ�, �밢��(���� �����Ʒ�), �밢��(���� ���ʾƷ�)

// ����ϱ� ���� �Լ�
// std::cin >> input; �������� �ƴ��� �Ǻ�, std::isdigit();
// std::settw() ������ ���̸� �����ϰ� ���߾� �ִ� �Լ�
// �����͸� Ŭ������ ǥ���� �� -> iterator
// ���ڿ��� Ŭ������ ǥ���� �� -> string

class Board
{
	// bMap ����ִ� �����Ͱ� �������� �ƴ��� üũ�ϴ� �Լ�
	bool isNum(std::string& s);
private:
	int size;	// ũ�� 3
	std::string** bMap;// 2���� �迭[����][����] 
public:
	Board();
	~Board() {}
	
	void GamePlay();

	// 2���� �迭�� �����͸� �ִ� �Լ�
	bool Insert_X(int pos);
	bool Insert_O(int pos);
	
	// 2���� �迭 �ȿ� �����Ͱ� �ִ��� ������ üũ�ϴ� �Լ�
	std::string Get_Item(int pos) const;
	std::string Get_Item(int col, int row) const;

	// �����ǿ� ����ִ� ���� ������ִ� �Լ�
	void Print();

	
	bool X_Win();
	bool O_Win();

	int GetSize() const { return size; }

};

// std::cout �Լ��� �̿��ؼ� Ŭ������ ���
std::ostream& operator<<(std::ostream& out, const Board& b);