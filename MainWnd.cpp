
#include "MainWnd.h"

//xml�ļ���Ӧ��Ŀ¼
CDuiString MainWnd::GetSkinFolder() 
{
	return _T("");
}

//xml�ļ�������
CDuiString MainWnd::GetSkinFile()
{
	return _T("MainWnd.xml");
}

//���ش���������֣���ע�ᴰ�ڵ�ʱ���ṩ
LPCTSTR MainWnd::GetWindowClassName(void) const
{
	return _T("MainWnd");
}


void MainWnd::Notify(TNotifyUI& msg)
{
	CDuiString strName = msg.pSender->GetName();
	if (msg.sType == _T("click"))
	{		
		if (strName == _T("BTN_CLOSE"))
			Close();
		else if (strName == _T("BTN_MIN"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
		else if (strName == _T("BTN_MAX"))
			::SendMessage(m_hWnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);

		else if (strName == _T("BTN_SELECT"))
			MessageBox(m_hWnd, _T("SELECT"), _T("Cashier"), IDOK);
		else if (strName == _T("BTN_INSERT"))
			MessageBox(m_hWnd, _T("INSERT"), _T("Cashier"), IDOK);
		else if (strName == _T("BTN_UPDATE"))
			MessageBox(m_hWnd, _T("UPDATE"), _T("Cashier"), IDOK);
		else if (strName == _T("BTN_DELETE"))
			DeleteEmployeeInfo();
		else if (strName == _T("BTN_RECORD"))
			MessageBox(m_hWnd, _T("RECORD"), _T("Cashier"), IDOK);

		
	}

	else if (msg.sType == _T("selectchanged"))
	{
		CTabLayoutUI* pTab = (CTabLayoutUI*)m_PaintManager.FindControl(_T("TABLAYOUT_1"));
		if (strName == _T("OPTION_EMPLOYEE"))
		{
			pTab->SelectItem(0);
		}
		else
		{
			pTab->SelectItem(1);
		}
	}
	else if (msg.sType == _T("windowinit"))
	{
		CComboBoxUI* pSex = (CComboBoxUI*)m_PaintManager.FindControl(_T("USER_SEX"));
		pSex->SelectItem(0);

		CComboBoxUI* pPosition = (CComboBoxUI*)m_PaintManager.FindControl(_T("USER_POSITION"));
		pPosition->SelectItem(0);

	}


}

//
//void MainWnd::SelectEmployeeInfo()
//{
//	string strSQL("select * from employee");
//
//	CComboBoxUI* pCombo = (CComboBoxUI*)m_PaintManager.FindControl(_T("USER_SELECT"))->;
//	CDuiString strStyle = pCombo->GetText();
//	if (strStyle == _T("��"))
//		strSQL += ";";
//	else if (strStyle == _T("����"))
//	{
//		strSQL += " where Name = '";
//		CDuiString strName = ((CEditUI*)m_PaintManager.FindControl(_T("USE_NAME")));
//		if (strName.IsEmpty())
//		{
//			MessageBox(m_hWnd, _T("�������ѯ�û�������"), _T("Cashier"), IDOK);
//			return;
//		}
//
//		strSQL += UnicodeToANSI(strName);
//		strSQL += "';";
//	}
//	else if (strStyle == _T("�Ա�"))
//		;
//	else if (strStyle == _T("н��"))
//		;
//
//	vector<vector<string>> vRet = m_pMySQL->Select();
//	
//
//}
/*
void MainWnd::DeleteEmployeeInfo()
{
	// ��ȡ��ǰѡ�е�����
	CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("ListEmployee"));
	pListUI->RemoveAll();
	int lineNo = pListUI->GetCurSel();
	CListTextElementUI* pRow = (CListTextElementUI*)pListUI->GetItemAt(lineNo);


	// �����ݿ��н���Ա������Ϣɾ��
	//����SQL����
	string strSQL("delete ");
	
	CDuiString strName = pRow->GetText(0);

	//�����ݿ��н�������¼ɾ��
	//m_pMySQL->Delete(strSQL);

	//��List�н���Ϣ�Ƴ�
	pListUI->RemoveAt(lineNo);
}*/

/*
void MainWnd::InsertEmployeeInfo()
{
	//�ӽ����л�ȡԱ����Ϣ
	 CDuiString strName = ((CEditUI*)m_PaintManager.FindControl(_T("USE_NAME")))->GetText();
	 CDuiString strGender = ((CComboBoxUI*)m_PaintManager.FindControl(_T("USER_SEX")))->GetText();
	 CDuiString strBirthday = ((CEditUI*)m_PaintManager.FindControl(_T("USER_BRITHDAY")))->GetText();
	 CDuiString strPosition = ((CComboBoxUI*)m_PaintManager.FindControl(_T("USER_POSITION")))->GetText();
	 CDuiString strTel = ((CEditUI*)m_PaintManager.FindControl(_T("USER_TAL")))->GetText();
	 CDuiString strSalary = ((CEditUI*)m_PaintManager.FindControl(_T("USER_SALARY")))->GetText();

	//����SQL����
	 string strSQL("insert into employee values(name='");
	 strSQL += UnicodeToANSI(strName);
	 strSQL += "',Gender='";
	 strSQL += UnicodeToANSI(strGender);
	 strSQL += "',Birthday='";
	 strSQL += UnicodeToANSI(strBirthday);
	 strSQL += "',password='000000',position='";
	 strSQL += UnicodeToANSI(strPosition);
	 strSQL += "',telphone='";
	 strSQL += UnicodeToANSI(strTel);
	 strSQL += "',salary='";
	 strSQL += "');";

	//��ӦSQL����
	 m_pMySQL->Insert(strSQL);

	//��Ա����Ϣ����List
	 CListTextElementUI* pItem = new CListTextElementUI;
	 CListUI* pListUI = (CListUI*)m_PaintManager.FindControl(_T("ListEmployee"));
	 pListUI->AddAt(pItem);
	 pItem->SetText(0, strName);
	 pItem->SetText(1, strGender);
	 pItem->SetText(2, strBirthday);
	 pItem->SetText(3, strPosition);
	 pItem->SetText(4, strTel);
	 pItem->SetText(5, strSalary);
}*/
