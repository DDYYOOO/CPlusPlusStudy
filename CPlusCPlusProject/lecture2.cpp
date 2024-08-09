/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-09
	�н� ��ǥ : C��� �����͸� C++���� Ȱ��(������reference)�� ���� ����
*/

/*
  C���� �����͸� ����ϴ� ����
  �Լ��� ����ϸ鼭 �Լ� �ȿ��� �����͸� �����Ϸ��� �����͸� ���ڷ� �Ѱ���� ��

*/

/*
  �Լ��� ����� �� �����Ͱ� �ƴ� �����ڸ� ����ϸ� ���ڷ� &(�ּҿ�����) ������� ���� �� �ִ�
  �ּ� ���� : int*
  ������ ���� : int& ������ �̸� = �����ϰ��� �ϴ� ����;
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

// �Լ� �����ε� : C���� �Լ��� �̸����� ������ C++�� �Լ��� �̸� + (�Ű�����, ����)
void SwapInt(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
// ���� �̸� ���� �Ű����� Ÿ���̸� C++������ ������
//void SwapInt(int& a, int& b)
//{
//
//}

void ChangeVal(int& p)
{
	p = 10;
}

// int�� ��ȯ�ϴ� �Լ�
int Function()
{
	int a = 2;
	return a;
}

// �����ڸ� �����ϴ� �Լ�
// ����� �����ؾ��ϴ� �Լ�
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
	std::cout << "�̸� �Է� : ";
	std::cin >> human.name;
	std::cout << "���� �Է� : ";
	std::cin >> human.age;
	return human;
}

void PrintHumanInfo(Human& human)
{
	std::cout << "�̸� : " << human.name << std::endl;
	std::cout << "���� : " << human.age << std::endl;
}

void lecture2()
{
	// C��� ����
	int num = 10;
	int* numPtr = &num;
	// C++�� ���������¸� ������� �ʾƵ� �۵��Ѵ�
	std::cout << "�������� �ּ� : " << numPtr << std::endl; 
	std::cout << "�����Ͱ� ����Ű�� �� : " << *numPtr << std::endl;

	// ������ �̸� ��Ģ
	// ���� ���� : �� ����� ���� ȥ���ؼ� ���� �� ��
	// ������ �̸� ��Ģ�� �ϳ��� �����ؼ� �� �� int NumberOfMonster (x)
	// �� ����� ��� ���� �� �� int number_ofMonster (x)
	//int number_of_people;	// �ܾ�� �ܾ���̸� '_' ǥ�� (������ũ?���)
	//int numberOfpeople;		// ���� �� �� �빮�ڷ� ǥ�� (ī����)
	
	int num1 = 1;
	int num2 = 2;
	SwapInt(&num1, &num2);

	std::cout << "num1�� �� : " << num1 << " num2�� �� : " << num2 << std::endl;

	// ������ ����� ��
	// ������ : ������ ����
	int a1 = 10;
	int& AnotherA1 = a1;	// AnotherA1�� a1�� �����̴�
	std::cout << "AnotherA1�� �� : " << AnotherA1 << std::endl;

	// a1 ������ ���� ����
	// primitive type
	// ����ü�� ũ��� ����� �������̱� ������ �ۼ��ڿ� ���� ũ�Ⱑ �޶�����
	// �����ڵ� ����������, �����ڰ� ����Ű�� �ּҸ� �ѹ� �����ϸ� 8����Ʈ(64��Ʈ �ý���)������ ����ü�� �����ؼ� �� �� �ֱ� ����

	// �����ڿ� �����Ͱ� �ٸ� �κ�
	// �����ʹ� �ּҿ����ڸ� ���ڷ� �ް� �ؾ� �Ѵ�. ����ڰ� �Լ��� �����Ϳ� ���� ���ص��� �־���Ѵ� (C���)
	// �����ڴ� �ּҿ����ڸ� ���ڷ� �޳�? �ȹ޴´�. ����ڰ� �� ���� ���� (C++���)

	int c_num1;
	char name[30];
	std::cout << "�Է� : "; 
	std::cin >> c_num1;
	std::cout << "�Է� �� : " << c_num1 << std::endl;
	std::cout << "�Է� : ";
	std::cin >> name;
	std::cout << "�Է� �� : " << name << std::endl;

	// ������(reference) �Լ����� ����ϴ� ���
	// �����ڴ� �ݵ�� ����� ���ÿ� �ʱ�ȭ �ؾ� ��
	// �����ڴ� ������ �� ����� �ּҸ� �����ͼ� ���縦 �Ѵ�
	int d_num1 = 1, d_num2 = 2;
	SwapInt(d_num1, d_num2);

	std::cout << "d_num1�� �� : " << d_num1 << " d_num2�� �� : " << d_num2 << std::endl;

	int& AnotherD_num1 = d_num1;

	// �����ڴ� ���ͷ� ����� ����Ű�� ���Ѵ�.
	//int& Literal = 100;
	// �����ڴ� const Ű����� ���ͷ� ����� ����ų �� �ִ�.
	const int& Literal = 100;

	int p = 5;
	ChangeVal(p);
	std::cout << "p�� �� : " << p << std::endl;

	int p2 = 5;
	// ������(reference)�� �����ϴ� �Լ�
	// ���۷��� Ÿ���� ������ ���� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ�
	int tempA = Function();		// tempA�� Function�� ���ϰ� a�� �����ؼ� ����
	//int tempB = Function2();	// ������ �ڵ�
	int tempB = Function3(p2);

	std::cout << "tempA�� �� : " << tempA << std::endl;
	std::cout << "tempB�� �� : " << tempB << std::endl;

	//int& AnotherTemp = Function(); // �� constŰ���� ������ ���� int& AnotherTemp = 2(Function());
	const int& AnotherTemp = Function();
	//int& AnotherTemp2 = Function2(); // �Ϻ� �����Ϸ����� ������ ������ �߻��Ѵ�

	// (1). �Լ����� ���� ������ ��
	// int a = Function();    a = 2; 2��� ���� a�� ����. ���� ���簡 �̷������ (��밡��)
	// int& a = Function();   ������ Ÿ������ ���ͷ� ����� ����ų �� ����. ������ ������ �߻�
	// const int& a = Function();  �����ڰ� ���ͷ��� ����Ű�� �ϰ� ������ const Ű���� ���

	// (2). �Լ��� �����ڸ� �����Ҷ� int& Function();
	// �ڡڷ��۷��� Ÿ���� ������ �� �ݵ�� ���������� ��ȯ���� �ʵ��� �����ؾ� �Ѵ� �ڡ�

	Human h1;
	
	AddHumanInfo(h1);

	PrintHumanInfo(h1);

}