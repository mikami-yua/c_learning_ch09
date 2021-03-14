#include <iostream>
using namespace std;
#include<set>
#include<string>
/*
set容器插入时自动排序
set：不能有重复元素
multiset：可以有重复元素
*/
void printSet(set<int>& s) {
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << "-";
	}
	cout << endl;
}
void printMulitSet(multiset<int>& s) {
	for (multiset<int>::iterator it = s.begin(); it != s.end(); it++) {
		cout << (*it) << "-";
	}
	cout << endl;
}



//构造
void test81() {
	set<int>s1;
	//插入数据时只有insert操作
	s1.insert(10);
	s1.insert(9);
	s1.insert(9);
	s1.insert(15);
	printSet(s1);//9-10-15- 自动排序，不能插入重复的值

	//拷贝构造
	set<int>s2(s1);
	printSet(s2);
	//赋值
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

//大小和交换 不能重新指定大小
void test82() {
	set<int>s1;
	//插入数据时只有insert操作
	s1.insert(10);
	s1.insert(9);
	s1.insert(15);
	printSet(s1);//9-10-15- 自动排序，不能插入重复的值
	cout << s1.size() << endl;
	cout << s1.empty() << endl;

	set<int>s2;
	s2.insert(1);
	s2.insert(3);
	s2.insert(2);
	printSet(s2);
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

//插入删除
void test83() {
	set<int>s1;
	s1.insert(10);
	s1.insert(9);
	s1.insert(15);
	printSet(s1);

	//删除
	s1.erase(s1.begin());
	printSet(s1);//10-15-

	s1.erase(15);
	printSet(s1);//删除指定数

	
}

//查找和统计
void test84() {
	set<int>s1;
	s1.insert(10);
	s1.insert(9);
	s1.insert(15);
	printSet(s1);

	//find查找返回迭代器，不存在也返回迭代器指向end
	set<int>::iterator pos = s1.find(9);
	cout <<(pos == s1.end())<<" "<<(*pos) << endl;

	//count统计个数 只能是0、1
	cout << s1.count(15) << endl;
}

//multiset
void test85() {
	/*
	set在插入数据的时候，会有返回值，表示插入是否成功
	multiset不会检测数据，因此可以插重复数据
	*/
	set<int>s1;
	pair<set<int>::iterator,bool> ret= s1.insert(10);
	cout << ret.second << endl;//1 ret.second 表示第二个数据，如果成功就返回真 
	ret = s1.insert(10);
	cout << ret.second << endl;//0

	multiset<int>s2;
	s2.insert(20);
	s2.insert(20);
	printMulitSet(s2);//20-20-
}

//pair对组
/*
成对出现的两个数据
*/
void test86() {
	//方法1
	pair<string, int> p("tom", 20);
	cout << "name:" << p.first << endl;
	cout << "age:" << p.second << endl;
	//方法2
	pair<string, int>p2 = make_pair("jerry", 30);
	cout << "name:" << p2.first << endl;
	cout << "age:" << p2.second << endl;
}

//内置类型指定排序规则
/*
利用仿函数
*/
class MyCompare {
public:
	bool operator()(int v1,int v2)const{
		return v1 > v2;
	}
};
void test87() {
	set<int>s1;
	s1.insert(10);
	s1.insert(9);
	s1.insert(15);
	printSet(s1);

	set<int,MyCompare>s2;
	s2.insert(10);
	s2.insert(9);
	s2.insert(15);
	for (set<int,MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << (*it) << "-";
	}
	cout << endl;

}

class bird {
public:
	bird(string name,int age) {
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

//set自定义数据类型排序,都需要指定排序规则
class MyCompare2 {
public:
	bool operator()(const bird&b1, const bird& b2)const {
		//按年龄降序
		return b1.age>b2.age;
	}
};
void test88() {
	set<bird,MyCompare2>b;
	bird b1("aaa", 1);
	bird b2("aab", 9);
	bird b3("add", 3);
	bird b4("acc", 5);
	bird b5("xxx", 2);

	b.insert(b1);
	b.insert(b2);
	b.insert(b3);
	b.insert(b4);
	b.insert(b5);

	for (set<bird,MyCompare2>::iterator it = b.begin(); it != b.end(); it++) {
		cout << (*it).name<<","<<(*it).age << "-";
	}
	cout << endl;


}

int mfun8() {
	test88();
	return 0;
}