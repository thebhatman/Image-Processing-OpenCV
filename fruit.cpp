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
	Mat a=imread("fruits.png",1);
	Mat b(a.rows,a.cols,CV_8UC3,Scalar(255,255,255));
	namedWindow("Image2",WINDOW_AUTOSIZE);
	

	int i,j,k;
	int flag;
	int bl,g,r;
	
	createTrackbar("Blue","Image2",&bl,255);
	createTrackbar("Green","Image2",&g,255);
	createTrackbar("Red","Image2",&r,255);
	
	imshow("Image",a);
	while(1)
	{
	
	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			if((a.at<Vec3b>(i,j)[2]>r)&&(a.at<Vec3b>(i,j)[0]<bl)&&(a.at<Vec3b>(i,j)[1]<g))
				for(k=0;k<3;k++)
					b.at<Vec3b>(i,j)[k]=a.at<Vec3b>(i,j)[k];
			else for(k=0;k<3;k++)
					b.at<Vec3b>(i,j)[k]=255;
		}

	imshow("Image2",b);
	flag=waitKey(50);
	if(flag==27) break;
	}
	
	return 0;
}

