/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-14
	�н� ��ǥ : Ŭ����(��ü���� ���α׷���)�� Ư¡
*/

// ���α׷��Ӹ� �����ϴ� ���� Ŭ������ ���� Ư¡�̴�.
// ���α׷����� �Ǽ��� ��õ������ ������ �� �ִ�.

// 1. ������
// ���α׷��Ӱ� �Ǽ��� �ʱ�ȭ���� �ʰ� �����͸� ����ϴ� ���� ��õ������ ���� ���� ����
// 2. ��������
// ���� �����ڸ� ���ؼ� ���α׷��Ӱ� �����͸� �����ϰ� ������ �� �ִ� ���(����� ���)
// ��� ������ private���� �����ϰ�, �ش� ������ �����ϴ� �Լ��� �����ؼ� ������ ���·� ��� ������ ������ �����ϴ� ���� �ǹ�
// ���� Ŭ������ �ۼ��ϱ� ���� �⺻ ���� : ��������(���м�), ĸ��ȭ
// 3. ĸ��ȭ
// �Լ��� �ڵ�� �ۼ��� �ؼ�, �� ����� �ʿ��� ����� �� �Լ��� ȣ�⸸ �ϸ� �ǰԲ� �ۼ�
// �����(����)�� �� �Լ��� ������ �ϴ� �� �� �ʿ� ����.
// �ۼ���(���α׷���) ���忡�� �ڵ带 �ۼ��ϴµ� �ʿ��� �Լ��� �׳� ȣ�⸸ �ϸ� �ȴ�


#include"lectures.h"

class Date
{
private:
	int day; // �⺻�� 30, 31
	int month; // 1 ~ 12
	int year; // 2024 �ʱ�ȭ ��
public:
	// private�� �������� �ʰ� ��� ������ ����
	void ChangeDay(int x);
	void ChangeMonth(int x);
	void ChangeYear(int x);
	void ChangeDate(int y, int m, int d);
	Date();
	Date(int day, int month, int year);
	void ShowData(); // ���� ��¥�� ����ϴ� �Լ�

};

// ����Ʈ �������� ������
Date::Date()
{
	day = 14;
	month = 8;
	year = 2024;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

//Date::Date(int _day, int _month, int _year)
//{
//	day = _day;
//	month = _month;
//	year = _year;
//}

void Date::ChangeDay(int x)
{
	if (x > 31)
	{
		std::cout << "���� 31���� ���� �� �����ϴ�." << std::endl;
		return;
	}
	day = x;
}

void Date::ChangeMonth(int x)
{
	month = x;
}

void Date::ChangeYear(int x)
{
	year = x;
}

void Date::ChangeDate(int y, int m, int d)
{
	this->year = y;
	this->month = m;
	this->day = d;
}

void Date::ShowData()
{
	std::cout << "������ " << year << "�� " << month << "�� " << day << "���Դϴ�." << std::endl;
}

class SinivelCap
{
public:
	void Take()
	{
		std::cout << "�๰���� �����߽��ϴ�" << std::endl;
	}
};

class SneezeCap
{
public:
	void Take()
	{
		std::cout << "������� �����߽��ϴ�" << std::endl;
	}
};

class Capsule100
{
private:
	SinivelCap sc;
	SneezeCap sz;
public:
	void Take()
	{
		sc.Take();
		sz.Take();
	}
};

class Patient
{
public:
	void TakeCapsule(Capsule100& capsule)
	{
		capsule.Take();
	}
};

// Point(int x, int y) ��ǥ�� ����ϴ� ��ü�� ����

class PointXY
{
private:
	int pointX;
	int pointY;
public:
	PointXY();
	int GetX() const;
	int GetY() const;
	void ShowPointXY() const;
};

PointXY::PointXY()
{
	std::cout << "X�� ��ǥ : ";
	std::cin >> pointX;
	std::cout << "Y�� ��ǥ : ";
	std::cin >> pointY;
}

// const �Լ��� ���� ����
// (��ȯ��) �Լ��̸� () const; 
// const keyword ���Ĺ޴� �Լ��� ��� ������ ���� ������� ������ �����ϴ� Ű����

int PointXY::GetX() const
{
	return pointX;
}

int PointXY::GetY() const
{
	return pointY;
}

void PointXY::ShowPointXY() const
{
	//std::cout << "X, Y�� ��ǥ : (" << pointX << "," << pointY << ")" << std::endl;
	std::printf("X, Y�� ��ǥ : (%d, %d)\n", GetX(), GetY());
}

// �簢�� Rectangle ��ü������
// Point -> leftDown, UpRight ��ǥ 2���� ����
// �簢���� ���̸� ���ϴ� �Լ�
// �簢���� ������ ���
// leftDown, UpRight�� ��ǥ�� �����ϴ� �Լ� �߰�

class Rectangle
{
private:
	PointXY leftDown;
	PointXY upRight;
	int areaSize;
public:
	Rectangle();
	int CalculateArea();
	void ShowRectangle();
};

// ��� �̴ϼȶ������� �̿��� ��� �ʱ�ȭ ���
// ��� �̴ϼȶ������� ��� ������ ����� ��ü�� ������ ȣ���� Ȱ���ϴ� ���

Rectangle::Rectangle() :leftDown(), upRight() 
{
	areaSize = CalculateArea();
};

int Rectangle::CalculateArea()
{
	int row = upRight.GetX() - leftDown.GetX();	// ���� ����
	int col = upRight.GetY() - leftDown.GetY();	// ���� ����

	std::cout << "�簢���� ���� : " << row * col << std::endl;
	return row * col;
}

void Rectangle::ShowRectangle()
{
	leftDown.ShowPointXY();
	upRight.ShowPointXY();
	std::cout << "�簢���� ���� : " << areaSize << std::endl;
}

// Circle Ŭ������ ���� ����
// ������ radius, const float PI = 3.14f, ���� ��ǥ Point
// ���� ȣ�� ���̿�, ���� ���̸� �����ڷ� �����ϰ� ShowCircleInfo(); ���� ��ǥ, ������ ����, ȣ�� ����, ���̸� ����ϴ� �Լ��� ����� ������

class Circle
{
private:
	double radius;
	const float PI = 3.14f;
public:
	Circle();

};


void lecture5()
{
	Date date1;		// ����Ʈ �����ڷ� �ʱ�ȭ
	date1.ShowData();

	Date date2 = Date(15, 8, 2024);
	date2.ShowData();
	date2.ChangeDay(16);
	date2.ChangeMonth(8);
	date2.ChangeYear(2024);
	date2.ShowData();

	Date date3;
	date3.ChangeDate(2025, 8, 15);
	date3.ShowData();
	date3.ChangeDay(35);
	date3.ShowData();

	// �Լ��� �̿��ؼ� ����� ���� �����ϴ� �Ͱ� ����� ������ ���� �����ؼ� �����ϴ� �Ͱ� ũ�� �������� ����

	Patient pa;
	Capsule100 capsule;
	pa.TakeCapsule(capsule);

	Rectangle rect1;
	rect1.ShowRectangle();

}