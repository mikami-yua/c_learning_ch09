#include <iostream>
using namespace std;
#include<stack>
/*
栈 先进后出
栈不允许有遍历的行为
可以判断元素个数是否为空
可以判断元素个数
*/


void test51() {
	stack<int>s;
	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);

	//查看栈顶
	cout << s.size() << endl;
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.size() << endl;
}

int mfun5() {
	test51();
	return 0;
}