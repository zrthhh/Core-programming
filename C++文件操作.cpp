#include<iostream>
using namespace std;
#include<string>
#include<fstream>

/*写文件
* 1.包含头文件-#include<fstream>
* 2.创建流对象-ofstream ofs;
* 3.打开文件-ofs.open("文件路径","打开方式");
* 4.写数据-ofs<<"写入的数据";
* 5.关闭文件-ofs.close();
*/

/*文件打开方式：
* ios::in      为读文件而打开文件
* ios::out     为写文件而打开文件
* ios::ate     初始位置：文件尾
* ios::app     追加方式写文件
* ios::trunc   如果文件存在先删除，再创建
* ios::binary  二进制方式
*/

//文件打开方式可以配合使用，利用|操作符
//例如：用二进制方式写文件 ios::binary | ios::out

void writeflie()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "写入数据" << endl;
	ofs.close();
}

/*读文件
* 1.包含头文件-#include<fstream>
* 2.创建流对象-ifstream ifs;
* 3.打开文件并判断文件是否打开成功-ifs.open("文件路径","打开方式");
* 4.读数据-四种方式读取
* 5.关闭文件-ifs.close();
*/
void readfile()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//四种方式读取
	//1.
	char buff[1024] = { 0 };
	while (ifs >> buff) {
		cout << buff << endl;
	}
	//2.
	char buff1[1024] = { 0 };
	while (ifs.getline(buff1, sizeof(buff1)))
	{
		cout << buff1 << endl;
	}
	//3.
	string buff2;
	while (getline(ifs, buff2))
	{
		cout << "buff2" << endl;
	}
	//4.
	char c;
	while ((c = ifs.get()) != EOF)//EOF end of file
	{
		cout << c;
	}



	//关闭文件
	ifs.close();
}


//二进制文件，打开方式指定为ios::binary
/*二进制方式写文件主要利用流对象调用成员函数write
* 函数原型：ostream &write(const char *buffer,int len);
* 参数解释：字符指针buffer指向内存中的一段存储空间，len是读写字节数
*/
class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void binarywrite()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();

}

/*二进制读文件
* 二进制方式读文件主要利用流对象调用成员函数read
* 函数原型：istream& read(char* buffer,int len);
* 参数解释：字符指针buffer指向内存中一段存储空间，len是读写的字节数
*/
void binaryread()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(Person));
	cout << p.m_Age << endl;
	cout << p.m_Name << endl;
	ifs.close();
}




int main()
{
	/*程序运行时产生的数据都属于临时数据，程序一但运行结束就会被释放
	* 通过文件可以将数据持久化
	* C++中对文件操作需要包含头文件<fstream>
	* 文件类型分为两种：
	* 1.文本文件--文件以文本的ASCII码形式储存在计算机中
	* 2.二进制文件--文件以文本的二进制形式储存在计算机中，用户一般不能直接读懂
	* 操作文件的三大类：
	* 1.ofstream:写操作
	* 2.ifstream:读操作
	* 3.fstream:读写操作
	*/



	system("pause");
	return 0;
}