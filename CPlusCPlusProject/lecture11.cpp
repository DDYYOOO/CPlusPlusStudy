/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-27
	�н� ��ǥ : 
*/

/*
  1. C++ casting ������ ����

  2. virtual �����Լ��� ���� ����(��ü���� ���α׷����� ������)
  pure virtual
  abstractŬ����
  vtable

  3. monster class(Goblin, Slime class) - Player ����
  4. ���� ��� Reward - monster�׾��� �� �����ϴ� ������

*/

#include"lectures.h"

class AA
{
private:
	int Aint;
public:
	virtual void Show()
	{
		std::cout << "AA" << std::endl;
	}
};

class BB : public AA
{
private:
	int Bint;
public:
	void Show() override
	{
		std::cout << "BB" << std::endl;
	}
	void MyBB()
	{
		std::cout << "MyBB" << std::endl;
	}
};

class CC : public AA
{
public:
	void Show()
	{
		std::cout << "CC" << std::endl;
	}
	void MyCC()
	{
		std::cout << "MyCC" << std::endl;
	}
};

// 2. virtual �����Լ��� ���� ����(��ü���� ���α׷����� ������)
// pure virtual		: Pet _ void Sound(Pet* pet) ��, �����, �� �������� �κ��� Pet. �����Ҹ�
// PetŬ������ �߻����� ����
// abstractŬ����
// vtable

class NewPet
{
public:
	virtual void Sound() = 0;	// ���� ���� �Լ� -> NewPet�� ��ӹ޴� Dog, Cat Sound ����
};

// pure virtual function
// ��� : �ݵ�� �������̵� �Ǿ���ϴ� �Լ�
// ���� ���� �Լ��� �����ϰ� �ִ� Ŭ������ �߻�Ŭ������� ����
// �߻�Ŭ������ �ݵ�� �ϳ� �̻��� ����� �ʿ�
// NewPet* (o)
// NewPet nP1; (x)

// virtual ���� �Լ��� ����ϴ� Ŭ������ ��� �����ؼ� ����� �� �ִ�
// ��� �Լ��� virtual�Լ�(���� �Լ�)�� �����ص� ������ ���� ������?

// virtual Ű���带 �Է��ϴ� ���� : Ű���带 �Է����� ������ �۵����� �ʴ´�
// �� C++ �⺻ �������� virtual�� ����Ǿ� ���� ������?
// virtual ���������� vtable������ ���� vPtr;
// virtual �������� �ʾ��� �� �ٷ� ����Լ��� ����

// �������� �ʿ��� ���� �����Լ��� ����ϴ� ���� ���� ����ȭ�� �ӵ��� ���� �ڵ尡 �� �� �ִ�.
// virtual�� ��� �Լ��� ����ص� ������ ����
// �޸�, �ð��� ���ݾ� ������ ��ġ�� �ִ�

// monster calss -> �߻� Ŭ������ ������
// reward class -> ����ġ(int), ��(int), ������(������ ��ȣ...)���
// IS-A, HAS-A

// player <-> monster battle system
// battle calss. bool End() : �÷��̾ �׾��� ��, ���Ͱ� �׾��� ��, �÷��̾ �������� ��
// ���� �ݺ�(������ �� bool)
// 1. playerTurn; (1)����, (2)���, (3)����
// NextTurn
// 2. monsterTurn (1)����

// ���Ͱ� ������ monster class HAS-A -> reward DropItem()
// player.GetItem(monster* m1);
 
class NewDog : public NewPet
{
public:
	virtual void Sound()
	{
		std::cout << "�п�" << std::endl;
	}
	virtual void Play()
	{
		std::cout << "���" << std::endl;
	}
	void DDD()
	{
		std::cout << "DDD" << std::endl;
	}
};


void lecture11()
{
	std::cout << "C++ casting ������ ����" << std::endl;

	// �⺻ �ڷ����� ��ȯ, ������ �� ������ ��ȯ, ��Ӱ����� Ŭ���� ��ȯ�� ���� �� �ִ�
	std::cout << "1. static_cast<type>" << std::endl;
	
	double pi = 3.14;	// 3
	int pi_int = (int)3.14 - 0.14;	// (int)3.14 => 3 - 0.14 = (int)2.xxxxxx => 2
	int pi_int2 = static_cast<int>(pi);
	std::cout << "pi_int�� �� : " << pi_int << std::endl;
	std::cout << "pi_int2�� �� : " << pi_int2 << std::endl;

	// 1. �����Լ��� �̿��Ͽ� ��ü�� ������
	AA* aPtr1 = new AA();
	aPtr1->Show();
	AA* aPtr2 = new BB();
	aPtr2->Show();
	AA* aPtr3 = new CC();
	aPtr3->Show();

	// static_cast ��Ӱ����� Ŭ���� ǥ��
	BB* bPtr1 = static_cast<BB*>(aPtr2);
	bPtr1->Show();
	bPtr1->MyBB();

	BB* bPtr2 = static_cast<BB*>(aPtr3);
	bPtr2->Show();
	bPtr2->MyBB();

	// static_cast<type> : ���� ��ü�� ������ type���·� ����ȯ�� ��Ų��.

	// ��ӻ����� Ŭ���� ����ȯ dynamic_cast
	CC* cPtr1 = dynamic_cast<CC*>(aPtr3);
	if(cPtr1 != nullptr)	// C���� NULL #define NULL 0. ������ ���� 0. ����Ű�� �ּҰ� ����. C++ : nullptr
		cPtr1->MyCC();

	// const_cast : constŰ���带 ���Ĺ޴� ������ ������� ���ִ� ��ȯ
	const int num = 10;
	// num = 12;(x)
	int* nonConstNum = const_cast<int*>(&num);
	*nonConstNum = 12;
	std::cout << "num�� �� : " << num << std::endl;
	std::cout << "nonConstNum�� �� : " << *nonConstNum << std::endl;

	// reinterpret_cast
	int num2 = 65;	// int�� �ּҸ� char�� �ּҷ� ������ ����ȯ
	char* charPtr = reinterpret_cast<char*>(&num2);
	std::cout << "char���·� ���� ����ȯ : " << *charPtr << std::endl;
	
	// �����Ͱ� ����ִ� ���� ������ �Ű澲�� �ʰ� ������ ����ȯ
	double* intPtrValue = reinterpret_cast<double*>(&num2);
	std::cout << "���� �����͸� ������ ��ȯ �� : " << *intPtrValue << std::endl;

	
	std::cout << "2. virtual �����Լ��� ���� ����" << std::endl;

	NewPet* nP1 = new NewDog();
	nP1->Sound();

	NewDog* nD1 = dynamic_cast<NewDog*>(nP1);
	nD1->Play();
}