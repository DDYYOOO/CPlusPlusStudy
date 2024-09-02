#include<iostream>
#include<stdlib.h>
#include"StdExample.cpp"
#include"TicTacToe.h"

// Ŭ���� Ű����, �̸�, ����� �ؾ��ϸ� ����� ����
// ��ɰ� ������� ���� private, public, protected
// ������, �Ҹ���, ���� ������, (���� ����, ���� ����)
// ��� : Virtual <-> �Ϲ��Լ�
// ������ ǥ�� - Ŭ������ Ȯ�强�� ����
// virtual �Լ�(); �ڽ� �Լ�(�̸��� ���� �Լ�) override;
// C++����ȯ �θ�<->�ڽ� ����ȯ : dynamic_cast, if���� �Բ� ����ؼ� ������ ����ȯ ����
// template �Ϲ�ȭ �ڵ� �ۼ�

template<typename T>
class SingleTon
{
private:
	static T* singleton;
public:
	SingleTon() {}
	virtual ~SingleTon() {}
	static T* GetSingleTon()
	{
		if (nullptr == singleton)
		{
			singleton = new T;
		}
		return singleton;
	}
	static void Release()
	{
		delete singleton;
		singleton == nullptr;
	}

};

template<typename T>
T* SingleTon<T>::singleton = nullptr;

// GameManager Ŭ������ SingleTon Ŭ������ ��ӹ޴´�. 
// SingleTon Ŭ������ GameManager Ŭ������ ���������� ����ϰ� �ִ�
class GameManager : public SingleTon<GameManager>
{
private:
	// ���
public:
	GameManager() {}
	~GameManager() {}
	// ��� : ���ӽ���, ��������, ����ȭ�� ���
	void MainMenu()
	{
		std::cout << "���θ޴� ����" << std::endl;

		while (1)
		{
			//system("cls");
			int userInput = 0;
			std::cout << "1. ���� ����" << std::endl;
			std::cout << "2. ���� ����" << std::endl;
			std::cin >> userInput;

			if(userInput == 1)
			{
				GameStart();
			}
			else if (userInput == 2)
			{
				GameEnd();
			}
			else
			{
				std::cout << "�߸��� �Է��Դϴ� �ٽ� �Է��ϼ���." << std::endl;
			}
		}
	}
	void GameStart()
	{
		std::cout << "���� ����" << std::endl;
		// Ŭ���� ���� �̸�.h ���� �̸�.cpp
		// Board board; board.GamePlay();
		Board b;

		while (1)
		{
			// ������ �帧 ����
		}

	}
	void GameEnd()
	{
		exit(0);
	}
};

int main()
{
	std::cout << "STD�Լ� ����" << std::endl;

	//SampleSTD* sample = new SampleSTD;
	////sample->SetWidthExample();
	//sample->IsDigitExample();
	//delete sample;
	

	
	// GameManager* gm = GameManager::GetSingleTon();
	//gm->MainMenu();


}