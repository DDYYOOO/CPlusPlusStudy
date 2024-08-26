/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-26
	�н� ��ǥ : C++ ����ȯ
*/

// PETŬ���� 
// Dog, HuntDog, Cat : PET�� ����ϴ� Ŭ����
//(down, child, derived) <-> (up, parent, base)

// PetController Ŭ����
// Has-A, Feed(PET* pet) Play(PET* pet)

// 1. Ȯ�强�� ������
// Play(Dog, Cat, Bird....) Ȯ���ؾ� �ϴ� Ŭ���� ��ŭ �����ε��� �ؾ��ϴ� ����
// �ذ���
// Play(PET* pet) -> PETŬ���� �ȿ� �ִ� virtual void PlayWithMaster();
// virtual <-> override

// Ŭ���� �����Ϳ� ��Ӱ���
// Frist Ŭ���� Ÿ��
// SecondŬ���� Ÿ��(FirstŬ���� + Second ���� ���)

// First* a = new First();
// First* b = new Second();

// Second* a = new Second();
// Second* c = new First(); (x)


// C��� ����ȯ  (Ÿ��)�̸�;
// C++��� ����ȯ  ������ �߰��ؼ� �����ڷ� ����;
// static_cast, dynamic_cast, reinterpret_cast, const_cast


#include"lectures.h"

#define _CRT_SECURE_NO_WARNINGS

class First
{
private:
	char* str1;
public:
	First(const char* _str1)
	{
		str1 = new char[strlen(_str1 + 1)];
		strcpy_s(str1, strlen(str1), _str1);
	}
	virtual void SimpleFunc()
	{
		std::cout << str1 << std::endl;
	}
};

class Second : public First
{
private:
	char* str2;
public:
	Second(const char* _str1, const char* _str2) : First(_str1)
	{
		str2 = new char[strlen(_str2 + 1)];
		strcpy_s(str2, strlen(str2), _str2);
	}
	void SimpleFunc() override
	{
		std::cout << str2 << std::endl;
	}
};



class Handler
{
private:
	First* first;
public:
	void Show()
	{
		first->SimpleFunc();
	}
};

// 1. static_cast ������		(static : ������)
// 2. dynamic_cast ������	(dynamic : ������)

// �⺻ ������ Ÿ��(primitive Type) : int, double char���� ����ȯ�� ������ static_cast ���

class Water
{
private:
	int mL;
public:
	Water(int mL) : mL(mL) {}
	virtual void Show()
	{
		std::cout << mL << "mL" << std::endl;
	}
};

class SparklingWater : public Water
{
private:
	int sparkle;
public:
	SparklingWater(int mL, int sparkle) : Water(mL), sparkle(sparkle) {}
	void Show() override
	{
		Water::Show();
		std::cout << sparkle << std::endl;
	}
};

// ������, ������ ������ ����ȯ ������
// reinterpret_cast

/*
  C++ ����ȯ ����
  �⺻ �ڷ����� ����ȯ : static_cast
  ��Ӱ����� ����ȯ : dynamic_cast
  ��Ӱ��迡�� ������ ����ȯ : static_cast
  ������,������ Ÿ�Կ��� ������ ����ȯ : reinterpret_cast(static_cast���� ��)
  const ������ ���ַ��� const_cast
*/


void lecture10()
{
	First* fPtr = new First("ù��° Ŭ����");
	fPtr->SimpleFunc();

	First* sPtr = new Second("ù��° Ŭ����", "�ι�° Ŭ����");
	sPtr->SimpleFunc();

	// 1�� ���� static_cast
	std::cout << "static_cast �⺻ ����ȯ" << std::endl;
	int d = 4;
	char* iPtr1 = (char*)d; // C��Ÿ�� ����ȯ

	// reinterpret_cast ����
	// �뵵 : ������, ������ ������ ����ȯ�� ������ ����
	char* iPtr2 = reinterpret_cast<char*>(&d); 
	First* sPtr2 = reinterpret_cast<First*>(fPtr);

	// const_cast ������
	// ��� Ű����� ������ ������ �� ����� �����ϴ� ������
	const char* str = "Hello";
	char* str2 = const_cast<char*>(str);
	// ���� ���� str2[2] = 'a'; str2�� ���� �����ؼ� �����ϴ� ���� �Ұ���
	std::cout << "const_cast ���� : " << str2 << std::endl;
	
	int newint = static_cast<int>(d); // ��밡���� ���

	// static_cast�� ����ϴ� ����
	// 1. ���� ����ȯ�� �Ʒ� �������� ����
	// �ٸ� Ÿ�԰��� ����ȯ�� ���� (int <-> double <-> char)
	
	// 2. �θ�<->�ڽ� Ŭ���� ����ȯ
	// Parent* parent = new Child();
	// (Child)parent;
	
	// dynamic_cast ������
	// ��Ӱ��迡���� ����ȯ�� �����ϰ� ó���� �� �ִ� ������
	// static_cast�� ��쿡�� ����ȯ�� �Ұ����� ��쿡�� �������� ����ϱ� ������ ��Ӱ��迡�� �Ҿ����� ����ȯ ����̹Ƿ� dynamic_cast�� ���

	std::cout << "�θ� �ڽ� ����ȯ ����" << std::endl;

	Water* water = new SparklingWater(10, 10);
	water->Show();

	SparklingWater* spWater = dynamic_cast<SparklingWater*>(water); // �θ�������(ź����� ����ִ� ��ü)
	water->Show();

	Water* water2 = new Water(150);
	SparklingWater* spWater2 = dynamic_cast<SparklingWater*>(water2); // �θ�������(�θ� ��ü)�� ����ִ� 
	water2->Show();
	if (spWater2 != nullptr)
	{
		spWater2->Show();
	}


	// spWater2�� static_cast�� ����ȯ�� �ϸ� �״�� ������ ������ �߻�
	// spWater2�� dynamic_cast�� ����ȯ�� �ؼ� �� ������� ����ȯ�� �Ұ����ϸ� nullPtr�� ��ȯ

	// PET Dog, Cat...
	// Cat* catPtr = dynamic_cast<Cat*>(myPet);
}