#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

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

int isValid(int x, int y, int rows, int cols)
{
	if(x<0||y<0||x>=rows||y>=cols) return 0;
	return 1;
}

void DFS_Visit(int i,int j,int count,Mat a,Mat b)
{
	b.at<uchar>(i,j)=255/count;
	imshow("Image",b);
	waitKey(5);
	if(count==3) printf("%d,%d\n",i,j);

	int p,q;
	for(p=i;p<=i+1;p++)
		for(q=j;q<=j+1;q++)
			if(isValid(p,q,a.rows,a.cols) && a.at<uchar>(p,q)==255 && b.at<uchar>(p,q)==0)
				DFS_Visit(p,q,count,a,b);
}

int main()
{
	Mat a=imread("Binary1.png",0);
	a=graytobin(a);
	imshow("Original",a);
	
	int i,j,count;

	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));

	for(i=0,count=1;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			if(a.at<uchar>(i,j) && b.at<uchar>(i,j)==0) 
				{DFS_Visit(i,j,count++,a,b); imshow("Image",b);
	while(waitKey(1)!=27){}}

	
	imshow("Image",b);
	
	waitKey(0);
	
	return 0;
}

