/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-29
	�н� ��ǥ : templateŰ����(�Ϲ�ȭ �ڵ�)
*/

/*
  template�� ����ϴ°�?
  �� ���� ���ϴ� �Լ�(int �� return)
  �Լ� �����ε� : ���ڱ��� �����ؼ� �Լ��� ���� 
  �ѹ��� ������ Ÿ��(int, char, float....)�� ǥ���ϴ� ��� -> template
*/

/*
  template ����
  �Լ� �̸�<������ Ÿ��>()
*/

/*
  ��� ����
  �Լ� ���ø� : template<typename T> �Լ� ����. �Լ��� ����µ� ����ϴ� ���ø��� �ǹ�
  ���ø� �Լ� : Add<int>(3, 5);
*/

/*
  �Լ� ���ø��� ������µ�, ���� ���ø� �Լ��� �����Ǵ°�?
  Add<int>(3,5);
  int Add<int>(int num1, int num2)
  {
	  return num1 + num2;
  }
  �Լ� ���ø��� �����ϸ� ���ʿ��� �޸𸮸� ����ϴ� �;� �ƴѰ�?
  -> Add<int>(3, 5), �ڵ尡 �ۼ��Ǿ��� ��(������ ������) int Add<int> ������ �ȴ�.
  -> ������ ������ T Ÿ�Կ� �ش��ϴ� �Լ��� ����ٸ� ��ǻ�� �ӵ��� �������� ������?
  -> ������ <-> ��Ÿ�� ���� : ���α׷� ���� ���� �Լ��� ���� ��������� ������ ���α׷� �ӵ��� ����X
*/

/*
  type T => �� T��� �ܾ ����ؾ� �ϴ°�?
  -> �ٸ� �ܾ ����ص� ����(���������� T�� ���)
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
  �Լ� ���ø��� ����ȭ(specializtion)
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

// ������� : template<class T> ��õ���� ����
// class Ŭ���� << Ű����� ȥ���ϴ� ��찡 �־ templateŰ����� �ַ� ���

// Ÿ���� ������ 2���̻��� ���
template<typename T1, typename T2>

void ShowData(double a, double b)
{
	std::cout << "double a�� T1���� ����ȯ �� : " << (T1)a << std::endl;
	std::cout << "double a�� T2���� ����ȯ �� : " << (T2)b << std::endl;

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

// Max�� (a, b) ū ���� �������ִ� �Լ�
// ���� �� aaa < bb : ���̰� �� �� ���� �� ũ��(������) strlen(char*) -> ���� ��ȯ
// a93 < b94 : ���� ���� ���ڰ� �� ū���� ũ�ٰ� �Ѵ�(������) strcom -> ũ�� ��

template<typename T>
T Max(T a, T b)
{
	return a < b ? b : a;	// ���� ������ (������ num1��ȯ)
}

template<>
const char* Max<const char*>(const char* a, const char* b)
{
	return strlen(a) > strlen(b) ? a : b;
}

// non-type ���ø� : type�� �ƴ� ���ø�
template<typename T, int val>
T AddValue(T const& curValue)
{
	return curValue + val;
}

const int EVENTMONEY = 10000;	// int
const int EVENTEXP = 100;		// float

void lecture12()
{
	std::cout << "int Add(a, b)�� �� : " << Add(3, 5) << std::endl;
	std::cout << "double Add(a, b)�� �� : " << Add(3.5, 4.5) << std::endl;
	std::cout << "T Add<int>(a, b)�� �� : " << Add<int>(3, 5) << std::endl;
	std::cout << "T Add<float>(a, b)�� �� : " << Add<float>(3.5, 4.5) << std::endl;
	std::cout << "T Add<char>(a, b)�� �� : " << Add<char>(32, 32) << std::endl;
	std::cout << Minus<int>(5, 3) << std::endl;
	std::cout << Divide<float>(3.4, 2.3) << std::endl;
	ShowData<float, int>(3.2, 4.5);

	std::cout << "Add���ø� �Լ��� ����ȭ" << std::endl;
	Add<char>(97, 98);

	std::cout << "���Լ� ��뿹��" << std::endl;
	std::cout << Max<double>(5.2, 3.9) << std::endl;
	// �Լ� ���ø���<T Ÿ���� �������� �ʾƵ�> �����Ϸ��� ������ -> ����� ��ȯ ���ִ� ��� or ����� ���� ��� => ������� ����� ã�� �� �ִ�
	std::cout << Max(5.2, 5.4) << std::endl;
	std::cout << Max("aaa", "bb") << std::endl;

	float myExp = 1.1f;
	int myMoney = 500;
	std::cout << "myExp + EVENTEXP : " << AddValue<float, EVENTEXP>(myExp) << std::endl;
	std::cout << "myMoney + EVENTMONEY : " << AddValue<int, EVENTMONEY>(myMoney) << std::endl;
}