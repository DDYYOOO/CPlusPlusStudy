/*
	작성자 : 이동윤
	작성일 : 2024-08-14
	학습 목표 : 클래스(객체지향 프로그래밍)의 특징
*/

// 프로그래머를 제한하는 것이 클래스가 가진 특징이다.
// 프로그래머의 실수를 원천적으로 방지할 수 있다.

// 1. 생성자
// 프로그래머가 실수로 초기화하지 않고 데이터를 사용하는 것을 원천적으로 막기 위한 문법
// 2. 정보은닉
// 접근 지정자를 통해서 프로그래머가 데이터를 안전하게 보장할 수 있는 기능(숨기는 기능)
// 멤버 변수를 private으로 선언하고, 해당 변수에 접근하는 함수를 정의해서 안전한 형태로 멤버 변수의 접근을 유도하는 것을 의미
// 좋은 클래스를 작성하기 위한 기본 조건 : 정보은닉(은닉성), 캡슐화
// 3. 캡슐화
// 함수를 코드로 작성을 해서, 이 기능이 필요한 사람은 이 함수를 호출만 하면 되게끔 작성
// 사용자(유저)가 그 함수가 무엇을 하는 지 알 필요 없다.
// 작성자(프로그래머) 입장에서 코드를 작성하는데 필요한 함수를 그냥 호출만 하면 된다


#include"lectures.h"
#include<cmath>

class Date
{
private:
	int day; // 기본값 30, 31
	int month; // 1 ~ 12
	int year; // 2024 초기화 값
public:
	// private로 선언하지 않고 멤버 변수를 선언
	void ChangeDay(int x);
	void ChangeMonth(int x);
	void ChangeYear(int x);
	void ChangeDate(int y, int m, int d);
	Date();
	Date(int day, int month, int year);
	void ShowData(); // 오늘 날짜를 출력하는 함수

};

// 디폴트 생성자의 재정의
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
		std::cout << "일은 31일을 넘을 수 없습니다." << std::endl;
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
	std::cout << "오늘은 " << year << "년 " << month << "월 " << day << "일입니다." << std::endl;
}

class SinivelCap
{
public:
	void Take()
	{
		std::cout << "콧물약을 복용했습니다" << std::endl;
	}
};

class SneezeCap
{
public:
	void Take()
	{
		std::cout << "감기약을 복용했습니다" << std::endl;
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

// Point(int x, int y) 좌표를 출력하는 객체를 생성

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
	std::cout << "X의 좌표 : ";
	std::cin >> pointX;
	std::cout << "Y의 좌표 : ";
	std::cin >> pointY;
}

// const 함수에 대한 설명
// (반환값) 함수이름 () const; 
// const keyword 수식받는 함수는 멤버 변수의 값이 변경되지 않음을 보장하는 키워드

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
	//std::cout << "X, Y의 좌표 : (" << pointX << "," << pointY << ")" << std::endl;
	std::printf("X, Y의 좌표 : (%d, %d)\n", GetX(), GetY());
}

// 사각형 Rectangle 객체를생성
// Point -> leftDown, UpRight 좌표 2개를 생성
// 사각형의 넓이를 구하는 함수
// 사각형의 정보를 출력
// leftDown, UpRight의 좌표를 변경하는 함수 추가

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

// 멤버 이니셜라이저를 이용한 멤버 초기화 방법
// 멤버 이니셜라이저는 멤버 변수로 선언된 객체의 생성자 호출을 활용하는 방법

Rectangle::Rectangle() :leftDown(), upRight() 
{
	areaSize = CalculateArea();
};

int Rectangle::CalculateArea()
{
	int row = upRight.GetX() - leftDown.GetX();	// 가로 길이
	int col = upRight.GetY() - leftDown.GetY();	// 세로 길이

	std::cout << "사각형의 넓이 : " << row * col << std::endl;
	return row * col;
}

void Rectangle::ShowRectangle()
{
	leftDown.ShowPointXY();
	upRight.ShowPointXY();
	std::cout << "사각형의 넓이 : " << areaSize << std::endl;
}

// Circle 클래스를 직접 설계
// 반지름 radius, const float PI = 3.14f, 원점 좌표 Point
// 원의 호의 길이와, 원의 넓이를 생성자로 생성하고 ShowCircleInfo(); 원점 좌표, 반지름 길이, 호의 길이, 넓이를 출력하는 함수를 만들어 보세요

class Circle
{
private:
	PointXY point1;
	PointXY point2;
	int centerX;
	int centerY;
	float radius;
	const float PI = 3.14f;
	const float theta = 2 * PI * 1/4;
	float length;
	float circleArea;
	float circleCicrcum;
public:
	Circle();
	float CircleCenterX(); // 원점 좌표 X
	float CircleCenterY(); // 원점 좌표 Y
	float Radius();      // 반지름
	float Length();     // 호의 길이
	float CircleArea(); // 호의 넓이
	//int CircleCircum(); 원의 둘레
	void ShowCircleInfo();

};

Circle::Circle() : point1(), point2()
{
	this->centerX = CircleCenterX();
	this->centerY = CircleCenterY();
	this->radius = Radius();
	this->length = Length();
	this->circleArea = CircleArea();
	//this->circleCicrcum = CircleCircum();
}

float Circle::CircleCenterX()
{
	int centerX = (point1.GetX() - point2.GetX()) / 2;
	return centerX;
}

float Circle::CircleCenterY()
{
	int centerY = (point1.GetY() - point2.GetY()) / 2;
	return centerY;
}

float Circle::Radius()
{
	this->radius = sqrt((float)(centerX * centerX) + (centerY * centerY));
	return radius;
}

float Circle::Length()
{
	// 호의 길이
	this->length = radius * theta;
	return length;
}

float Circle::CircleArea()
{
	// 원의 넓이
	//this->Circlearea = radius * 2 * PI;

	// 호의 넓이
	this->circleArea = radius * length * 1/2;
	return circleArea;
}

//int Circle::CircleCircum()
//{
//	// 원의 둘레
//	this->circleCicrcum = radius * radius * PI;
//	return circleCicrcum;
//}

void Circle::ShowCircleInfo()
{
	//std::cout << "반지름 : " << radius << std::endl;
	//std::cout << "호의 길이 : " << length << std::endl;
	//std::cout << "호의 넓이 : " << circleArea << std::endl;
	//std::cout << "세타 값 : " << theta << std::endl;
	//std::cout << "원의 둘레 : " << circleCicrcum << std::endl;

	std::printf("원점 좌표 : (%d, %d)\n", centerX, centerY);
	std::printf("반지름 : %.3f\n", radius);
	std::printf("세타 값 : % .3f\n", theta);
	std::printf("호의 길이 : % .3f\n", length);
	std::printf("호의 넓이 : % .3f\n", circleArea);
	//std::printf("원의 둘레 : %.2f\n", circleCicrcum);
}


void lecture5()
{
	Date date1;		// 디폴트 생성자로 초기화
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

	// 함수를 이용해서 멤버의 값을 저장하는 것과 멤버의 변수에 직접 접근해서 변경하는 것과 크게 차이점이 없다

	Patient pa;
	Capsule100 capsule;
	pa.TakeCapsule(capsule);

	//Rectangle rect1;
	//rect1.ShowRectangle();

	Circle c1;
	c1.ShowCircleInfo();


}