// ClipboardConsole.cpp : 定义控制台应用程序的入口点。
//
  

  
#include <windows.h>
#include <stdio.h>
#include <locale.h>
  
void clientA() // ANSI版剪贴板客户端（复制操作）
{
    DWORD content;
    char buf[200] = {0};
    HGLOBAL hGlobal;
  
    while (true)
    {
        fgets(buf, sizeof(buf), stdin); // 获取输入的字符串
  
        hGlobal = GlobalAlloc(GPTR, (lstrlenA(buf) + 1)); // 新建一个Win32内存块
        char *pGlobal = (char*)GlobalLock(hGlobal); // 锁定并获取它的指针
        lstrcpyA(pGlobal, buf); // 将字符串复制到它的上边
        GlobalUnlock(hGlobal); // 释放内存块所有权
  
        OpenClipboard(NULL); // 打开剪贴板（拥有者窗口为NULL）
        EmptyClipboard(); // 清空
        SetClipboardData(CF_TEXT, hGlobal); // 放置已复制到hGlobal中的ANSI文本
        CloseClipboard(); // 关闭剪贴板
    }
}
  
void monitorA() // ANSI版剪贴板监视器（粘贴操作）
{
    DWORD content;
    HGLOBAL hGlobal;
    char *recstr = NULL;
  
    while (true) {
        OpenClipboard(NULL); // 打开剪贴板，所属窗口为NULL
        if (hGlobal = GetClipboardData(CF_TEXT)) // 获取包含剪贴板内容的Win32内存块句柄（ANSI文本）
        {
            char *pGlobal = (char*)GlobalLock(hGlobal); // 锁定它并获得内存块指针
            if (recstr == NULL || lstrcmpA(pGlobal, recstr) != 0) // 如果获得了新的字符串
            {
                free(recstr); // 释放以前的字符串
                recstr = (char*)malloc(GlobalSize(hGlobal)); // 分配一个新的缓冲区
                if (recstr != NULL)
                {
                    lstrcpyA(recstr, pGlobal); // 复制新的字符串
                    fputs(recstr, stdout); // 显示该字符串
                }
            }
        }
        CloseClipboard(); // 关闭剪贴板
        Sleep(500); // 延时等待
    }
}
  
void clientW() // Unicode版剪贴板客户端（复制操作）
{
    DWORD content;
    wchar_t wbuf[200] = {0}; // wchar_t
    HGLOBAL hGlobal;
  
    while (true)
    {
        fgetws(wbuf, sizeof(wbuf)/sizeof(wchar_t), stdin); // fgetws sizeof(wchar_t)
          
        hGlobal = GlobalAlloc(GHND, (lstrlenW(wbuf) + 1) * sizeof(wchar_t)); // lstrlenW sizeof(wchar_t)
        wchar_t *pGlobal = (wchar_t*)GlobalLock(hGlobal); // wchar_t
        lstrcpyW(pGlobal, wbuf); // lstrcpyW
        GlobalUnlock(hGlobal);
  
        OpenClipboard(NULL);
        EmptyClipboard();
        SetClipboardData(CF_UNICODETEXT, hGlobal); // Unicode文本CF_UNICODETEXT
        CloseClipboard();
    }
}
  
void monitorW() // Unicode版剪贴板监视器（粘贴操作）
{
    DWORD content;
    HGLOBAL hGlobal;
    wchar_t *recstr = NULL; // wchar_t
  
    while (true) {
        OpenClipboard(NULL);
        if (hGlobal = GetClipboardData(CF_UNICODETEXT)) // Unicode文本CF_UNICODETEXT
        {
            wchar_t *pGlobal = (wchar_t *)GlobalLock(hGlobal); // wchar_t
            if (recstr == NULL || lstrcmpW(pGlobal, recstr) != 0) // lstrcmpW
            {
                free(recstr);
                recstr = (wchar_t*)malloc(GlobalSize(hGlobal)); // wchar_t
                if (recstr != NULL)
                {
                    lstrcpyW(recstr, pGlobal); // lstrcpyW
                    fputws(recstr, stdout); // fputws
                }
            }
        }
        CloseClipboard();
        Sleep(500);
    }
}
  
int main(int argc, char* argv[])
{
    char mode[2], charset[2];
      
    setlocale(LC_CTYPE, ""); // 获取系统的区域设定，显示wchar_t需要
  
    printf("模式（【m】onitor或【c】lient）：");
    scanf("%1s", mode);
    printf("字符集（【a】nsi或【u】nicode）：");
    scanf("%1s", charset);
  
    if (mode[0] == 'm') {
        if (charset[0] == 'a') {
            monitorA();
        } else {
            monitorW();
        }
    } else {
        if (charset[0] == 'a') {
            clientA();
        } else {
            clientW();
        }
    }
  
    return 0;
}
