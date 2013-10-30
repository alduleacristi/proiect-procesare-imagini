#pragma once
#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include"Tools.h"
// MagnifierDlg dialog
#include<memory>

using namespace cv;

class MagnifierDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MagnifierDlg)

public:
	MagnifierDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~MagnifierDlg();

// Dialog Data
	enum { IDD = IDD_MAGNIFIER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();

private:
	Mat rezim;
	Mat im;
public:
	void SetImage(Mat& img);
	void Zoom(Mat& im);
};
