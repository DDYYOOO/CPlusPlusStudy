/*
	작성자 : 이동윤
	작성일 : 2024-08-09
	학습 목표 : C언어 포인터를 C++에서 활용(참조자reference)에 대한 이해
*/

/*
  C언어에서 포인터를 사용하는 이유
  함수를 사용하면서 함수 안에서 데이터를 변경하려면 포인터를 인자로 넘겨줘야 함

*/

/*
  함수를 사용할 때 포인터가 아닌 참조자를 사용하면 인자로 &(주소연산자) 사용하지 않을 수 있다
  주소 선언 : int*
  참조자 선언 : int& 참조자 이름 = 참조하고자 하는 변수;
  int a; 
  int& AnotherA = a;
*/

#include"lectures.h"

void SwapInt(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// 함수 오버로딩 : C언어는 함수의 이름으로 구별함 C++은 함수의 이름 + (매개변수, 인자)
void SwapInt(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
// 같은 이름 같은 매개변수 타입이면 C++에서는 사용못함
//void SwapInt(int& a, int& b)
//{
//
//}

void ChangeVal(int& p)
{
	p = 10;
}

// int를 반환하는 함수
int Function()
{
	int a = 2;
	return a;
}

// 참조자를 리턴하는 함수
// 사용을 지양해야하는 함수
//int& Function2()
//{
//	int a = 2;
//	return a;
//}

int& Function3(int& a)
{
	a = 2;
	return a;
}

typedef struct Human
{
	char name[30];
	int age;
}Human;

Human& AddHumanInfo(Human& human)
{
	std::cout << "이름 입력 : ";
	std::cin >> human.name;
	std::cout << "나이 입력 : ";
	std::cin >> human.age;
	return human;
}

void PrintHumanInfo(Human& human)
{
	std::cout << "이름 : " << human.name << std::endl;
	std::cout << "나이 : " << human.age << std::endl;
}

void lecture2()
{
	// C언어 복습
	int num = 10;
	int* numPtr = &num;
	// C++은 데이터형태를 명시하지 않아도 작동한다
	std::cout << "포인터의 주소 : " << numPtr << std::endl; 
	std::cout << "포인터가 가리키는 값 : " << *numPtr << std::endl;

	// 변수의 이름 규칙
	// 주의 사항 : 두 방식을 같이 혼동해서 쓰지 말 것
	// 변수의 이름 규칙을 하나로 통일해서 쓸 것 int NumberOfMonster (x)
	// 두 방식을 섞어서 쓰지 말 것 int number_ofMonster (x)
	//int number_of_people;	// 단어와 단어사이를 '_' 표현 (스네이크?방식)
	//int numberOfpeople;		// 띄어쓰기 할 때 대문자로 표현 (카멜방식)
	
	int num1 = 1;
	int num2 = 2;
	SwapInt(&num1, &num2);

	std::cout << "num1의 값 : " << num1 << " num2의 값 : " << num2 << std::endl;

	// 참조자 만드는 법
	// 참조자 : 변수의 별명
	int a1 = 10;
	int& AnotherA1 = a1;	// AnotherA1은 a1의 별명이다
	std::cout << "AnotherA1의 값 : " << AnotherA1 << std::endl;

	// a1 별명을 쓰는 이유
	// primitive type
	// 구조체의 크기는 사용자 정의형이기 때문에 작성자에 따라서 크기가 달라진다
	// 참조자도 마찬가지로, 참조자가 가리키는 주소를 한번 복사하면 8바이트(64비트 시스템)만으로 구조체를 복사해서 쓸 수 있기 때문

	// 참조자와 포인터가 다른 부분
	// 포인터는 주소연산자를 인자로 받게 해야 한다. 사용자가 함수와 포인터에 대한 이해도가 있어야한다 (C언어)
	// 참조자는 주소연산자를 인자로 받나? 안받는다. 사용자가 더 편리한 문법 (C++언어)

	int c_num1;
	char name[30];
	std::cout << "입력 : "; 
	std::cin >> c_num1;
	std::cout << "입력 값 : " << c_num1 << std::endl;
	std::cout << "입력 : ";
	std::cin >> name;
	std::cout << "입력 값 : " << name << std::endl;

	// 참조자(reference) 함수에서 사용하는 방법
	// 참조자는 반드시 선언과 동시에 초기화 해야 함
	// 참조자는 선언할 때 상대의 주소를 가져와서 복사를 한다
	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);

	std::cout << "d_num1의 값 : " << d_num1 << " d_num2의 값 : " << d_num2 << std::endl;

	int& AnotherD_num1 = d_num1;

	// 참조자는 리터럴 상수를 가리키지 못한다.
	//int& Literal = 100;
	// 참조자는 const 키워드로 리터럴 상수를 가리킬 수 있다.
	const int& Literal = 100;

	int p = 5;
	ChangeVal(p);
	std::cout << "p의 값 : " << p << std::endl;

	int p2 = 5;
	// 참조자(reference)를 리턴하는 함수
	// 레퍼런스 타입을 리턴항 때는 반드시 지역변수를 반환하지 않도록 조심해야 한다
	int tempA = Function();		// tempA는 Function의 리턴값 a를 복사해서 대입
	//int tempB = Function2();	// 안좋은 코드
	int tempB = Function3(p2);

	std::cout << "tempA의 값 : " << tempA << std::endl;
	std::cout << "tempB의 값 : " << tempB << std::endl;

	//int& AnotherTemp = Function(); // 위 const키워드 에러와 동일 int& AnotherTemp = 2(Function());
	const int& AnotherTemp = Function();
	//int& AnotherTemp2 = Function2(); // 일부 컴파일러에서 컴파일 에러가 발생한다

	// (1). 함수에서 값을 리턴할 때
	// int a = Function();    a = 2; 2라는 값을 a에 대입. 값의 복사가 이루어졌다 (사용가능)
	// int& a = Function();   참조자 타입으로 리터럴 상수를 가르킬 수 없다. 컴파일 에러가 발생
	// const int& a = Function();  참조자가 리터럴을 가리키게 하고 싶으면 const 키워를 사용

	// (2). 함수가 참조자를 리턴할때 int& Function();
	// ★★레퍼런스 타입을 리턴할 때 반드시 지역변수를 반환하지 않도록 조심해야 한다 ★★

	Human h1;
	
	AddHumanInfo(h1);

	PrintHumanInfo(h1);

}