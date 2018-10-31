#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace cv;
using namespace std;
int Is_Valid(int x,int y,Mat b)
{
	if(x<0||y<0||x>=b.rows||y>=b.cols)
		return 0;
	else
		return 1;
}
struct pi
	{
		int x,y;
	};
int main()
{
	Mat a=imread("Binary1.png",0);
	Mat visited(a.rows,a.cols,CV_8UC1,Scalar(0));
	
	queue <pi> q;
	int i,j,k,l;
	for(i=1;i<a.rows-1;i++)
	{
		for(j=1;j<a.cols-1;j++)
		{
			if(a.at<uchar>(i,j)==255)
			{
				
				visited.at<uchar>(i,j)=150;
				pi u;
				u.x=i;
				u.y=j;
				q.push(u);
				while(!q.empty())
				{
					pi u=q.front();
					u.x=k;u.y=l;
					q.pop();
					for(k=i-1;k<=i+1;k++)
					{
						for(l=j-1;l<=j+1;l++)
						{
							if(Is_Valid(k,l,a))
							if(visited.at<uchar>(k,l)==0)
							{
								u.x=k;u.y=l;
								q.push(u);
								visited.at<uchar>(k,l)=150;
							}
						}
					}
				}
			}
		}
	}
	imshow("IM",visited);
	waitKey(0);
}