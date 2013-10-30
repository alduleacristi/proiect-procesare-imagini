#pragma once

// GrayRow dialog

class GrayRow : public CDialogEx
{
	DECLARE_DYNAMIC(GrayRow)

public:
	GrayRow(CWnd* pParent = NULL);   // standard constructor
	virtual ~GrayRow();

// Dialog Data
	enum { IDD = IDD_GRAYROW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void CalcRow(int a[256],int yc);
private:
	int *v;
	int y;
	bool row;
};
