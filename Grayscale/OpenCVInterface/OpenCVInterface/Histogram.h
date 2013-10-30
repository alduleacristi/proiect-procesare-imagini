#pragma once


// Histogram dialog

class Histogram : public CDialogEx
{
	DECLARE_DYNAMIC(Histogram)

public:
	Histogram(CWnd* pParent = NULL);   // standard constructor
	virtual ~Histogram();

// Dialog Data
	enum { IDD = IDD_HISTOGRAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
private:
	int* v;
	bool h;
public:
	void setHisto(int a[256]);
};
