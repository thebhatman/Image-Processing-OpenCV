#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat a;//=imread("erosion.png",0);
Mat c;//=a.clone();

int isValid(int x, int y, int rows, int cols)
{
	if(x<0||y<0||x>=rows||y>=cols) return 0;
	return 1;
}

void erode(int rows, int cols, Mat b, Mat c)
{
	int i,j,p,q,flag=0;

	for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
		{
			if(c.at<uchar>(i,j))
				{
					for(p=i-1,flag=0;p<=i+1;p++)
						{
							for(q=j-1;q<=j+1;q++)
							if(isValid(p,q,rows,cols) && c.at<uchar>(p,q)==0) {flag=1; break;}

							if(flag==1) break;
						}
					if(flag==1) b.at<uchar>(i,j)=0;
					else b.at<uchar>(i,j )=255;
				}
			else b.at<uchar>(i,j)=0;
		}

}

void dil(int rows, int cols, Mat b, Mat c)
{
	int i,j,p,q,flag=0;

		for(i=0;i<rows;i++)
		for(j=0;j<cols;j++)
		{
			if(c.at<uchar>(i,j)==0)
			{
			for(p=i-1,flag=0;p<=i+1;p++)
				{
					for(q=j-1;q<=j+1;q++)
					if(isValid(p,q,rows,cols) && c.at<uchar>(p,q)) {flag=1; break;}
				if(flag==1) break;
				}
			if(flag==1) b.at<uchar>(i,j)=255;
			else b.at<uchar>(i,j)=0;
			}
			else b.at<uchar>(i,j)=255;
		}

}

int main()
{
	a=imread("erosion3.png",0);
	c=a.clone();
	imshow("Image2",a);

	int i,j,k=1,p,q;
	//namedWindow("Image",WINDOW_AUTOSIZE);
	//createTrackbar("Threshold","Image",&k,10);
	int temp;	
	
	while(1)
		{

			Mat b=a.clone();
	
			for(temp=k;temp>0;temp--)
				{
					erode(a.rows,a.cols,b,c);
					c=b.clone();
				}
				imshow("Image3", c);

			for(temp=k;temp>0;temp--)
				{
					dil(a.rows,a.cols,b,c);
					c=b.clone();
				}
	
	
			c=a.clone();	

			imshow("Image",b);
			int x=waitKey(30);
			if(x==27) break;
		}

	return 0;
}
