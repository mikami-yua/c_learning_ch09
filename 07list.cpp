#include <iostream>
using namespace std;
#include<list>
#include<algorithm>
/*
链表
对任意位置快速插入和删除
遍历没有数组快，占用空间比数组大
*/

class Dog {
public:
	Dog(int length, int age) {
		this->length = length;
		this->age = age;
	}
	int length;
	int age;
};

void printList(const list<int> &L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++){
		cout << (*it) << "+";
	}
	cout<<endl;
}

//list构造函数
void test71() {
	list<int>L1;//默认构造

	//添加
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	printList(L1);

	//区间构造
	list<int>L2(L1.begin(),L1.end());
	printList(L2);

	//拷贝构造
	list<int>L3(L2);
	printList(L3);

	//n个elem
	list<int>L4(10, 100);
	printList(L4);
}

//list赋值
void test72() {
	list<int>L1;

	//添加
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	printList(L1);

	//=
	list<int>L2;
	L2 = L1;
	printList(L2);

	//assign
	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	//
	list<int>L4;
	L4.assign(10,100);
	printList(L4);
}
//交换
void test73() {
	list<int>L1;

	//添加
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);


	list<int>L2;
	L2.assign(10, 9);
	//交换前
	printList(L1);
	printList(L2);

	//交换后
	L1.swap(L2);
	printList(L1);
	printList(L2);
}

//大小
void test74() {
	list<int>L1;

	//添加
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	cout << L1.empty() << endl;//0
	cout << L1.size() << endl;//5
	
	L1.resize(10);
	printList(L1);//10+20+30+40+50+0+0+0+0+0+
	L1.resize(20, 9);
	printList(L1);//10+20+30+40+50+0+0+0+0+0+9+9+9+9+9+9+9+9+9+9+
}

//插入删除
void test75() {
	list<int>L1;
	//尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	//头插
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);
	printList(L1);//300+200+100+10+20+30+

	//尾部删除
	L1.pop_back();
	printList(L1);//300+200+100+10+20+
	//头删
	L1.pop_front();
	printList(L1);//200+100+10+20+

	//insert
	L1.insert(L1.begin(), 999);
	printList(L1);//999+200+100+10+20+

	//erase
	L1.erase(++L1.begin());
	printList(L1);//999+100+10+20+

	//移除------删除所有匹配的值
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printList(L1);
	L1.remove(10000);
	printList(L1);

	L1.clear();
	printList(L1);
}

//数据存取
void test76() {
	list<int>L1;

	//添加
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);

	//front back  没有at 【】 不是连续的地址空间不能使用下标  list本质是链表
	cout << L1.front() << endl;
	cout << L1.back() << endl;
	/*
	迭代器不支持+3 +1等操作，只支持++ -——（地址空间不连续）
	*/
}

bool myCompare(int v1,int v2) {
	return v1 > v2;
}

bool dogCompare(Dog &d1,Dog &d2) {//年龄升序
	if (d1.age == d2.age) {
		//身高降序
		return d1.length > d2.length;
	}
	return d1.age < d2.age;
}

//反转和排序
void test77() {
	list<int>L1;

	//反转
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_back(50);
	printList(L1);
	L1.reverse();
	printList(L1);//50+40+30+20+10+

	//排序
	//sort(L1.begin(), L1.end());  所有不支持随机访问的迭代器不支持标准算法 内部提供
	L1.sort();//默认规则升序
	printList(L1);//10+20+30+40+50+
	//降序已函数名重载
	L1.sort(myCompare);
	printList(L1);
}

//排序案例  年龄升序，年龄相同长度降序
void test78() {
	list<Dog>L1;

	Dog d1(1, 12);
	Dog d2(1, 15);
	Dog d3(2, 15);
	Dog d4(3, 13);
	Dog d5(4, 12);
	Dog d6(5, 11);

	//反转
	L1.push_back(d1);
	L1.push_back(d2);
	L1.push_back(d3);
	L1.push_back(d4);
	L1.push_back(d5);
	L1.push_back(d6);

	for (list<Dog>::iterator it = L1.begin(); it != L1.end(); it++) {
		cout << (*it).age << "+"<<(*it).length<<" ";
	}
	cout << endl;

	//排序
	L1.sort(dogCompare);
	for (list<Dog>::iterator it = L1.begin(); it != L1.end(); it++) {
		cout << (*it).age << "+" << (*it).length << " ";
	}
	cout << endl;

}

int mfun7() {
	test78();
	return 0;
}