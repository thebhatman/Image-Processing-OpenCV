#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#include <queue>

using namespace cv;
using namespace std;

typedef struct
{
	int x;
	int y;
}pt;

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

void BFS_Visit(int i,int j,int count,Mat a,Mat b)
{
	b.at<uchar>(i,j)=255/count;
	
	queue<pt> q;
	pt s;
	s.x=i;
	s.y=j;
	q.push(s);
	
	while(!q.empty())
	{
		pt u=q.front();
		q.pop();

		int m,n;
		for(m=u.x-1;m<=u.x+1;m++)
			for(n=u.y-1;n<=u.y+1;n++)
				if(isValid(m,n,a.rows,a.cols)==1 && b.at<uchar>(m,n)==0 && a.at<uchar>(m,n)==255)
				{
					pt v;
					v.x=m;
					v.y=n;
					q.push(v);
					b.at<uchar>(m,n)=255/count;
				}
		//imshow("Image",b);
		//waitKey(10);
	}	
}

int main()
{
	Mat a=imread("binary3.jpg",0);
	a=graytobin(a);
	imshow("Original",a);
	
	int i,j,count;

	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));

	for(i=0,count=1;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
			if(a.at<uchar>(i,j)==255 && b.at<uchar>(i,j)==0) 
				{BFS_Visit(i,j,count,a,b); count++; printf("%d\n",count);}

	
	imshow("Image",b);
	waitKey(0);
	
	return 0;
}

