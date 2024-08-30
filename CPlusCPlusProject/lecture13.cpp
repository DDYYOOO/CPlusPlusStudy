/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-30
	�н� ��ǥ : 
*/

/*
  template Ű����
  �ڵ带 ���� Ʋ�� ����� ��(������ Ÿ��)
*/

/*
  Ŭ���� ���ø��� �Լ� ���ø��� ������
  �Լ� ���ø��� �Լ� ȣ�� �ÿ� <type> ������� ������ (����)�� ���� Ÿ���� ���������� ���ø� �Լ��� ����
  �Ϲ��Լ��� �����Ѵٸ�, �Ϲ��Լ��� ���� ȣ��ȴ�
  Ŭ���� ���ø��� ���������� Ÿ���� �������ִ� ����� ����
  �ݵ�� <type>�� ���������Ѵ�
*/

/*
  C, C++ << Ŭ����
  �߻�ȭ : ���ǿ� �������� �ʴ� �͵� �ڵ�� ǥ��
  ��������, ĸ��ȭ -> ���α׷��� �Ǽ� ����
  ��� -> ������
  STL(Standard Template Library)
  - ������ ���� 
  - template : ������ Ÿ���� ��� �����ϴ� �Ϲ�ȭ ���α׷���
  vector ���� �迭 << �ڷᱸ��
*/

// �÷��̾� <-> ���� ��Ʋ �ý���(Player <-> Monster)
// GamemanageerŬ����
// ��� : ��Ʋ ����, ����, ����, ���� ����, ����, �ҷ�����


#include"lectures.h"

// Ŭ������ �Ѱ��� �����ؾ� �ϴ� ����ȭ - �̱��� ����
// templateŬ������ ǥ�� -> �̱��� ������ �ʿ��� Ŭ������ ��� ���
// ��� + ���ø�Ŭ����

template<typename T>
class SingleTon
{
	// �ݵ�� ��ü�� 1���� �־�� �Ѵ�
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

	// ���� ����, ����, ����...
	void GameStart()
	{
		std::cout << "���� ����" << std::endl;
	}
	void GameEnd()
	{
		std::cout << "���� ����" << std::endl;
	}
	void GameSave()
	{
		std::cout << "���� ����" << std::endl;
	}
	void GameLoad()
	{
		std::cout << "���� �ҷ�����" << std::endl;
	}
};

// GameData, �÷��� Ÿ��, ���� �������� é��

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
		std::cout << "a + b�� ������ �����ε�" << std::endl;
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

// ���� ���� �迭
template<typename T, int N>
class MyArray
{
private:
	T data[N];	// Nũ�� ��ŭ �迭�� ����
public:
	MyArray() {}
	MyArray(T(&arr)[N])	// �迭�� �����ؼ� �����ϴ� ������
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

	// �迭
	int arrNum[3] = {1, 2, 3};
	MyArray<int, 3> mArray(arrNum);
	std::cout << "MyArray Ŭ������ ũ�� : " << mArray.Size() << std::endl;
	mArray.ShowInfo();

	double arrDouble[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	MyArray<double, 5> arrD(arrDouble);
	arrD.ShowInfo();

	std::cout << "Gamemanager Ŭ����" << std::endl;

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


	// ���� ����
	gm->GameStart();
	// ���� �޴�
	
	// ���� �÷���

	// ����
	gm->GameEnd();
}