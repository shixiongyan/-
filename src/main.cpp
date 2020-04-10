#include "Key.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Abuse.h"
#include <conio.h>
using namespace std;
//void run()
//{
//	Key *nkey= new Key;
//	nkey->sleep(3000);
//	nkey->setSleepTime(100);
//	nkey->bearStr("He became interested in two theories that possibly explained how cholera killed people. ");
//	nkey->bearStr("The first suggested that cholera multiplied in the air. ");
//	nkey->bearStr("A cloud of dangerous gas floated around until it found its victims. ");
//	nkey->bearStr("The second suggested that people absorbed this disease into their bodies with their meals. ");
//	nkey->bearStr("From the stomach the disease quickly attacked the body and soon the affected person died. ");
//	nkey->bearStr("John Snow suspected that the second theory was correct but he needed evidence. ");
//	nkey->bearStr("So when another outbreak hit London in 1854, he was ready to begin his enquiry. ");
//	nkey->bearStr("As the disease spread quickly through poor neighbourhoods, he began to gather information. ");
//	nkey->bearStr("In two particular streets, the cholera outbreak was so severe that more than 500 people died in ten days. ");
//	nkey->bearStr("He was determined to find out why.");
//} 
void test()
{
	Key *nkey= new Key;
	nkey->setSleepTime(100); 
	cout<<nkey->getTime();
}
void fileTest()
{
	string str;
	ifstream txt("test.txt");
	getline(txt,str); 
	//cout<<str;
	Key *nkey= new Key;
	nkey->sleep(3000);
	nkey->setSleepTime(10);
	nkey->bearStr(str); 
}
void test1()
{
	Key *nkey= new Key;
	nkey->sleep(5000);
	nkey->setSleepTime(10);
	for(int cout=0;cout<100;cout++)
	{
		nkey->bearStr("Hello"); 
		nkey->press(13);
	}
	
} 
int main(int argv,char *argc[])
{
	//test();
	//run();
//	string fileName="";
//	{
//		getline(cin,fileName);getline(cin,fileName);key->combination(Ctrl,'V');
//		fileTest(fileName);	
//	}
	//fileTest();
	//test1();
	int num,sleeptime;
	cout<<"设置执行次数：";
	cin>>num;
	if(num<1)
	{
		num=10;
	}
	cout<<"设置时间间隔（推荐大于50ms）：";
	cin>>sleeptime;
	string file;
	cout<<"请输入文件名（默认arrange.txt）：";
	cin>>file; 
	cout<<"将在五秒之后自动执行，请注意查找窗口..."<<endl;
	Abuse *abuse = new Abuse;
	abuse->run(num,sleeptime,file);
	cout<<"执行完毕!"<<endl;
	getch();
	return 0;
}
