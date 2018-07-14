#include "stdlib.h"
#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include <opencv/cvaux.h> 
#include <iostream>
#include <math.h>
#include "myGMMbackground.h"
#include "constants.h"

class FrGrdExtract
{
private:
	IplImage* curImg;
	IplImage* showImg;
	CvGaussBGModel* bg_model; // Initialize the Gaussian mixture model parameters

public:
	//In order to facilitate parameter access, the following variables are the main parameters of the InvFireDetector.
	int blockRowNum,blockColumnNum;
  int *blockMark;
  CvRect* blockSeq;
	//***********************************************************
	CvRect* rectSeq;
	int seqNum;
	int *Mark;
	IplImage* pFrImg; 
	IplImage* pBackImg;


	FrGrdExtract();
	void init(IplImage* pFrame);
	void show();
	void nextImage(IplImage* pFrame);
	void setRectSeq(CvRect* rectseq,int* rectMark);
  void setBlockVar(CvRect* blockseq,int* blockmark,int blockrownum,int blockcolumnnum);
	void filter(IplImage* pFrImg);
	void release();
	void segmentation(IplImage* pFrImg);
};