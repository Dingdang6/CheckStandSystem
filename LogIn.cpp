#include "login.h"
#include "MainWnd.h"
#include "Common.h"

//xml�ļ���Ӧ��Ŀ¼
CDuiString LogInWnd::GetSkinFolder()
{
	return _T("");
}

//xml�ļ�������
CDuiString LogInWnd::GetSkinFile()
{
	return _T("LogInWnd.xml");
}

//���ش���������֣���ע�ᴰ�ڵ�ʱ���ṩ
LPCTSTR LogInWnd::GetWindowClassName(void) const
{
	return _T("LogInWnd");
}

void LogInWnd::Notify(TNotifyUI& msg)
{
	CDuiString strName = msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{
		if (strName == _T("BTN_MIN"))
		{
			//ʹ��ϵͳ�Դ��ķ���
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		else if(strName == _T("BTN_CLOSE"))
		{
			//����رպ�ֱ�ӽ����ڹر�
			Close();
		}
		else if (strName == _T("BTN_LOGIN"))
		{
			LogIn();
		}		
	}
}

void LogInWnd::LogIn()
{
	//�ӱ༭���ȡ�û���������
	CEditUI* pEditUserName = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_NAME"));
	CDuiString strUserName = pEditUserName->GetText();

	CEditUI* pEditPassword = (CEditUI*)m_PaintManager.FindControl(_T("EDIT_USER_PASSWORD"));
	CDuiString strUserPassword = pEditPassword->GetText();

	if (strUserName.IsEmpty())
	{
		MessageBox(m_hWnd, _T("�������û���"), _T("Cashier"), IDOK);
		return;
	}

	if (strUserPassword.IsEmpty())
	{
		MessageBox(m_hWnd, _T("����������"), _T("Cashier"), IDOK);
		return;
	}
	//��ѯ���ݿ⣬����û��Ƿ��ǺϷ��û�


	//��¼֮�����ص�¼����
	ShowWindow(false);


	//������½֮���������
	MainWnd mainWnd;
	mainWnd.Create(NULL, _T("MainWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	mainWnd.CenterWindow();
	mainWnd.ShowModal();

	

}