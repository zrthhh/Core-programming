#include<iostream>
using namespace std;
#include<string>


/*��Ԫfriend
* ��Ԫ��Ŀ�ľ�����һ�����������������һ�����е�˽�г�Ա
* ����ʵ�֣�ȫ�ֺ�������Ԫ
* ������Ԫ
* ��Ա��������Ԫ
*/
class building
{
	//1.��Ԫȫ�ֺ���
	friend void visit(building* build);

	//2.������Ԫ
	friend class visitor;

public:
	building()
	{
		m_sittingroom = "����";
		m_bedroom = "����";
	}
	string m_sittingroom;//����
private:
	string m_bedroom;//����
};

//ȫ�ֺ���
void visit(building *build)
{
	cout << build->m_sittingroom << endl;
	cout << build->m_bedroom << endl;
}

//test
void test()
{
	building build;
	visit(&build);//�ȿ��Է��ʹ��������ֿ��Է���˽������

}

//������Ԫ
class visitor
{
public:
	visitor()
	{
		build = new building;
	}

	void visit()
	{
		cout << build->m_sittingroom << endl;
		cout << build->m_bedroom << endl;
	}


	building* build;
};

void test01()
{
	visitor vi;
	vi.visit();
}



int main()
{



	system("pause");
	return 0;
}