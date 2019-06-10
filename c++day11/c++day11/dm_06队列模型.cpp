#include <iostream>
using namespace std;
#include <queue>

void main61()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << "队列元素:" << q.front() << endl;
	cout << "队列的大小:" << q.size() << endl;
	while (!q.empty())//队列是先进先出，不同于之前的后进先出
	{
		int tmp = q.front();
		cout << tmp << " ";
		q.pop();
	}

}

//Teacer结点
class Teacher
{
public:
	int age;
	char name[32];
	void ptintT()
	{
		cout << "age:" << age << endl;
	}
};

void main62()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);

	while (!q.empty())
	{
		Teacher tmp = q.front();
		tmp.ptintT();
		q.pop();
	}
}

void main63()
{
	Teacher t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	queue<Teacher*> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);

	while (!q.empty())
	{
		Teacher* tmp = q.front();
		tmp->ptintT();
		q.pop();
	}
}

void main()
{
	//main61();
	//main62();
	main63();

	return;
}