#include <iostream>
using namespace std;
#include "map"
#include "string"

//multimap案例：
//1个key值可以对应多个value = 分组
//公司有销售部sale(员工2名)、技术研发部development(1人)、财务部financial(2人)
//人员信息有：姓名，年龄，电话，工资等组成
//通过multimap进行 信息的插入、保存、显示
//分部门显示员工信息
class Person
{
public:
	string name;
	int age;
	string tel;
	double sal;
};


void main1201()
{
	Person p1, p2, p3, p4, p5;

	p1.name = "王1";
	p1.age = 31;
	
	p2.name = "王2";
	p2.age = 32;
	
	p3.name = "张3";
	p3.age = 33;
	
	p4.name = "张4";
	p4.age = 34;
	
	p5.name = "赵5";
	p5.age = 35;

	multimap<string, Person> map2;
	//sale部门
	map2.insert(make_pair("sale", p1));
	map2.insert(make_pair("sale", p2));

	//development部门
	map2.insert(make_pair("development", p3));
	map2.insert(make_pair("development", p4));

	//financial部门
	map2.insert(make_pair("financial", p5));

	for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
	}
	cout << "遍历结束" << endl;

	//
	int num2 = map2.count("development");
	cout << "development部门==>" << num2 << endl;

	cout << "development部门员工信息" << endl;
	multimap<string, Person>::iterator it2 = map2.find("development");
	int tag = 0;//加它是因为要满足tag<num2的条件，否则先打印development部门员工信息，然后又会把其他员工信息打印出来
	while (it2 != map2.end() && tag<num2)
	{
		cout << it2->first << "\t" << it2->second.name << endl;
		it2++;
		tag++;
	}
}

//age =32修改成name32
void main1202()
{
	Person p1, p2, p3, p4, p5;

	p1.name = "王1";
	p1.age = 31;

	p2.name = "王2";
	p2.age = 32;

	p3.name = "张3";
	p3.age = 33;

	p4.name = "张4";
	p4.age = 34;

	p5.name = "赵5";
	p5.age = 35;

	multimap<string, Person> map2;
	//sale部门
	map2.insert(make_pair("sale", p1));
	map2.insert(make_pair("sale", p2));

	//development部门
	map2.insert(make_pair("development", p3));
	map2.insert(make_pair("development", p4));

	//financial部门
	map2.insert(make_pair("financial", p5));

	cout << "按照条件检索数据，进行修改" << endl;
	for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		//cout << it->first << " " << it->second.name << endl;
		if (it->second.age == 32)
		{
			it->second.name = "name32";
		}
	}
	
	for (multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		cout << it->first << " " << it->second.name << endl;
	}

}


void main()
{
	//main1201();
	main1202();
	
	return;
}