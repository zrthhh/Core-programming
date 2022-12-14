#include<iostream>
using namespace std;
#include<string>

/*�������ʹ�������
* ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
* �����ʽ--�������е�����������Ϊ���������ߴ�������
* �������ʹ����������ԣ�
* 1.���Խ������ָ���ͷ��������
* 2.����Ҫ����ĺ���ʵ��
* �������ʹ�������������
* 1.����Ǵ����������������ڳ����࣬�޷�ʵ��������
* �������﷨��virtual ~����(){};
* ���������﷨��virtual ~����() = 0; ����::~����(){};
*/
class Animal
{
public:
	Animal()
	{
		cout << "Animal���캯������" << endl;
	}
	//�������������Խ������ָ���ͷ��������ʱ���ɾ�������
	/*virtual ~Animal()
	{
		cout << "Animal������������" << endl;
	}*/

	//��������--��Ҫ����Ҳ��Ҫʵ��
	//���˴�������֮�������Ҳ���ڳ�����
	virtual ~Animal() = 0;

	//���麯��
	virtual void speak() = 0;
};
Animal::~Animal()
{
	cout << "Animal��������������" << endl;
}

class cat :public Animal
{
public:
	cat(string name)
	{
		cout << "cat���캯������" << endl;
		m_name = new string(name);
	}

	virtual void speak()
	{
		cout << "cat is speaking" << endl;
	}

	~cat()
	{
		cout << "cat������������" << endl;
		if (m_name != NULL)
		{
			delete m_name;
		}
	}
	string* m_name;
};

void test01()
{
	Animal* animal = new cat("tom");
	animal->speak();
	//����ָ����������ʱ�򣬲�����������е�����������������������ж������ԣ�������ڴ�й¶
	delete animal;
}



//��̬������-������װ

//�����cpu��
class CPU
{
public:
	//����ļ��㺯��
	virtual void caculate() = 0;
};

//������Կ���
class navi
{
public:
	virtual void dispaly() = 0;
};

//�����ڴ�����
class Memory
{
public:
	virtual void storage() = 0;
};

//������
class computer
{
public:
	computer(CPU* cpu, navi* na, Memory* men)
	{
		this->cpu = cpu;
		this->mem = mem;
		this->na = na;
	}
	void work()
	{
		cpu->caculate();
		na->dispaly();
		mem->storage();
	}
	~computer()
	{
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (na != NULL)
		{
			delete na;
			na = NULL;
		}
		if (mem != NULL) {
			delete mem;
			mem = NULL;
		}
	}

private:
	CPU* cpu;
	navi* na;
	Memory* mem;
};

//���峧��
//Intel
class intelCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Intel��CPU��ʼ������" << endl;
	}
};

class Intelnavi :public navi
{
public:
	virtual void dispaly()
	{
		cout << "Intel���Կ�" << endl;
	}
};

class IntelMem :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel�Ĵ���" << endl;
	}
};

//Lenovo
class LenovoCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Lenovo��CPU��ʼ������" << endl;
	}
};

class Lenovonavi :public navi
{
public:
	virtual void dispaly()
	{
		cout << "Lenovo���Կ�" << endl;
	}
};

class LenovoMem :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo�Ĵ���" << endl;
	}
};

void test01()
{
	//��һ̨���Ե����
	CPU* intelcpu = new intelCPU;
	navi* intelcard = new Intelnavi;
	Memory* intelmem = new IntelMem;

	//������һ̨����
	computer* computer1 = new computer(intelcpu,intelcard,intelmem);
	computer1->work();
	delete computer1;
	cout << "--------" << endl;
	//�����ڶ�̨����
	computer* computer2 = new computer(new LenovoCPU, new Lenovonavi, new LenovoMem);
	computer2->work();
	delete computer2;

}
int main()
{
	test01();



	system("pause");
	return 0;
}