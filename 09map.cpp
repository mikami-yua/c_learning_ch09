#include <iostream>
using namespace std;
#include<map>
#include<string>
/*
map中所有元素都是pair，第一个元素称为key值，第二个元素称为value值
所有元素按照key值升序排列---key不能重复
本质是map、multimap属于关联是容器（区别与set的相同）
优点：根据key快速找到value
*/
void printMap(map<int, int> &m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << (*it).first << " value:" << (*it).second << endl;
	}
	cout << endl;
}

//构造
void test91() {
	map<int, int> m;

	//插入 插入数据时需要使用对组
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 10));
	m.insert(pair<int, int>(5, 50));

	printMap(m);

	//拷贝构造
	map<int, int> m2(m);
	printMap(m2);

	//=
	map<int, int> m3;
	m3 = m2;
	printMap(m3);
}

//大小交换
void test92() {
	map<int, int> m;

	//插入 插入数据时需要使用对组
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 10));
	m.insert(pair<int, int>(5, 50));

	cout << m.size() << endl;
	cout << m.empty() << endl;

	map<int, int> m2;
	m2.insert(pair<int, int>(8, 10));
	m2.insert(pair<int, int>(66, 10));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(pair<int, int>(6, 10));
	m2.insert(pair<int, int>(2, 50));
	printMap(m);
	printMap(m2);

	m.swap(m2);
	printMap(m);
	printMap(m2);
}

//插入删除
void test93() {
	map<int, int> m;

	//插入 插入数据时需要使用对组
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 10));
	m.insert(pair<int, int>(5, 50));

	//方法2
	m.insert(make_pair(7, 20));
	//方法3
	m.insert(map<int, int>::value_type(8, 90));
	printMap(m);
	//方法4---不建议使用
	m[80] = 77;
	printMap(m);
	cout << m[666] << endl;
	printMap(m);//key:666 value:0 插错了会自动生成一个value为0的pair

	//删除
	m.erase(m.begin());
	printMap(m);

	m.erase(3);//按照key删除
	printMap(m);

	m.erase(m.begin(), m.end());
}

//查找和统计-----都是按照key（同set）
void test94() {
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 10));
	m.insert(pair<int, int>(5, 50));

	map<int, int>::iterator pos = m.find(3);
	cout << (pos == m.end()) << " " << (*pos).first << "-" << (*pos).second << endl;//0 3-30

	cout << m.count(5) << endl;//对于map count只能是0、1
}

//排序---仿函数
class MyCompare3 {
public:
	bool operator()(int v1, int v2)const {//第一个（）表示重载（）运算符
		return v1 > v2;
	}
};
void test95() {
	map<int, int,MyCompare3> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 10));
	m.insert(pair<int, int>(5, 50));
	for (map<int, int,MyCompare3>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << (*it).first << " value:" << (*it).second << endl;
	}
}

int mfun9() {
	test95();
	return 0;
}