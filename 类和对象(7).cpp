#include<iostream>
using namespace std;
#include<string>

//��ͨʵ��ҳ��

////Javaҳ��
//class Java
//{
//public:
//	void header()
//	{
//		cout << "head info" << endl;
//	}
//	void footer()
//	{
//		cout << "foot info" << endl;
//	}
//	void left()
//	{
//		cout << "left info" << endl;
//	}
//	void content()
//	{
//		cout << "java info" << endl;
//	}
//};
//
////python ҳ��
//class Python
//{
//public:
//	void header()
//	{
//		cout << "head info" << endl;
//	}
//	void footer()
//	{
//		cout << "foot info" << endl;
//	}
//	void left()
//	{
//		cout << "left info" << endl;
//	}
//	void content()
//	{
//		cout << "python info" << endl;
//	}
//};
//
////c++ҳ��
//class Cpp
//{
//public:
//	void header()
//	{
//		cout << "head info" << endl;
//	}
//	void footer()
//	{
//		cout << "foot info" << endl;
//	}
//	void left()
//	{
//		cout << "left info" << endl;
//	}
//	void content()
//	{
//		cout << "cpp info" << endl;
//	}
//};

//�̳�ʵ��
//ʵ�ֹ���ҳ��
class BasePage
{
public:
	void header()
	{
		cout << "head info" << endl;
	}
	void footer()
	{
		cout << "foot info" << endl;
	}
	void left()
	{
		cout << "left info" << endl;
	}
};

//java
class Java :public BasePage
{
public:
	void content()
	{
		cout << "java info" << endl;
	}
};

//python
class Python :public BasePage
{
public:
	void content()
	{
		cout << "python info" << endl;
	}
};

//cpp
class Cpp :public BasePage
{
public:
	void content()
	{
		cout << "cpp info" << endl;
	}
};
//�̳�--�����ظ�����
//�﷨��class ����(������)���̳з�ʽ ����(����)


//�̳з�ʽ--�����̳У������̳У�˽�м̳�
class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

//�����̳�
class son1 :public Base
{
public:
	void func()
	{
		m_A = 10;
		m_B = 10;  //�����еı���Ȩ�޳�Ա�����ڿ��Է��ʣ����ⲻ���Է���
		//m_C = 10; ˽��Ȩ���޷�����
	}
};

//�����̳�
class son2 :protected Base
{
public:
	void func()
	{
		m_A = 100;  //�����еĹ�����Ա��֮���Ϊ����Ȩ��
		m_B = 100;
		//m_C = 100; �����е�˽�г�Ա�޷�����
	}
};

//˽�м̳�
class son3 :private Base
{
public:
	void func()
	{
		m_A = 100;  //�����й�����Ա���������Ϊ˽�г�Ա
		m_B = 100;  //�����б�����Ա���������Ϊ˽�г�Ա
		//m_C = 100;  //������˽�г�Ա�޷�����
	}
};

//�̳��еĹ��������˳������
//�ȹ��츸�࣬�ٹ������࣬������˳���빹���˳���෴


//�̳���ͬ����Ա����
//��������ͬ����Ա ֱ�ӷ��ʼ���
//���ʸ���ͬ����Ա ��Ҫ��������

//��������г��ֺ͸���ͬ���ĳ�Ա�����������ͬ����Ա�����ص����������е�ͬ����Ա����
//�������ʵ������б����ص�ͬ����Ա��������Ҫ��������



//�̳�ͬ����̬��Ա����ʽ
/*��̬��Ա�ͷǾ�̬��Ա����ͬ��������ʽһ��
* ��������ͬ����Ա��ֱ�ӷ��ʼ���
* ���ʸ���ͬ����Ա����Ҫ��������
*/
class base
{
public:
	static void func()
	{
		cout << "base - static void func()" << endl;
	}
	static int m_A;
};
int base::m_A = 100;

class sons :public base
{
public:
	static void func()
	{
		cout << "sons - static void func()" << endl;
	}
	static int m_A;
};
int sons::m_A = 200;

//ͬ����̬��Ա����
void test01()
{
	sons s;
	cout << "sons �� m_A" << s.m_A << endl;
	cout << "base �� m_A" << s.base::m_A << endl;
}

//ͬ����̬��������
void test02()
{
	sons s;
	s.func();
	s.base::func();
}
//�������ͬ����̬��Ա�������Ὣ�����ͬ����Ա����
//ͨ��������ʻ���ͨ����������



//��̳��﷨
/*c++����һ��̳ж����
* �﷨��class ����:�̳з�ʽ ����1,�̳з�ʽ ����2...
* ��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������
* ʵ���в�����ʹ�ö�̳�
*/

/*���μ̳�
* ����������̳�ͬһ������
* ����ĳ����ͬʱ�̳�����������
*/
//������
class Animal
{
public:
	int Age;
};
//����
class sheep :public Animal
{

};
//������
class camal :public Animal
{

};
//������
class sc :public Animal
{

};
//�����μ̳У���������ӵ����ͬ����ʱ����Ҫͨ���������������
//���׵�����Դ�˷�
//ͨ��ʹ����̳н�����⣬����virtual�ؼ���


int main()
{
	

	









	system("pause");
	return 0;
}