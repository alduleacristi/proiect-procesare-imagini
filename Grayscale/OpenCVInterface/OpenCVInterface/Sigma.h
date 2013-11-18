#pragma once


// Sigma dialog

class Sigma : public CDialogEx
{
	DECLARE_DYNAMIC(Sigma)

public:
	Sigma(CWnd* pParent = NULL);   // standard constructor
	virtual ~Sigma();

// Dialog Data
	enum { IDD = IDD_SIGMA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	double si;
public:
	double getSigma();
	afx_msg void OnBnClickedOk();
};
