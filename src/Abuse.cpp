#include "Abuse.h"

Abuse::Abuse()
{
	this->line=0;
}

Abuse::~Abuse()
{
}
//ctrl+c 
void Abuse::ctrl_c()
{
	Key *key= new Key;
	key->combination(VK_Ctrl,'C');
	delete[] key;
}
//ctrl+v 
void Abuse::ctrl_v()
{
	Key *key= new Key;
	key->combination(VK_Ctrl,'V');
}
void Abuse::enter()
{
	Key *key = new Key;
	key->press(VK_Enther);	
} 
//run���� 
void Abuse::runKey(int time)
{
	Key *key= new Key;
	this->ctrl_v();
	key->sleep(time);
	this->enter();

}
void Abuse::readAbuseTxt(string str)
{
	
	ifstream arrFile(str.c_str());
	string strLen;
	for(;;)
	{
		getline(arrFile,strLen);//��ȡһ���ַ���
	 
		if(strLen!="END")
		{
			this->txt.push_back(strLen);
			this->line++;
		}
		else
		{
			break;
		}
	}
//	getline(arrFile,strLen);
//	cout<<strLen<<endl;
	cout<<"��ȡ�ļ���"<<str<<"��� ��"<<line<<"��"<<endl; 
}
//���������� 
void Abuse::run(int i,int sleeptime,string str)
{
	this->readAbuseTxt(str);
	Key key;
	srand(unsigned(time(NULL)));
	//ִ�д���
	int n_line=0;
	key.sleep(5000);//�ӳ������� 
	for(int cout=0;cout<i;cout++)
	{
		key.sleep(sleeptime);
		n_line=rand()%line;
		this->setClipboardTxt(this->txt[n_line]);
		this->ctrl_v();
		key.sleep(10);
		this->enter();
	}
	
}
void Abuse::testString()
{
	for(int i=0;i<line;i++)
	{
		cout<<txt[i]<<endl;
	}
}
void Abuse::setClipboardTxt(string str)
{
	HWND hWnd = NULL;
	OpenClipboard( hWnd );//�򿪼��а�
	EmptyClipboard();//��ռ��а�
	HANDLE hHandle = GlobalAlloc(GMEM_FIXED, str.length()*2);//�����ڴ�
	char* pData = (char*) GlobalLock(hHandle);//�����ڴ棬���������ڴ���׵�ַ
	strcpy(pData,str.c_str());//��strcpy(pData, "this is a ClipBoard Test.");
	SetClipboardData(CF_TEXT, hHandle);//���ü��а�����
	GlobalUnlock(hHandle);//�������
	CloseClipboard();//�رռ��а�
}
