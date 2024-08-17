#include"2024_8_16.h"

void test01()
{
	manbo::string s1;
	manbo::string s2="Hello world";
	cout << s2.c_str() << endl;
	cout << s1.c_str() << endl;
	manbo::string const s3 = "asdddd";
}

void test02()
{
	manbo::string const s2 = "Hello world";
	manbo::string::iterator it = s2.begin();
	while (it!=s2.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}

void test03()
{
	manbo::string  s2 = "Hello world";
	s2.insert(6, "******");
	cout << s2.c_str() << endl;
	s2.erase(0);
	cout << s2.c_str() << endl;
}

void test04()
{
	manbo::string  s2 = "Hello world";
	size_t pos1 = s2.find("world");
	size_t pos2 = s2.find('e');
	cout << pos2 << endl;
}

void test05()
{

	manbo::string s1 = "https://www.bilibili.com/video/BV1fW421X7gD/?spm_id_from=333.1007.tianma.6-1-19.click";
	//解析网址，分协议   域名  资源
	size_t pos1 = s1.find("://");
	if (pos1 == manbo::string::npos)
	{
		cout << "No Find";
		exit(1);
	}
	manbo::string agreement = s1.substr(0, pos1);
	cout << "协议:" << agreement.c_str()<< endl;

	size_t pos2 = s1.find('/', pos1 + 3);
	if (pos2 == manbo::string::npos)
	{
		cout << "No Find";
		exit(1);
	}

	manbo::string domain = s1.substr(pos1 + 3, pos2 - (pos1 + 3));
	cout << "域名:" << domain.c_str()<< endl;

	manbo::string resource = s1.substr(pos2 + 1);
	cout << "资源:" << resource.c_str() << endl;
}

void test06()
{
	string s1 = "hello world";
	manbo::string s2 = "hello world";
	//s1.resize(4,'x');
	//s2.resize(4,'x');
	s1 += '\0';
	s1 += "******";

	s2 += '\0';
	s2 += "******";
	cout << s1 << endl;
	cout << s2<< endl;

	manbo::string s3;

	cin >> s3;
	cout << s3;

	cin >> s3;
	cout << s3;
}

void test07()
{
	manbo::string s1="hello";
	manbo::string s2="hello world";
	cout << (s1 < s2) << endl;
	cout << (s1 == s2) << endl;
	cout << (s1 > s2) << endl << endl;

	manbo::string s3 = "hello world";
	manbo::string s4 = "hello";
	cout << (s3 < s4) << endl;
	cout << (s3 == s4) << endl;
	cout << (s3 > s4) << endl<<endl;

	manbo::string s5 = "hello";
	manbo::string s6 = "hello";
	cout << (s5 < s6) << endl;
	cout << (s5 == s6) << endl;
	cout << (s5 > s6) << endl << endl;
}

void test08()
{
	manbo::string s1 = "hello";
	manbo::string s2 = "hello world";
	s1 = s2;
	cout << s1;

}

int main()
{
	test08();
	return 0;
}