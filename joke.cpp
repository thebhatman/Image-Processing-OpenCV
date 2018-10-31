#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int Matmax(Mat b)
{
	int max=0;
	int i,j;
	for(i=0;i<b.rows;i++)
		for(j=0;j<b.cols;j++)
			if(b.at<uchar>(i,j)>max) max=b.at<uchar>(i,j);

	return max;
}

int allWhite(Mat b)
{
	int i,j;
	for(i=0;i<b.rows;i++)
		for(j=0;j<b.cols;j++)
			if(b.at<uchar>(i,j)==0) return 0;

	return 1;
}

int main()
{
	Mat b(200,200,CV_8UC1,Scalar(0));
	int i,j;
	while(!allWhite(b))
	{
		i=rand()%b.rows;
		j=rand()%b.cols;
		if(b.at<uchar>(i,j)<255) b.at<uchar>(i,j)++;
	}

	int max=Matmax(b);

	for(i=0;i<b.rows;i++)
		for(j=0;j<b.cols;j++)
			b.at<uchar>(i,j)*=255/max;

	imshow("Image",b);
	waitKey(0);
	
	return 0;
}

