#pragma once
#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace cv;

// GrayRow dialog

class GrayRow : public CDialogEx
{
	DECLARE_DYNAMIC(GrayRow)

public:
	GrayRow(Mat image,CWnd* pParent = NULL);   // standard constructor
	virtual ~GrayRow();

// Dialog Data
	enum { IDD = IDD_GRAYROW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void CalcRow(int a[256],int yc,int c, int r);
	void SetCoord(int x, int y);
private:
	Mat m_image;
	int x_coord;
	int y_coord;
	int *grey_lev;
	CWnd* parent;

	bool gcheck;
public:
	void setGCheck(bool check);
	bool getGCheck(void);
	int GetY(void);
	int GetX(void);
};
