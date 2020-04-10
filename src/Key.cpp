#include "Key.h"
#include <string>
Key::Key()
{
	this->time=0; //默认没有延迟 
}

Key::~Key()
{
	
}

//按下 
Key& Key::down(int vk_code)
{
	keybd_event(vk_code,0,0,0);

}
//弹起 
Key& Key::up(int vk_code)
{
	keybd_event(vk_code,0,KEYEVENTF_KEYUP,0);

}
//按下并弹起 
Key& Key::press(int vk_code)
{
	if(this->time)
	{
		this->sleep(this->time);
	}
	
	if(islower(vk_code))//小写字母 
	{
		vk_code-=32; 
	}
	down(vk_code);
	up(vk_code);
	return *this; 
}
//单键 
Key& Key::combination(int vk_code)
{
	press(vk_code);
	return *this;
}
//双向组合键 
Key& Key::combination(int vk_code_1,int vk_code_2)
{
	down(vk_code_1);
	press(vk_code_2);
	up(vk_code_1);
	return *this;
}
//三键组合键 
Key& Key::combination(int vk_code_1,int vk_code_2,int vk_code_3)
{
	down(vk_code_1);
	down(vk_code_2);
	press(vk_code_3);
	up(vk_code_2);
	up(vk_code_1);
	return *this;
}
//四键组合键 
Key& Key::combination(int vk_code_1,int vk_code_2,int vk_code_3,int vk_code_4)
{
	down(vk_code_1);
	down(vk_code_2);
	down(vk_code_3);
	press(vk_code_4);
	up(vk_code_3);
	up(vk_code_2);
	up(vk_code_1);
	return *this;
}
//延迟 
Key& Key::sleep(int _time)
{
	Sleep(_time);
	return *this;
}
//绝对小写输入模式 
Key& Key::caps()
{
	if (GetKeyState(VK_CAPITAL))
    {
         // 如果当前键盘状态为大写,要求改小写,则模拟按键CapsLock切换状态

             keybd_event(VK_CAPITAL, 0, 0, 0);
             keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
    }
    return *this;
}
//绝对大写输入模式 
Key& Key::Caps()
{
	if (!GetKeyState(VK_CAPITAL))
    {
         // 如果当前键盘状态为小写,要求改大写,则模拟按键CapsLock切换状态

             keybd_event(VK_CAPITAL, 0, 0, 0);
             keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
    }
    return *this;
}
Key& Key::setSleepTime(int _time)
{
	this->time=_time;
	return *this;
}
//逗号 
Key& Key::period()
{
	keybd_event(VK_DECIMAL, 0, 0, 0);
    keybd_event(VK_DECIMAL, 0, KEYEVENTF_KEYUP, 0);
}
//空格 
Key& Key::comma()
{
	keybd_event(188, 0, 0, 0);
    keybd_event(188, 0, KEYEVENTF_KEYUP, 0);
}
//获取延迟时间 
int Key::getTime()
{
	return this->time;
}
//模拟字符串 
Key& Key::bearStr(string str)
{
    for(int cout=0;cout<str.length();cout++)
    {
    	if(isupper(str[cout]))//如果是大写字母
		{
			this->Caps();
			press(str[cout]);
			this->caps(); 
		}
		else if(str[cout]=='.')
		{
			period();
		}
		else if(str[cout]==',')
		{
			comma();
		}
		else
		{
			press(str[cout]);
		}
	}
	return *this;
}

