#include<iostream>
using namespace std;
#include<string>

//Բ��
const double PI = 3.14;

class circle
{
	//����Ȩ��
public:
	//����
	int m_r;
	//��Ϊ
	double calculate()
	{
		return 2 * PI * m_r;
	}
};

//ѧ����
class student
{
public:
	string s_name;
	string s_id;
	void setinfo(string name, string id)
	{
		s_name = name;
		s_id = id;
	}

	void show()
	{
		cout << "name:" << s_name << endl;
		cout << "s_id" << s_id << endl;
	}
};

//����Ȩ�޿���
//����Ȩ�� public    ��Ա ���ڿ��Է��ʣ�����Ҳ���Է���
//����Ȩ�� protexted ��Ա ���ڿ��Է��ʣ����ⲻ���Է���
//˽��Ȩ�� private   ��Ա ���ڿ��Է��ʣ����ⲻ���Է���
class Person
{
	//public
public:
	string m_name;
	//protected
protected:
	string m_car;
	//private
private:
	int m_password;

public://���ڷ���
	void func()
	{
		m_name = "aa";
		m_car = "bb";
		m_password = 123;
	}
};


//��Ա��������Ϊ˽��
class person1
{
public:
	void setname(string name)
	{
		m_name = name;
	}
	string getname()
	{
		return m_name;
	}
	void setage(int age)
	{
		m_age = age;
	}
	int getage()
	{
		return m_age;
	}
private:
	string m_name;
	int m_age;
	string m_lover;
};

//�����������
class cube
{
public:
	void set(int l, int w, int h)
	{
		L = l;
		W = w;
		H = h;
	}
	int calculateS()
	{
		return 2 * (L * W + W * H + L * H);
	}
	int calculateV()
	{
		return L * W * H;
	}
private:
	int L;  //��
	int W;  //��
	int H;  //��
};
//����ȫ�ֺ����ж��������Ƿ����
bool isequal(cube &a, cube &b)
{
	return (a.calculateS() == b.calculateS()) && (a.calculateV() == b.calculateV());
}


int main()
{
	//C++��������������ԣ���װ���̳С���̬

	/*1.��װ
	* (1)�����Ժ���Ϊ��Ϊһ�����壬���������е�����
	* (2)�����Ժ���Ϊ����Ȩ�޿���
	*/

	//(1)��������ʱ�����Ժ���Ϊд��һ�𣬱�������
	//�﷨��class ����{����Ȩ�ޣ�����/��Ϊ};
	//����1--���Բ�࣬����Բ���ܳ�
	circle c1;
	c1.m_r = 1.0;
	cout << "Բc1���ܳ�Ϊ��" << c1.calculate() << endl;

	//����2-���ѧ���࣬��������ѧ�Ÿ�ֵ������ʾ
	student s1;
	s1.setinfo("����", "202211");
	s1.show();
	//���е����Ժ���Ϊ��ͳ��Ϊ��Ա
	//����Ҳ�Ƴ�Ա���Ի��Ա����
	//��ΪҲ�Ƴ�Ա�������Ա����


	//(2)�������ʱ�����԰����Ժ���Ϊ�ֱ���Բ�ͬ��Ȩ��
	Person p1;
	p1.m_name = "cc";
	//p1.m_car = "bens";�޷�����


	/*struct��class������
	* Ψһ�������������Ĭ�ϵķ���Ȩ�޲�ͬ
	* structĬ��Ȩ��Ϊ����
	* classĬ��Ȩ��Ϊ˽��
	*/

	//��Ա��������Ϊ˽��
	//�����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
	//����дȨ�ޣ����Լ�����ݵ���Ч��
	person1 p;
	p.setname("����");
	cout << "����Ϊ��" << p.getname() << endl;
	p.setage(12);
	cout << "����Ϊ��" << p.getage() << endl;


	//��ϰ����--�����������-������������
	cube c;
	c.set(1, 2, 3);
	cout << "c�����Ϊ��" << c.calculateS() << endl;
	cout << "c�����Ϊ��" << c.calculateV() << endl;

	cube cu;
	cu.set(2, 3, 4);
	bool value = isequal(c, cu);
	if (value == true) {
		cout << "is equal" << endl;
	}
	else {
		cout << "is not equal" << endl;
	}

	system("pause");
	return 0;
}