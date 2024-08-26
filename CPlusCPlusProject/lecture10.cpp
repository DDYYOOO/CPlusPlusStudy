/*
	작성자 : 이동윤
	작성일 : 2024-08-26
	학습 목표 : C++ 형변환
*/

// PET클래스 
// Dog, HuntDog, Cat : PET을 상속하는 클래스
//(down, child, derived) <-> (up, parent, base)

// PetController 클래스
// Has-A, Feed(PET* pet) Play(PET* pet)

// 1. 확장성의 문제점
// Play(Dog, Cat, Bird....) 확장해야 하는 클래스 만큼 오버로딩을 해야하는 문제
// 해결방안
// Play(PET* pet) -> PET클래스 안에 있는 virtual void PlayWithMaster();
// virtual <-> override

// 클래스 포인터와 상속관계
// Frist 클래스 타입
// Second클래스 타입(First클래스 + Second 고유 멤버)

// First* a = new First();
// First* b = new Second();

// Second* a = new Second();
// Second* c = new First(); (x)


// C언어 형변환  (타입)이름;
// C++언어 형변환  조건을 추가해서 연산자로 만듦;
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

// 1. static_cast 연산자		(static : 정적인)
// 2. dynamic_cast 연산자	(dynamic : 동적인)

// 기본 데이터 타입(primitive Type) : int, double char들의 형변환은 무조건 static_cast 사용

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

// 포인터, 참조자 사이의 형변환 연산자
// reinterpret_cast

/*
  C++ 형변환 정리
  기본 자료형의 형변환 : static_cast
  상속관계의 형변환 : dynamic_cast
  상속관계에서 강제로 형변환 : static_cast
  포인터,참조자 타입에서 무조건 형변환 : reinterpret_cast(static_cast보다 쎔)
  const 성향을 없애려면 const_cast
*/


void lecture10()
{
	First* fPtr = new First("첫번째 클래스");
	fPtr->SimpleFunc();

	First* sPtr = new Second("첫번째 클래스", "두번째 클래스");
	sPtr->SimpleFunc();

	// 1번 예시 static_cast
	std::cout << "static_cast 기본 형변환" << std::endl;
	int d = 4;
	char* iPtr1 = (char*)d; // C스타일 형변환

	// reinterpret_cast 예시
	// 용도 : 포인터, 참조사 사이의 형변환을 강제로 실행
	char* iPtr2 = reinterpret_cast<char*>(&d); 
	First* sPtr2 = reinterpret_cast<First*>(fPtr);

	// const_cast 연산자
	// 상수 키워드로 선언한 변수를 비 상수롤 변경하는 연산자
	const char* str = "Hello";
	char* str2 = const_cast<char*>(str);
	// 주의 사항 str2[2] = 'a'; str2를 직접 접근해서 변경하는 것은 불가능
	std::cout << "const_cast 예시 : " << str2 << std::endl;
	
	int newint = static_cast<int>(d); // 사용가능한 경우

	// static_cast을 사용하는 이유
	// 1. 강제 형변환을 아래 조건으로 제한
	// 다른 타입간의 형변환을 제한 (int <-> double <-> char)
	
	// 2. 부모<->자식 클래스 형변환
	// Parent* parent = new Child();
	// (Child)parent;
	
	// dynamic_cast 연산자
	// 상속관계에서의 형변환을 안전하게 처리할 수 있는 연산자
	// static_cast의 경우에는 형변환이 불가능한 경우에도 컴파일을 허용하기 때문에 상속관계에서 불안정한 형변환 방식이므로 dynamic_cast를 사용

	std::cout << "부모 자식 형변환 예시" << std::endl;

	Water* water = new SparklingWater(10, 10);
	water->Show();

	SparklingWater* spWater = dynamic_cast<SparklingWater*>(water); // 부모포인터(탄산수가 들어있는 객체)
	water->Show();

	Water* water2 = new Water(150);
	SparklingWater* spWater2 = dynamic_cast<SparklingWater*>(water2); // 부모포인터(부모 객체)가 들어있다 
	water2->Show();
	if (spWater2 != nullptr)
	{
		spWater2->Show();
	}


	// spWater2를 static_cast로 형변환을 하면 그대로 컴파일 에러가 발생
	// spWater2를 dynamic_cast롤 형변환을 해서 그 결과값이 형변환이 불가능하면 nullPtr로 변환

	// PET Dog, Cat...
	// Cat* catPtr = dynamic_cast<Cat*>(myPet);
}