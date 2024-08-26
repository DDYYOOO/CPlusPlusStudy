/*
	�ۼ��� : �̵��� 
	�ۼ��� : 2024-08-23
	�н� ��ǥ : 
*/

/*
  Ŭ���� ���
  1. class Parent{};
  2. class Child : public ParentP{}

*/

/*
  class Pet
  hungry, happy...
  dog, cat, bird, ..... �߰� ������ : PetŬ���� ��� �޴� Ŭ���� ����
*/

/*
  ��ü ������ ��������
  C++���� ������ ������ �ش� ��ü�� ���� Ȥ�� ���������� ����ų �� �ִ�.
  Dog : public Pet
  Pet* pet;	: �翬�� �ȴ�
  Pet* dog; : ��ӵ� Ŭ������ �θ� �����Ͱ� ����ų �� �ִ�.
  Dog* dog;
  Dog* pet;	: �����Ϸ� ���� -> ���������� �ڽ�Ŭ���� �����Ͱ� �θ�Ŭ������ ���� ����Ű�� ���� ���Ƴ��� -> ���������� ����ȯ
  (Pet)Dog
  */

/*
  ���� : Ŭ������ Ȯ�强�� ���� ������ �����ϱ� ���� ���
  DogŬ����. CatŬ������ Play(Dog* dog), Play(Cat* cat), Feed�Լ��� ǥ��
  Cat�� Dog�� ���ÿ� ����ϴ� PetŬ������ ���ڷ� �Ѱ��ش�
  Play(Pet* pet) <- Dog
*/

/*
  �θ�Ŭ������ ���ڷ� ����ؼ� ���뼺 �ִ� �Լ��� ����
  void Play(PET* pet) => pet�� ��ӹ޴� ��� Ŭ������ ���������� ǥ�������ϰ� ��
  ���� �߻� : pet��ӹ޴� Dog, HunDog �ڽ�Ŭ������ �θ�Ŭ������ ���� �Լ��� ���� �ߴµ�?
  -> �θ� ���� �ִ� �Լ��� �ڽ� �������� �����ϰ� �ʹ�
  �����Լ�, override Ű����
  virtualŰ���� -> ���� �Լ�
  overrideŰ���� -> virtual�� �Բ� ���. �����
*/

/*
  PET*	pet     = pet(o)
  PET*  petPtr  = dog(o)
  PET*  petPtr2 = huntdog(o)

  Dog*	dog = pet(x)
  Dog*  dog = dog(o)
  Dog*  dog = huntdog(o)

  HuntDog*	huntdog = huntdog(o)
  HuntDog*	huntdog = dog(x)
  HuntDog*	huntdog = pet(x)
*/

#include"lectures.h"

// ���� : �߻����� ��ü
// ���, ��ũ, .... (�ΰ���) -> ���͸� ��ӹް� �� 

class PET	// �߻����� ������� ������ �� �ִ� ��ü
{
protected:
	int hungry;
	int happy;
public:
	PET() {};
	PET(int hungry, int happy) : hungry(hungry), happy(happy)
	{
		//this->hungry = hungry;
		//this->happy = happy;
		//std::cout << "���� �����߽��ϴ�" << std::endl;

	}
	virtual void PlayWithMaster()
	{
		std::cout << "��� �������ϴ�" << std::endl;
		hungry -= 10;
		happy += 5;
	}
	void ShowInfo()
	{
		std::cout << "����� : " << hungry << std::endl;
		std::cout << "�ູ�� : " << happy << std::endl;
	}
};

class Dog : public PET
{
public:
	Dog() {};
	Dog(int hungry, int happy) : PET(hungry, happy)
	{
		std::cout << "���� �����߽��ϴ�" << std::endl;
	}
	virtual void Bark()
	{
		std::cout << "�п�" << std::endl;
	}
	void PlayWithMaster() override	// virtual�� �ۼ��� �Լ��� ������ �ݵ�� �� �Լ��� override�ض�
	{
		std::cout << "���� �������ϴ�" << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

// IS-A ��ɰ��� ���̴�
class HuntDog : public Dog
{
public:
	HuntDog() {};
	HuntDog(int hungry, int happy) : Dog(hungry, happy)
	{
		std::cout << "��ɰ��� �����߽��ϴ�" << std::endl;
	}
	void Hunting()
	{
		std::cout << "��ɰ��� ����� �մϴ�" << std::endl;

	}

	void PlayWithMaster() override
	{
		std::cout << "��ɰ��� �������ϴ�" << std::endl;
		hungry -= 20;
		happy += 10;
	}
	void Bark() override {
		std::cout << "������" << std::endl;
	}
};

class Cat : public PET
{
public:
	Cat() {};
	Cat(int hungry, int happy) : PET(hungry, happy)
	{
		std::cout << "����̸� �����߽��ϴ�" << std::endl;
	}
	void Hide()
	{
		std::cout << "����̰� �������ϴ�" << std::endl;
	}
};

class CatAndDog : public Cat, public Dog
{

};

// Pet controller(handler) -> PetŬ������ �����ϴ� Ŭ����
class PetContorller		// �� �����ڴ� ���̴�? (IS-A)(x) (HAS-A)(x)
{
private:
	PET* myPet;
	int money;	// �� ���� ���, �˹�, �� ��ǰ ����....
	int activePoint;
	//Pet* myPets[10]; == Pet** myPets;
	void UseActivePoint()
	{
		std::cout << "�ൿ���� 1 �Һ��߽��ϴ�" << std::endl;
		activePoint--;
		std::cout << "���� �ൿ�� : " << activePoint << std::endl;
	}
public:
	PetContorller() {};		// ����Ʈ ������
	PetContorller(PET* pet, int money, int AP) : money(money), activePoint(AP)
	{
		myPet = pet;
	}
	void EarnMoney(int pay)
	{
		std::cout << pay << "��ŭ ���� ȹ���߽��ϴ�" << std::endl;
		UseActivePoint();
		money += pay;
	}
	void Play()
	{
		myPet->PlayWithMaster();
		std::cout << "�ൿ��1�� �Ҹ��߽��ϴ�" << std::endl;
		activePoint--;
	}

	// PETŬ������ �̿��ؼ� ���� �Լ��� �����Ű�� �ʹ�
	// PET�� ���� Ŭ������ Ÿ�� ��ȯ(casting) ��Ű�� �ʹ�
	// ����. ��� PET�� ��� �޴� �ϳ��� �ڽ� Ŭ������ ��ȯ�� �� �ִ�
	// ������ �ʿ�

	// C��� ����ȯ  (Ÿ��)�̸�;
	// C++��� ����ȯ  ������ �߰��ؼ� �����ڷ� ����;
	// static_cast, dynamic_cast, reinterpret_cast, const_cast

	void Play2()  
	{
		Dog* dog = dynamic_cast<Dog*>(myPet);
		if (dog != nullptr)
			dog->Bark();

		HuntDog* huntDog = dynamic_cast<HuntDog*>(myPet);
		if(huntDog != nullptr)
			huntDog->Hunting();

		Cat* cat = dynamic_cast<Cat*>(myPet);
		if (cat != nullptr)
			cat->Hide();

	}
	void ShowInfo()
	{
		std::cout << "���� ������ : " << money << std::endl;
		std::cout << "���� �ൿ�� : " << activePoint << std::endl;
		std::cout << "------���� ����------" << std::endl;
		myPet->ShowInfo();
	}

};

// ��ü���α׷����� ������ : ���� ���·� ������ ����� ����
// Ŭ������ Ȯ���� �� ���� ���� �Լ��� �����ε��� �����ϴ� ���� ���ϰ� �ϳ��� �Լ��� ǥ���ϱ� ����
// PetContorller�� ���� player.Play() ���°� ��� ����
// ����� ��� �ٸ���

// ����� �Լ� virtual void PlayWithMaster();
// �̸��� ��ȯ ���� ���� �Լ��� ��ӹ޴� Ŭ������ ������ ����� ��

// PET�� ��ӹ޴� Ŭ�����ε�, �� Ŭ���� ������ �޼��带 �����ϴ� ���
// Hunting �����ϴ� �� : Cat, Hide ������ �Ϸ��� ��� �ؾ��ϴ°�?

// Play(Pet* pet)���� Cat������ �Լ�, Dog������ �Լ��� �����ϴ� ��
// PlayWithCat(Cat* cat); (Cat& cat);  cat->Hide();
// PlayWithDog(Dog* dog);
// PlayWithBird(Bird* bird);

void lecture9()
{
	PET pet(100, 100);
	Dog dog(100, 100);
	HuntDog huntdog(100,100);
	Cat cat(100, 100);

	PetContorller player(&pet, 10000, 3);
	player.Play();
	player.ShowInfo();

	PetContorller p2(&dog, 10000, 3);
	//p2.Play();
	p2.Play2();
	p2.ShowInfo();

	PetContorller p3(&huntdog, 10000, 3);
	//p3.Play();
	p3.Play2();
	p3.ShowInfo();

	PetContorller p4(&cat, 10000, 3);
	p4.Play2();
	p4.ShowInfo();
}