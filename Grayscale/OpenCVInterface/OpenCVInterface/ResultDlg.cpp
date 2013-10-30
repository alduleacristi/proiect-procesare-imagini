// ResultDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "ResultDlg.h"
#include "afxdialogex.h"


// CResultDlg dialog

IMPLEMENT_DYNAMIC(CResultDlg, CDialogEx)

CResultDlg::CResultDlg(Mat image,CWnd* pParent /*=NULL*/)
	: CDialogEx(CResultDlg::IDD, pParent)
	, thisImage(image)
	, ImageBrush(NULL)
	, m_parent(pParent)
{

}

CResultDlg::~CResultDlg()
{
	if(ImageBrush)
	 delete ImageBrush;
}

void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CResultDlg, CDialogEx)
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_LOADINTOMAINFRAME, &CResultDlg::OnFileLoadintomainframe)
	ON_COMMAND(ID_FILE_SAVE32772, &CResultDlg::OnFileSave32772)
END_MESSAGE_MAP()

BOOL CResultDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CBitmap bmpB;
	int nrPixels=thisImage.cols*thisImage.rows;
	COLORREF *RGB_buffer=new COLORREF[nrPixels];
	for(int x=0;x<nrPixels;x++)
	{
		int i=x/thisImage.cols;
		int j=x%thisImage.cols;
		//RGB_buffer[x]=RGB(thisImage.at<Vec3b>(i,j)[0],thisImage.at<Vec3b>(i,j)[1],thisImage.at<Vec3b>(i,j)[2]);
		RGB_buffer[x]=RGB(thisImage.at<uchar>(i,j),thisImage.at<uchar>(i,j),thisImage.at<uchar>(i,j));
	}
	
	
	bmpB.CreateBitmap(thisImage.cols,thisImage.rows,4,8,RGB_buffer);
	
	delete []RGB_buffer;
	
	ImageBrush=new CBrush(&bmpB);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CResultDlg::OnPaint()
{
		CPaintDC dc(this); // device context for painting

		//In variabila r1 pastrez dimensiunile ferestrei picture1
		CRect r1;
		GetClientRect(&r1);

		int w,h;
		
		//aleg minimul dintre dimensiunile imag si ale ferestrei de afisare
		if(thisImage.cols<r1.Width()) w=thisImage.cols;
		else w=r1.Width();
		if(thisImage.rows<r1.Height()) h=thisImage.rows;
		else h=r1.Height();
	
			//creez un dreptunghi cu dimensiunile minime si il umplu cu peria imagine
		CRect r(0,0,w-1,h-1);
		dc.FillRect(r,ImageBrush);
	}

void CResultDlg::OnFileLoadintomainframe()
{
	m_parent->SendMessageA(WM_COMMAND,ID_LOAD_IM);
	EndDialog(TRUE);
}

void CResultDlg::OnFileSave32772()
{
	CFileDialog fSaveDlg(FALSE, "bmp", "", OFN_HIDEREADONLY, "Bitmap Files (*.bmp)|*.bmp||", NULL);
	CFile m_dataFile;
	
	if(fSaveDlg.DoModal()==IDOK)
	{
		CString s=fSaveDlg.GetPathName();
		PSTR szFileName=strdup(s);
		imwrite(szFileName,thisImage);	
	}
}