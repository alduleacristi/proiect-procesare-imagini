
// OpenCVInterfaceDlg.h : header file
//

#pragma once
//#include <vld.h>

#include <opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include "ResultDlg.h"
#include"Tools.h"
#include"GammaValue.h"
#include"MagnifierDlg.h"
#include"Bin1Val.h"
#include"Bin2Val.h"
#include"LumVal.h"
#include"Histogram.h"
#include"GrayRow.h"
#include"GrayColumn.h"
#include"Filters.h"
#include "ParametersDlg.h"
#include "MaskDlg.h"

#include<memory>
#include <algorithm>
#include <time.h>

using namespace cv;
// COpenCVInterfaceDlg dialog

typedef std::auto_ptr<CResultDlg> CResultPtr;
typedef std::auto_ptr<MagnifierDlg> MagnifierPtr;
typedef std::auto_ptr<GrayRow> GrayRowPtr;
typedef std::auto_ptr<GrayColumn> GrayColumnPtr;


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
	Mat result;
	CBrush *ImageBrush;
	CResultPtr m_Result;
	MagnifierPtr mag;
	GrayRowPtr gr;
	GrayColumnPtr gc;
	Mat CalculeazaFiltruMedian(int k);

	double Partitie(double v[], int st, int dr);
	double Statistica(double v[], int k, int st, int dr);
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
	afx_msg void OnFileSave32776();

	
	afx_msg void OnToolsInvert();

	Mat InitImage(int rows, int cols);
	void ResetImageBrush(void);
	
	//Loads the proceese image into the main frame
	void ShowResult(Mat result);
	void OnLoadPrelImage();
	
	afx_msg void OnToolsMagnifier();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnToolsBinarization();
	afx_msg void OnToolsBinarization2();
	afx_msg void OnLuminosityGammacorrection();
	afx_msg void OnLuminosityIncreaseluminosity();
	afx_msg void OnLuminosityDecreaseluminosity();
	afx_msg void OnLuminosityLogaritmicoperator();
	afx_msg void OnLuminosityInverselogaritmicoperator();
	afx_msg void OnToolsHistogram();
	afx_msg void OnToolsGraylevelrow();
	afx_msg void OnToolsGraylevelcolumn();
	afx_msg void OnFiltersGaussianfilter();
	afx_msg void OnContrastLogaritmicoperator();
	afx_msg void OnFiltersMedianfilter();
	afx_msg void OnContrastExponential();
	afx_msg void OnFiltersMedianFilterAnca();
	afx_msg void OnFiltersZeroCrossingsAnca();
};
