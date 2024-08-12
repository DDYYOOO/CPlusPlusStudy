/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-12
	�н� ��ǥ : C++�� ����ü ������ �н�
*/

// typedefŰ���� : �ٿ �ۼ��Ǵ� ������ Ÿ���� �ڿ� �̸����� �������� �����ִ� ��

// �� : �̸�, �ູ��(int), �����(int) ��ġ���� ���� 100�� �ִ�ġ
// ����ü ������ ����ؼ� cin �Լ��� ����ؼ� ���� �̸��� �޾ƿͼ� ������� ����ü�� �����ϴ� ���(���̵� : ����)

// 1. �� �����ϱ�
// userInput 1�̶�� �����͸� ������ -> ���� �Ҵ����� ���ο� ���� ����(���̵� : ��)

// ��, ����� ����ü�� �߰�

#include"lectures.h"
#include<cstdio>

typedef struct Dog
{
	char name[30];
	int Happy;
	int Hungry;
}Dog;

typedef struct Cat
{
	char name[30];
	int Happy;
	int Hungry;
	int curious;
}Cat;

typedef struct Bird
{
	char name[30];
	int Happy;
	int Hungry;
	int fly;
}Bird;

// ��
void DogName(Dog& dog)
{
	std::cout << "���� �̸��� �Է� : ";
	std::cin >> dog.name;
	dog.Happy = 100;
	dog.Hungry = 100;
}

void Play(Dog& dog)
{
	dog.Happy += 10;
	dog.Hungry -= 5;
}

void Feed(Dog& dog)
{
	dog.Happy += 5;
	dog.Hungry += 10;
}

void DayEnd(Dog& dog, int& currentday)
{
	dog.Happy -= 10;
	dog.Hungry -= 10;
	currentday++;
}

void ShowStatus(Dog& dog, int& currentday)
{
	std::cout << "���� ��¥ :" << currentday << "��" << std::endl;
	std::cout << "�� �̸� : " << dog.name << std::endl;
	std::cout << "�� �ູ�� : " << dog.Happy << std::endl;
	std::cout << "�� ��⵵ : " << dog.Hungry << std::endl;
}

void DogMainPlay(Dog& dog, int currentday)
{
	DogName(dog);
	while (1)
	{
		system("cls");
		int userInput = 0;
		ShowStatus(dog, currentday);
		std::cout << "�ൿ ���� " << std::endl;
		std::cout << "1. ����ֱ� " << std::endl;
		std::cout << "2. �����ֱ� " << std::endl;
		std::cout << "�ൿ �Է� : ";
		std::cin >> userInput;
		if (userInput == 1)
		{
			Play(dog);
		}
		else if (userInput == 2)
		{
			Feed(dog);
		}
		DayEnd(dog, currentday);

		if (currentday == 10)
			break;
	}
	ShowStatus(dog, currentday);
}

// �����
void CatName(Cat& cat)
{
	std::cout << "����� �̸��� �Է� : ";
	std::cin >> cat.name;
	cat.Happy = 100;
	cat.Hungry = 100;
	cat.curious = 0;
}
void Play(Cat& cat)
{
	srand(time(NULL)); // �õ带 ������ִ� �Լ�
	int randomNumber = rand() % 101; // 1 ~ 100 ���� ���ڸ� �޾ƿ� 
	if (cat.curious < randomNumber)
	{
		std::cout << "����" << std::endl;
		cat.Hungry -= 5;
	}
	else
	{
		cat.Happy += 10;
		cat.Hungry -= 5;
	}
}

void Feed(Cat& cat)
{
	cat.Happy += 10;
	cat.Hungry += 10;
}

void DayEnd(Cat& cat, int& currentday)
{
	cat.Happy -= 10;
	cat.Hungry -= 10;
	currentday++;
}

void ShowStatus(Cat& cat, int& currentday)
{
	std::cout << "���� ��¥ :" << currentday << "��" << std::endl;
	std::cout << "����� �̸� : " << cat.name << std::endl;
	std::cout << "����� �ູ�� : " << cat.Happy << std::endl;
	std::cout << "����� ��⵵ : " << cat.Hungry << std::endl;
	std::cout << "����� ȣ��� : " << cat.curious << std::endl;
}

void CatMainPlay(Cat& cat, int currentday)
{
	CatName(cat);
	while (1)
	{
		system("cls");
		int userInput = 0;
		ShowStatus(cat, currentday);
		std::cout << "�ൿ ���� " << std::endl;
		std::cout << "1. ����ֱ� " << std::endl;
		std::cout << "2. �����ֱ� " << std::endl;
		std::cout << "�ൿ �Է� : ";
		std::cin >> userInput;
		if (userInput == 1)
		{
			Play(cat);
		}
		else if (userInput == 2)
		{
			Feed(cat);
		}
		DayEnd(cat, currentday);

		if (currentday == 10)
			break;
	}
	ShowStatus(cat, currentday);
}

// ��
void BirdName(Bird& bird)
{
	std::cout << "���� �̸��� �Է� : ";
	std::cin >> bird.name;
	bird.Happy = 100;
	bird.Hungry = 100;
	bird.fly = 0;
}
void Play(Bird& bird)
{
	bird.Happy += 10;
	bird.Hungry -= 5;
}

void Feed(Bird& bird)
{
	bird.Happy += 5;
	bird.Hungry += 10;
}

void DayEnd(Bird& bird, int& currentday)
{
	bird.Happy -= 10;
	bird.Hungry -= 10;
	currentday++;
}

void ShowStatus(Bird& bird, int& currentday)
{
	std::cout << "���� ��¥ :" << currentday << "��" << std::endl;
	std::cout << "�� �̸� : " << bird.name << std::endl;
	std::cout << "�� �ູ�� : " << bird.Happy << std::endl;
	std::cout << "�� ��⵵ : " << bird.Hungry << std::endl;
}

void BirdMainPlay(Bird& bird, int currentday)
{
	BirdName(bird);
	while (1)
	{
		system("cls");
		int userInput = 0;
		ShowStatus(bird, currentday);
		std::cout << "�ൿ ���� " << std::endl;
		std::cout << "1. ����ֱ� " << std::endl;
		std::cout << "2. �����ֱ� " << std::endl;
		std::cout << "�ൿ �Է� : ";
		std::cin >> userInput;
		if (userInput == 1)
		{
			Play(bird);
		}
		else if (userInput == 2)
		{
			Feed(bird);
		}
		DayEnd(bird, currentday);

		if (currentday == 10)
			break;
	}
	ShowStatus(bird, currentday);
}

// ���� ���� ȭ�� -> ���� ���� -> �̸��� �Է�
// ���� �÷��� ȭ�� -> 1���� ->

void lecture3() 
{
	// ����ü ����
	Dog dog;
	Cat cat;
	Bird bird;
	int currentday = 1;
	int selectpet = 0;

	std::cout << "���� Ű��� ����" << std::endl;
	std::cout << "1. �� Ű��� " << std::endl;
	std::cout << "2. ����� Ű��� " << std::endl;
	std::cout << "3. �� Ű��� " << std::endl;
	std::cout << "�Է� : ";
	std::cin >> selectpet;
 
	switch (selectpet)
	{
	case 1:
		DogMainPlay(dog, currentday);
		break;
	case 2:
		CatMainPlay(cat, currentday);
		break;
	case 3:

		break;
	default:
		std::cout << "�߸� �Է��߽��ϴ�" << std::endl;
	}


	
	//strcpy_s(dog.name, 30, "�ǻ�");
	//std::cout << "���� �̸� : " << dog.name << std::endl;

	



	// ����ü ������
	//Dog* dogPtr = &dog;		// ù��° ��� : ����ü �����͸� ������ �Ŀ� ������ �ּҿ����ڸ� �Ҵ�

	// ���� �Ҵ� (memory allocation)
	// C++������ �����Ҵ��� new ������ Ÿ��(); delete
	//Dog* dogPtr2 = new Dog();
	// (*dogPtr2).name; ���� �ڵ�� ����
	//strcpy_s(dogPtr2->name, 30, "ġ��");
	//std::cout << "����ü �����Ͱ� ����Ű�� �̸� : " << dogPtr2->name << std::endl;
	
}

// ����
// 1. Dog ����ü�� ��� �Լ��� ǥ���� �� ������ -> Dog, Cat, Bird ����� �������� �ϳ��� ǥ���ϴ� ����� ������?
// 2. ���� ����� �߰��ϱ� ���ؼ��� Dog, Cat, Bird�Լ��� �����ε� => play(Pet& pet);
// 3. pet.play(); ǥ���ϴ� ����� �� �ڿ�������
// 4. struct �������� ���� �ʱ�ȭ �Լ��� �ʿ�. �ʱ�ȭ �Լ��� ���� ������ �ʰ� ���������� ���������� ������?
//												Ŭ����