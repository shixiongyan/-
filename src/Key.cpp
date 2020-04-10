#include "Key.h"
#include <string>
Key::Key()
{
	this->time=0; //Ĭ��û���ӳ� 
}

Key::~Key()
{
	
}

//���� 
Key& Key::down(int vk_code)
{
	keybd_event(vk_code,0,0,0);

}
//���� 
Key& Key::up(int vk_code)
{
	keybd_event(vk_code,0,KEYEVENTF_KEYUP,0);

}
//���²����� 
Key& Key::press(int vk_code)
{
	if(this->time)
	{
		this->sleep(this->time);
	}
	
	if(islower(vk_code))//Сд��ĸ 
	{
		vk_code-=32; 
	}
	down(vk_code);
	up(vk_code);
	return *this; 
}
//���� 
Key& Key::combination(int vk_code)
{
	press(vk_code);
	return *this;
}
//˫����ϼ� 
Key& Key::combination(int vk_code_1,int vk_code_2)
{
	down(vk_code_1);
	press(vk_code_2);
	up(vk_code_1);
	return *this;
}
//������ϼ� 
Key& Key::combination(int vk_code_1,int vk_code_2,int vk_code_3)
{
	down(vk_code_1);
	down(vk_code_2);
	press(vk_code_3);
	up(vk_code_2);
	up(vk_code_1);
	return *this;
}
//�ļ���ϼ� 
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
//�ӳ� 
Key& Key::sleep(int _time)
{
	Sleep(_time);
	return *this;
}
//����Сд����ģʽ 
Key& Key::caps()
{
	if (GetKeyState(VK_CAPITAL))
    {
         // �����ǰ����״̬Ϊ��д,Ҫ���Сд,��ģ�ⰴ��CapsLock�л�״̬

             keybd_event(VK_CAPITAL, 0, 0, 0);
             keybd_event(VK_CAPITAL, 0, KEYEVENTF_KEYUP, 0);
    }
    return *this;
}
//���Դ�д����ģʽ 
Key& Key::Caps()
{
	if (!GetKeyState(VK_CAPITAL))
    {
         // �����ǰ����״̬ΪСд,Ҫ��Ĵ�д,��ģ�ⰴ��CapsLock�л�״̬

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
//���� 
Key& Key::period()
{
	keybd_event(VK_DECIMAL, 0, 0, 0);
    keybd_event(VK_DECIMAL, 0, KEYEVENTF_KEYUP, 0);
}
//�ո� 
Key& Key::comma()
{
	keybd_event(188, 0, 0, 0);
    keybd_event(188, 0, KEYEVENTF_KEYUP, 0);
}
//��ȡ�ӳ�ʱ�� 
int Key::getTime()
{
	return this->time;
}
//ģ���ַ��� 
Key& Key::bearStr(string str)
{
    for(int cout=0;cout<str.length();cout++)
    {
    	if(isupper(str[cout]))//����Ǵ�д��ĸ
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

