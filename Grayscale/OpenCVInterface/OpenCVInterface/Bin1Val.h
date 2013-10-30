#pragma once


// Bin1Val dialog

class Bin1Val : public CDialogEx
{
	DECLARE_DYNAMIC(Bin1Val)

public:
	Bin1Val(CWnd* pParent = NULL);   // standard constructor
	virtual ~Bin1Val();

// Dialog Data
	enum { IDD = IDD_BINARIZATION1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int getT(void);
private:
	int t;
};
