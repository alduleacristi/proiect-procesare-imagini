#pragma once


// GammaValue dialog

class GammaValue : public CDialogEx
{
	DECLARE_DYNAMIC(GammaValue)

public:
	GammaValue(CWnd* pParent = NULL);   // standard constructor
	virtual ~GammaValue();

// Dialog Data
	enum { IDD = IDD_GAMMAVAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	double gamma;
public:
	afx_msg void OnBnClickedOk();
	double getGamma(void);
};
