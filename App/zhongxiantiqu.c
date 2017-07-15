#include "common.h"
#include "include.h"
extern int mid2;
extern uint8 CCD[3][TSL1401_SIZE];
extern uint8 CCD2[3][TSL1401_SIZE];
extern int16 CCD_diff[1][128];
extern uint8 rightline[8][8];
extern uint8 leftline[8][8];
extern uint8 flag1;
extern uint8 flag2;
extern uint8 flag12;
extern uint8 flag22;
extern uint8 zuoflag3;
extern uint8 youflag3;
extern uint8 imagestore[8][4];
extern uint8 imagestore2[8][4];
extern int  rightdeadline;
extern int  leftdeadline;
extern uint8 rightline2[8][8];
extern uint8 leftline2[8][8];
extern int m,n;
extern int q;
extern int w;
extern int p;
extern int o;
extern short int nextError;
extern int LeftBigBendflag;//左大弯道标志
extern int RightBigBendflag;//右大弯道标志
extern int LittleBendflag;
extern short int speedreal;
extern short int car_speedl;
extern short int car_speedr;
extern long int car_speed;
/*
 * @file       erzhihua.h
 * @brief      边界提取函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
/*void zhongxiantiqu()
{ int k;
  int l;
  int blackline;
  int whiteline;
  
   for(k=mid2;k>0;k--)
       {   if(k>leftdeadline)
         {  if(CCD[1][k]-CCD[1][k-3]>100)
       {   
         
         leftline[0][0]=k;
          
           break;
     
       }
      
         }
      
      else
      {
       leftline[0][0]=5;
       break;
      }
       
       }
       if(leftline[0][0]-leftline[0][1]>0&&leftline[0][0]-leftline[0][1]>15)
       {for(k=mid2;k>0;k--)
       {   if(k>leftdeadline)
         {  if(CCD[1][k]-CCD[1][k-3]>100)
       {   
         
         leftline[0][0]=k;
          
           break;
     
       }
      
         }
      
      else
      {
       leftline[0][0]=5;
       break;
      }
       
       }
       }
      else if(leftline[0][0]-leftline[0][1]<0&&leftline[0][0]-leftline[0][1]+15<0)
       {for(k=mid2;k>0;k--)
       {  
         if(k>leftdeadline)
         {  if(CCD[1][k]-CCD[1][k-3]>100)
       {   
         
         leftline[0][0]=k;
         
           break;
     
       }
      
         }
      
      else
      {
       leftline[0][0]=8;
       break;
      }
       
       }
       } 
       for(l=mid2;l<128;l++)
       { if(l<rightdeadline)
       {if(CCD[1][l]-CCD[1][l+3]>100)
       {  
      
       rightline[0][0]=l;
           flag2=0;
           break;
       
       }
      
     
       }
       else
       {rightline[0][0]=125;
         break;
       }
       
       } 
       if(rightline[0][0]-rightline[0][1]>0&&rightline[0][0]-rightline[0][1]<15)
       {
         for(l=mid2;l<120;l++)
       { if(l<rightdeadline)
       {if(CCD[1][l]-CCD[1][l+3]>100)
       {   
      
       rightline[0][0]=l;
          
           break;
       
       }
      
     
       }
       else
       {rightline[0][0]=125;
         break;
       }
        
       }
       }
      else if(rightline[0][0]-rightline[0][1]<0&&rightline[0][0]-rightline[0][1]+15<0)
       {for(l=mid2;l<128;l++)
       { if(l<rightdeadline)
       
       {
         if(CCD[1][l]-CCD[1][l+2]>100)
       {   
      
       rightline[0][0]=l;
          
           break;
       
       }
      
     
       }
       else
       {
         rightline[0][0]=125;
         break;
       }
       }
       }
} */
/*
 * @file       erzhihua.h
 * @brief      边界提取函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void zhongxiantiqu2()
{
  int k;
  int l;
  int heibai1=0;
  for(k=0;k<8;k++)
  {
    leftline[0][k]=0;
    rightline[0][k]=0;
  }
  q=0;
  w=0;
   if(CCD2[1][0]==255)heibai1=1;
    if(CCD2[1][0]==0)heibai1=0;
  for(k=0;k<127;k++)
       {
         if(heibai1==1)
         {
         if(CCD2[1][k]==0)
         { 
         if((k>10)&&(k<120))
         {
           
         rightline[0][q]=k;
         heibai1=0;
        
         q++;
           
           
         }
      
      
         }
         }
         if(heibai1==0)
         {
         if(CCD2[1][k]==255)
         { 
         if((k>10)&&(k<120))
         {
          
           leftline[0][w]=k;
         heibai1=1;
        
         w++;
          
          
           
         }
      
      
         }
         }
         
      
      
       
       }
  
}
/*
 * @file       erzhihua.h
 * @brief      边界3提取函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void zhongxiantiqu3()
{  
  int k;
  int heibai=0;
  o=0;
  p=0;
  flag1=0;
  flag2=0;
  
  for(k=0;k<8;k++)
  {
    leftline2[0][k]=0;
    rightline2[0][k]=0;
  }
  
    if(CCD[1][0]==255)heibai=1;
    if(CCD[1][0]==0)heibai=0;
     
  for(k=0;k<127;k++)
       {
         if(heibai==1)
         {
             if(CCD[1][k]==0)
             { 
                   if((k>10)&&(k<120))
                   {                    
                   rightline2[0][o]=k;
                   heibai=0;                 
                   o++;                     
                   }         
          
             }
         }
         if(heibai==0)
         {
             if(CCD[1][k]==255)
             { 
                 if((k>10)&&(k<120))
                 {
             
                 leftline2[0][p]=k;
                 heibai=1;               
                 p++;                                                   
                 }      
             }
         }                   
       }
  
  
  
}
/*
 * @file       erzhihua.h
 * @brief      边界3提取函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void zhongxiantiqu4()
{  
  int k;

  int cishu;
  int cishu2;
  o=0;
  p=0;
  flag1=0;
  
  flag2=0;  
  for(k=0;k<8;k++)
  {
    leftline2[0][k]=0;
    rightline2[0][k]=0;
  }
  
     
  for(k=5;k<125;k++)
       {
          
         if(CCD_diff[0][k]>CCD_diff[0][k-1]&&CCD_diff[0][k]>CCD_diff[0][k+1]&&CCD_diff[0][k]>0)
         {
          
         leftline2[0][o]=k;
         
       
         o++;
         
           
         
      
      
        
        
        
         
      
       
         }
         if(CCD_diff[0][k]<CCD_diff[0][k-1]&&CCD_diff[0][k]<CCD_diff[0][k+1]&&CCD_diff[0][k]<0)
         {
           rightline2[0][p]=k;
           p++;
           
         }
        
       
       }
  
  
  
  
}

  

/*
 * @file       erzhihua.h
 * @brief      突变处理函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void Avoid_mutation()
{ static int16 tubian1,tubian2;
  static int16 Track_R,Track_L;
  static int16 Road_wide=40;
  static int16 Mid_road1;
  static int16 record_Mid_road;
  int temp1,temp2,temp3,temp4,temp5,temp6;
  int Deviation;
  int i;
  int j;
    m=0;
    n=0;
    zuoflag3=0;
      youflag3=0;
      tubian1=20;
      tubian2=20;
      flag1=0;
      flag2=0;
   /* temp1=ABS(imagestore[0][1]-imagestore[0][0]);
    temp2=ABS(imagestore[1][1]-imagestore[1][0]);
    temp3=ABS(imagestore[0][1]-imagestore[1][1]);
    temp4=ABS(imagestore[2][1]-imagestore[1][1]);
    temp5=ABS(imagestore[0][0]-imagestore[1][0]);
    temp6=ABS(imagestore[2][0]-imagestore[1][0]);
    if((flag1==1&&flag2==2)||((flag1==2&&flag2==1)))
    {
    if(temp1<5&&temp2<5)
    {
      if(temp3<5&&temp4<5&&temp5<5&&temp6<5)
      {
        for(i=0;i<8;i++)
        {
          for(j=0;j<8;j++)
          {
           if(rightline2[0][i]-leftline2[0][i]<40&&rightline2[0][i]-leftline2[0][i]>20)
           {
            
             if((rightline2[0][i]+leftline2[0][i])<128)
             { Track_L=leftline2[0][i];
              zuoflag3=1;
             }
             if((rightline2[0][i]+leftline2[0][i])>128)
             {   Track_R=rightline2[0][i];
             zuoflag3=1;
             }
           }
          }
          
        }
      }
    }
    }*/
  Mid_road1=imagestore[0][2];
  Track_R=imagestore[0][1];
  Track_L=imagestore[0][0];
  
  for(i=0;i<8;i++)
  {  Deviation=ABS(leftline2[0][i]-imagestore[0][0]);
 
    if(leftline2[0][i]<123&&leftline2[0][i]>10&&Deviation<=tubian1&&leftline2[0][i]<Mid_road1)//
    {
     //tubian1=Deviation;
      Track_L=leftline2[0][i];//&&(leftline2[0][i]<Mid_road)
      flag1=1;
    }
   
    
    
  }
  tubian2=ABS(imagestore[0][1]-rightline2[0][0]);
  for(i=0;i<8;i++)
  {  Deviation=ABS(imagestore[0][1]-rightline2[0][i]);
    
    if(rightline2[0][i]>10&&rightline2[0][i]<123&&Deviation<=tubian2&&rightline2[0][i]>Mid_road1)//
    { //tubian2=Deviation;
      Track_R=rightline2[0][i];//&&(rightline2[0][i]>Mid_road)
      flag2=1;
    }
    
  }
  
  
 /*for(i=0;i<127;i++)
  {
   if(CCD[0][i]>190)
   {
     m++;
     if(m>4)
     {
       zuoflag3=1;
       break;
     }
     
     
   }
   if(m<=4)
     {
       zuoflag3=0; 
     }
   
    
  }
  
  for(i=0;i<127;i++)
  {
   if(CCD[0][i]<70&&CCD[0][i]>10)
   {
     n++;
       if(n>4)
       { youflag3=1; 
          break;
       
       }
     
       
     
   }
   if(n<=4)
     {
       youflag3=0;
       
       
     }
  
    
  
  }*/
  
  if((flag1==0)&&(flag2==1))
  {  
     Track_L=Track_R-Road_wide;
    // Mid_road1=(Track_R+Track_L)/2;
  }
  //if((flag1==0)&&(flag2==1)&&Track_R>=90)
 // {  
     //Track_R=128-Track_L;
 //   Track_R=Track_L+Road_wide;
    // Mid_road1=(Track_R+Track_L)/2;
 // }
  
  if((flag1==1)&&(flag2==0))
  {  
    Track_R=Track_L+Road_wide;
     //Mid_road1=(Track_R+Track_L)/2;
  }
 // if((flag1==1)&&(flag2==0)&&Track_L<=35)
 // {  
    //Track_R=Track_L+Road_wide;
 //   Track_L=Track_R-Road_wide;
     //Track_L=128-Track_R;
     //Mid_road1=(Track_R+Track_L)/2;
 // }
  
   if((flag1==1)&&(flag2==1))
   {  
      Road_wide=(Track_R-Track_L);
    // Mid_road1=(Track_R+Track_L)/2;
     
   }
 // if((flag1==1)&&(flag2==1)&&(Track_R-Track_L)>=60)
 //{
 //   Track_R=imagestore[1][1];
 //   Track_L=imagestore[1][0];
    
    
    
 //}
 
   Mid_road1=(Track_R+Track_L)/2;
  //白天是60晚上是40
 /* if(youflag3==0&&zuoflag3==0)
   {
     if(flag1==0&&flag2==1)
     {
       
       Mid_road1=imagestore[1][2]--;
       
     }
     
     if(flag1==1&&flag2==0)
     {
       Mid_road1=imagestore[1][2]++;
       
     }
     
     
   }*/
  imagestore[0][2]=Mid_road1;
   
   imagestore[0][0]=Track_L;
   imagestore[0][1]=Track_R;
    
  
 /*if(Mid_road1>72)
  {car_speedr=car_speedr+speedreal;
   car_speed=0;
   car_speedl=0;
  }
  if(Mid_road1<56)
  {car_speedl=car_speedl+speedreal;
  car_speed=0;
    car_speedr=0;
    
  }
  if(car_speedr>3000)
  {
    RightBigBendflag++;
    //car_speedl=0;
    LeftBigBendflag=0;
  
  }
  if(car_speedl>3000)
  {LeftBigBendflag++;
  //car_speedr=0;
   RightBigBendflag=0;
  }
  if(Mid_road1>80&&RightBigBendflag<5&&RightBigBendflag!=0)
  {
    record_Mid_road=imagestore[0][2];
  }
  if(Mid_road1<50&&LeftBigBendflag<5&&LeftBigBendflag!=0)
  {
    record_Mid_road=imagestore[0][2];
  }
  if(Mid_road1<80&&Mid_road1>50)
  {
   car_speed=car_speed+speedreal;
    
  }
  if(record_Mid_road>80)record_Mid_road=80;
  if(record_Mid_road<44)record_Mid_road=48;
  
  if(car_speed>50&&LeftBigBendflag!=0)
  {
   
   car_speedl=0;
   LeftBigBendflag=0;
    
  }
  if(car_speed>50&&RightBigBendflag!=0)
  {
    car_speedr=0;
   RightBigBendflag=0;
 
    
  }
  
  if(car_speed>600)car_speed=600;
  if(LeftBigBendflag!=0&&imagestore[0][2]>record_Mid_road)
  {
    imagestore[0][2]=record_Mid_road;
  }
  if(RightBigBendflag!=0&&imagestore[0][2]<record_Mid_road)
  {
    imagestore[0][2]=record_Mid_road;
  }
  if(imagestore[0][2]<40&&LeftBigBendflag!=0)imagestore[0][2]=40;
   if(imagestore[0][2]>88&&RightBigBendflag!=0)imagestore[0][2]=88;
 if(RightBigBendflag==0&&LeftBigBendflag==0)
 {
   imagestore[0][2]=Mid_road1;
   
 }*/
 if(Road_wide<30)Road_wide=30;
if(Road_wide>50)Road_wide=50;
 
  imagestore[0][3]=Road_wide;
  
  
  
}
void Avoid2_mutation()
{ 
  
  int Deviation;
  int i;
  int j;
    
 
  for(i=0;i<8;i++)
  {  
    for(j=0;j<8;j++)
    {
    if(leftline2[0][j]!=0&&rightline2[0][i]!=0)
    {
     if((leftline2[0][j]-rightline2[0][i])>10&&(leftline2[0][j]-rightline2[0][i])<20)
     {
       if((leftline2[0][j]+rightline2[0][i])<128)
        ; //左障碍
       if((leftline2[0][j]+rightline2[0][i])>128)
       ;  //右障碍  
         
         
     }
      
    }
    
    
    }
  }
  
  
  
  
  
}
/*
 * @file       erzhihua.h
 * @brief      突变处理函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void Avoid3_mutation()
{ static int16 tubian1,tubian2;
  static int16 Track_R,Track_L;
  static int16 Road_wide=40;
  static int16 tubian12,tubian22;
  static int16 Track_R2,Track_L2;
  static int16 Road_wide2=40;
  static int16 Mid_road1;
  static int16 Mid_road2;
  static int16 record_Mid_road;
  
  int Deviation;
  int i;
  int j;
    m=0;
    n=0;
    zuoflag3=0;
      youflag3=0;
      tubian1=20;
      tubian2=20;
      tubian12=20;
      tubian22=20;
      flag1=0;
      flag2=0;
 
  Mid_road1=imagestore[0][2];
  Track_R=imagestore[0][1];
  Track_L=imagestore[0][0];
  Mid_road2=imagestore2[0][2];
  Track_R2=imagestore2[0][1];
  Track_L2=imagestore2[0][0];
  for(i=0;i<8;i++)
  {  Deviation=ABS(leftline2[0][i]-imagestore[0][0]);
 
    if(leftline2[0][i]<123&&leftline2[0][i]>10&&Deviation<=tubian1&&leftline2[0][i]<Mid_road1)//
    {
    //tubian1=Deviation;
      Track_L=leftline2[0][i];//&&(leftline2[0][i]<Mid_road)
      flag1=1;
    }
   
    
    
  }
  tubian2=ABS(imagestore[0][1]-rightline2[0][0]);
  for(i=0;i<8;i++)
  {  Deviation=ABS(imagestore[0][1]-rightline2[0][i]);
    
    if(rightline2[0][i]>10&&rightline2[0][i]<123&&Deviation<=tubian2&&rightline2[0][i]>Mid_road1)//
    { //tubian2=Deviation;
      Track_R=rightline2[0][i];//&&(rightline2[0][i]>Mid_road)
      flag2=1;
    }
    
  }
  for(i=0;i<8;i++)
  {  Deviation=ABS(leftline[0][i]-imagestore2[0][0]);
  
    if(leftline[0][i]>10&&leftline[0][i]<123&&(Deviation<tubian12)&&leftline[0][i]<Mid_road2)
    {
      tubian12=Deviation;
      Track_L2=leftline[0][i];//&&(leftline2[0][i]<Mid_road)
      flag12=1;
    }
    
    
    
  }
  for(i=0;i<8;i++)
  {  Deviation=ABS(rightline[0][i]-imagestore2[0][1]);
    
    if((rightline[0][i]>10)&&(rightline[0][i]<123)&&(Deviation<tubian22)&&rightline[0][i]>Mid_road2)
    { tubian22=Deviation;
      Track_R2=rightline[0][i];//&&(rightline2[0][i]>Mid_road)
      flag22=1;
    }
    
    
  }
 
  if((flag1==0)&&(flag2==1))
  {  
     Track_L=Track_R-Road_wide;
    // Mid_road1=(Track_R+Track_L)/2;
  }
  
  if((flag1==1)&&(flag2==0))
  {  
    
    Track_R=Track_L+Road_wide;
     //Mid_road1=(Track_R+Track_L)/2;
  }
  
   if((flag1==1)&&(flag2==1))
   {  
      Road_wide=(Track_R-Track_L);
    // Mid_road1=(Track_R+Track_L)/2;
     
   }
 

  if((flag12==0)&&(flag22==1))
  {Track_L2=Track_R2-Road_wide2;
    
  }
  if((flag12==1)&&(flag22==0))
  {
    Track_R2=Track_L2+Road_wide2;
    
  }
  if((flag12==1)&&(flag22==1))
  {
    Road_wide2=(Track_R2-Track_L2);
    
  }

     
  
  Mid_road1=(Track_R+Track_L)*0.5;
  Mid_road2=(Track_R2+Track_L2)*0.5;
  //白天是60晚上是40
  imagestore[0][2]=Mid_road1;
   
   imagestore[0][0]=Track_L;
   imagestore[0][1]=Track_R;
   imagestore2[0][2]=Mid_road2;
   
   imagestore2[0][0]=Track_L2;
   imagestore2[0][1]=Track_R2;
  
 
  if(Road_wide<30)Road_wide=30;
if(Road_wide>50)Road_wide=50;
 if(Road_wide2<30)Road_wide2=30;
if(Road_wide2>50)Road_wide2=50;
  
  imagestore[0][3]=Road_wide;
  imagestore2[0][3]=Road_wide2;
  
  
  
}


