#include<iostream>
using namespace std;
#include<string>
#include<fstream>

/*д�ļ�
* 1.����ͷ�ļ�-#include<fstream>
* 2.����������-ofstream ofs;
* 3.���ļ�-ofs.open("�ļ�·��","�򿪷�ʽ");
* 4.д����-ofs<<"д�������";
* 5.�ر��ļ�-ofs.close();
*/

/*�ļ��򿪷�ʽ��
* ios::in      Ϊ���ļ������ļ�
* ios::out     Ϊд�ļ������ļ�
* ios::ate     ��ʼλ�ã��ļ�β
* ios::app     ׷�ӷ�ʽд�ļ�
* ios::trunc   ����ļ�������ɾ�����ٴ���
* ios::binary  �����Ʒ�ʽ
*/

//�ļ��򿪷�ʽ�������ʹ�ã�����|������
//���磺�ö����Ʒ�ʽд�ļ� ios::binary | ios::out

void writeflie()
{
	ofstream ofs;
	ofs.open("test.txt", ios::out);
	ofs << "д������" << endl;
	ofs.close();
}

/*���ļ�
* 1.����ͷ�ļ�-#include<fstream>
* 2.����������-ifstream ifs;
* 3.���ļ����ж��ļ��Ƿ�򿪳ɹ�-ifs.open("�ļ�·��","�򿪷�ʽ");
* 4.������-���ַ�ʽ��ȡ
* 5.�ر��ļ�-ifs.close();
*/
void readfile()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//���ַ�ʽ��ȡ
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



	//�ر��ļ�
	ifs.close();
}


//�������ļ����򿪷�ʽָ��Ϊios::binary
/*�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
* ����ԭ�ͣ�ostream &write(const char *buffer,int len);
* �������ͣ��ַ�ָ��bufferָ���ڴ��е�һ�δ洢�ռ䣬len�Ƕ�д�ֽ���
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
	Person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();

}

/*�����ƶ��ļ�
* �����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
* ����ԭ�ͣ�istream& read(char* buffer,int len);
* �������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д���ֽ���
*/
void binaryread()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
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
	/*��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н����ͻᱻ�ͷ�
	* ͨ���ļ����Խ����ݳ־û�
	* C++�ж��ļ�������Ҫ����ͷ�ļ�<fstream>
	* �ļ����ͷ�Ϊ���֣�
	* 1.�ı��ļ�--�ļ����ı���ASCII����ʽ�����ڼ������
	* 2.�������ļ�--�ļ����ı��Ķ�������ʽ�����ڼ�����У��û�һ�㲻��ֱ�Ӷ���
	* �����ļ��������ࣺ
	* 1.ofstream:д����
	* 2.ifstream:������
	* 3.fstream:��д����
	*/



	system("pause");
	return 0;
}