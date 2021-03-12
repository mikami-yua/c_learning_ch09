#include <iostream>
using namespace std;
#include<deque>
#include<algorithm>
/*
双端数组
vector在头部插入元素，需要移动元素。vector是尾部数组
deque可以在头部和尾部插入
内部有一个中控器，维护每段缓冲区内容，缓冲区中存放真实数据
*/


void printDeque(const deque<int>&d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//deque构造 和vector基本相同
void test21() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque(d2);

	deque<int>d3(10, 100);
	printDeque(d3);

	deque<int>d4(d3);
	printDeque(d4);
}

//赋值
void test22() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);
	//=
	deque<int>d2;
	d2 = d1;
	printDeque(d2);

	//assign
	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	//n个elem
	deque<int>d4;
	d4.assign(9, 77);
	printDeque(d4);
}

//大小操作------与vector不同之处在于没有capacity
void test23() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	cout << d1.empty() << endl;//0
	cout << d1.size() << endl;//10
	
	//d1.resize(15);
	d1.resize(15,6);
	printDeque(d1);

}

//插入和删除
void test24() {
	deque<int>d1;
	//尾插
	d1.push_back(10);
	d1.push_back(20);

	//头插
	d1.push_front(3);
	d1.push_front(5);
	printDeque(d1);

	//尾删
	d1.pop_back();
	printDeque(d1);

	//头删
	d1.pop_front();
	printDeque(d1);
	
	//指定位置插入删除
	deque<int>d2;
	for (int i = 0; i < 10; i++) {
		d2.push_back(i);
	}
	printDeque(d2);
	//insert插入
	d2.insert(d2.begin(), 1000);
	printDeque(d2);

	d2.insert(d2.end(), 2, 10000);
	printDeque(d2);
	//区间插入
	d2.insert(d2.begin(), d1.begin(), d1.end());//在d2容器的起始位置插入 d1从begin到end的内容
	printDeque(d2);

	//删除
	deque<int>::iterator it = d2.begin();
	it++;
	d2.erase(it);
	printDeque(d2);
	//区间删除
	it = d2.begin();
	it+=2;
	d2.erase(it, d2.end());
	printDeque(d2);

	//清空
	d2.clear();
	printDeque(d2);
}

//数据存取---------与vector完全相同
void test25() {
	deque<int>d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	//[]
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << "---";
	}
	cout << endl;
	//at
	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << "---";
	}
	cout << endl;
	//front
	cout << d1.front() << endl;
	cout << d1.back() << endl;
}

//排序---sort算法 只需要提供区间
void test26() {
	deque<int>d1;
	d1.push_back(8);
	d1.push_back(3);
	d1.push_back(7);
	d1.push_back(1);
	d1.push_back(2);
	d1.push_back(9);
	d1.push_back(12);
	d1.push_back(6);
	printDeque(d1);
	sort(d1.begin(), d1.end());//默认升序排序
	printDeque(d1);
}


int mfun3() {
	test26();
	return 0;
}