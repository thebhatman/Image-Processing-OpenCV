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
	Mat a=imread("joker.jpg",1);
	int i,j;
	
	Mat b(a.rows,a.cols*2,CV_8UC3,Scalar(0,0,0));

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols;j++)
		{
			b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,j)[0];
			b.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,j)[1];
			b.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,j)[2];
		}
	
	int temp[3],k;

	for(i=0;i<a.rows;i++)
		for(j=0;j<a.cols/2;j++)
			for(k=0;k<3;k++)
			{
			temp[k]=a.at<Vec3b>(i,j)[k];		
			a.at<Vec3b>(i,j)[k]=a.at<Vec3b>(i,a.cols-j)[k];
			a.at<Vec3b>(i,a.cols-j)[k]=temp[k];
			}

	for(i=0;i<a.rows;i++)
		for(j=a.cols;j<a.cols*2;j++)
		{
			b.at<Vec3b>(i,j)[0]=a.at<Vec3b>(i,j)[0];
			b.at<Vec3b>(i,j)[1]=a.at<Vec3b>(i,j)[1];
			b.at<Vec3b>(i,j)[2]=a.at<Vec3b>(i,j)[2];
		}	


	imshow("Image",b);
	waitKey(0);
	
	return 0;
}

