#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>



//遍历算法foreach
//普通函数
void print01(int val) {
	cout << val << " ";

}
//仿函数
class print02 {
public:
	void operator()(int val) {
		cout << val << " ";
	}
};

void test121() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print01);
	for_each(v.begin(), v.end(), print02());
}

/*
transfrom 从一个容器搬运到另一个容器   搬运时必须提前给目标容器确定空间
beg1 原容器的开始迭代器
end1 原容器的结束迭代器
beg2 目标容器的开始迭代器
end2 目标容器的结束迭代器
func 可以在搬运数据时进行一些运算
*/
class Transfrom {//可以在搬运时进行一些运算
public:
	int operator()(int v) {
		return v;
	}
};


void test122() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>target;//目标容器  必须提前开辟空间
	target.resize(v.size());
	transform(v.begin(), v.end(), target.begin(), Transfrom());
	for_each(target.begin(), target.end(), print02());
}


//查找算法
class GreaterThanFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void test123() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	vector<int>::iterator it=find(v.begin(), v.end(), 5);//三个参数分别时是  起始 终止 目标是找到5  
	//自定义数据类型不能接把把自定义数据类型写到第三个参数的位置  需要重载=
	cout << (*it) << endl;
	

	//find_if
	it=find_if(v.begin(), v.end(), GreaterThanFive());//
	if (it == v.end()) {
		cout << "cannot find" << endl;
	}
	else {
		cout << "find bigger than 5" << endl;
	}

	//adjacent_find 相邻查找
	v.push_back(2);
	v.push_back(2);
	it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "未找到相邻重复元素" << endl;
	}
	else {
		cout << "找到了相邻重复元素" << endl;
	}
	//binary_serach 返回元素是否存在-------使用时容器必须是有序的，无序的结果未知
	bool ret=binary_search(v.begin(), v.end(), 9);
	cout << ret << endl;

	//count
	int num=count(v.begin(), v.end(), 2);
	cout << num << endl;
	/*
	自定义数据类型，第三个参数需要重载==
	在自定义的数据类型中重载==
	*/

	//count_if  统计条件下个元素的个数
	num=count_if(v.begin(), v.end(), GreaterThanFive());
	cout << num << endl;

}

//排序算法
void test124() {
	//sort
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	v.push_back(3);
	sort(v.begin(), v.end());
	for_each(v.begin(),v.end(),print01);
	cout << endl;

	//random_shuffle
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), print01);
}

int main() {
	test124();
	return 0;
}