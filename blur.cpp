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
	
	namedWindow("Image",WINDOW_AUTOSIZE);
	int i,j,k,p,q;
	int avg;
	createTrackbar("Blur","Image",&k,15);
	//commented for readability
	while(1)
	{		
	Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));

	for(i=k;i<a.rows-k;i++)
		for(j=k;j<a.cols-k;j++)
			{for(p=i-k,avg=0;p<=i+k;p++)
				for(q=j-k;q<=j+k;q++)
					avg+=a.at<uchar>(p,q);
			avg/=(2*k+1)*(2*k+1);
			b.at<uchar>(i,j)=avg;
			}

	imshow("Image2",a);
	imshow("Image",b);
	int flag=waitKey(30);
	if(flag==27) break;
	}
	return 0;
}

