#include "Common.h"


class LogInWnd : public WindowImplBase
{
public:
	virtual void Notify(TNotifyUI& msg);
	void LogIn();
   
protected:
	// WindowImplBase �ṩ�Ĵ��麯��
	//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString GetSkinFolder();

	//xml�ļ�������
	virtual CDuiString GetSkinFile();

	//���ش���������֣���ע�ᴰ�ڵ�ʱ���ṩ
	virtual LPCTSTR GetWindowClassName(void) const;

};