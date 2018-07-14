#include <stdlib.h>
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h> //Must include this header
#include <iostream>
#include <math.h>

class ColorFilter
{
	IplImage* curImg;
	IplImage* firImg;
	IplImage* showImg;
	int threshold_color;
public:
	//In order to facilitate parameter access, the following variables are 
        //the main parameters of the InvFireDetector.
	int blockRowNum,blockColumnNum;
  int *blockMark;
  CvRect* blockSeq;
	//***********************************************************
	CvRect* rectSeq;
	int seqNum;
	int* Mark;
	int fireBlockNum;

	ColorFilter();
	void init(IplImage *pFrame);
	void show();
	void setRectSeq(CvRect* rectseq,int Num,int* rectMark);
	void setBlockVar(CvRect* blockseq,int* blockmark,int blockrownum,int blockcolumnnum);
	void nextImage(IplImage *pFrame);
	void filter();
	void blockFilter();
	void release();
};