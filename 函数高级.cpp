#include<iostream>
using namespace std;

//����Ĭ�ϲ���
//�������β��б��еĲ����ǿ�����Ĭ��ֵ��
//�﷨������ֵ���� ������ (���� = Ĭ��ֵ){}
int func(int a, int b = 10, int c = 10)
{
	return a + b + c;
}
//����Լ��������ݣ������Լ������ݣ����û�У�����Ĭ��ֵ
//ע��������ĳ��λ���Ѿ�����Ĭ�ϲ�������ô���λ���Ժ󶼱���Ҫ��Ĭ��ֵ
//�������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ���
//������ʵ��ֻ����һ����Ĭ�ϲ���


//����ռλ����
//�β��б��п�����ռλ������������ռλ�����ú���ʱ���������λ��
//�﷨������ֵ���� ������ (��������){}
void func1(int a, int)
{
	cout << "ռλ����" << endl;
}


//��������
/*������������ͬ����߸�����
* ������������������ͬһ���������£�����������ͬ��
* �����������Ͳ�ͬ���߸�����ͬ����˳��ͬ
* ע�⣺�����ķ���ֵ��������Ϊ�������ص�����
*/
void func2()
{
	cout << "func2 �ĵ���" << endl;
}


void func2(int a)
{
	cout << "func2(int a) �ĵ���!" << endl;
}

void func2(int a, double b)
{
	cout << "func2(int a,double b) �ĵ���" << endl;
}


void func2(double a, int b)
{
	cout << "func2(double a,d b) �ĵ���" << endl;
}
/*�������ص�ע������
* 1.������Ϊ���ص�����
*/
void func3(int& a)
{
	cout << "func3(int &a)����" << endl;
}

void func3(const int& a)
{
	cout << "func3(const int &a) ����" << endl;
}



int main()
{
	cout << func(10) << endl;
	cout << func(10, 30) << endl;
	 
	func1(1, 2);

	func2();
	func2(1);






	system("pause");
	return 0;
}