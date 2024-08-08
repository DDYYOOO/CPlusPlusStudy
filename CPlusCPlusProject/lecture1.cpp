/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-08
	�н� ��ǥ : C++ ��� �н�(C��� ����)
*/

/*
  Hello World ��� ���ִ� �Լ� : ����� �Լ� <- <stdio.h> printf, scanf
  Hello World ��� ���ִ� �Լ� : ����� �Լ� <- <iostream> cout, cin
  cout : ��� �Լ�
  ���� : std::cout << "Hello World!";(std::cout << "Hello World!" << std::endl;)
  cin : �Է� �Լ�
  ���� : std::cin >> num;
  std::endl; == \n
*/

/*
  1. std:: -> C++ standard Library�� ��ϵ� �Լ���, C++ ǥ�� ���̺귯���� ��� �Լ��� ���ǵ� �̸� ����
  namespace(�̸� ����) : � ���ǵ� ��ü�� ��� �ҼӵǾ� �ִ��� �˷��ִ� ��


*/

/*
  �Լ�, ������ �ۼ� �ϴµ� �ٸ� ����� �� �ڵ带 ������ ���鼭 �ߺ��� �̸��� ���� �Լ��� ����� Ȯ���� ������
  C++���������� �̸� �����ϱ� ���ؼ� namespace ���� ����
  �ƹ� �̸� ::  <- �̷� �������� ������ �տ� �Լ� �̸��� namespace�̴�
  ����
  namespace �̸� { } 
*/

/*
  ���� ���� ������ '::'
  ���� : namespace:: ���� �Ǵ� �Լ�;
  namespace�ȿ� �ִ� ���� �Ǵ� �Լ��� ����� �� �ִ�.
  namespace�� �� ���
  using Ű����
  using TODATISTHRUSDAY::num;
*/

/*
  1. ���� : int, char, float, double....
  2. �ݺ���, ���ǹ� : for�ݺ���, while�ݺ���, if���ǹ�, switch���ǹ�...
  3. ������(����) : int*, char*, &num, *num.....
  */

#include"lectures.h"
#include"cstring"

namespace TODATISTHRUSDAY
{
	int num;
}

using TODATISTHRUSDAY::num;			// �� �̸��������� num������ ���
//using namespace TODATISTHRUSDAY;	// �� �̸��������� ����ϴ� ��� ���� �Ǵ� �Լ��� using namespace ���
									// ���� : �̸��� �� namespace�� ���� �Է� ���ص� ��
									// ���� : namespace�ȿ� ������ �Լ��� ��������, �ٸ� �Լ� �Ǵ� ������ �̸��� ��ġ�� ��찡 ����
// ��õ ����
// using namespace�� �̿��ؼ� ��� ������ �����ϴ� ����� ����
// �ʿ��� �Լ��� �ʿ��� ������ �����ؼ� ���

// using ��� ����

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
		std::cout << "�� �̸��� " << name << "�Դϴ�\n";
		std::cout << "�� ���̴� " << age << "�Դϴ�\n";
	}
}

using std::cin;


void lecture1()
{
	//std:: std��� namespace�����ȿ� C++�� ��� �Լ��� �� �ִ�
	cout << "Hello World!" << endl;
	std::cout << "Hello World!\n";

	CPP::Sample();
	CPP2::Sample();
	strcpy_s(LDY::name, 30, "�̵���");
	LDY::PrintfMyName();
	
	int a1;

	std::cout << "�Է� ���� ���� �Է� : ";
	std::cin >> a1;
	std::cout << "�Է� ���� �� : " << a1 << endl;

	int LuckyNumber  = 5;
	int UserInput;

	cout << "���� ���߱� ����" << endl;
	
	while (1)
	{
		cout << "���� �Է� : " << endl;
		std::cin >> UserInput;

		if (UserInput == LuckyNumber)
		{
			cout << "������ϴ�" << endl;
			break;
		}
		else
		{
			cout << "Ʋ�Ƚ��ϴ�" << endl;
			continue;
		}
	} 
}