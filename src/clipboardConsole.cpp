// ClipboardConsole.cpp : �������̨Ӧ�ó������ڵ㡣
//
  

  
#include <windows.h>
#include <stdio.h>
#include <locale.h>
  
void clientA() // ANSI�������ͻ��ˣ����Ʋ�����
{
    DWORD content;
    char buf[200] = {0};
    HGLOBAL hGlobal;
  
    while (true)
    {
        fgets(buf, sizeof(buf), stdin); // ��ȡ������ַ���
  
        hGlobal = GlobalAlloc(GPTR, (lstrlenA(buf) + 1)); // �½�һ��Win32�ڴ��
        char *pGlobal = (char*)GlobalLock(hGlobal); // ��������ȡ����ָ��
        lstrcpyA(pGlobal, buf); // ���ַ������Ƶ������ϱ�
        GlobalUnlock(hGlobal); // �ͷ��ڴ������Ȩ
  
        OpenClipboard(NULL); // �򿪼����壨ӵ���ߴ���ΪNULL��
        EmptyClipboard(); // ���
        SetClipboardData(CF_TEXT, hGlobal); // �����Ѹ��Ƶ�hGlobal�е�ANSI�ı�
        CloseClipboard(); // �رռ�����
    }
}
  
void monitorA() // ANSI��������������ճ��������
{
    DWORD content;
    HGLOBAL hGlobal;
    char *recstr = NULL;
  
    while (true) {
        OpenClipboard(NULL); // �򿪼����壬��������ΪNULL
        if (hGlobal = GetClipboardData(CF_TEXT)) // ��ȡ�������������ݵ�Win32�ڴ������ANSI�ı���
        {
            char *pGlobal = (char*)GlobalLock(hGlobal); // ������������ڴ��ָ��
            if (recstr == NULL || lstrcmpA(pGlobal, recstr) != 0) // ���������µ��ַ���
            {
                free(recstr); // �ͷ���ǰ���ַ���
                recstr = (char*)malloc(GlobalSize(hGlobal)); // ����һ���µĻ�����
                if (recstr != NULL)
                {
                    lstrcpyA(recstr, pGlobal); // �����µ��ַ���
                    fputs(recstr, stdout); // ��ʾ���ַ���
                }
            }
        }
        CloseClipboard(); // �رռ�����
        Sleep(500); // ��ʱ�ȴ�
    }
}
  
void clientW() // Unicode�������ͻ��ˣ����Ʋ�����
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
        SetClipboardData(CF_UNICODETEXT, hGlobal); // Unicode�ı�CF_UNICODETEXT
        CloseClipboard();
    }
}
  
void monitorW() // Unicode��������������ճ��������
{
    DWORD content;
    HGLOBAL hGlobal;
    wchar_t *recstr = NULL; // wchar_t
  
    while (true) {
        OpenClipboard(NULL);
        if (hGlobal = GetClipboardData(CF_UNICODETEXT)) // Unicode�ı�CF_UNICODETEXT
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
      
    setlocale(LC_CTYPE, ""); // ��ȡϵͳ�������趨����ʾwchar_t��Ҫ
  
    printf("ģʽ����m��onitor��c��lient����");
    scanf("%1s", mode);
    printf("�ַ�������a��nsi��u��nicode����");
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
