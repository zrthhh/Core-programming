#include<iostream>
using namespace std;


//��������������
//��������ʱ�������������õļ������β�����ʵ��
//���Լ�ָ���޸�ʵ��

//ֵ����
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//��ַ����
void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//���ô���
void swap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//���ô��ݣ��β�Ҳ������ʵ��


//��������������ֵ
/*�����ǿ�����Ϊ��������ֵ���ڵ�
* ע�⣺��Ҫ���ؾֲ���������
* �÷�����������Ϊ��ֵ
*/
int& test1()
{
	static int a = 10;
	return a;
}

//���õı�����c++�ڲ���ʵ����һ��ָ�볣��
//���������ã�ת��Ϊint* const ref = &a;
void func(int& ref) {
	ref = 100;//ref�����ã�ת��Ϊ*ref = 100
}

int main()
{
	//����
	//���ã������������
	//�﷨���������� &���� = ԭ��
	int m = 10;
	int& n = m;
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;
	
	n = 100;
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;

	//���õ�ע������
	//���ñ����ʼ��
	//�����ڳ�ʼ���󣬲����Ըı�

	//ͨ�����ò���������Ч��ͬ����ַ���ݵ�Ч��ʱһ���ģ����õ��﷨���Ӽ����

	//���ÿ�������ֵ
	int& ref = test1();
	cout << "ref = 2" << ref << endl;
	test1() = 1000;
	cout << "ref = 2" << ref << endl;

	//���õı���
	//���õı�����c++�ڲ���ʵ����һ��ָ�볣��
	int a = 10;
	//�Զ�ת��Ϊint* const ref = &a;ָ�볣����ָ��ָ�򲻿ɸģ�Ҳ˵��Ϊʲô���ò��ɸ���
	int& ref1 = a;
	ref1 = 20;//�ڲ�������ref�����ã��Զ�������ת��Ϊ��*ref=20��
	cout << "a:" << a << endl;
	cout << "ref1:" << ref1 << endl;

	//��������
	//���ã�����������Ҫ���������βΣ���ֹ�����
	//�ں����β��б��У����Լ�const�����βΣ���ֹ�βθı�ʵ��

	const int& ref2 = 10;//����const֮�󣬱������������޸�
	//int temp = 10;const int &ref = temp;
	




	system("pause");
	return 0;
}