/*
	작성자 : 이동윤
	작성일 : 2024-08-29
	학습 목표 : template키워드(일반화 코딩)
*/

/*
  template왜 사용하는가?
  두 수를 더하는 함수(int 값 return)
  함수 오버로딩 : 인자까지 포함해서 함수를 구분 
  한번에 데이터 타입(int, char, float....)을 표현하는 방법 -> template
*/

/*
  template 사용법
  함수 이름<데이터 타입>()
*/

/*
  용어 정리
  함수 템플릿 : template<typename T> 함수 정의. 함수를 만드는데 사용하는 템플릿을 의미
  템플릿 함수 : Add<int>(3, 5);
*/

/*
  함수 템플릿만 만들었는데, 언제 템플릿 함수가 생성되는가?
  Add<int>(3,5);
  int Add<int>(int num1, int num2)
  {
	  return num1 + num2;
  }
  함수 템플릿을 선언하면 불필요한 메모리를 사용하는 것아 아닌가?
  -> Add<int>(3, 5), 코드가 작성되었을 때(컴파일 시점에) int Add<int> 생성이 된다.
  -> 컴파일 시점에 T 타입에 해당하는 함수를 만든다면 컴퓨터 속도가 느려지지 않을까?
  -> 컴파일 <-> 런타임 시점 : 프로그램 시작 전에 함수가 전부 만들어지기 때문에 프로그램 속도에 영향X
*/

/*
  type T => 꼭 T라는 단어를 사용해야 하는가?
  -> 다른 단어를 사용해도 무방(관습적으로 T로 사용)
*/

#include"lectures.h"

template<typename T>
class Point
{
private:
	T posX;
	T posY;
public:

};

template<typename T>
T Add(T num1, T num2)
{
	return num1 + num2;
}

/*
  함수 템플릿의 전문화(specializtion)
*/
template<>
char Add(char num1, char num2)
{
	std::cout << num1 << num2 << std::endl;
	return 0;
}


template<typename P>
P Minus(P num1, P num2)
{
	std::cout << "P Minus(num1 - num2) : ";
	return num1 - num2;
}

template<typename T>
T Divide(T num1, T num2)
{
	std::cout << "T Divide(num1 / num2) : ";
	return num1 / num2;
}

template<class T>
T Mulitply(T num1, T num2)
{
	return num1 * num2;
}

// 권장사항 : template<class T> 추천하지 않음
// class 클래스 << 키워드와 혼동하는 경우가 있어서 template키워드로 주로 사용

// 타입의 종류가 2개이상인 경우
template<typename T1, typename T2>

void ShowData(double a, double b)
{
	std::cout << "double a를 T1으로 형변환 값 : " << (T1)a << std::endl;
	std::cout << "double a를 T2으로 형변환 값 : " << (T2)b << std::endl;

	//static_cast<T1>a
}

int Add(int num1, int num2)
{
	return num1 + num2;
}

double Add(double num1, double num2)
{
	return num1 + num2;
}

// Max비교 (a, b) 큰 수를 리턴해주는 함수
// 문자 비교 aaa < bb : 길이가 더 긴 것이 더 크다(재정의) strlen(char*) -> 길이 반환
// a93 < b94 : 문자 안의 숫자가 더 큰것을 크다고 한다(재정의) strcom -> 크기 비교

template<typename T>
T Max(T a, T b)
{
	return a < b ? b : a;	// 이항 연산자 (같으면 num1반환)
}

template<>
const char* Max<const char*>(const char* a, const char* b)
{
	return strlen(a) > strlen(b) ? a : b;
}

// non-type 템플릿 : type이 아닌 템플릿
template<typename T, int val>
T AddValue(T const& curValue)
{
	return curValue + val;
}

const int EVENTMONEY = 10000;	// int
const int EVENTEXP = 100;		// float

void lecture12()
{
	std::cout << "int Add(a, b)의 값 : " << Add(3, 5) << std::endl;
	std::cout << "double Add(a, b)의 값 : " << Add(3.5, 4.5) << std::endl;
	std::cout << "T Add<int>(a, b)의 값 : " << Add<int>(3, 5) << std::endl;
	std::cout << "T Add<float>(a, b)의 값 : " << Add<float>(3.5, 4.5) << std::endl;
	std::cout << "T Add<char>(a, b)의 값 : " << Add<char>(32, 32) << std::endl;
	std::cout << Minus<int>(5, 3) << std::endl;
	std::cout << Divide<float>(3.4, 2.3) << std::endl;
	ShowData<float, int>(3.2, 4.5);

	std::cout << "Add템플릿 함수의 전문화" << std::endl;
	Add<char>(97, 98);

	std::cout << "비교함수 사용예제" << std::endl;
	std::cout << Max<double>(5.2, 3.9) << std::endl;
	// 함수 템플릿에<T 타입을 선언하지 않아도> 컴파일러가 묵시적 -> 제대로 변환 해주는 경우 or 제대로 못한 경우 => 디버깅을 해줘야 찾을 수 있다
	std::cout << Max(5.2, 5.4) << std::endl;
	std::cout << Max("aaa", "bb") << std::endl;

	float myExp = 1.1f;
	int myMoney = 500;
	std::cout << "myExp + EVENTEXP : " << AddValue<float, EVENTEXP>(myExp) << std::endl;
	std::cout << "myMoney + EVENTMONEY : " << AddValue<int, EVENTMONEY>(myMoney) << std::endl;
}