/*
	�ۼ��� : �̵���
	�ۼ��� : 2024-08-16
	�н� ��ǥ : ���� �����ڿ� ���� ���� �� �Ҹ���
*/

// 1. ���� Ŭ���� ����

// 2. Ŭ������ �Ҹ��ڿ� ���� �н�
// newŰ���尡 ���Ե� �����ڸ� �������� ��, newŰ����� ������ ������ �޸� ������ ���ϴ� ������
// Ŭ������ �Ҹ��ϴ� ������ ȣ��Ǵ� �Ҹ��ڸ� �����ؼ� deleteŰ����� �޸𸮸� ����

// 3. ���� �����ڸ� �̿��ؼ� Ŭ������ ����
// �ڱ��ڽ� Ŭ������ �����ؼ� �ٸ� Ŭ����(�ν��Ͻ�)�� �����ϴ� ������

// 4. ���� ����(shallow copy) vs ���� ����(deep copy)
// ���� ���� : ���縦 �� ��, �ּҸ� �״�� �����ͼ� ���� �ּҸ� ����Ű�� ���� ���(�ּҸ� ������ �� �ٸ� �ּҰ� ���� �޸� ������ �Ǹ� ���� �ּҸ� ����Ű�� ������ �߻�)
// ���� ���� : ���縦 �� ��, �ּ��� ��� �ش� ������ ���� �Ҵ����� �����ؼ� ���ο� ������ �����ϴ� ���
// ���� ���縦 ���� ���� : �ϳ��� �޸𸮷� 2�� �̻��� ǥ���� �� �ִ�(�޸� ȿ����). (�޸𸮸� ������ �� ���� �߻�)

#include"lectures.h"

// 1. ���� Ŭ����
// ��Ÿũ����Ʈ�� �����ϴ� ���� 
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
	Marine(int x, int y); // �跰�� ��ġ���� ������ ����
	Marine(int x, int y, const char* marinename); // Ŭ���� ����� name�� �ܺ��� marinename�� �����ϴ� ��.  const �����ؼ�, marinename ������ �ʴ� �ٴ� ���� ���
	Marine(const Marine& m1);  // ���� ������ ȣ�� ���
	~Marine();		// �Ҹ��� : �Ҹ��� �� ȣ��
	int Hp();
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
	std::cout << "Marine������ ȣ��" << std::endl;
	// �̸��� �ִ� 
	// (���� �Ҵ�)char name[30] ���� : 30 �̻��� �̸� ũ�⸦ ������ �� ����.
	// strcpy_s(name, 30, marinename);
	// (���� �Ҵ�) : �����ϰ��� �ϴ� ���ڿ��� ���� ��ŭ �޸� ������ �Ҵ��ؼ� ����
	name = new char[strlen(marinename) + 1];	// strlen�� �ι��ڸ� ǥ�� ���ϱ� ������ + 1�� ����� �Ѵ�.
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
	if (hp <= 0)
	{
		std::cout << name << "�� �Ҹ��� ȣ��" << std::endl;
		delete[] name;  // delete[] : �迭�� ��ü �޸𸮸� ����
	}
}

int Marine::Hp()
{
	return hp;
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
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "��ġ : " << posX << "," << posY << std::endl;
	std::cout << "���ݷ� : " << attackPower << std::endl;
	std::cout << "���� ü�� : " << hp << std::endl;
	std::cout << "              " << std::endl;
}


void lecture6()
{
	// ����1 ����
	Marine marine1(1, 2, "marine1");
	marine1.ShowStatus();

	// ����2 ����
	Marine marine2(5, 10, "marine2");
	marine2.ShowStatus();

	std::cout << "����1�� ����2�� ����" << std::endl;

	marine2.Damaged(marine1.Attack());
	marine2.ShowStatus();

	// ���������� ������ ����
	Marine* marines[100];

	marines[0] = new Marine(2, 3,"marine3"); 
	marines[1] = new Marine(3, 5, "marine4");
	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	delete marines[0];
	delete marines[1];

	// int�� �� ����
	int num = 10;
	int num2 = num;
	int num3(num);		// num3(num) num�ȿ� �ִ� �����͸� �����ؼ� num3�� ����

	std::cout << num3 << std::endl;

	// Marine�� �� ���� (����Ʈ ���� ������)
	Marine marine5(0, 0, "marine5");
	Marine marine6 = marine5;
	Marine marine7(marine5);

	// ����Ʈ ����������� �Ѱ� : Ŭ������ ��� ������ ������ ������ �ּҸ� ����Ű�� ��쿡 ���� ����� �����Ѵ� -> ���� ����� ���ؼ� ���� �޸� �Ҹ� �� �ּҸ� ã�� �� ���� ���� �߻�

	marine7.ShowStatus();

	// marine5 �Ҹ��� ȣ�� -> marine6 �Ҹ��� ȣ�� -> marine7 �Ҹ��� ȣ��
}

// 1. ���� Ŭ���� ����
// 2. ������, �Ҹ���(ü�°� �̸��� �ʱ�ȭ�ϰ�, �Ҹ��� �� �����Ҵ��� �ּҸ� �����ϰ� �����)
// 3. ���� �����ڸ� ��������� �ۼ��ϰ�, ���� ���簡 �ƴ� ���� ���� ������� ������ �� �ְ� �ڵ带 ����

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
	Zealot(int x, int y, const char* zealotname);
	Zealot(const Zealot& z1);
	~Zealot();
	void Move(int x, int y);
	int Hp();
	int Attack();
	int Damaged(int damage);
	void ShowStatus();
};

Zealot::Zealot(int x, int y, const char* zealotname)
{
	std::cout << "Zealot������ ȣ��" << std::endl;
	name = new char[strlen(zealotname) + 1];
	strcpy_s(name, strlen(zealotname) + 1, zealotname);
	hp = 100;
	attackPower = 10;
	posX = x;
	posY = y;
	isDead = false;
}

Zealot::Zealot(const Zealot& z1)
{
	std::cout << "��������� ȣ��" << std::endl;
	name = new char[strlen(z1.name) + 1];
	strcpy_s(name, strlen(z1.name) + 1, z1.name);
	hp = z1.hp;
	attackPower = z1.attackPower;
	posX = z1.posX;
	posY = z1.posY;
}

Zealot::~Zealot()
{
	if(hp <= 0)
		std::cout << name << "�Ҹ��� ȣ��" << std::endl;
		delete[] name;
}

void Zealot::Move(int x, int y)
{
	posX = x;
	posY = y;
}

int Zealot::Hp()
{
	return hp;
}

int Zealot::Attack()
{
	return attackPower;
}

int Zealot::Damaged(int damage)
{
	hp -= damage;

	if (hp <= 0)
		isDead = true;
	return damage;
}

void Zealot::ShowStatus()
{
	std::cout << "���� �̸� : " << name << std::endl;
	std::cout << "���� ��ġ : " << posX << "," << posY << std::endl;
	std::cout << "���� ���ݷ� : " << attackPower << std::endl;
	std::cout << "���� ü�� : " << hp << std::endl;
	std::cout << "              " << std::endl;
}

class Hydra
{
private:
	char name[30];
	int hp;
	int attackPower;
	int posX;
	int posY;
	bool isDead;
public:
	Hydra();
	Hydra(Hydra& h1);
	~Hydra();
	void Move(int x, int y);
	int Hp();
	int Attack();
	int Damaged(int damage);
	void ShowStatus();

};

Hydra::Hydra()
{
	std::cout << "����� �̸� �Է� :";
	std::cin >> name; 
	std::cout << "����� posX �Է� :";
	std::cin >> posX;
	std::cout << "����� posY �Է� :";
	std::cin >> posY;
	hp = 70;
	attackPower = 8;
	isDead = false;
}

Hydra::Hydra(Hydra& h1)
{
	std::cin >> h1.name;
	std::cin >> h1.posX;
	std::cin >> h1.posY;

	h1.hp = 70;
	h1.attackPower = 8;
	h1.isDead = false;
}

Hydra::~Hydra()
{
	if (hp <= 0)
	{
		std::cout << "Hydra �Ҹ��� ����" << std::endl;
	}
}

void Hydra::Move(int x, int y)
{
	posX = x;
	posY = y;
}

int Hydra::Hp()
{
	return hp;
}

int Hydra::Attack()
{
	return attackPower;
}

int Hydra::Damaged(int damage)
{
	hp -= damage;
	
	if (hp <= 0)
		isDead = true;

	return damage;
}

void Hydra::ShowStatus()
{
	std::cout << "����� �̸� : " << name << std::endl;
	std::cout << "����� ��ġ : " << posX << "," << posY << std::endl;
	std::cout << "����� ���ݷ� : " << attackPower << std::endl;
	std::cout << "����� ü�� : " << hp << std::endl;
	std::cout << "              " << std::endl;
}



void lecture6_1()
{
	Marine marine1(1, 2, "marine1");
	marine1.ShowStatus();

	Zealot zealot1(1, 2, "zealot1");
	zealot1.ShowStatus();

	Hydra hydra1;
	hydra1.ShowStatus();

	while (1)
	{
		std::cout << "������ ������ ����� ���� ����" << std::endl;
		std::cout << " " << std::endl;
	
		marine1.Damaged(zealot1.Attack());
		marine1.Damaged(hydra1.Attack());

		zealot1.Damaged(marine1.Attack());
		zealot1.Damaged(hydra1.Attack());

		hydra1.Damaged(marine1.Attack());
		hydra1.Damaged(zealot1.Attack());
	
		marine1.ShowStatus();
		zealot1.ShowStatus();
		hydra1.ShowStatus();

		if (zealot1.Hp() <= 0 && marine1.Hp() <= 0)
		{
			std::cout << "����� ��θ� �����ϰ� ��Ƴ��ҽ��ϴ�" << std::endl;
			std::cout << " " << std::endl;
			hydra1.ShowStatus();
			break;
		}
		else if (marine1.Hp() <= 0 && hydra1.Hp() <= 0)
		{
			std::cout << "������ ��θ� �����ϰ� ��Ƴ��ҽ��ϴ�" << std::endl;
			std::cout << " " << std::endl;
			zealot1.ShowStatus();
			break;
		}
		else if (zealot1.Hp() <= 0 && hydra1.Hp() <= 0)
		{
			std::cout << "������ ��θ� �����ϰ� ��Ƴ��ҽ��ϴ�" << std::endl;
			std::cout << " " << std::endl;
			marine1.ShowStatus();
			break;
		}

	}


}

