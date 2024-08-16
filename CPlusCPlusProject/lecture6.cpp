/*
	작성자 : 이동윤
	작성일 : 2024-08-16
	학습 목표 : 복사 생성자에 대한 이해 및 소멸자
*/

// 1. 몬스터 클래스 생성

// 2. 클래스의 소멸자에 대한 학습
// new키워드가 포함된 생성자를 구현했을 때, new키워드로 생성한 변수의 메모리 해제를 못하는 문제점
// 클래스가 소멸하는 시점에 호출되는 소멸자를 구현해서 delete키워드로 메모리를 해제

// 3. 복사 생성자를 이용해서 클래스를 복사
// 자기자신 클래스를 복사해서 다른 클래스(인스턴스)에 복사하는 생성자

// 4. 얕은 복사(shallow copy) vs 깊은 복사(deep copy)
// 얕은 복사 : 복사를 할 때, 주소를 그대로 가져와서 같은 주소를 가리키는 복사 방식(주소를 복사할 때 다른 주소가 먼저 메모리 해제가 되면 없는 주소를 가리키는 에러가 발생)
// 깊은 복사 : 복사를 할 때, 주소인 경우 해당 공간을 동적 할당으로 복사해서 새로운 공간을 복사하는 방식
// 얕은 복사를 쓰는 이유 : 하나의 메모리로 2개 이상을 표현할 수 있다(메모리 효율성). (메모리를 해제할 때 문제 발생)

#include"lectures.h"

// 1. 몬스터 클래스
// 스타크래프트에 등장하는 마린 
class Marine
{
private:
	int hp;
	int attackPower;
	int posX;
	int posY;
	bool isDead;
	char* name;  // == char name[30]
public:
	Marine(int x, int y); // 배럭의 위치에서 마린을 생성
	Marine(int x, int y, const char* marinename); // 클래스 멤버인 name을 외부의 marinename로 복사하는 것.  const 한정해서, marinename 변하지 않는 다는 것을 명시
	Marine(const Marine& m1);  // 복사 생성자 호출 방식
	~Marine();		// 소멸자 : 소멸할 때 호출
	void Move(int x, int y);
	int Attack();
	void Damaged(int damage);


	void ShowStatus();
};

Marine::Marine(int x, int y)
{
	hp = 50;
	attackPower = 5;
	posX = x;
	posY = y;
	isDead = false;
}

Marine::Marine(int x, int y, const char* marinename)
{
	// 이름의 최대 
	// (정적 할당)char name[30] 단점 : 30 이상의 이름 크기를 복사할 수 없다.
	// strcpy_s(name, 30, marinename);
	// (동적 할당) : 복사하고자 하는 문자열의 길이 만큼 메모리 공간을 할당해서 생성
	name = new char[strlen(marinename) + 1];	// strlen은 널문자를 표현 못하기 때문에 + 1을 해줘야 한다.
	strcpy_s(name, strlen(marinename) + 1, marinename);
	hp = 50;
	attackPower = 5;
	posX = x;
	posY = y;
	isDead = false;
}

Marine::Marine(const Marine& m1)
{
	name = new char[strlen(m1.name) + 1];
	strcpy_s(name, strlen(m1.name) + 1, m1.name);
	hp = m1.hp;
	attackPower = m1.attackPower;
	posX = m1.posX;
	posY = m1.posY;
	isDead = m1.isDead;
}

Marine::~Marine()
{
	std::cout << name << "의 소멸자 호출" << std::endl;
	delete[] name;  // delete[] : 배열을 전체 메모리를 해제
}

void Marine::Move(int x, int y)
{
	posX = x;
	posY = y;
}

int Marine::Attack()
{
	return attackPower;
}

void Marine::Damaged(int damage)
{
	hp -= damage;

	if (hp <= 0)
		isDead = true;
}

void Marine::ShowStatus()
{
	std::cout << "** 마린생성 **" << std::endl;
	std::cout << "이름 : " << name << std::endl;
	std::cout << "위치 : " << posX << "," << posY << std::endl;
	std::cout << "공격력 : " << attackPower << std::endl;
	std::cout << "현재 체력 : " << hp << std::endl;

}


void lecture6()
{
	// 마린1 생성
	Marine marine1(1, 2, "marine1");
	marine1.ShowStatus();

	// 마린2 생성
	Marine marine2(5, 10, "marine2");
	marine2.ShowStatus();

	std::cout << "마린1이 마린2를 공격" << std::endl;

	marine2.Damaged(marine1.Attack());
	marine2.ShowStatus();

	// 여러마리의 마린을 생성
	Marine* marines[100];

	marines[0] = new Marine(2, 3,"marine3"); 
	marines[1] = new Marine(3, 5, "marine4");
	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	delete marines[0];
	delete marines[1];

	// int형 값 복사
	int num = 10;
	int num2 = num;
	int num3(num);		// num3(num) num안에 있는 데이터를 복사해서 num3에 대입

	std::cout << num3 << std::endl;

	// Marine형 값 복사 (디폴트 복사 생성자)
	Marine marine5(0, 0, "marine5");
	Marine marine6 = marine5;
	Marine marine7(marine5);

	// 디폴트 복사생성자의 한계 : 클래스의 멤버 변수로 포인터 변수가 주소를 가리키는 경우에 얕은 복사로 복제한다 -> 얕은 복사로 인해서 기존 메모리 소멸 시 주소를 찾을 수 없는 문제 발생

	marine7.ShowStatus();

	// marine5 소멸자 호출 -> marine6 소멸자 호출 -> marine7 소멸자 호출
}

// 1. 질럿 클래스 생성
// 2. 생성자, 소멸자(체력과 이름을 초기화하고, 소멸할 때 동적할당한 주소를 해제하게 만들것)
// 3. 복사 생성자를 명시적으로 작성하고, 얕은 복사가 아닌 깊은 복사 방식으로 복사할 수 있게 코드를 변경

class Zealot
{
private:
	char* name;
	int hp;
	int attackPower;
	int posX;
	int posY;
	bool isDead;
public:
	Zealot(int x, int y, char* zealotname);
	Zealot(const Zealot& z1);
	~Zealot();
	void Move(int x, int y);
	int Attack();
	void ShowStatus();
};

Zealot::Zealot(int x, int y, char* zealotname)
{
	std::cout << "생성자 호출" << std::endl;
	name = new char[strlen(zealotname) + 1];
	strcpy_s(name, strlen(zealotname) + 1, zealotname);
	hp = 100;
	attackPower = 10;
	posX = x;
	posY = y;
}

Zealot::Zealot(const Zealot& z1)
{
	std::cout << "복사생성자 호출" << std::endl;
	name = new char[strlen(z1.name) + 1];
	strcpy_s(name, strlen(z1.name) + 1, z1.name);
	hp = z1.hp;
	attackPower = z1.attackPower;
	posX = z1.posX;
	posY = z1.posY;
}

Zealot::~Zealot()
{
	std::cout << "소멸자 호출" << std::endl;
}

void Zealot::Move(int x, int y)
{
	posX = x;
	posY = y;
}

int Zealot::Attack()
{
	return attackPower;
}

void Zealot::ShowStatus()
{
	std::cout << "질럿 생성" << std::endl;
	std::cout << "질럿 이름 : " << name << std::endl;
	std::cout << "질럿 공격력 : " << attackPower << std::endl;
	std::cout << "질럿 체력 : " << hp << std::endl;
}


void lecture6_1()
{
	Zealot zealot1(3, 5, "Zealot1");
	zealot1.ShowStatus();

}