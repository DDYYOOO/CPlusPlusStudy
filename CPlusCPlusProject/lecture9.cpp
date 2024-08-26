/*
	작성자 : 이동윤 
	작성일 : 2024-08-23
	학습 목표 : 
*/

/*
  클래스 상속
  1. class Parent{};
  2. class Child : public ParentP{}

*/

/*
  class Pet
  hungry, happy...
  dog, cat, bird, ..... 추가 컨텐츠 : Pet클래스 상속 받는 클래스 구현
*/

/*
  객체 포인터 참조관계
  C++에서 포인터 변수는 해당 객체를 직접 혹은 간접적으로 가르킬 수 있다.
  Dog : public Pet
  Pet* pet;	: 당연히 된다
  Pet* dog; : 상속된 클래스를 부모 포인터가 가르킬 수 있다.
  Dog* dog;
  Dog* pet;	: 컴파일러 에러 -> 문법적으로 자식클래스 포인터가 부모클래스를 직접 가르키는 것을 막아놨다 -> 간접적으로 형변환
  (Pet)Dog
  */

/*
  정리 : 클래스의 확장성에 대한 문제를 개선하기 위한 방안
  Dog클래스. Cat클래스도 Play(Dog* dog), Play(Cat* cat), Feed함수로 표현
  Cat과 Dog를 동시에 상속하는 Pet클래스를 인자로 넘겨준다
  Play(Pet* pet) <- Dog
*/

/*
  부모클래스를 인자로 사용해서 범용성 있는 함수를 구현
  void Play(PET* pet) => pet을 상속받는 모든 클래스를 범용적으로 표현가능하게 함
  문제 발생 : pet상속받는 Dog, HunDog 자식클래스와 부모클래스가 같은 함수를 구현 했는데?
  -> 부모가 갖고 있는 함수를 자식 버젼으로 변경하고 싶다
  가상함수, override 키워드
  virtual키워드 -> 가상 함수
  override키워드 -> virtual과 함께 사용. 덮어쓰다
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

// 몬스터 : 추상적인 객체
// 고블린, 오크, .... (인간형) -> 몬스터를 상속받게 함 

class PET	// 추상적인 대상으로 접근할 수 있는 객체
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
		//std::cout << "펫을 생성했습니다" << std::endl;

	}
	virtual void PlayWithMaster()
	{
		std::cout << "펫과 놀아줬습니다" << std::endl;
		hungry -= 10;
		happy += 5;
	}
	void ShowInfo()
	{
		std::cout << "배고픔 : " << hungry << std::endl;
		std::cout << "행복도 : " << happy << std::endl;
	}
};

class Dog : public PET
{
public:
	Dog() {};
	Dog(int hungry, int happy) : PET(hungry, happy)
	{
		std::cout << "개를 생성했습니다" << std::endl;
	}
	virtual void Bark()
	{
		std::cout << "왈왈" << std::endl;
	}
	void PlayWithMaster() override	// virtual로 작성된 함수가 있으면 반드시 이 함수로 override해라
	{
		std::cout << "개와 놀아줬습니다" << std::endl;
		hungry -= 10;
		happy += 5;
	}
};

// IS-A 사냥개는 개이다
class HuntDog : public Dog
{
public:
	HuntDog() {};
	HuntDog(int hungry, int happy) : Dog(hungry, happy)
	{
		std::cout << "사냥개를 생성했습니다" << std::endl;
	}
	void Hunting()
	{
		std::cout << "사냥개가 사냥을 합니다" << std::endl;

	}

	void PlayWithMaster() override
	{
		std::cout << "사냥개와 놀아줬습니다" << std::endl;
		hungry -= 20;
		happy += 10;
	}
	void Bark() override {
		std::cout << "으르렁" << std::endl;
	}
};

class Cat : public PET
{
public:
	Cat() {};
	Cat(int hungry, int happy) : PET(hungry, happy)
	{
		std::cout << "고양이를 생성했습니다" << std::endl;
	}
	void Hide()
	{
		std::cout << "고양이가 숨었습니다" << std::endl;
	}
};

class CatAndDog : public Cat, public Dog
{

};

// Pet controller(handler) -> Pet클래스를 제어하는 클래스
class PetContorller		// 펫 관리자는 펫이다? (IS-A)(x) (HAS-A)(x)
{
private:
	PET* myPet;
	int money;	// 펫 먹이 비용, 알바, 펫 용품 구입....
	int activePoint;
	//Pet* myPets[10]; == Pet** myPets;
	void UseActivePoint()
	{
		std::cout << "행동력을 1 소비했습니다" << std::endl;
		activePoint--;
		std::cout << "남은 행동력 : " << activePoint << std::endl;
	}
public:
	PetContorller() {};		// 디폴트 생성자
	PetContorller(PET* pet, int money, int AP) : money(money), activePoint(AP)
	{
		myPet = pet;
	}
	void EarnMoney(int pay)
	{
		std::cout << pay << "만큼 돈을 획득했습니다" << std::endl;
		UseActivePoint();
		money += pay;
	}
	void Play()
	{
		myPet->PlayWithMaster();
		std::cout << "행동력1을 소모했습니다" << std::endl;
		activePoint--;
	}

	// PET클래스를 이용해서 고유 함수를 실행시키고 싶다
	// PET을 고유 클래스로 타입 변환(casting) 시키고 싶다
	// 문제. 모든 PET이 상속 받는 하나의 자식 클래스로 변환할 수 있다
	// 조건이 필요

	// C언어 형변환  (타입)이름;
	// C++언어 형변환  조건을 추가해서 연산자로 만듦;
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
		std::cout << "현재 소지금 : " << money << std::endl;
		std::cout << "남은 행동력 : " << activePoint << std::endl;
		std::cout << "------펫의 정보------" << std::endl;
		myPet->ShowInfo();
	}

};

// 객체프로그래밍의 다형성 : 동일 형태로 복수의 기능을 구현
// 클래스를 확장할 때 마다 동일 함수의 오버로딩을 구현하는 것을 피하고 하나의 함수로 표현하기 위함
// PetContorller의 변수 player.Play() 형태가 모두 같다
// 결과는 모두 다르다

// 공통된 함수 virtual void PlayWithMaster();
// 이름과 반환 값이 같은 함수를 상속받는 클래스에 선언을 해줘야 함

// PET을 상속받는 클래스인데, 각 클래스 고유의 메서드를 실행하는 방법
// Hunting 실행하는 법 : Cat, Hide 실행을 하려면 어떻게 해야하는가?

// Play(Pet* pet)으로 Cat고유의 함수, Dog고유의 함수를 실행하는 법
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