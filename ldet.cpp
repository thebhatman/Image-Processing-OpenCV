#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <bits/stdc++.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <queue>

#define N 1

using namespace cv;
using namespace std;

float pi=CV_PI/180;


int isValid(int x, int y, Mat a)
{
	if(x<0 || y<0 || x>=a.rows || y>=a.cols) return 0;
	return 1;
}

Mat graytobin(Mat a)
{
	int i,j;
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)>127) a.at<uchar>(i,j)=255;
			else a.at<uchar>(i,j)=0;
		}

		return a;
}


int kmax(int i,int j, int th, Mat b)
{
	if(b.at<uchar>(i,j)<th) return 0;

	int p,q;
	for(p=i-N;p<=i+N;p++)
		for(q=j-N;q<=j+N;q++)
			if(isValid(p,q,b) && b.at<uchar>(p,q)>b.at<uchar>(i,j)) return 0;

	return 1;
}

int main()
{
	int th=60;

	Mat a=imread("A3.png",0);
	a=graytobin(a);
	//printf("%d,%d\n",a.rows,a.cols);
	//GaussianBlur(a,a,Size(5,5),1.5,1.5);
	
	//Canny(a,a,15,50);
	imshow("Canny",a);
	//imshow("Canny",a);
	//while(waitKey(1)!=27)
	//{}
	//namedWindow("Image",WINDOW_NORMAL);
	namedWindow("Refined",WINDOW_NORMAL);
	createTrackbar("Threshold","Refined",&th,255);
	int diag=(a.rows*a.rows)+(a.cols*a.cols);
	diag=sqrt(diag);
	diag=diag;

	//int m=1;
	Mat b(2*diag+1,180,CV_8UC1,Scalar(0));

	int i,j,theta,r;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			if(a.at<uchar>(i,j))
				for(theta=0;theta<180;theta++)
				{
					r=(j*cos(theta*pi))+(i*sin(theta*pi));
					//for(int k=0;k<m;k++)
					if(b.at<uchar>(r+diag,theta)<=255)						
						b.at<uchar>(r+diag,theta)++;
				}

	int temp=1;

	while(1)
	{
		int count=0;
	Mat c(b.rows,b.cols,CV_8UC1,Scalar(0));
	Mat d(a.rows,a.cols,CV_8UC1,Scalar(0));


	for(i=0;i<b.rows;i++)
		for(j=0;j<b.cols;j++)
			if(kmax(i,j,th,b)) 
				{c.at<uchar>(i,j)=255; count++;}

	if(temp==1)
		for(i=0;i<c.rows;i++)
		for(j=0;j<c.cols;j++)
			if(c.at<uchar>(i,j)==255)
					{printf("%d\n",i-diag); temp=0;}
	

	for(i=0;i<c.rows;i++)
		for(j=0;j<c.cols;j++)
			if(c.at<uchar>(i,j)==255)
			{
				r=i-diag;
				//printf("%d\n",r);
				theta=j;
				//printf("%d\n",theta);
				int x,y;
				for(x=0;x<d.cols;x++)
				{	if(theta==0) {/*printf("zero,%d\n",x);*/ for(y=0;y<d.rows;y++) d.at<uchar>(y,r)=255; break;}
					if(theta==90) {/*rintf("ninety\n");*/ y=r;}
					else y=(r/sin(theta*pi))-(x*cos(theta*pi)/sin(theta*pi));
					if(y<d.rows && y>=0) d.at<uchar>(y,x)=255;
				}

			}
	//printf("\n\n");
	imshow("Lines",d);
	//imshow("Image",b);
	imshow("Refined",c);
	int flag=waitKey(30);
	if(flag==27) break;
	if(flag==48) printf("%d\n",count);
	}
	//imshow("Image",b);
	//waitKey(0);

	return 0;

}
