#include<iostream>
using namespace std;
#include<string>

//�������캯���ĵ���ʱ��--���������
class Test
{
public:
	Test()
	{
		cout << "Test��Ĭ�Ϲ��캯������" << endl;
	}
	Test(int value)
	{
		cout << "Test�������캯������" << endl;
		m_value = value;
	}
	Test(const Test& t)
	{
		cout << "Test�������캯������" << endl;
		m_value = t.m_value;
	}
	~Test()
	{
		cout << "Test��������������" << endl;
	}
	int m_value;
};

//1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test01()
{
	Test t1(20);
	Test t2(t1);
	cout << t2.m_value << endl;
}
//2.ֵ���ݵķ�ʽ������������ֵ
void set(Test t)
{
	t.m_value = 22;//�������캯������
}
void test02()
{
	Test t;
	set(t);
}

//3.��ֵ��ʽ���ؾֲ�����
Test set1()
{
	Test t;
	return t;
}
void test03()
{
	Test t = set1();
}


int main()
{
	test01();
	test02();
	test03();



	system("pause");
	return 0;
}