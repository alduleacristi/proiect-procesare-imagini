#pragma once

#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace cv;
// CResultDlg dialog

class CResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(Mat image,CWnd* pParent = NULL);   // standard constructor
	virtual ~CResultDlg();

// Dialog Data
	enum { IDD = IDD_RESULT };
private:
	Mat thisImage;
	CBrush *ImageBrush;
	CWnd* m_parent;

protected:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnFileLoadintomainframe();

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnFileSave32772();
};
