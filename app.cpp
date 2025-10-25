#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat imgHSVr,imgHSVg,maskred,maskgreen,img,imgredero;                 
      int hmin1=160,smin1=60,vmin1=50;         
      int hmax1=179,smax1=255,vmax1=255; 

     int hmin2=52,smin2=193,vmin2=119;         
     int hmax2=120,smax2=255,vmax2=255; 

int main(){
      string path="TrafficLight.mp4",writerpath="result.avi";
      VideoCapture cap(path);
      int imgw=cap.get(CAP_PROP_FRAME_WIDTH);
      int imgh=cap.get(CAP_PROP_FRAME_HEIGHT);
      int count=cap.get(CAP_PROP_FRAME_COUNT);
      double fps=cap.get(CAP_PROP_FPS);
      VideoWriter writer(writerpath,cap.get(CAP_PROP_FOURCC),fps,Size(imgw,imgh),true);
       while(1){
         cap.read(img);
         if(img.empty()){
           break;
         }  
          Mat imgcopy=img;
        Mat imgerored, imgerogreen,imgdil;
         cvtColor(img,imgHSVr,COLOR_BGR2HSV);                      
           Scalar lowerr(hmin1,smin1,vmin1);        
           Scalar upperr(hmax1,smax1,vmax1);
           inRange(imgHSVr,lowerr,upperr,maskred);
        

          Mat kernel=getStructuringElement(MORPH_RECT,Size(9,9));
          erode(maskred,imgerored,kernel);
          vector<vector<Point>>contoursred; 
          vector<Vec4i>hierarchyred;
          findContours(imgerored,contoursred,hierarchyred,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
          for(int i=0;i<contoursred.size();i++){
            Rect boundRectred;   
            int area=contourArea(contoursred[i]); 
            if(area>11500){
              boundRectred=boundingRect(contoursred[i]);
              rectangle(img,boundRectred.tl(),boundRectred.br(),Scalar(255,0,255),3);
              putText(img,"Red Stop",Point(50,150),FONT_HERSHEY_SIMPLEX,3,Scalar(0,0,255),2);
            }
          }  
          

          cvtColor(imgcopy,imgHSVg,COLOR_BGR2HSV);                      
           Scalar lowerg(hmin2,smin2,vmin2);        
           Scalar upperg(hmax2,smax2,vmax2);
           inRange(imgHSVg,lowerg,upperg,maskgreen);
  
          Mat kernelgreen=getStructuringElement(MORPH_RECT,Size(5,5));
          dilate(maskgreen,imgdil,kernelgreen); 
          vector<vector<Point>>contoursgreen; 
          vector<Vec4i>hierarchygreen;
          findContours(imgdil,contoursgreen,hierarchygreen,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
          for(int i=0;i<contoursgreen.size();i++){
            Rect boundRectgreen;   
            int area=contourArea(contoursgreen[i]); 
            if(area>12000){
              boundRectgreen=boundingRect(contoursgreen[i]);
              rectangle(img,boundRectgreen.tl(),boundRectgreen.br(),Scalar(255,0,255),3);
              putText(img,"Green Go",Point(50,150),FONT_HERSHEY_SIMPLEX,3,Scalar(0,255,0),2);
            }
          }  
           imshow("test",img);
            waitKey(20);
            writer.write(img);
 
        } 
        writer.release();
        cap.release();                   
     }


