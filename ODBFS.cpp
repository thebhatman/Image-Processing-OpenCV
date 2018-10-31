#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <queue>

using namespace cv;
using namespace std;

int Isvalid(int i, int j,Mat img)
{

                if ((i<0)||(j<0)||(i>=img.rows)||(j>=img.cols))
		return 0;

		else return 1;
}

typedef struct{

                int i;
                int j;

              }lct;

void BFS(lct t,Mat a,Mat b,int* count)
{

         queue <lct> q;
	 b.at<uchar>(t.i,t.j)=255/(*count);
	 q.push(t);
	 lct v,r;
	 int k,l;
	 while(!q.empty())
	 {


	        
	           r=q.front();
		   q.pop();

		   for(k=r.i-1;k<=r.i+1;++k)
		   {


		       for(l=r.j-1;l<=r.j+1;++l)
		       {

			   if(Isvalid(k,l,a)==1)
			   {

			     if((b.at<uchar>(k,l)==0)&&(a.at<uchar>(k,l)==255))
			      {
				   v.i=k;
				   v.j=l;
				   q.push(v);
				   b.at<uchar>(k,l)=255/(*count);
			      }
			   }
		       }
		   }


	 }	   

	 *count=*count+1;
}

int main()
{

       Mat a=imread("Binary1.png",0);
       Mat c(a.rows,a.cols,CV_8UC1,Scalar(0));
       Mat b(a.rows,a.cols,CV_8UC1,Scalar(0));
       int i,j,count=2;
       lct v;
       for(i=0;i<a.rows;++i)
       {
	   for(j=0;j<a.cols;++j)
	   {
	         if(a.at<uchar>(i,j)>=100)
		 c.at<uchar>(i,j)=255;
	   }
       }
       a=c.clone();

       for(i=0;i<a.rows;++i)
       {

	     for(j=0;j<a.cols;++j)
	     {


	                    if((b.at<uchar>(i,j)==0)&&(a.at<uchar>(i,j)==255))
			    {
			      
			      v.i=i;
			      v.j=j;
			      BFS(v,a,b,&count);
                            }
	     }
       }	     
       imshow("YO",b);
       waitKey(0);
       return 0;
}       
         		    
				   
                               	      
