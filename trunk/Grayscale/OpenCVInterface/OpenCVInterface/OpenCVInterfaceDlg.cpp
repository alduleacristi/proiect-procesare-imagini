
// OpenCVInterfaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OpenCVInterface.h"
#include "OpenCVInterfaceDlg.h"
#include "afxdialogex.h"
#include "ContrastPolinomial.h"
#include "MedianFilter.h"
#include "FiltruMedianCristi.h"
#include "CannyOperator.h"
#include <vector>

#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// COpenCVInterfaceDlg dialog

COpenCVInterfaceDlg::COpenCVInterfaceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpenCVInterfaceDlg::IDD, pParent)
	, ImageBrush(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpenCVInterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpenCVInterfaceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_OPEN32771, &COpenCVInterfaceDlg::OnFileOpen32771)
	ON_COMMAND(ID_TOOLS_INVERT, &COpenCVInterfaceDlg::OnToolsInvert)
	ON_COMMAND(ID_LOAD_IM, &COpenCVInterfaceDlg::OnLoadPrelImage)
	ON_COMMAND(ID_FILE_SAVE32776, &COpenCVInterfaceDlg::OnFileSave32776)
	ON_COMMAND(ID_TOOLS_MAGNIFIER, &COpenCVInterfaceDlg::OnToolsMagnifier)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_TOOLS_BINARIZATION, &COpenCVInterfaceDlg::OnToolsBinarization)
	ON_COMMAND(ID_TOOLS_BINARIZATION2, &COpenCVInterfaceDlg::OnToolsBinarization2)
	ON_COMMAND(ID_LUMINOSITY_GAMMACORRECTION, &COpenCVInterfaceDlg::OnLuminosityGammacorrection)
	ON_COMMAND(ID_LUMINOSITY_INCREASELUMINOSITY, &COpenCVInterfaceDlg::OnLuminosityIncreaseluminosity)
	ON_COMMAND(ID_LUMINOSITY_DECREASELUMINOSITY, &COpenCVInterfaceDlg::OnLuminosityDecreaseluminosity)
	ON_COMMAND(ID_LUMINOSITY_LOGARITMICOPERATOR, &COpenCVInterfaceDlg::OnLuminosityLogaritmicoperator)
	ON_COMMAND(ID_LUMINOSITY_INVERSELOGARITMICOPERATOR, &COpenCVInterfaceDlg::OnLuminosityInverselogaritmicoperator)
	ON_COMMAND(ID_TOOLS_HISTOGRAM, &COpenCVInterfaceDlg::OnToolsHistogram)
	ON_COMMAND(ID_TOOLS_GRAYLEVELROW, &COpenCVInterfaceDlg::OnToolsGraylevelrow)
	ON_COMMAND(ID_TOOLS_GRAYLEVELCOLUMN, &COpenCVInterfaceDlg::OnToolsGraylevelcolumn)
	ON_COMMAND(ID_FILTERS_GAUSSIANFILTER, &COpenCVInterfaceDlg::OnFiltersGaussianfilter)
	ON_COMMAND(ID_CONTRAST_LOGARITMICOPERATOR, &COpenCVInterfaceDlg::OnContrastLogaritmicoperator)
	ON_COMMAND(ID_CONTRAST_LOGARITMICOPERATOR, &COpenCVInterfaceDlg::OnContrastLogaritmicoperator)
	ON_COMMAND(ID_FILTERS_MEDIANFILTER, &COpenCVInterfaceDlg::OnFiltersMedianfilter)
	ON_COMMAND(ID_FILTERS_CANNYOPERATOR, &COpenCVInterfaceDlg::OnFiltersCannyoperator)
END_MESSAGE_MAP()

// COpenCVInterfaceDlg message handlers

BOOL COpenCVInterfaceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COpenCVInterfaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void COpenCVInterfaceDlg::ResetImageBrush(void)
{
	CBitmap bmpB;
	int nrPixels=mainImage.cols*mainImage.rows;
	COLORREF *RGB_buffer=new COLORREF[nrPixels];
	for(int x=0;x<nrPixels;x++)
	{
		int i=x/mainImage.cols;
		int j=x%mainImage.cols;
		//RGB_buffer[x]=RGB(mainImage.at<Vec3b>(i,j)[0],mainImage.at<Vec3b>(i,j)[1],mainImage.at<Vec3b>(i,j)[2]);
		RGB_buffer[x]=RGB(mainImage.at<uchar>(i,j),mainImage.at<uchar>(i,j),mainImage.at<uchar>(i,j));
	}


	bmpB.CreateBitmap(mainImage.cols,mainImage.rows,4,8,RGB_buffer);
	
	delete []RGB_buffer;

	if(ImageBrush) 
		delete ImageBrush;

	ImageBrush=new CBrush(&bmpB);
}

void COpenCVInterfaceDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//In variabila r1 pastrez dimensiunile ferestrei picture1
	CRect r1;
	GetClientRect(&r1);

	int w,h;

	if(mainImage.cols)
	{
		//aleg minimul dintre dimensiunile imag si ale ferestrei de afisare
		if(mainImage.cols<r1.Width()) w=mainImage.cols;
		else w=r1.Width();
		if(mainImage.rows<r1.Height()) h=mainImage.rows;
		else h=r1.Height();

		//creez un dreptunghi cu dimensiunile minime si il umplu cu peria imagine
		CRect r(0,0,w-1,h-1);
		dc.FillRect(r,ImageBrush);

	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COpenCVInterfaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COpenCVInterfaceDlg::OnFileOpen32771()
{
	CFileDialog fOpenDlg(TRUE, "bmp", "", OFN_HIDEREADONLY|OFN_FILEMUSTEXIST, "Bitmap Files (*.bmp)|*.bmp||", NULL);
	CFile m_dataFile;

	if(fOpenDlg.DoModal()==IDOK)
	{
		CString s=fOpenDlg.GetPathName();

		PSTR szFileName=strdup(s);

		//IplImage* img  = cvLoadImage(szFileName); 
		Mat temp;
		//temp=imread(szFileName,CV_LOAD_IMAGE_ANYDEPTH |CV_LOAD_IMAGE_COLOR);
		//temp=imread(szFileName,CV_LOAD_IMAGE_UNCHANGED);
		temp=imread(szFileName,CV_LOAD_IMAGE_GRAYSCALE);
		if(temp.cols>0)
		{
			mainImage=temp;
			ResetImageBrush();
			Invalidate();
		}
		else 
			AfxMessageBox("error in opening file");
	}
}

void COpenCVInterfaceDlg::OnFileSave32776()
{
	CFileDialog fSaveDlg(FALSE, "bmp", "", OFN_HIDEREADONLY, "Bitmap Files (*.bmp)|*.bmp||", NULL);
	CFile m_dataFile;

	if(fSaveDlg.DoModal()==IDOK)
	{
		CString s=fSaveDlg.GetPathName();
		PSTR szFileName=strdup(s);
		imwrite(szFileName,mainImage);	
	}
}

Mat COpenCVInterfaceDlg::InitImage(int rows, int cols)
{
	//Mat rez(rows,cols,CV_8UC3,Scalar(0,0,0));
	Mat rez(rows,cols,CV_8UC1,Scalar(0));
	return rez;
}

void COpenCVInterfaceDlg::ShowResult(Mat result)
{
	m_Result=CResultPtr(new CResultDlg(prelImage,this));
	m_Result->Create(CResultDlg::IDD,0);
	m_Result->ShowWindow(SW_SHOW);
}

void COpenCVInterfaceDlg::OnLoadPrelImage()
{
	mainImage=prelImage;
	ResetImageBrush();
	Invalidate();
}

void COpenCVInterfaceDlg::OnToolsInvert()
{
	if(mainImage.cols)
	{
		prelImage=InitImage(mainImage.rows,mainImage.cols);
		for(int i=0;i<mainImage.rows;i++)
			for(int j=0;j<mainImage.cols;j++)
			{
				prelImage.at<uchar>(i,j)=255-mainImage.at<uchar>(i,j);
			}

			ShowResult(prelImage);
	}
	else
		MessageBox("No image loaded");
}

COpenCVInterfaceDlg::~COpenCVInterfaceDlg()
{
	if(ImageBrush) 
		delete ImageBrush;
}

void COpenCVInterfaceDlg::OnToolsMagnifier()
{
	if(mainImage.cols)
	{
		mag=MagnifierPtr(new MagnifierDlg(this));

		mag->Create(MagnifierDlg::IDD,0);

		mag->ShowWindow(SW_SHOW);
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnToolsGraylevelrow()
{
	/*if(mainImage.cols)
	{
		gr=GrayRowPtr(new GrayRow(this));

		gr->Create(GrayRow::IDD,0);

		gr->ShowWindow(SW_SHOW);
	}
	else
		MessageBox("No image loaded");*/
}

void COpenCVInterfaceDlg::OnToolsGraylevelcolumn()
{
	/*if(mainImage.cols)
	{
		gc=GrayColumnPtr(new GrayColumn(this));

		gc->Create(GrayColumn::IDD,0);

		gc->ShowWindow(SW_SHOW);
	}
	else
		MessageBox("No image loaded");*/
}

void COpenCVInterfaceDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	//if(gc.get())
	//{
	//	gc->CalcCol(Tools::calcCol(mainImage,point.x),point.x);
	//	Point p1;
	//	p1.x=point.x;
	//	p1.y=0;
	//	Point p2;
	//	p2.x=point.x;
	//	p2.y=mainImage.rows;
	//	line(mainImage,p1,p2,RGB(0,255,0));
	//	gc->Invalidate();
	//	
	//}

	//if(gr.get())
	//{
	//	gr->CalcRow(Tools::calcRow(mainImage,point.y),point.y);
	//	Point p1;
	//	p1.x=0;
	//	p1.y=point.y;
	//	Point p2;
	//	p2.x=mainImage.cols;
	//	p2.y=point.y;
	//	line(mainImage,p1,p2,RGB(0,255,0));
	//	gr->Invalidate();
	//	
	//}

	if(mag.get())
	{	
		mag->Zoom(Tools::zoom(mainImage,point.y,point.x));
		mag->Invalidate();
		//mag.release();
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void COpenCVInterfaceDlg::OnToolsBinarization()
{
	if(mainImage.cols)
	{
		Bin1Val dlg;
		INT_PTR nRet=dlg.DoModal();
		if(nRet==IDOK)
		{
			int T=dlg.getT();
			prelImage=Tools::binarization(mainImage,T);
			ShowResult(prelImage);
		}
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnToolsBinarization2()
{
	if(mainImage.cols)
	{
		Bin2Val dlg;
		INT_PTR nRet=dlg.DoModal();
		if(nRet==IDOK)
		{
			int T1=dlg.getT1();
			int T2=dlg.getT2();
			prelImage=Tools::binarization2(mainImage,T1,T2);
			ShowResult(prelImage);
		}
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnLuminosityGammacorrection()
{
	if(mainImage.cols)
	{
		GammaValue dlg;
		INT_PTR nRet=dlg.DoModal();
		if(nRet==IDOK)
		{
			double g=dlg.getGamma();
			prelImage=Tools::gammaCorrection(mainImage,g);
			ShowResult(prelImage);
		}
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnLuminosityIncreaseluminosity()
{
	if(mainImage.cols)
	{
		LumVal dlg;
		INT_PTR nRet=dlg.DoModal();
		if(nRet==IDOK)
		{

			int b=dlg.getB();
			prelImage=Tools::increaseLuminosity(mainImage,b);
			ShowResult(prelImage);
		}
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnLuminosityDecreaseluminosity()
{
	if(mainImage.cols)
	{
		LumVal dlg;
		INT_PTR nRet=dlg.DoModal();
		if(nRet==IDOK)
		{

			int b=dlg.getB();
			prelImage=Tools::decreaseLuminosity(mainImage,b);
			ShowResult(prelImage);
		}
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnLuminosityLogaritmicoperator()
{
	if(mainImage.cols)
	{
		prelImage=Tools::logaritm(mainImage);
		ShowResult(prelImage);
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnLuminosityInverselogaritmicoperator()
{
	if(mainImage.cols)
	{
		prelImage=Tools::inverseLogaritm(mainImage);
		ShowResult(prelImage);
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnToolsHistogram()
{
	if(mainImage.cols)
	{
		Histogram dlg;
		dlg.setHisto(Tools::calcHisto(mainImage));
		dlg.DoModal();
	}
	else
		MessageBox("No image loaded");
}

void COpenCVInterfaceDlg::OnFiltersGaussianfilter()
{
	/*if(mainImage.cols)
	{
		Sigma dlg;
		INT_PTR nRet=dlg.DoModal();
		if(nRet==IDOK)
		{
			double s;
			s=dlg.getSigma();

<<<<<<< .mine
		prelImage=Filters::gaussianFilter(mainImage,0.5);
		ShowResult(prelImage);
=======
			prelImage=Filters::gaussianFilter(mainImage,s);
			ShowResult(prelImage);
		}
>>>>>>> .r20
	}
	else
		MessageBox("No image loaded");*/
}

void COpenCVInterfaceDlg::OnContrastLogaritmicoperator()
{
	double *LookUp ;
	LookUp = CreateLookUpForContrast();
	prelImage=InitImage(mainImage.rows,mainImage.cols);
	for(int i=0;i<mainImage.rows;i++)
		for(int j=0;j<mainImage.cols;j++)
		{
			prelImage.at<uchar>(i,j)=LookUp[mainImage.at<uchar>(i,j)];
		}
	ShowResult(prelImage);
	delete LookUp;
}

Mat COpenCVInterfaceDlg::CalculeazaFiltruMedian(int k)
{
	int* v = new int[k*k];
	int n=mainImage.rows,m=mainImage.cols;
	prelImage=InitImage(n,m);

	for(int i=k/2;i<n -k/2;i++)
		for(int j=k/2;j<m -k/2;j++){
			int poz=0;
			for(int i2=i-k/2;i2<i+k/2;i2++)
				for(int j2=j-k/2;j2<j+k/2;j2++)
					v[poz++]=mainImage.at<uchar>(i2,j2);
			int aux = statistici(poz/2,0,poz-1,v);
			prelImage.at<uchar>(i,j)=aux;
		}

		return prelImage;

	delete v;
}


void COpenCVInterfaceDlg::OnFiltersMedianfilter()
{
	int n=mainImage.rows,m=mainImage.cols;
	prelImage=InitImage(n,m);
	int k;
	FiltruMedianCristi obj;
	if(obj.DoModal())
	{
		k = obj.getVal();
		prelImage = CalculeazaFiltruMedian(k);
		ShowResult(prelImage);
	}
	
}

void COpenCVInterfaceDlg::OnFiltersCannyoperator()
{
	int n=mainImage.rows,m2=mainImage.cols;
	prelImage=InitImage(n,m2);
	//prelImage = CalculeazaFiltruMedian(3);

	std::vector<std::vector <int>> rezSx,rezSy;


	int l=1,h=1,hi=mainImage.rows,li=mainImage.cols;
	int m[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};

	for(int x=h;x<hi-h;x++)
	{
		std::vector<int> aux;
		for(int y=l;y<li-l;y++)
		{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

			int c=0,nr=0;
			for(int i=-h;i<=h;i++)
			{
				for(int j=-l;j<=l;j++){
					nr++;
					c=c+mainImage.at<uchar>(x+i,y+j)*m[i+h][j+l];
				}
			}
			aux.push_back(c);
			if(c<0)
				c=0;
			else
				if(c>255)
					c=255;
			
			prelImage.at<uchar>(x,y)=c;
		}
		rezSy.push_back(aux);
	}
	//ShowResult(prelImage);

	l=1,h=1,hi=mainImage.rows,li=mainImage.cols;
	int m3[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};

	for(int x=h;x<hi-h;x++)
	{
		std::vector<int> aux;
		for(int y=l;y<li-l;y++)
		{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        

			double c=0.0;
			for(int i=-h;i<=h;i++)
			{
				for(int j=-l;j<=l;j++)
					c=c+mainImage.at<uchar>(x+i,y+j)*m3[i+h][j+l];
			}

			aux.push_back(c);
			if(c<0)
				c=0;
			else
				if(c>255)
					c=255;
			//prelImage.at<uchar>(x,y)=c;
			
		}
		rezSx.push_back(aux);
	}
	
	std::vector<std::vector<double>> gradient = CalculeazaGradient(rezSx,rezSy);

	for(int i=1;i<rezSx.size()-1;i++)
		for(int j=1;j<rezSx[0].size()-1;j++)
		{
			int dir = DeterminaDirectie(rezSx[i][j],rezSy[i][j]);

			if(dir == 1)
			{
				double max = 0.0;

				if(gradient[i][j] > max)
					max = gradient[i][j];

				if(gradient[i-1][j] > max)
					max = gradient[i-1][j];

				if( gradient[i+1][j] > max)
					max = gradient[i+1][j]; 

				if(gradient[i][j] == max){
					gradient[i-1][j] = 0;
					gradient[i+1][j] = 0;
				}else if(gradient[i-1][j] == max){
					gradient[i+1][j] = 0;
					gradient[i][j] = 0;
				}else if(gradient[i+1][j] == max){
					gradient[i][j] = 0;
					gradient[i-1][j] = 0;
				}
			}

			if(dir == 2)
			{
				double max = 0.0;

				if(gradient[i][j] > max)
					max = gradient[i][j];

				if(gradient[i-1][j-1] > max)
					max = gradient[i-1][j-1];

				if( gradient[i+1][j+1] > max)
					max = gradient[i+1][j+1]; 

				if(gradient[i][j] == max){
					gradient[i-1][j-1] = 0;
					gradient[i+1][j+1] = 0;
				}else if(gradient[i-1][j-1] == max){
					gradient[i+1][j+1] = 0;
					gradient[i][j] = 0;
				}else if(gradient[i+1][j+1] == max){
					gradient[i][j] = 0;
					gradient[i-1][j-1] = 0;
				}
			}

			if(dir == 3)
			{
				double max = 0.0;

				if(gradient[i][j] > max)
					max = gradient[i][j];

				if(gradient[i][j-1] > max)
					max = gradient[i][j-1];

				if( gradient[i][j+1] > max)
					max = gradient[i][j+1]; 

				if(gradient[i][j] == max){
					gradient[i][j-1] = 0;
					gradient[i][j+1] = 0;
				}else if(gradient[i][j-1] == max){
					gradient[i][j+1] = 0;
					gradient[i][j] = 0;
				}else if(gradient[i][j+1] == max){
					gradient[i][j] = 0;
					gradient[i][j-1] = 0;
				}
			}

			if(dir == 4)
			{
				double max = 0.0;

				if(gradient[i][j] > max)
					max = gradient[i][j];

				if(gradient[i-1][j+1] > max)
					max = gradient[i-1][j+1];

				if( gradient[i+1][j-1] > max)
					max = gradient[i+1][j-1]; 

				if(gradient[i][j] == max){
					gradient[i+1][j-1] = 0;
					gradient[i-1][j+1] = 0;
				}else if(gradient[i+1][j-1] == max){
					gradient[i-1][j+1] = 0;
					gradient[i][j] = 0;
				}else if(gradient[i-1][j+1] == max){
					gradient[i][j] = 0;
					gradient[i+1][j-1] = 0;
				}
			}
		}

	for(int i=0;i<rezSx.size();i++)
		for(int j=0;j<rezSx[0].size();j++)
			if(gradient[i][j] < 0)
				prelImage.at<uchar>(i,j) = 0;
			else 
				if(gradient[i][j] > 255)
					prelImage.at<uchar>(i,j) = 255;
				else
					prelImage.at<uchar>(i,j) = gradient[i][j];
	
	for(int i=0;i<rezSx.size();i++)
		for(int j=0;j<rezSx[0].size();j++)
			if(prelImage.at<uchar>(i,j) < 60)
				prelImage.at<uchar>(i,j) = 0;
			else
				if(prelImage.at<uchar>(i,j) > 100)
					prelImage.at<uchar>(i,j) = 255;

	for(int i=1;i<rezSx.size()-1;i++)
		for(int j=1;j<rezSx[0].size()-1;j++)
		{
			if(prelImage.at<uchar>(i,j) != 255 && prelImage.at<uchar>(i,j) != 0)
			{
				bool ok = false;
				for(int y=-1;y<=1;y++)
					for(int x=-1;x<=1;x++)
						if(prelImage.at<uchar>(i+y,j+x) = 255)
						{
							ok = true;
							break;
						}
				if(ok)
					prelImage.at<uchar>(i,j) = 255;
			}
		}

	ShowResult(prelImage);

	//ScrieLaFisier("Rezultat.txt",gradient,n,m2);
}
