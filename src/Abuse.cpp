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
//run函数 
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
		getline(arrFile,strLen);//读取一行字符串
	 
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
	cout<<"读取文件名"<<str<<"完成 共"<<line<<"行"<<endl; 
}
//运行主函数 
void Abuse::run(int i,int sleeptime,string str)
{
	this->readAbuseTxt(str);
	Key key;
	srand(unsigned(time(NULL)));
	//执行次数
	int n_line=0;
	key.sleep(5000);//延迟五秒钟 
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
	OpenClipboard( hWnd );//打开剪切板
	EmptyClipboard();//清空剪切板
	HANDLE hHandle = GlobalAlloc(GMEM_FIXED, str.length()*2);//分配内存
	char* pData = (char*) GlobalLock(hHandle);//锁定内存，返回申请内存的首地址
	strcpy(pData,str.c_str());//或strcpy(pData, "this is a ClipBoard Test.");
	SetClipboardData(CF_TEXT, hHandle);//设置剪切板数据
	GlobalUnlock(hHandle);//解除锁定
	CloseClipboard();//关闭剪切板
}
