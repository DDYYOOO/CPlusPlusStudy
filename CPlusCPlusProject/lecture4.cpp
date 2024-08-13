/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-13
	�н� ��ǥ : ù Ŭ���� ����, �Լ� �����ε��� �����ڿ� ���� ����
*/

#include"lectures.h"

/*
  Ŭ���� ����
  Ŭ����(class) : ��ü - ���α׷��� ���� ���� �����ϴ� ��� ����� ǥ���ϴ� ��

*/

// 1. ��ü�� �Լ��� �����ϴ� ���� �� ���⿡ �������̴�
// struct ����ü �Լ��� ���ο� ������ �� ����
// Ŭ���� ���ο� �Լ��� �����ؼ� ����� �� �� �ִ�

class Pet
{
private:
	char name[30];
	int happy;
	int hungry;
	int sleep;

public:
	Pet();  // �� Ŭ���� �ȿ� �ִ� �����͵��� ����Ʈ ��
	Pet(int happy, int hungry);
	Pet(int sleep, int happy, int hungry);
	void Play();
	void Feed();
	void ShowStatus();
	void MakeDog();

};

// ���� ������ �̸�����::  // ���� �����̽� �ȿ� �ִ� �Լ��� ���
// Ŭ����::�Լ��̸�   // Ŭ���� �ȿ� �ִ� �Լ��� ���

Pet::Pet()
{
	strcpy_s(name, 30, "�ǻ�");
	happy = 100;
	hungry = 100;
}

Pet::Pet(int happy, int hungry)
{
	std::cin >> name;
	this->happy = happy;
	this->hungry = hungry;
}

Pet::Pet(int _sleep, int _happy, int _hungry)
{
	sleep = _sleep;
	happy = _happy;
}

void Pet::Play()
{
	happy += 10;
	hungry -= 5;
}

void Pet::Feed()
{
	happy += 5;
	hungry += 10;
}

void Pet::ShowStatus()
{
	std::cout << "���� �̸� : " << name << std::endl;
	std::cout << "���� �ູ�� : " << happy << std::endl;
	std::cout << "���� ��⵵ : " << hungry << std::endl;
}
/// <summary>
/// Dog�� �ʱ�ȭ �Լ��̹Ƿ� �ݵ�� ������ ����� �Բ� ���
/// </summary>
void Pet::MakeDog()
{
	
}

/*
  �Լ� �����ε�(overloading) : �����ϴ�, �����Ͽ� �ɸ��� �ϴ�

  void Add(int a, int b) { a + b; }
  void Add(float a, float b) { a + b; }
  void Add(double a, double b) { a + b; }
  void Add(char a, char b) { a + b; }

*/

/*
  �Լ� �����ε� ��� �� ���� ����
  1. �����Ϸ��� �Լ��� �����ϴ� ����� (1) �Լ��� �̸� (2) ������ ������ Ÿ��
	 void Add(int a);
	 void Add(int b);
	 void Add();
  
  2. void Print(int x);
     void Print(char x);
	 void Print(double x);

*/

void Print(int x)
{
	std::cout << "int x : " << x << std::endl;
}
void Print(char x)
{
	std::cout << "char x : " << x << std::endl;
}
void Print(double x)
{
	std::cout << "double x : " << x << std::endl;
}
/*
  Ŭ���� ������ : Ŭ������ ������ �� �ʱ�ȭ �Լ��� ������ ȣ���Ű�� ���

  Dog dog1;  // default �����ڰ� ȣ��

  default : ���� �����͵��� 0���� �ʱ�ȭ, �ּ� �����͵��� NULL(C++������ nullPtr);

*/

void lecture4()
{
	// Play();		C��� �Լ� ȣ�� ���x
	//Dog::Play();	Ư���� ����(static)�� ������� �ʴ� �̻� ���x

	// ������, ����ü ó�� ������ �����ϰ� ���� �����͸� �ʱ�ȭ���� ������ �̻��� �����Ͱ� ��µǴ� ������ �ִ�
	// MakeDog() : �ʱ�ȭ �Լ��� �ݵ�� ���� ���� ����� ��
	Pet dog1;
	dog1.MakeDog();	// ���������� �ݵ�� �����ϴ� ����� ������
	dog1.ShowStatus();

	// case1. �Լ� �����ε��� ���ڸ� ������� Ÿ��
	int a = 1;
	char b = 'b';
    double c = 1.1;
	Print(a);
	Print(b);
	Print(c);

	// case2. �Լ� �����ε��� ���� ����
	short s1 = 2;
	float f1 = 2.2f;
	Print(s1);
	Print(f1);

	// �Լ��� �̸��� �����ϴµ� ������ Ÿ���� ���� ���
	// �����Ϸ��� ��� �ൿ?
	// 1. ������ Ÿ���� ������ �����Ϸ��� ����ȯ�� �õ�
	// 2. ����� ����ȯ, ������ ����ȯ�� �ִµ�. ���� �ڵ忡���� ������ ����ȯ�� �Ͼ�� �ִ�
	// 3. ������ ������ Ÿ���� ���� int������ ��ȯ�� �õ��ϰ� �Ǽ��� ������ Ÿ���� double������ ��ȯ�� �õ��ϰ� float���� ����ȯ�� �õ�
	// 4. ������ ������ Ÿ���� ���� ��� �Ǽ��� ������ Ÿ���� ���������� �ٲپ ����ȯ�� �õ�
	//    float, double -> ������ ������ Ÿ���� ��ȯ?
	//	  int�� �޴� �Լ�, char�� �޴� �Լ� �� �߿� ������ �����ؾ� �� �� �𸣱� ������ 
	//    �����ε�� �Լ��� �ν��Ͻ� �� �� �� �̻��� �μ� ��ϰ� ��ġ�մϴ�

	// ����
	// �����Ϸ��� �츮�� �˰� �𸣰� �߸��� �ڵ嵵 ���������� ó���ϵ��� ���� �ϰ� �ִ�
	// 1. ������ Ÿ���� �������� �ʾҴµ� ���� �� -> Ÿ���� �����ε����� ���ǵ��� �ʾҾ ����� ����
	// 2. �Ǽ��� ������ Ÿ���� �������� �ʰ� ������ ������ Ÿ���� �� �� �̻� �����ߴ�. 

	// �������� ����
	Pet dog2;		   // ����Ʈ ������ ȣ��
	dog2.ShowStatus();
	Pet dog3 = Pet();  // ����Ʈ ������ ȣ��
	dog3.ShowStatus();

	int doghappy;
	std::cin >> doghappy;
	int doghungry;
	std::cin >> doghungry;
	Pet dog4 = Pet(doghappy, doghungry);
	dog4.ShowStatus();

	// �Ʒ� �ڵ�� ���� ������ �ִ� �ڵ�
	Pet dog5 = dog4;
	dog5.ShowStatus();

	Pet* dogs[100];
	dogs[0] = new Pet();

	dogs[1] = dogs[0];
	dogs[1]->ShowStatus();
	delete dogs[0];

}