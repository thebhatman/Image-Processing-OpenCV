		#include<iostream>

		#include "opencv2/highgui/highgui.hpp"
		#include "opencv2/imgproc/imgproc.hpp"
		#include "opencv2/core/core.hpp"

		using namespace cv;
		using namespace std;

int is_valid(int i,int j,Mat img2)
	{
		if(i<0 or j<0 or i>=img2.rows-1 or j>=img2.cols-1)
			return 0;
		return 1;
	}

void DFS_visit(int i,int j,int count,Mat img2)
	{	int k,l; 
		img2.at<uchar>(i,j)=255-30*count;

		for(k=i-1;k<=i+1;k++)
			{
				for(l=j-1;l<=j+1;l++)
					{if(k!=i and l!=j)
						if(img2.at<uchar>(k,l)==255 and is_valid(k,l,img2))			
								DFS_visit(k,l,count,img2);
					}
			}
	}



int main()
	{
		int i,j,count=2;
		Mat img=imread("/home/ritik/Desktop/winter_workshop/Binary1.png",0);
		Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));

		for(i=0;i<img.rows;i++)
		 	{
		 		for(j=0;j<img.cols;j++)
		 			{
		 				if(img.at<uchar>(i,j)>=50)
								img3.at<uchar>(i,j)=255;
					}
			}

		Mat img2=img3.clone();

		for(i=0;i<img.rows;i++)
		 	{
		 		for(j=0;j<img.cols;j++)
		 			{
		 				if(img2.at<uchar>(i,j)==255)
		 					{
		 						DFS_visit(i,j,count,img2);
		 						count++;
		 					}
		 			}
		 	}
		imwrite("object_detection.jpg",img2);
		imshow("image",img2);
		waitKey(0);
		return 0;
	}

