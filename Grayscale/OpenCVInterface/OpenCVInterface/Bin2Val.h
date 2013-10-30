#pragma once


// Bin2Val dialog

class Bin2Val : public CDialogEx
{
	DECLARE_DYNAMIC(Bin2Val)

public:
	Bin2Val(CWnd* pParent = NULL);   // standard constructor
	virtual ~Bin2Val();

// Dialog Data
	enum { IDD = IDD_BINARIAZATION2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int t1;
	int t2;
public:
	afx_msg void OnBnClickedOk();
	int getT1(void);
	int getT2(void);
};
