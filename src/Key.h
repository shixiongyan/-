#ifndef KEY_H
#define KEY_H

#include <windows.h> 
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;


#define VK_Enther 13
#define VK_Ctrl   17


//#define ; 186
//#define Caps_Lock 20
class Key
{
	public:
		Key();
		~Key();
		Key& down(int vk_code);
		Key& up(int vk_code);
		Key& press(int vk_code);
		Key& combination(int vk_code);
		Key& combination(int vk_code_1,int vk_code_2);
		Key& combination(int vk_code_1,int vk_code_2,int vk_code_3);
		Key& combination(int vk_code_1,int vk_code_2,int vk_code_3,int vk_code_4);
		Key& sleep(int _time);
		Key& caps(); 
		Key& Caps();
		Key& setSleepTime(int _time);
		Key& bearStr(string str);
		Key& period();
		Key& comma();
		int  getTime();
		 
	private:
		
		int time;
		
};

#endif
