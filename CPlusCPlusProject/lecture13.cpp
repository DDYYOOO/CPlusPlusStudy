/*
	작성자 : 이동윤
	작성일 : 2024-08-30
	학습 목표 : 
*/

/*
  template 키워드
  코드를 위한 틀을 만드는 것(데이터 타입)
*/

/*
  클래스 템플릿과 함수 템플릿의 차이점
  함수 템플릿을 함수 호출 시에 <type> 명시하지 않으면 (인자)를 통해 타입을 묵시적으로 템플릿 함수를 선언
  일반함수가 존재한다면, 일반함수가 먼저 호출된다
  클래스 템플릿은 묵시적으로 타입을 지정해주는 기능이 없다
  반드시 <type>을 명시해줘야한다
*/

/*
  C, C++ << 클래스
  추상화 : 현실에 존재하지 않는 것도 코드로 표현
  정보은닉, 캡슐화 -> 프로그래머 실수 방지
  상속 -> 다형성
  STL(Standard Template Library)
  - 안정성 보장 
  - template : 데이터 타입을 모두 대응하는 일반화 프로그래밍
  vector 가변 배열 << 자료구조
*/

// 플레이어 <-> 몬스터 배틀 시스템(Player <-> Monster)
// Gamemanageer클래스
// 기능 : 배틀 종료, 점수, 저장, 게임 종료, 시작, 불러오기


#include"lectures.h"

// 클래스가 한개만 존재해야 하는 패턴화 - 싱글톤 패턴
// template클래스로 표현 -> 싱글톤 패턴이 필요한 클래스를 모두 사용
// 상속 + 템플릿클래스

template<typename T>
class SingleTon
{
	// 반드시 객체가 1개만 있어야 한다
private:
	static T* singleTon;
public:
	SingleTon() {}
	virtual ~SingleTon() {}
	static T* GetSingleTon() 
	{
		if (nullptr == singleTon)
		{
			singleTon = new T;
		}
		return singleTon;
	}
	static void Release()
	{
		delete singleTon;
		singleTon == nullptr;
	}
};

template<typename T>
T* SingleTon<T>::singleTon = nullptr;


class GameManager : public SingleTon<GameManager>
{
private:
	int score;
public:
	GameManager() {}
	~GameManager() {}
	GameManager(int s) : score(s) {}
	int GetScore() { return score; }
	void SetScore(int val) { score = val; }

	// 게임 시작, 저장, 종료...
	void GameStart()
	{
		std::cout << "게임 시작" << std::endl;
	}
	void GameEnd()
	{
		std::cout << "게임 종료" << std::endl;
	}
	void GameSave()
	{
		std::cout << "게임 저장" << std::endl;
	}
	void GameLoad()
	{
		std::cout << "게임 불러오기" << std::endl;
	}
};

// GameData, 플레이 타임, 현재 진행중인 챕터

class GameData : public SingleTon<GameData>
{
private:
	int areaInfo;
public:
	GameData() {}
	~GameData() {}
	GameData(int area) : areaInfo(area) {}
	int GetInfo() { return areaInfo; }
	void SetInfo(int area) { areaInfo = area; }
};

template<typename T>
void Plus(T a, T b)
{
	std::cout << a << " + " << b << " : " << a + b << std::endl;
}


template<typename T1, typename T2>
void SomeFunc(T1 a, T2 b) {}

template<typename T1>
void SomeFunc(T1 a, int b) {}

class One
{
public:
	void operator+(const One& one)
	{
		std::cout << "a + b의 연산자 오버로딩" << std::endl;
	}
};


template<typename T>
class Point
{
private:
	T posX;
	T posY;
public:
	Point() {}
	Point(T x, T y) : posX(x), posY(y) {}
	void Show()
	{
		std::cout << "posX : " << posX << std::endl;
		std::cout << "posY : " << posY << std::endl;
	}
};

// 직접 만든 배열
template<typename T, int N>
class MyArray
{
private:
	T data[N];	// N크기 만큼 배열을 선언
public:
	MyArray() {}
	MyArray(T(&arr)[N])	// 배열을 복사해서 저장하는 생성자
	{
		for (int i = 0; i < N; i++)
		{
			data[i] = arr[i];
		}
	}
	T* GetArr() { return data; }
	int Size() { return N; }
	void ShowInfo()
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << data[i] << ", ";
		}
		std::cout << std::endl;
	}

	void operator+()
	{
		
	}

};

void lecture13()
{
	Plus(1.1, 2.2);

	Point<int> p1(1, 2);
	p1.Show();
	Point<double> p2(1.1, 2.2);
	p2.Show();

	// 배열
	int arrNum[3] = {1, 2, 3};
	MyArray<int, 3> mArray(arrNum);
	std::cout << "MyArray 클래스의 크기 : " << mArray.Size() << std::endl;
	mArray.ShowInfo();

	double arrDouble[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	MyArray<double, 5> arrD(arrDouble);
	arrD.ShowInfo();

	std::cout << "Gamemanager 클래스" << std::endl;

	GameManager* gm = GameManager::GetSingleTon();
	gm->SetScore(100);
	std::cout << gm->GetScore() << std::endl;
	GameManager* gm2 = GameManager::GetSingleTon();
	gm2->SetScore(150);
	std::cout << gm2->GetScore() << std::endl;

	GameData* gd = GameData::GetSingleTon();
	gd->SetInfo(10);
	GameData* gd2 = GameData::GetSingleTon();
	//gd2->SetInfo(15);
	std::cout << gd->GetInfo() << std::endl;
	std::cout << gd2->GetInfo() << std::endl;


	// 게임 시작
	gm->GameStart();
	// 게임 메뉴
	
	// 메인 플레이

	// 종료
	gm->GameEnd();
}