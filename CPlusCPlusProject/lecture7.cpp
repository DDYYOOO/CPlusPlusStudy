/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-19
	�н� ��ǥ : ������ �����ε�
*/

/*
  #include<iostream>
  istream(�Է� ��Ʈ��), ostream(��� ��Ʈ��)
  �ܼ�â�� ������� ����
  cout << : C���� ��Ʈ�����ڷ� ���Ǿ��µ�, cout <<  ��Ʈ ����� ������ �ֳ�?
  cin >> : C���� ��Ʈ�����ڷ� ���Ǿ��µ�, cin >>  ��Ʈ ����� ������ �ֳ�?
*/

/*
  ����ü, Ŭ���� : ����� ���� �ڷ���
  Ŭ������ Ŭ���� ���̿� ��������ڰ� ����� �����Ѱ�?
  ���� -> �ش��ϴ� �ǿ����ڰ� ����
  �ذ� : �ش��ϴ� �����ڸ� ������ָ� �ȴ�
*/

/*
  ������ �����ε� : �⺻ �����ڵ�(+, -, *, /, [], <<, >>)���� ����ڰ� Ŭ������ ���� �����ϴ� ��
  ���� : (��ȯ��)(������)()
  ���� : void operator+();
*/

/*
  �����Լ� �����ε�
  - ����Լ��� ���� �����ε� : ��ü.operator+(�ǿ�����) : ��ü + �ǿ����� ������ �̷���� �ִ�
  - ������ �������� ��ü�� �ݵ�� ���ʿ� �־�� �Ѵ�.
  - ������
  p1 + 10;
  10 + p1;
  �����Լ� �����ε��� operator+(�ǿ�����, �ǿ�����) �ǿ����� + �ǿ����� ������ ��ü�� �ڿ� ��ġ�ص� �������� ����� ���
  �ǿ����� + �ǿ����� = operator+(�ǿ�����, �ǿ�����)
*/

/*
  friend �Լ�
  Ŭ������ ����Լ��� �ƴϸ鼭 �ش� Ŭ������ private �����͸� ������ �� ����ϴ� �Լ�
  Ŭ������ ������ ������, �� Ŭ���� �ȿ� �ִ� �����͸� ����ϰ� �;��� �� ����ϴ� Ű����
  ���� : private, public -> private�� �̿��ؼ� �ܺο��� ������ ���ϰ� �ϱ� ���� ���� ������ �����ϴ� ����
  ���� : ������ �����ε��� ����ؼ� �������� �Լ��� ���� �� �ִ�.
  ��� : ������ �����ε� �̿ܿ� friend �Լ� ����� ����
*/

/*
  ���� ������ �����ε� : ���� ������
  ++ : num + 1;
  -- : num - 1;

  ++num : ���� ���� ������
  num++ : ���� ���� ������ 

*/

#include"lectures.h"


class Point
{
private:
	int posX, posY;
public:
	Point() {}			// ����Ʈ ������
	Point(int x, int y) // ������ �����ε�
	{
		posX = x;
		posY = y;
	}
	void ShowPosition()
	{
		std::cout << "posX : " << posX << ", posY : " << posY << std::endl;
	}
	Point operator+(Point& ref)
	{
		//posX + ref.posX;
		//posY + ref.posY;
		return Point(posX + ref.posX, posY + ref.posY);
	}
	Point operator-(Point& ref)
	{
		//posX - ref.posX;
		//posY - ref.posY;
		return Point(posX - ref.posX, posY - ref.posY);
	}
	Point operator+(int value)
	{
		return Point(posX + value, posY + value);
	}

	friend Point operator+(int num, Point ref);	// ���� �Լ� ������ �����ε�

	Point operator++() // ���� ���� ������   ++p1;
	{
		posX += 1;
		posY += 1;
		return *this;	// �ڱ� �ڽ��� ��ü�� ��ȯ(�ڱ� ���� �����ε�)
	}
	Point operator++(int) // ���� ���� ������  p1++;
	{
		Point temp(*this); // ���� ������ : ���� ����
		posX += 1;
		posY += 1;
		return temp;
	}
};

Point operator+(int num, Point ref)		// �ǿ����� + �ǿ�����
{
	ref.posX += num;
	ref.posY += num;
	return ref;
}

// �̸� ������ ���� �Ǿ��ִ� Ŭ����

class Eng;  // Eng Ŭ������ �����Ѵٰ� ���
class Math
{
private:
	char name[10];
	int score;
public:
	Math() {};		// ����Ʈ ������ (�ʼ�) : �����ڸ� ���� �����ϸ� ����Ʈ �����ڰ� �ڵ����� �������� �ʱ� ������ ��������� ����
	Math(const char* name, int score) 
	{
		strcpy_s(this->name, 10, name);
		this->score = score;
	}

	friend int Add(Math m1, Eng e1);
};

class Eng
{
private:
	char name[10];
	int score;
public:
	Eng() {};
	Eng(const char* name, int score)
	{
		strcpy_s(this->name, 10, name);
		this->score = score;
	}

	friend int Add(Math m1, Eng e1);
};

int Add(Math m1, Eng e1)
{
	return m1.score + e1.score;
}

// <iostream> istream, ostream

// ����Լ��� ������ �����ε� ����
/*
  ostream& operator<<(std::ostream& out, int& val)
  {
	  printf("%d", val);
	  return out;
  }

   ostream& operator<<(std::ostream& out, const char* val)
  {
	  printf("%s", val);
	  return out;
  }
  ostream& operator<<(std::ostream& out, double& val);
  .....

  ostream& operator<< (std::ostream& out)
  {
	  printf("\n");
	  return out;
  }
*/ 

// �Է��Լ� ������ �����ε� ����
/*
  istream& operator<<(std::istream& in, int& val)
  {
      int some;
      scanf(val, some);
	  return in;
  }
  .....
*/


// C��� int -> printf("%d", num); 




void lecture7()
{
	Point p1(1,1);
	Point p2(2, 3);
	
	p1.ShowPosition();
	p2.ShowPosition();
	
	// Point p1 + Point p2 -> p1.operator+(Point& p2)
	Point plus = p1 + p2;  // �����ڿ� ��ġ�ϴ� "+" �����ڰ� �����ϴ�.
	plus.ShowPosition();

	// Point p1 - Point p2 -> p1.operator-(Point& p2)
	Point minus = p1 - p2;
	minus.ShowPosition();

	// Point p1 + 10 -> p1.operator+(int value = 10)
 	Point plusWithNum = p1 + 10;
	plusWithNum.ShowPosition();

	// (int + Point)10 + p1 -> Point operator(int num, Point p1)
	// 10.operator+(Point& p1); (x)
	Point numPlusPoint = 10 + p1;
	numPlusPoint.ShowPosition();

	Point p3(3, 3);
	++p3;
	p3.ShowPosition();

	Point p4(4, 4);
	p4++;
	p4.ShowPosition();

	system("cls");
	std::cout << "���� ����" << std::endl;

	Math m1("����", 95), m2("����", 70);
	Eng e1("����", 95), e2("����", 70);

	std::cout << "�л�1�� ���� + ���� ���� : " << Add(m1, e1) << std::endl;
	std::cout << "�л�2�� ���� + ���� ���� : " << Add(m2, e2) << std::endl;


}