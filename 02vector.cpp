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

int main(){
	test13();
}