/*
	작성자 : 이동윤
	작성일 : 2024-08-22
	학습 목표 : C++ 클래스 상속 기본 문법에 대한 이해
*/

/*
  상속(intheritance) : 부모로부터 유산을 이어받는 것
  부모(클래스) <-> 자식(클래스) 상속한다 : private 멤버 변수 선언. public에 함수를 선언해서 멤버 변수를 사용
  부모가 가지고 있는 변수, 함수를 자식이 사용하면 부모가 소유하고 있는 모든 것을 사용할 수 있을까?
*/

/*
  상속에서 자주 사용되는 용어
  상속을 해주는 클래스 <-> 상속을 받는 클래스
     부모(parent)     <->    자식(child) 
     기반(base)       <->   유도,파생(derived)
	 슈퍼(super)      <->    서브(sub)
	 상위             <->    하위
*/

/*
  상속의 기본 기능 : 부모 클래스(상속 하는 클래스)를 중복하지 않고 사용할 수 있는 문법
  클래스의 생성자 소멸자
*/

/*
  접근 지정자
  public    : public 범위 보다 큰 모든 멤버의 접근을 허용.  private이외의 모든 접근을 허용
  private   : 자기자신클래스 이외의 모든 클래스의 접근을 막는다.   자식클래스의 접근도 제한
  protected : 기본적으로 private과 용도가 같은데, 클래스가 상속되었을 때 자식 클래스의 접근을 허용하는 범위
*/

/*
  상속의 세가지 방법 
  private상속   : 모든 접근 지정자를 private로 변경 (재상속하는 이유가 없어진다)
  public상속    : private이외의 모든 접근을 허용. 부모가 갖고 있는 접근지정자와 동일하게 가져온다
  protected상속 : (부모 클래스)private이외의 모든 접근을 protected접근으로 변경

  C++ 특별한 상속 문법 : 다중상속, 이중상속 문제를 접근지정자로 해결하기 위해서 private, protected 상속이 존재

*/

/*
  ★★★★★ IS-A에 해당하는 경우에만 상속
  상속을 언제 해야 하는가?
  IS-A  : A is B인가? -> Child(Parent + 추가로 Chile 구현된 기능)가 Parent인가요?
  Ebook은 책인가? 책을 클래스로 정의 Ebook 책의 내용을 상속받을 수 있다

  HAS-A : A가 B를 소유하고 있다 Police(자식)가 Gun(부모)를 소유하고 있다
  Police(경찰)
  Gun(총)
*/

#include"lectures.h"
#include<string>

class Book
{
private:
	char* title;
	//std::string name;
	int price;
public:
	Book(const char* title, int price)
	{
		this->price = price; 
		title = new char[strlen(title) + 1];
		strcpy_s(this->title, strlen(title) + 1, title);
	}
	//Book(int price, std::string name) : price(price), name(name) {}
	~Book()
	{
		delete[] title;
	}

	void ShowBookInfo() 
	{
		std::cout << "제목 : " << title << std::endl;
		std::cout << "가격 : " << price << std::endl;
	}

};

class Ebook : public Book
{
private:
	char* DRMkey;
public:
	Ebook(const char* title, int price, const char* key) : Book(title, price)
	{
		DRMkey = new char[strlen(key) + 1];
		strcpy_s(DRMkey, strlen(key) + 1, key);
	}
	~Ebook()
	{
		delete[] DRMkey;
	}

	void ShowEbookInfo()
	{
		ShowBookInfo();
		std::cout << "DRMkey 값 : " << "wwwwwwwwwww" << std::endl;
	}

};

class Gun
{
protected:
	int bulletCount;
public:
	Gun()
	{ 
		bulletCount = 10;
	}
	Gun(int bullet)
	{
		bulletCount = bullet;
	}
	void UseGun()
	{
		bulletCount--;
	}
	int ShowRemainBullet()
	{
		return bulletCount;
	}
};

class Police : public Gun	// IS-A인지 HAS-A인지 비교 : 경찰이 총(소유(HAS-A)하고있다)입니까?
{
private:
	Gun* gun;
public:
	Police()
	{
		gun = new Gun(10);
	}
	void Shot()
	{
		gun->UseGun();
		std::cout << "발사" << std::endl;
		std::cout << "남은 잔탄수 : "<< gun->ShowRemainBullet() << std::endl;
	}
};

class Police2 : public Gun
{
	// 경찰 총에 총을 소유안한 경찰이 있을 수 있나? -> 소유할수도 있고 아닐수도 있고
	// HAS-A Police객체가 Gun을 상속해야할지 말아야할지 판단할 때 Gun클래스 소유안해도 되는 경우도 만들어야하는 case
};


class Base
{
private:
	int num1;
protected:
	int num3;
public:
	Base(int value, int value3) : num1(value), num3(value3) {}	// 멤버 이니셜라이져
	Base()
	{
		std::cout << "Base() 생성자 호출 " << std::endl;
	}
	void Print()
	{
		num1 = 1;
		std::cout << "Base() : " << num1 << std::endl;
	}
	~Base()
	{
		std::cout << "Base() 소멸자 생성" << std::endl;
	}
};

class Derived : public Base
{
private:
	int num2;
public:
	Derived(int value) : num2(value) {}
	Derived()
	{
		std::cout << "Derived() 생성자 호출" << std::endl;
	}
	void dPrint()
	{
		num3 = 3;
		num2 = 2;
		std::cout << "Derived() : " << num2 << "," << num3 << std::endl;
	}
	~Derived()
	{
		std::cout << "Derived() 소멸자 생성" << std::endl;
	}
};

class Parent
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;
};

class Child : protected Parent
{
	// num3 접근 지정자가 protected
};

class Rectangle
{
private:
	int width;
	int height;
public:
	Rectangle(int width, int height) : width(width), height(height) {}
	void ShowInfo()
	{
		std::cout << "width * height :  " << width * height << std::endl;
	}
};

class Square : public Rectangle
{

public:
	Square(int size) : Rectangle(size, size) {}
};

void lecture8()
{
	Base b1(1, 3);
	b1.Print();

	Derived d1;		// 자식클래스는 생성될 때 부모클래스도 같이 생성해야 함
	d1.Print();
	d1.dPrint();

	// protected 상속
	// 객체지향의 정보은닉 원칙을 지키려는 문법적 지원
	Parent p1;
	p1.num3 = 10;
	Child c1;
	//c1.num3 = 100;(x)

	// 책
	Ebook ebook("C++예제문제집", 10000, "wwwwwww");

	// 경찰
	Police police;
	police.Shot();


	// 예제
	Rectangle re(2, 4);
	re.ShowInfo();

	Square sq(5);
	sq.ShowInfo();

	// pet관리 프로그램 dog, cat, bird -> pet 공통클래스
	// dog, cat, bird 돌봐주는 사람 player 
}