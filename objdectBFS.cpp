#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
#include<cstdlib>
#include<queue>
using namespace cv;
using namespace std;

struct cod
{
	int x,y;
};

int isValid(int x,int y,int r,int c)
{
	if(x<0 || x>=r) 
		return 0;
	if(y<0 || y>=c) 
		return 0;
	return 1;
}

void ero(Mat b)
{
	Mat p=b.clone();
	for(int i=0;i<b.rows;i++)
				for(int j=0;j<b.cols;j++)
					if(p.at<uchar>(i,j)==255)
						for(int i1=i-1;i1<=i+1;i1++)
							for(int j1=j-1;j1<=j+1;j1++)
								if(isValid(i1,j1,b.rows,b.cols)!=0)
									if(p.at<uchar>(i1,j1)==0 && i1!=i && j1!=j)
									{
										b.at<uchar>(i,j)=0;
									}
}

void dia(Mat b)
{
	Mat p=b.clone();
	for(int i=0;i<b.rows;i++)
				for(int j=0;j<b.cols;j++)
					if(p.at<uchar>(i,j)==0)
						for(int i1=i-1;i1<=i+1;i1++)
							for(int j1=j-1;j1<=j+1;j1++)
								if(isValid(i1,j1,b.rows,b.cols)!=0)
									if(p.at<uchar>(i1,j1)==255 && i1!=i && j1!=j)
									{
										b.at<uchar>(i,j)=255;
									}
}

void binarythres(Mat a)
{
	for(int i=0;i<a.rows;i++)
		for(int j=0;j<a.cols;j++)
			if(a.at<uchar>(i,j)>150)
				a.at<uchar>(i,j)=255;
			else
				a.at<uchar>(i,j)=0;
	ero(a);
	dia(a);		
}

int isVisited(Mat a,int i,int j)
{
	if(isValid(i,j,a.rows,a.cols))
		if (a.at<uchar>(i,j)!=0 && a.at<uchar>(i,j)!=255)
			return 1;
	return 0;	
}

void markVisited(Mat a,int i,int j,int ran)
{
	a.at<uchar>(i,j)=ran;
}

void BFS(Mat a)
{
	binarythres(a);
	for(int i=0;i<a.rows;i++)
		for(int j=0;j<a.cols;j++)
		{
			if(a.at<uchar>(i,j)==255)
			{
				queue <cod> q;
				cod t;t.x=i;t.y=j;
				markVisited(a,i,j,170);
				q.push(t);
				while(!q.empty())
				{
					cod p=q.front();
					int ix=p.x,jy=p.y;
					q.pop();
					for(int i1=ix-1;i1<=ix+1;i1++)
						for(int j1=jy-1;j1<=jy+1;j1++)
							if(isValid(i1,j1,a.rows,a.cols))
								if(!(isVisited(a,i1,j1)) && a.at<uchar>(i1,j1)==255)
								{
									t.x=i1;t.y=j1;
									q.push(t);
									markVisited(a,i1,j1,170);
								}
				}
			}
		}	
}

int main()
{
	Mat a=imread("Binary1.png",0);
	BFS(a);
	imshow("Image",a);
	waitKey(0);
}