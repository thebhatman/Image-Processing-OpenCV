#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int main()
{
	Mat a=imread("testim.png",0);
	Mat c=imread("joker.jpg",0);
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(255));
	namedWindow("Image2",WINDOW_NORMAL);
	

	int i,j,k,t=0;
	int flag;
	int temp=1;
	int th;
	
	createTrackbar("Threshold","Image2",&th,255);
	
	imshow("Image",a);
	while(1)
	{
	
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)>th)
				b.at<uchar>(i,j)=255;
			else
				b.at<uchar>(i,j)=0;
		}

	imshow("Image2",b);
	flag=waitKey(50);
	if(flag==27) break;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(c.at<uchar>(i,j)>th)
				b.at<uchar>(i,j)=0;
			else
				b.at<uchar>(i,j)=255;
		}
	imshow("Image2",b);
	flag=waitKey(t);
	t=t+temp;
	if(flag==27) break;
	if(t>100) temp=-1;
	if(t<30) temp=1;
	
}
	
	return 0;
}

