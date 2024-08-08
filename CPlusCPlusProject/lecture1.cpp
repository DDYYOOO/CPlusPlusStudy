/*
	작성자 : 이동윤
	작성일 : 2024-08-08
	학습 목표 : C++ 언어 학습(C언어 복습)
*/

/*
  Hello World 출력 해주는 함수 : 입출력 함수 <- <stdio.h> printf, scanf
  Hello World 출력 해주는 함수 : 입출력 함수 <- <iostream> cout, cin
  cout : 출력 함수
  사용법 : std::cout << "Hello World!";(std::cout << "Hello World!" << std::endl;)
  cin : 입력 함수
  사용법 : std::cin >> num;
  std::endl; == \n
*/

/*
  1. std:: -> C++ standard Library에 등록된 함수들, C++ 표준 라이브러리의 모든 함수가 정의된 이름 공간
  namespace(이름 공간) : 어떤 정의된 객체가 어디에 소속되어 있는지 알려주는 것


*/

/*
  함수, 변수를 작성 하는데 다른 사람이 쓴 코드를 가져다 쓰면서 중복된 이름을 가진 함수를 사용할 확률이 높아짐
  C++문법에서는 이를 구분하기 위해서 namespace 문법 제공
  아무 이름 ::  <- 이런 형식으로 나오면 앞에 함수 이름은 namespace이다
  사용법
  namespace 이름 { } 
*/

/*
  범위 지정 연산자 '::'
  사용법 : namespace:: 변수 또는 함수;
  namespace안에 있는 변수 또는 함수를 사용할 수 있다.
  namespace가 긴 경우
  using 키워드
  using TODATISTHRUSDAY::num;
*/

/*
  1. 변수 : int, char, float, double....
  2. 반복문, 조건문 : for반복문, while반복문, if조건문, switch조건문...
  3. 포인터(변수) : int*, char*, &num, *num.....
  */

#include"lectures.h"
#include"cstring"

namespace TODATISTHRUSDAY
{
	int num;
}

using TODATISTHRUSDAY::num;			// 이 이름공간에서 num변수만 사용
//using namespace TODATISTHRUSDAY;	// 이 이름공간에서 사용하는 모든 변수 또는 함수는 using namespace 사용
									// 장점 : 이름이 긴 namespace를 굳이 입력 안해도 됨
									// 단점 : namespace안에 변수와 함수가 많을수록, 다른 함수 또는 변수와 이름이 겹치는 경우가 생김
// 추천 사용법
// using namespace를 이용해서 모든 벼수를 참조하는 방식을 지양
// 필요한 함수만 필요한 변수만 지정해서 사용

// using 사용 예제

namespace CPP
{
	void Sample()
	{
		std::cout << "sample\n";
	}
}

namespace CPP2
{
	void Sample()
	{
		std::cout << "sample2\n";
	}
}

using std::cout;
using std::endl;

namespace LDY
{
	int age;
	char name[30];
	void PrintfMyName()
	{
		std::cout << "제 이름은 " << name << "입니다\n";
		std::cout << "제 나이는 " << age << "입니다\n";
	}
}

using std::cin;


void lecture1()
{
	//std:: std라는 namespace공간안에 C++의 모든 함수가 들어가 있다
	cout << "Hello World!" << endl;
	std::cout << "Hello World!\n";

	CPP::Sample();
	CPP2::Sample();
	strcpy_s(LDY::name, 30, "이동윤");
	LDY::PrintfMyName();
	
	int a1;

	std::cout << "입력 받을 수를 입력 : ";
	std::cin >> a1;
	std::cout << "입력 받은 수 : " << a1 << endl;

	int LuckyNumber  = 5;
	int UserInput;

	cout << "숫자 맞추기 게임" << endl;
	
	while (1)
	{
		cout << "숫자 입력 : " << endl;
		std::cin >> UserInput;

		if (UserInput == LuckyNumber)
		{
			cout << "맞췄습니다" << endl;
			break;
		}
		else
		{
			cout << "틀렸습니다" << endl;
			continue;
		}
	} 
}