#ifndef ABUSE_H
#define ABUSE_H
#include "Key.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream> //�ı����� 
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
		void runKey(int time=10);//���м� 
		void run(int i=100,int sleeptime=50,string str="arrange.txt");				 //���� 
		void ctrl_c();
		void ctrl_v();
		void enter();
		void readAbuseTxt(string str);//��ȡ�ı� 
		void testString();
		void setClipboardTxt(string str);//���ü����� 
		
	private:
		vector <string> txt;
		int line;
		
};

#endif
