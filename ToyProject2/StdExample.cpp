// ����ϱ� ���� �Լ�
// std::cin >> input; �������� �ƴ��� �Ǻ�, std::isdigit();
// std::settw() ������ ���̸� �����ϰ� ���߾� �ִ� �Լ�
// �����͸� Ŭ������ ǥ���� �� -> iterator
// ���ڿ��� Ŭ������ ǥ���� �� -> string

#include<iostream>
#include<cstdlib>
#include<iomanip>


class SampleSTD
{
public:
	SampleSTD() {}

	// �ܼ��� ��� ���� ����� �Լ� (������ ����)
	// setw(����) : ���� ũ�� ��ŭ ũ�⸦ ä���� �����ش�.
	// std::left : ���� ����
	// std::right : ������ ����
	// std::setfill : ��ĭ�� (����)�� ä���ش�.
	void SetWidthExample()
	{
		int a = 423;
		int b = 12345;
		
		std::cout << std::setfill('#') << std::left << std::setw(10) << a << std::endl;
		std::cout << std::setfill('*') << std::right << std::setw(20) << b << std::endl;
		std::cout << "�� ������ �����ϸ� �ƹ� ���ڳ� �Է����ּ���" << std::endl;

		int waitnum;
		std::cin >> waitnum;
		system("cls");
	}
	void IsDigitExample()
	{
		// �������� ���ڰ� �ƴϸ� false, ������ true ��ȯ���ִ� �Լ�
		int a = 10;
		if (std::isdigit(a))
		{
			std::cout << "���Դϴ�" << std::endl;
		}
		
	}

};

// ������
// *ptr : ������
// IteratorŬ���� std
// �ڷᱸ�� class
// Ŭ���� �ȿ� ������(iteratorŬ����)
// for�ݺ���
// for(int i = 0; i < arr.Length; i++) {}
// Iterator s;		s.begin();    s.End();
// while(s.End() != nullptr)

class Iterator
{
private:
	int* ptr;
public:
	Iterator(int* p) : ptr(p) {}
	
	// ������ �����ε�
	Iterator* operator++()
	{
		++ptr;
		return this;
	}
	Iterator* operator++(int)
	{
		Iterator* temp = this;
		++(*this);
		return temp;
	}
};