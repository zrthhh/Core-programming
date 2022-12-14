#include<iostream>
using namespace std;
#include<string>

/*��̬�������̬��������֮һ
* ��̬��Ϊ����
* ��̬��̬���������غ�������������ھ�̬��̬�����ú�����
* ��̬��̬����������麯��ʵ������ʱ��̬
* ����
* ��̬��̬�ĺ�����ַ���-����׶�ȷ��������ַ
* ��̬��̬�ĺ�����ַ���-���н׶�ȷ��������ַ
*/
//������
class Animal
{
public:
	//�����麯�����Ϳ���ʵ�ֵ�ַ���
	/*virtual void speak()
	{
		cout << "speak!" << endl;
	}*/
	void speak()
	{
		cout << "speak!" << endl;
	}
};
//����
class dog:public Animal
{
public:
	void speak()
	{
		cout << "dog speak" << endl;
	}
};
//è��
class cat :public Animal
{
public:
	//��д����������ֵ���� ������ �����б� ��ȫһ�³�Ϊ��д
	void speak()
	{
		cout << "cat speak" << endl;
	}
};

//ִ�к���
//��ַ��󶨣�����׶ξ�ȷ���˵�ַ
//ʹ���麯�����������
void dospeak(Animal &animal)
{
	animal.speak();
}
/*��̬��̬��������
* 1.�м̳й�ϵ
* 2.������д�����е��麯��
* ��̬��̬��ʹ��
* 1.�����ָ��������� ִ���������
*/
void test01()
{
	cat mimi;
	dospeak(mimi);
	dog wangwang;
	dospeak(wangwang);
}

void test02()
{
	//����virtual��Ϊ1
	cout << "sizeof Animal = " << sizeof(Animal) << endl;
	//��virtual��Ϊ4
}


//��̬����--��������
//�ֱ�����ͨд���Ͷ�̬���������ʵ��������������������ļ�������
/*��̬���ŵ�
* 1.������֯�ṹ����
* 2.�ɶ���ǿ
* 3.����ǰ�ںͺ��ڵ���չ�Լ�ά��
*/

//��ͨʵ��
class Calculator
{
public:
	int getResult(string str)
	{
		if (str == "+") {
			return num1 + num2;
		}
		else if (str == "-") {
			return num1 - num2;
		}
		else if (str == "*") {
			return num1 * num2;
		}
		//�������չ�µĹ��ܣ�����Ҫ�޸�Դ��
		//����ʵ�Ŀ����ߣ��ᳫ����ԭ��
		//����ԭ�򣺶���չ���п��������޸Ľ��йر�
	}
	int num1;
	int num2;
};

void test_1()
{
	Calculator c;
	c.num1 = 2;
	c.num2 = 1;

}

//���ö�̬ʵ��

//ʵ�ּ�����������
class AbstractCalculator
{
public:
	virtual int getResult()
	{
		return 0;
	}
	int num1;
	int num2;
};

//ʵ�ּӷ���������
class add :public AbstractCalculator
{
	int getResult()
	{
		return num1 + num2;
	}
};

//ʵ�ּ�����������
class sub :public AbstractCalculator
{
	int getResult()
	{
		return num1 - num2;
	}
};
//ʵ�ֳ˷���������
class mul :public AbstractCalculator
{
	int getResult()
	{
		return num1 * num2;
	}
};

void test_2()
{
	//��̬ʹ������
	//����ָ���������ָ���������

	//ʵ�ּӷ�
	AbstractCalculator* abc = new add;
	abc->num1 = 1;
	abc->num2 = 4;
	cout << "num1 + num2 = " << abc->getResult() << endl;
	//�������ݣ�����ǵ�����
	delete abc;

	//ʵ�ּ���
	sub s;
	*abc = s;
	abc->num1 = 1;
	abc->num2 = 9;
	cout << "num1 - num2 = " << abc->getResult() << endl;
	delete abc;
}


//���麯���ͳ�����
/*��̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ���������д������
* ��˿��Խ��麯����Ϊ���麯��
* �﷨��virtual ����ֵ���� ������ (�����б�) = 0;
* ���������˴��麯���������Ҳ��Ϊ������
* �������ص㣺
* 1.�޷�ʵ��������
* 2.���������д�������еĴ��麯��������Ҳ���ڳ�����
*/
class base
{
public:
	//���麯��
	//ֻҪ��һ�����麯���������ͽг�����
	virtual void func() = 0;
};

class son :public base
{
public:
	//���������д�����еĴ��麯���������޷�ʵ��������
	virtual void func()
	{
		cout << "�������д" << endl;
	}
};


//��̬����--��Ʒ��������
class AbstractDrinking
{
public:
	//��ˮ
	virtual void biol() = 0;
	//����
	virtual void brew() = 0;
	//���뱭��
	virtual void pour() = 0;
	//���븨��
	virtual void putin() = 0;
	//����
	void makedring()
	{
		biol();
		brew();
		pour();
		putin();
	}
};

//��������
class coffee :public AbstractDrinking
{
public:
	//��ˮ
	virtual void biol()
	{
		cout << "��ˮ" << endl;
	}
	//����
	virtual void brew()
	{
		cout << "���ݿ���" << endl;
	}
	//���뱭��
	virtual void pour()
	{
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void putin()
	{
		cout << "���Ǻ�ţ��" << endl;
	}
};

//������Ҷ
class tea :public AbstractDrinking
{
	//��ˮ
	virtual void biol()
	{
		cout << "�տ�ˮ" << endl;
	}
	//����
	virtual void brew()
	{
		cout << "�ݲ�" << endl;
	}
	//���뱭��
	virtual void pour()
	{
		cout << "���뱭��" << endl;
	}
	//���븨��
	virtual void putin()
	{
		cout << "���븨��" << endl;
	}
};

//������Ʒ
void dowork(AbstractDrinking* abs)
{
	abs->makedring();
	delete abs;
}

void makecoffee()
{
	dowork(new coffee);
	cout << "-----------" << endl;
	dowork(new tea);
}




int main()
{



	system("pause");
	return 0;
}