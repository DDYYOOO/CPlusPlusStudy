#include<iostream>
#include<stdlib.h>
#include"StdExample.cpp"
#include"TicTacToe.h"

// 클래스 키워드, 이름, 상속을 해야하면 상속을 선언
// 기능과 멤버변수 선언 private, public, protected
// 생성자, 소멸자, 복사 생성자, (얕은 복사, 깊은 복사)
// 상속 : Virtual <-> 일반함수
// 다형성 표현 - 클래스의 확장성을 제공
// virtual 함수(); 자식 함수(이름이 같은 함수) override;
// C++형변환 부모<->자식 형변환 : dynamic_cast, if문과 함께 사용해서 안전한 형변환 가능
// template 일반화 코딩 작성

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

// GameManager 클래스가 SingleTon 클래스를 상속받는다. 
// SingleTon 클래스는 GameManager 클래스를 내부적으로 사용하고 있다
class GameManager : public SingleTon<GameManager>
{
private:
	// 멤버
public:
	GameManager() {}
	~GameManager() {}
	// 기능 : 게임시작, 게임종료, 게임화면 출력
	void MainMenu()
	{
		std::cout << "메인메뉴 시작" << std::endl;

		while (1)
		{
			//system("cls");
			int userInput = 0;
			std::cout << "1. 게임 시작" << std::endl;
			std::cout << "2. 게임 종료" << std::endl;
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
				std::cout << "잘못된 입력입니다 다시 입력하세요." << std::endl;
			}
		}
	}
	void GameStart()
	{
		std::cout << "게임 시작" << std::endl;
		// 클래스 게임 이름.h 게임 이름.cpp
		// Board board; board.GamePlay();
		Board b;

		while (1)
		{
			// 게임의 흐름 정리
		}

	}
	void GameEnd()
	{
		exit(0);
	}
};

int main()
{
	std::cout << "STD함수 예제" << std::endl;

	//SampleSTD* sample = new SampleSTD;
	////sample->SetWidthExample();
	//sample->IsDigitExample();
	//delete sample;
	

	
	// GameManager* gm = GameManager::GetSingleTon();
	//gm->MainMenu();


}