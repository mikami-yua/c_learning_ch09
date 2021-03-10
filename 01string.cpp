#include <iostream>
using namespace std;
#include<string>

/*
string是个类，内部封装了char*
string有很多成员方法

构造方式
    string（）
    string（const char*c）
    string（const string &s）
    string（int n,char c）//使用n个c进行初始化
*/

//构造函数
void test01() {
    string s1;//默认构造
    const char* st = "hello world";
    string s2(st);
    cout << s2 << endl;
    string s3(s2);
    cout << s3 << endl;
    string s4(10, 'k');
    cout << s4 << endl;
}

//string赋值
/*
=
assign
*/
void test02() {
    string str1;
    str1 = "hello hello";
    cout << str1 << endl;

    string str2;
    str2 = str1;
    cout << str2 << endl;

    string str3;
    str3.assign("hello c++");
    cout << str3 << endl;
    string str4;
    str4.assign("hello c++",5);//使用前n个参数进行赋值
    cout << str4 << endl;
    string str5;
    str5.assign(str3);
    cout << str5 << endl;
}

//字符串拼接
/*
+=
append
*/
void test03() {
    string str1="我";
    str1 += "在这里";
    cout << str1 << endl;
    str1 += ':';
    cout << str1 << endl;
    
    string str2;
    str2 = "地下城与勇士";
    str1 += str2;
    cout << str1 <<endl;

    string str3 = "I";
    str3.append(" love");
    cout << str3 << endl;
    str3.append(" game abcde", 7);
    cout << str3 << endl;

    str3.append(str2);
    cout << str3 << endl;

    str3.append(str2, 0, 6);//参数2 从哪个位置开始截取  参数3 截取的个数
    cout << str3 << endl;
}


//string查找
/*
find
rfind rfind从右向左查找 第一次出现的位置（位置都是按从左向右排的）
*/
void test04() {
    string str1 = "abcdefg";
    int pos=str1.find("de");//pos=3
    cout <<"pos="<< pos << endl;
    pos = str1.find("dg");//pos=-1 未找到字符串
    cout << "pos=" << pos << endl;

    pos = str1.rfind("de");
    cout << "pos=" << pos << endl;//pos=3
    string str2 = "abcdefgde";
    pos = str2.rfind("de");
    cout << "pos=" << pos << endl;//pos=7
}
//string替换
void test05() {
    string str1 = "abcdefg";
    str1.replace(1, 3, "1111");//从1好位置起 3个字符替换为1111
    cout << str1 << endl;//a1111efg
}

//string比较
/*
=0
>1
<-1
*/
void test06() {
    string str1 = "xello";
    string str2 = "zhello";
    cout << str1.compare(str2) << endl;
   
}

//string存取
/*
[]下标
at函数
*/
void test07() {
    string str1 = "abcdefg";
    //[]
    for (int i = 0; i < str1.size(); i++) {
        cout << str1[i] << " ";
    }
    cout << endl;
    //at
    for (int i = 0; i < str1.size(); i++) {
        cout << str1.at(i) << " ";
    }
    cout << endl;

    str1[3] = 'x';
    cout << str1 << endl;
}


//string 插入删除
/*
insert
erase 删除
*/
void test08() {
    string str1 = "hello world";
    str1.insert(1, "aaa");
    cout << str1 << endl;//haaaello world

    str1.erase(1, 3);
    cout << str1 << endl;
}

//string 字串获取
/*
substr
*/
void test09() {
    string str = "abcdefg";
    string substr = str.substr(1, 3);//从哪个位置起 截取多少个
    cout << substr << endl;//bcd

    //使用操作
    string email = "zhangsan@sina.com";
    //邮箱中获取用户名
    int pos=email.find("@");//8

    string username = email.substr(0, pos);
    cout << username << endl;
}

int mfun1()
{
    //test01();
    //test02();
    //test03();
    //test04();
    test09();
    return 0;
}


