#include<iostream>
using namespace std;
#include<string>

//���������
//�����е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
class Add
{
public:
	Add(int a,int b) {
		this->a = a;
		this->b = b;
	}
	//ͨ����Ա��������
	Add operator+ (Add& p)
	{
		Add temp(0,0);
		temp.a = this->a + p.a;
		temp.b = this->b + p.b;
	}
	int a;
	int b;
};

//ͨ��ȫ�ֺ�������
Add operator- (Add& p1, Add& p2)
{
	Add temp(0,0);
	temp.a = p1.a - p2.a;
	temp.b = p1.b - p2.b;
	return temp;
}
//��������أ�Ҳ���Է�����������
//���õ��������͵ı��ʽ��������ǲ������޸ĵ�
//��Ҫ�����������ط�


//�������������
class Left
{
public:
	//�������ó�Ա�����������������������Ϊ�޷�ʵ��cout�����

	int m_A;
	int m_B;
};

//ֻ������ȫ�ֺ������������������
//ostream & operator<<(ostream& cout, Left& p)
//{
//	cout << "m_A = " << p.m_A << "m_B = " << p.m_B;
//	return cout;
//}

//void test01()
//{
//	Left p;
//	p.m_A = 10;
//	p.m_B = 10;
//	cout << p << endl;
//}




//�������������
//ͨ�����ص����������ʵ���Լ�����������
class Integer
{
	friend ostream& operator<<(ostream& out, Integer myint);
public:
	Integer()
	{
		m_Num = 0;
	}

	//����ǰ�õ���++a
	Integer& operator++()//����������Ϊ���ö�һ������һֱ����
	{
		m_Num++;
		return *this;//��������
	}
	//���غ��õ���a++
	Integer operator++(int)//intռλ���������ں�������
	{
		Integer temp = *this;
		m_Num++;
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream& cout, Integer myint)
{
	cout << myint.m_Num;
	return cout;
}


void test02()
{
	Integer myint;
	cout << ++myint << endl;
	cout << myint << endl;
}

void test03()
{
	Integer myint;
	cout << myint++ << endl;
	cout << myint << endl;
}
//ǰ�õ����������ã����õ�������ֵ



//��ֵ���������
/*c++���������ٸ�һ�������4������
* 1.Ĭ�Ϲ��캯��
* 2.Ĭ����������
* 3.Ĭ�Ͽ������캯��
* 4.��ֵ�����operator=��������ֵ���п���
* �������������ָ�����������ֵ������Ҳ�������ǳ��������
*/
class Person
{
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}
	
	//���ظ�ֵ�����
	 Person& operator=(Person& p)
	{
		//�������ṩ����ǳ����
		//Ӧ�����ж��Ƿ��������ٶ�������������ͷŸɾ���Ȼ�������
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		//���
		m_Age = new int(*p.m_Age);
		return *this;
	}


	int* m_Age;
};
void test04()
{
	Person p1(18);
	Person p2(20);
	p2 = p1;
}




/*�����������������
* �������������()Ҳ��������
* �������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
* �º���û�й̶���д�����ǳ����
*/
class myprint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}      
};

void test05()
{
	myprint print;
	print("hello world");
}

int main()
{

	Add p1(3, 6);
	Add p2(5, 8);

	//�ӷ�����
	Add p3 = p1 + p2;
	cout << "p3.a = " << p3.a << endl;
	cout << "p3.b = " << p3.b << endl;

	//��������
	Add p4 = p1 - p2;
	cout << "p4.a = " << p4.a << endl;
	cout << "p4.b = " << p4.b << endl;


	system("pause");
	return 0;
}