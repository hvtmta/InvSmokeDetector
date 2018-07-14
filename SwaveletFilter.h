#ifndef _SWAVELET_H_
#define _SWAVELET_H_

#include "stdlib.h"
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h>
#include <iostream>
#include <math.h>
#include "constants.h"
#include <fstream>
using namespace std;
class SwaveletFilter
{
public:
	int framecount;
	CvRect* rectSeq;
	int seqNum;
	int* Mark;
	int  fireBlockNum;
	CvMat *pSwaveletMat;
	CvMat *pEnergyImg;

	//In order to facilitate parameter access, the following variables are the main parameters of the InvFireDetector.
	int blockRowNum,blockColumnNum;
  int *blockMark;
  CvRect* blockSeq;
	//***********************************************************

	SwaveletFilter();
	void init(IplImage* pFrame,const char* wavename="haar",int layer=1);
	void show();
	void nextImage(IplImage *pFrame);
	void setRectSeq(CvRect* rectseq, int Num,int* rectMark);
	void setBlockVar(CvRect* blockseq,int* blockmark,int blockrownum,int blockcolumnnum);
	void WaveletAnalysis(CvMat *pImage, CvMat* pMatenergy);
	void filter(CvMat *pFrameCur,CvMat *pBackGround,CvRect *rectSeq,int rectNum);
	void blockFilter(CvMat *pFrameCur);

	void release();

	void makeCore(float* hd,float* ld,int num);
	void getFilter(const char* wavename);
	CvMat* zeroPadding(CvMat* img,int left,int right,int top,int bottom);
	CvMat *pBackground;
	ofstream fout;
private:
	CvMat* ll;
	CvMat* hh;
	CvMat* lh;
	CvMat* hl;

	int     level;

	CvMat *pFrameMat;
	CvMat *pFrameGray;
	
	IplImage* pCurFrame;
	IplImage *showImg;
	
	float SCALE;

};

#endif