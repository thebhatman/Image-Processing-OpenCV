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
	Mat a=imread("lena.png",0);
	Mat c=a.clone();

	imshow("Image2",a);
	int i,j,p,q,k=1;
	float gauss[3][3]={{0.0625,0.125,0.0625},{0.125,0.25,0.125},{0.0625,0.125,0.0625}};
	int avg;
	namedWindow("Image",WINDOW_AUTOSIZE);
	createTrackbar("Gaussian Blur","Image",&k,100);
	
	while(1)
	{
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));

	int temp;
	for(temp=k;temp>0;temp--)
		{
		for(i=1;i<a.rows-1;i++)
			for(j=1;j<a.cols-1;j++)
				{for(p=i-1,avg=0;p<=i+1;p++)
					for(q=j-1;q<=j+1;q++)
						avg+=c.at<uchar>(p,q)*gauss[p-i+1][q-j+1];
				b.at<uchar>(i,j)=avg;
				}
		for(i=1;i<a.rows-1;i++)
			for(j=1;j<a.cols-1;j++)
				c.at<uchar>(i,j)=b.at<uchar>(i,j);
	
		}
		c=a.clone();

	imshow("Image",b);
	int flag=waitKey(30);
	if (flag==27) break;
	}
	
	return 0;
}

