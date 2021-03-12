#include <iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>

class Person {
public:
	Person(string name,int score) {
		this->name = name;
		this->score = score;
	}

	string name;
	int score;

};

void createPerson(vector<Person>&v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//评委的分数放到deque中
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60; //60~100
			d.push_back(score);
		}
		sort(d.begin(), d.end());
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			cout << (*dit) << "+";
		}
		cout << endl;
		//去除最高最低
		d.pop_back();
		d.pop_front();
		
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		(*it).score = sum / d.size();
	}
}

int main() {
	//1.创建选手
	vector<Person>v;
	createPerson(v);
	/*for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).name << "=====" << (*it).score << endl;
	}*/

	//2.给选手打分
	setScore(v);
	
	//3.显示分数
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it).name << "=====" << (*it).score << endl;
	}
	return 0;
}