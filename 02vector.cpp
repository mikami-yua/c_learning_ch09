#include <iostream>
using namespace std;
#include<vector>
/*
vector可以动态扩展
*/

//构造函数
/*
vector<T> v
vectot(v.begin(),v.end())  [begin,end)
vector(n,elem)				n个elem
vector(const vector &vec)
*/
void printVector(vector<int>&v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test11() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	//区间构造
	vector<int> v2(v1.begin(),v1.end());
	printVector(v2);

	//n个elem
	vector<int> v3(10, 100);
	printVector(v3);

	//拷贝构造
	vector<int> v4(v3);
	printVector(v4);
}

//vector赋值
/*
=
assign
*/
void test12() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2;
	v2 = v1;
	printVector(v2);

	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	vector<int> v4;
	v4.assign(100, 10);
	printVector(v4);
}

//vector容量和大小
/*
empty-------------------- 真 -》 空
capacity 容量
size	 实际个数
resize   重新指定大小
*/
void test13() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	vector<int> v2;
	cout << v1.empty() << endl;//0
	cout << v2.empty() << endl;//1

	cout << v1.capacity() << endl;//13
	cout << v1.size() << endl;//10

	//重新指定大小
	v2 = v1;
	v1.resize(15);
	printVector(v1);//0 1 2 3 4 5 6 7 8 9 0 0 0 0 0  重新指定的比原来长了默认用0填充
	v2.resize(15, 100);
	printVector(v2);//0 1 2 3 4 5 6 7 8 9 100 100 100 100 100 

	v1.resize(5);
	printVector(v1);//0 1 2 3 4重新指定的小了会删除其他的
	
}

//vector插入删除
void test14() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	//尾删除
	v1.pop_back();
	printVector(v1);

	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);

	//删除
	v1.erase(v1.begin());
	printVector(v1);

	v1.erase(v1.begin(),v1.end());
	printVector(v1);
}

//vector数据存取
/*
除了迭代器
使用
at 【】 front（返回容器中第一个元素） back（返回容器中最后一个元素）
*/
void test15() {
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << v1.front() << endl;
	cout << v1.back() << endl;
}

//vector互换容器
void test16() {
	//使用方法
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);
	vector<int> v2;
	for (int i = 10; i > 0; i--) {
		v2.push_back(i);
	}
	printVector(v2);
	v1.swap(v2);
	printVector(v1);
	printVector(v2);

	//用处：可以收缩内存空间
	vector<int> v3;
	for (int i = 0; i < 100000; i++) {
		v3.push_back(i);
	}
	cout << v3.capacity() << endl;//138255
	cout << v3.size() << endl;//100000
	v3.resize(3);
	cout << v3.capacity() << endl;//138255 容量没有变小但是size小了，浪费空间
	cout << v3.size() << endl;//3
	//使用swap收缩内存
	vector<int>(v3).swap(v3);//vector<int>(v3)匿名对象，使用v3创建匿名对象，按照v3所用的元素个数来初始化大小
	//交换后的空间也不会浪费，编译器对匿名对象，当前行执行完马上就回收了
	cout << v3.capacity() << endl;//3
	cout << v3.size() << endl;//3
}

//vector预留空间  减少动态扩展容量时的扩展次数 reserve
/*
与resize的不同在于：resize会给定没用到的元素的0，reserve不会给元素值，扩展的元素时不可访问的
*/
void test17() {
	vector<int> v1;
	int count = 0;//统计开辟空间的次数
	int* p = NULL;

	for (int i = 0; i < 100000; i++) {
		v1.push_back(i);
		if (p != &v1[0]) { 
			p = &v1[0]; //更换了一次内存
			count++;
		}
	}
	cout << count << endl;//30次

	vector<int> v2;
	v2.reserve(100000);
	int count2 = 0;//统计开辟空间的次数
	int* p2 = NULL;

	for (int i = 0; i < 100000; i++) {
		v2.push_back(i);
		if (p2 != &v2[0]) {
			p2 = &v2[0]; //更换了一次内存
			count2++;
		}
	}
	cout << count2 << endl;//1次

}

int mfun2(){
	test17();
	return 0;
}