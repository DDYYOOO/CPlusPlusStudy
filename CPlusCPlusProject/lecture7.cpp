/*
	작성자 : 이동윤
	작성일 : 2024-08-19
	학습 목표 : 연산자 오버로딩
*/

/*
  #include<iostream>
  istream(입력 스트림), ostream(출력 스트림)
  콘솔창에 입출력을 구현
  cout << : C언어에서 비트연산자로 사용되었는데, cout <<  비트 연산과 관련이 있나?
  cin >> : C언어에서 비트연산자로 사용되었는데, cin >>  비트 연산과 관련이 있나?
*/

/*
  구조체, 클래스 : 사용자 정의 자료형
  클래스와 클래스 사이에 산술연산자가 사용이 가능한가?
  에러 -> 해당하는 피연산자가 없다
  해결 : 해당하는 연산자를 만들어주면 된다
*/

/*
  연산자 오버로딩 : 기본 연산자들(+, -, *, /, [], <<, >>)들을 사용자가 클래스에 직접 정의하는 것
  문법 : (반환값)(연산자)()
  예시 : void operator+();
*/

/*
  전역함수 오버로딩
  - 멤버함수를 통한 오버로딩 : 객체.operator+(피연산자) : 객체 + 피연산자 식으로 이루어져 있다
  - 연산자 기준으로 객체가 반드시 왼쪽에 있어야 한다.
  - 문제점
  p1 + 10;
  10 + p1;
  전역함수 오버로딩은 operator+(피연산자, 피연산자) 피연산자 + 피연산자 식으로 객체가 뒤에 위치해도 정상적인 결과를 출력
  피연산자 + 피연산자 = operator+(피연산자, 피연산자)
*/

/*
  friend 함수
  클래스의 멤버함수가 아니면서 해당 클래스의 private 데이터를 접근할 때 사용하는 함수
  클래스에 속하지 않지만, 이 클래스 안에 있는 데이터를 사용하고 싶었을 때 사용하는 키워드
  단점 : private, public -> private을 이용해서 외부에서 수정을 못하게 하기 위한 정보 은닉을 무시하는 문법
  장점 : 연산자 오버로딩을 사용해서 범용적인 함수를 만들 수 있다.
  결론 : 연산자 오버로딩 이외에 friend 함수 사용을 지양
*/

/*
  단항 연산자 오버로딩 : 증강 연산자
  ++ : num + 1;
  -- : num - 1;

  ++num : 전위 증가 연산자
  num++ : 후위 증가 연산자 

*/

#include"lectures.h"


class Point
{
private:
	int posX, posY;
public:
	Point() {}			// 디폴트 생성자
	Point(int x, int y) // 생성자 오버로딩
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

	friend Point operator+(int num, Point ref);	// 전역 함수 연산자 오버로딩

	Point operator++() // 전위 증가 연산자   ++p1;
	{
		posX += 1;
		posY += 1;
		return *this;	// 자기 자신을 객체로 반환(자기 참조 오버로딩)
	}
	Point operator++(int) // 후위 증가 연산자  p1++;
	{
		Point temp(*this); // 복사 생성자 : 얕은 복사
		posX += 1;
		posY += 1;
		return temp;
	}
};

Point operator+(int num, Point ref)		// 피연산자 + 피연산자
{
	ref.posX += num;
	ref.posY += num;
	return ref;
}

// 이름 성적이 포함 되어있는 클래스

class Eng;  // Eng 클래스가 존재한다고 명시
class Math
{
private:
	char name[10];
	int score;
public:
	Math() {};		// 디폴트 생성자 (필수) : 생성자를 직접 정의하면 디폴트 생성자가 자동으로 생성되지 않기 때문에 명시적으로 생성
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

// 출력함수의 연산자 오버로딩 예시
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

// 입력함수 연산자 오버로딩 예시
/*
  istream& operator<<(std::istream& in, int& val)
  {
      int some;
      scanf(val, some);
	  return in;
  }
  .....
*/


// C언어 int -> printf("%d", num); 




void lecture7()
{
	Point p1(1,1);
	Point p2(2, 3);
	
	p1.ShowPosition();
	p2.ShowPosition();
	
	// Point p1 + Point p2 -> p1.operator+(Point& p2)
	Point plus = p1 + p2;  // 연산자와 일치하는 "+" 연산자가 없습니다.
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
	std::cout << "예제 문제" << std::endl;

	Math m1("수학", 95), m2("수학", 70);
	Eng e1("영어", 95), e2("영어", 70);

	std::cout << "학생1의 수학 + 영어 총합 : " << Add(m1, e1) << std::endl;
	std::cout << "학생2의 수학 + 영어 총합 : " << Add(m2, e2) << std::endl;


}