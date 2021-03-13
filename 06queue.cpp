#include <iostream>
using namespace std;
#include<queue>
#include<string>
/*
队列先进先出
不能遍历
*/
class Cat {
public:
	Cat(string name,int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};
void test61() {
	queue<Cat>q;

	Cat c1("aaa", 2);
	Cat c2("bbb", 3);
	Cat c3("ccc", 4);
	Cat c4("ddd", 5);
	Cat c5("eee", 6);

	q.push(c1);
	q.push(c2);
	q.push(c3);
	q.push(c4);
	q.push(c5);

	cout << q.size() << endl;
	while (!q.empty())
	{
		//查看队头
		cout << q.front().name << endl;
		//查看队尾
		cout << q.back().name << endl;
		q.pop();
	}
	cout << q.size() << endl;
}

int mfun6() {
	test61();
	return 0;
}