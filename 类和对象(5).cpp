#include<iostream>
using namespace std;
#include<string>


/*友元friend
* 友元的目的就是让一个函数或者类访问另一个类中的私有成员
* 三种实现：全局函数做友元
* 类做友元
* 成员函数做友元
*/
class building
{
	//1.友元全局函数
	friend void visit(building* build);

	//2.类做友元
	friend class visitor;

public:
	building()
	{
		m_sittingroom = "客厅";
		m_bedroom = "卧室";
	}
	string m_sittingroom;//客厅
private:
	string m_bedroom;//卧室
};

//全局函数
void visit(building *build)
{
	cout << build->m_sittingroom << endl;
	cout << build->m_bedroom << endl;
}

//test
void test()
{
	building build;
	visit(&build);//既可以访问公共属性又可以访问私有属性

}

//类作友元
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