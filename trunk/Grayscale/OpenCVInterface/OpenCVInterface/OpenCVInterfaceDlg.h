
// OpenCVInterfaceDlg.h : header file
//

#pragma once

#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include "ResultDlg.h"

#include<memory>

using namespace cv;
// COpenCVInterfaceDlg dialog

typedef std::auto_ptr<CResultDlg> CResultPtr;

class COpenCVInterfaceDlg : public CDialogEx
{
// Construction
public:
	COpenCVInterfaceDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~COpenCVInterfaceDlg();
// Dialog Data
	enum { IDD = IDD_OPENCVINTERFACE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

private:
	Mat mainImage;
	Mat prelImage;
	CBrush *ImageBrush;
	CResultPtr m_Result;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen32771();
	void ResetImageBrush(void);
	afx_msg void OnToolsInvert();
	Mat InitImage(int rows, int cols);

	//Loads the proceese image into the main frame
	void ShowResult(Mat result);
	
	void OnLoadPrelImage();
	afx_msg void OnFileSave32776();
};
