#pragma once
//#include "MySQL.h"
#include "Common.h"


class MainWnd : public WindowImplBase
{
//public:
//	MainWnd(MySQL* pMySQL);
//	~MainWnd();

	virtual void Notify(TNotifyUI& msg);


protected:
	// WindowImplBase �ṩ�Ĵ��麯��
	//xml�ļ���Ӧ��Ŀ¼
	virtual CDuiString GetSkinFolder();

	//xml�ļ�������
	virtual CDuiString GetSkinFile();

	//���ش���������֣���ע�ᴰ�ڵ�ʱ���ṩ
	virtual LPCTSTR GetWindowClassName(void) const;

	void SelectEmployeeInfo();

	void DeleteEmployeeInfo();

	void InsertEmployeeInfo();

//private:
//	MySQL* m_pMySQL;
};