#pragma once
#include<iostream>
#include<cstdlib>
#include<string>

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
private:
	int size;	// ũ�� 3
	std::string** bMap;// 2���� �迭[����][����] 
public:
	Board();
	~Board() {}
	
	void GamePlay();

	// 2���� �迭�� �����͸� �ִ� �Լ�
	void Insert_X(int pos);
	void Insert_Y(int pos);
	
	// 2���� �迭 �ȿ� �����Ͱ� �ִ��� ������ üũ�ϴ� �Լ�
	std::string Get_Item(int pos);
	
	bool X_Win();
	bool O_Win();

	int GetSize() { return size; }

};

// std::cout �Լ��� �̿��ؼ� Ŭ������ ���
std::ostream& operator<<(std::ostream& out, const Board& b);