/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-22
	�н� ��ǥ : C++ Ŭ���� ��� �⺻ ������ ���� ����
*/

/*
  ���(intheritance) : �θ�κ��� ������ �̾�޴� ��
  �θ�(Ŭ����) <-> �ڽ�(Ŭ����) ����Ѵ� : private ��� ���� ����. public�� �Լ��� �����ؼ� ��� ������ ���
  �θ� ������ �ִ� ����, �Լ��� �ڽ��� ����ϸ� �θ� �����ϰ� �ִ� ��� ���� ����� �� ������?
*/

/*
  ��ӿ��� ���� ���Ǵ� ���
  ����� ���ִ� Ŭ���� <-> ����� �޴� Ŭ����
     �θ�(parent)     <->    �ڽ�(child) 
     ���(base)       <->   ����,�Ļ�(derived)
	 ����(super)      <->    ����(sub)
	 ����             <->    ����
*/

/*
  ����� �⺻ ��� : �θ� Ŭ����(��� �ϴ� Ŭ����)�� �ߺ����� �ʰ� ����� �� �ִ� ����
  Ŭ������ ������ �Ҹ���
*/

/*
  ���� ������
  public    : public ���� ���� ū ��� ����� ������ ���.  private�̿��� ��� ������ ���
  private   : �ڱ��ڽ�Ŭ���� �̿��� ��� Ŭ������ ������ ���´�.   �ڽ�Ŭ������ ���ٵ� ����
  protected : �⺻������ private�� �뵵�� ������, Ŭ������ ��ӵǾ��� �� �ڽ� Ŭ������ ������ ����ϴ� ����
*/

/*
  ����� ������ ��� 
  private���   : ��� ���� �����ڸ� private�� ���� (�����ϴ� ������ ��������)
  public���    : private�̿��� ��� ������ ���. �θ� ���� �ִ� ���������ڿ� �����ϰ� �����´�
  protected��� : (�θ� Ŭ����)private�̿��� ��� ������ protected�������� ����

  C++ Ư���� ��� ���� : ���߻��, ���߻�� ������ ���������ڷ� �ذ��ϱ� ���ؼ� private, protected ����� ����

*/

/*
  �ڡڡڡڡ� IS-A�� �ش��ϴ� ��쿡�� ���
  ����� ���� �ؾ� �ϴ°�?
  IS-A  : A is B�ΰ�? -> Child(Parent + �߰��� Chile ������ ���)�� Parent�ΰ���?
  Ebook�� å�ΰ�? å�� Ŭ������ ���� Ebook å�� ������ ��ӹ��� �� �ִ�

  HAS-A : A�� B�� �����ϰ� �ִ� Police(�ڽ�)�� Gun(�θ�)�� �����ϰ� �ִ�
  Police(����)
  Gun(��)
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
		std::cout << "���� : " << title << std::endl;
		std::cout << "���� : " << price << std::endl;
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
		std::cout << "DRMkey �� : " << "wwwwwwwwwww" << std::endl;
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

class Police : public Gun	// IS-A���� HAS-A���� �� : ������ ��(����(HAS-A)�ϰ��ִ�)�Դϱ�?
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
		std::cout << "�߻�" << std::endl;
		std::cout << "���� ��ź�� : "<< gun->ShowRemainBullet() << std::endl;
	}
};

class Police2 : public Gun
{
	// ���� �ѿ� ���� �������� ������ ���� �� �ֳ�? -> �����Ҽ��� �ְ� �ƴҼ��� �ְ�
	// HAS-A Police��ü�� Gun�� ����ؾ����� ���ƾ����� �Ǵ��� �� GunŬ���� �������ص� �Ǵ� ��쵵 �������ϴ� case
};


class Base
{
private:
	int num1;
protected:
	int num3;
public:
	Base(int value, int value3) : num1(value), num3(value3) {}	// ��� �̴ϼȶ�����
	Base()
	{
		std::cout << "Base() ������ ȣ�� " << std::endl;
	}
	void Print()
	{
		num1 = 1;
		std::cout << "Base() : " << num1 << std::endl;
	}
	~Base()
	{
		std::cout << "Base() �Ҹ��� ����" << std::endl;
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
		std::cout << "Derived() ������ ȣ��" << std::endl;
	}
	void dPrint()
	{
		num3 = 3;
		num2 = 2;
		std::cout << "Derived() : " << num2 << "," << num3 << std::endl;
	}
	~Derived()
	{
		std::cout << "Derived() �Ҹ��� ����" << std::endl;
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
	// num3 ���� �����ڰ� protected
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

	Derived d1;		// �ڽ�Ŭ������ ������ �� �θ�Ŭ������ ���� �����ؾ� ��
	d1.Print();
	d1.dPrint();

	// protected ���
	// ��ü������ �������� ��Ģ�� ��Ű���� ������ ����
	Parent p1;
	p1.num3 = 10;
	Child c1;
	//c1.num3 = 100;(x)

	// å
	Ebook ebook("C++����������", 10000, "wwwwwww");

	// ����
	Police police;
	police.Shot();


	// ����
	Rectangle re(2, 4);
	re.ShowInfo();

	Square sq(5);
	sq.ShowInfo();

	// pet���� ���α׷� dog, cat, bird -> pet ����Ŭ����
	// dog, cat, bird �����ִ� ��� player 
}