#ifndef ABUSE_H
#define ABUSE_H
#include "Key.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream> //文本操作 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std; 
class Abuse
{
	public:
		Abuse();
		~Abuse();
		void runKey(int time=10);//运行键 
		void run(int i=100,int sleeptime=50,string str="arrange.txt");				 //运行 
		void ctrl_c();
		void ctrl_v();
		void enter();
		void readAbuseTxt(string str);//读取文本 
		void testString();
		void setClipboardTxt(string str);//设置剪贴板 
		
	private:
		vector <string> txt;
		int line;
		
};

#endif
