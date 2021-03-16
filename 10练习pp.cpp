#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>

#define CHEHUA	0
#define MEISHU	1
#define YANFA	2

class Worker {
public:
	string name;
	int salary;
};

void createWorker(vector<Worker>& v) {
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		Worker worker;
		worker.name = "worker ";
		worker.name += nameSeed[i];

		worker.salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v, multimap<int, Worker>&m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		//产生随机部门编号
		int deptId = rand() % 3;

		//员工插入map
		m.insert(pair<int, Worker>(deptId, (*it)));

	}
}

void showWorkerByMap(multimap<int, Worker>& m) {
	cout << "策划: " << endl;
	multimap<int, Worker>::iterator it = m.find(CHEHUA);
	int count = m.count(CHEHUA);
	for (int index=0; it != m.end()&&index<count; index++,it++) {
		cout << "姓名： " << (*it).second.name << " 工资：" << (*it).second.salary << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
	cout << "美术: " << endl;
	it = m.find(MEISHU);
	count = m.count(MEISHU);
	for (int index = 0; it != m.end() && index < count; index++, it++) {
		cout << "姓名： " << (*it).second.name << " 工资：" << (*it).second.salary << endl;
	}
	cout << "--------------------------------------------------------------------" << endl;
	cout << "研发: " << endl;
	it = m.find(YANFA);
	count = m.count(YANFA);
	for (int index = 0; it != m.end() && index < count; index++, it++) {
		cout << "姓名： " << (*it).second.name << " 工资：" << (*it).second.salary << endl;
	}
}
int mfun10() {
	vector<Worker>vw;
	createWorker(vw);
	/*for (vector<Worker>::iterator it = vw.begin(); it != vw.end(); it++) {
		cout << "name:" << (*it).name << " salary:" << (*it).salary << endl;
	}*/
	//员工分组
	multimap<int, Worker>m;
	setGroup(vw, m);

	showWorkerByMap(m);
	return 0;
}