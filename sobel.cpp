#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace cv;
using namespace std;

int isValid(int x, int y, int rows, int cols)
{
	if(x<0||y<0||x>=rows||y>=cols) return 0;
	return 1;
}

int Gx(int i, int j, Mat a)
{
	int p,q;

	int x[3][3]={{-3,0,3},{-10,0,10},{-3,0,3}};

	int gx=0;

	for(p=i-1;p<=i+1;p++)
		for(q=j-1;q<=j+1;q++)
				gx+=a.at<uchar>(p,q)*x[p-i+1][q-j+1];

	return abs(gx)/16;

}

int Gy(int i, int j, Mat a)
{
	int p,q;

	int y[3][3]={{3,10,3},{0,0,0},{-3,-10,-3}};

	int gy=0;

	for(p=i-1;p<=i+1;p++)
		for(q=j-1;q<=j+1;q++)
				gy+=a.at<uchar>(p,q)*y[p-i+1][q-j+1];

	return abs(gy)/4;

}

int G(int i, int j, Mat a)
{
	int x=Gx(i,j,a);
	int y=Gy(i,j,a);

	return sqrt((x*x)+(y*y));
}

int main()
{
	Mat a=imread("fruits.png",0);
	int i,j,k,m,n;
	namedWindow("Imagex",WINDOW_AUTOSIZE);
	namedWindow("Imagey",WINDOW_AUTOSIZE);
	namedWindow("Imagez",WINDOW_AUTOSIZE);
	createTrackbar("Thresholdx","Imagex",&k,255);
	createTrackbar("Thresholdy","Imagey",&m,255);
	createTrackbar("Thresholdz","Imagez",&n,255);

	while(1)
	{	
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
	Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
	Mat z(a.rows,a.cols,CV_8UC1,Scalar(0));

	for(i=1;i<a.rows-1;i++)
		for(j=1;j<a.cols-1;j++)
			{
				if(Gx(i,j,a)>k) b.at<uchar>(i,j)=255;
				if(Gy(i,j,a)>m) c.at<uchar>(i,j)=255;
				if(G(i,j,a)>n) z.at<uchar>(i,j)=255;
			}

	imshow("Image",a);
	imshow("Imagex",b);
	imshow("Imagey",c);
	imshow("Imagez",z);

	int flag=waitKey(30);
	if(flag==27) break;
	}
	
	return 0;
}

