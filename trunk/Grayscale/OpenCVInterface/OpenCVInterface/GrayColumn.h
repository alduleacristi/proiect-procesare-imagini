#pragma once

// GrayColumn dialog

class GrayColumn : public CDialogEx
{
	DECLARE_DYNAMIC(GrayColumn)

public:
	GrayColumn(CWnd* pParent = NULL);   // standard constructor
	virtual ~GrayColumn();

// Dialog Data
	enum { IDD = IDD_GRAYCOLUMN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void CalcCol(int a[256],int xc);
private:
	int* v;
	int x;
	bool col;
	CWnd* parent;
public:
	afx_msg void OnClose();
};
