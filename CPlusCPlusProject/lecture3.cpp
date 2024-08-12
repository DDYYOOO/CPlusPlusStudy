/*
	작성자 : 이동윤
	작성일 : 2024-08-12
	학습 목표 : C++로 구조체 포인터 학습
*/

// typedef키워드 : 다운에 작성되는 데이터 타입을 뒤에 이름으로 별명으로 지어주는 것

// 개 : 이름, 행복도(int), 배고픔(int) 수치들은 각각 100이 최대치
// 구조체 변수를 사용해서 cin 함수를 사용해서 개의 이름을 받아와서 만들어진 구조체에 복사하는 방법(난이도 : 쉬움)

// 1. 팻 생성하기
// userInput 1이라는 데이터를 받으면 -> 동적 할당으로 새로운 개를 생성(난이도 : 중)

// 새, 고양이 구조체를 추가

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

// 개
void DogName(Dog& dog)
{
	std::cout << "개의 이름을 입력 : ";
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
	std::cout << "현재 날짜 :" << currentday << "일" << std::endl;
	std::cout << "개 이름 : " << dog.name << std::endl;
	std::cout << "개 행복도 : " << dog.Happy << std::endl;
	std::cout << "개 허기도 : " << dog.Hungry << std::endl;
}

void DogMainPlay(Dog& dog, int currentday)
{
	DogName(dog);
	while (1)
	{
		system("cls");
		int userInput = 0;
		ShowStatus(dog, currentday);
		std::cout << "행동 선택 " << std::endl;
		std::cout << "1. 놀아주기 " << std::endl;
		std::cout << "2. 먹이주기 " << std::endl;
		std::cout << "행동 입력 : ";
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

// 고양이
void CatName(Cat& cat)
{
	std::cout << "고양이 이름을 입력 : ";
	std::cin >> cat.name;
	cat.Happy = 100;
	cat.Hungry = 100;
	cat.curious = 0;
}
void Play(Cat& cat)
{
	srand(time(NULL)); // 시드를 만들어주는 함수
	int randomNumber = rand() % 101; // 1 ~ 100 랜텀 숫자를 받아옴 
	if (cat.curious < randomNumber)
	{
		std::cout << "실패" << std::endl;
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
	std::cout << "현재 날짜 :" << currentday << "일" << std::endl;
	std::cout << "고양이 이름 : " << cat.name << std::endl;
	std::cout << "고양이 행복도 : " << cat.Happy << std::endl;
	std::cout << "고양이 허기도 : " << cat.Hungry << std::endl;
	std::cout << "고양이 호기심 : " << cat.curious << std::endl;
}

void CatMainPlay(Cat& cat, int currentday)
{
	CatName(cat);
	while (1)
	{
		system("cls");
		int userInput = 0;
		ShowStatus(cat, currentday);
		std::cout << "행동 선택 " << std::endl;
		std::cout << "1. 놀아주기 " << std::endl;
		std::cout << "2. 먹이주기 " << std::endl;
		std::cout << "행동 입력 : ";
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

// 새
void BirdName(Bird& bird)
{
	std::cout << "새의 이름을 입력 : ";
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
	std::cout << "현재 날짜 :" << currentday << "일" << std::endl;
	std::cout << "새 이름 : " << bird.name << std::endl;
	std::cout << "새 행복도 : " << bird.Happy << std::endl;
	std::cout << "새 허기도 : " << bird.Hungry << std::endl;
}

void BirdMainPlay(Bird& bird, int currentday)
{
	BirdName(bird);
	while (1)
	{
		system("cls");
		int userInput = 0;
		ShowStatus(bird, currentday);
		std::cout << "행동 선택 " << std::endl;
		std::cout << "1. 놀아주기 " << std::endl;
		std::cout << "2. 먹이주기 " << std::endl;
		std::cout << "행동 입력 : ";
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

// 게임 시작 화면 -> 개를 생성 -> 이름을 입력
// 메인 플레이 화면 -> 1일차 ->

void lecture3() 
{
	// 구조체 선언
	Dog dog;
	Cat cat;
	Bird bird;
	int currentday = 1;
	int selectpet = 0;

	std::cout << "동물 키우기 게임" << std::endl;
	std::cout << "1. 개 키우기 " << std::endl;
	std::cout << "2. 고양이 키우기 " << std::endl;
	std::cout << "3. 새 키우기 " << std::endl;
	std::cout << "입력 : ";
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
		std::cout << "잘못 입력했습니다" << std::endl;
	}


	
	//strcpy_s(dog.name, 30, "뽀삐");
	//std::cout << "개의 이름 : " << dog.name << std::endl;

	



	// 구조체 포인터
	//Dog* dogPtr = &dog;		// 첫번째 방법 : 구조체 포인터를 선언한 후에 변수의 주소연산자를 할당

	// 동적 할당 (memory allocation)
	// C++에서의 동적할당은 new 데이터 타입(); delete
	//Dog* dogPtr2 = new Dog();
	// (*dogPtr2).name; 밑의 코드와 동일
	//strcpy_s(dogPtr2->name, 30, "치코");
	//std::cout << "구조체 포인터가 가리키는 이름 : " << dogPtr2->name << std::endl;
	
}

// 정리
// 1. Dog 구조체로 모든 함수를 표현할 수 없었다 -> Dog, Cat, Bird 공통된 구초제를 하나로 표현하는 방법이 없을까?
// 2. 샐운 기능을 추가하기 위해서는 Dog, Cat, Bird함수를 오버로딩 => play(Pet& pet);
// 3. pet.play(); 표현하는 방식이 더 자연스럽다
// 4. struct 변수들은 따로 초기화 함수가 필요. 초기화 함수를 따로 만들지 않고 문법적으로 지원해주지 않을까?
//												클래스