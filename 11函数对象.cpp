#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
/*
函数对象：重载函数嗲用操作符的类称为函数对象
函数对象使用重载的（）时，行为类似仿函数嗲用，也称为仿函数
本质是个类不是个函数
*/

class MyAdd {
public:
	int operator()(int v1,int v2) {
		return v1 + v2;
	}
};

//函数对象使用时，可以像普通函数一样调用，可以有参数，可以有返回值
void test111() {
	MyAdd myadd;
	cout << myadd(10, 10) << endl;
}
//函数对象可以拥有自己的状态
class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}
	int count;//自己的状态
};

void test112() {
	MyPrint mp;
	mp("hello world");
	mp("hello world");
	mp("hello world");
	cout << "调用次数 ：" << mp.count << endl;
}

//函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test) {
	mp(test);
}

void test113(){
	MyPrint mp;
	doPrint(mp, "hello c++");
}

/*
谓词 仿函数返回值类型时bool类型，称为谓词
一元谓词：

*/
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void test114() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//查找容器中有没有》5的
	vector<int>::iterator it = find_if(v.begin(), v.end(),GreaterFive());//GreaterFive匿名的函数对象
	if (it == v.end()) {
		cout<<"cannot find"<<endl;
	}
	else {
		cout << "find some num bigger than 5 " <<(*it)<< endl;
	}
	
}


int mfun11() {
	test114();
	return 0;
}