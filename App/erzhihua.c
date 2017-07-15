#include "common.h"
#include "include.h"
extern unsigned char fazhi1;
extern unsigned char fazhi2;
extern int16 smax;
extern int16 smin;
extern int16 max2;
extern int16 min;
extern uint8 CCD_BUFF[TSL1401_MAX*3][TSL1401_SIZE];
extern uint8 CCD[3][TSL1401_SIZE];
extern uint8 CCD2[3][TSL1401_SIZE];
extern int16 CCD_diff[1][128]; 
extern int blackline;
extern int whiteline;
extern int fazhicaiji;
extern int fazhi2max;
extern int fazhi2min;
extern int Motor_Protect;
extern int fazhicaijiover2;
extern int16 max3;
extern int16 min3;

/*
 * @file       erzhihua.h
 * @brief      归一化一阶梯度图函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void yitaodaizou()
{
  
  int i;
  int k;
  //60晚上140//80白天140傍晚110晚上
  
  max3=0;//为什么最小值是255
  min3=255;
  
  float  percent;
  
 for(k=1;k<127;k++)
      {
        CCD_BUFF[0][k]=(CCD_BUFF[0][k-1]+2*CCD_BUFF[0][k]+CCD_BUFF[0][k+1])/4;
         
   }
  
  for(k=0;k<128;k++)
       {
         if(CCD_BUFF[0][k]>max3)max3=CCD_BUFF[0][k];
         
         
         if(CCD_BUFF[0][k]<min3)min3=CCD_BUFF[0][k];
         
         
       }
 
  
  for(k=0;k<128;k++)
  {
    if(max3>0)
    
    CCD[2][k]=CCD_BUFF[0][k]*200/(max3-0);
    
    
  }
 
 
  for(k=2;k<126;k++)
  {
    
    
    CCD[0][k]=(8*(CCD[2][k+1]-CCD[2][k-1]+2*CCD[2][k+2]-2*CCD[2][k-2]))/4+135;
    
    if( CCD[0][k]>250)CCD[0][k]=250;
    if( CCD[0][k]<0)CCD[0][k]=0;
    
  }
  
  
 
}
void yitaodaizou2()
{
  
  int i;
  int k;
  //60晚上140//80白天140傍晚110晚上
  smax=0;
  smin=255;
  max3=0;
  min3=255;
  float  percent;
  

  for(k=0;k<128;k++)
       {
         
         if(CCD_BUFF[0][k]>max3)max3=CCD_BUFF[0][k];       
         if(CCD_BUFF[0][k]<min3)min3=CCD_BUFF[0][k]; 
         
       }
  
 
  
  for(k=0;k<128;k++)
  {
    if(max3>0)
    
    CCD[2][k]=(CCD_BUFF[0][k]*200)/(max3-0);//降低归一化，原值200，现在200
    
    
  }
  for(k=0;k<128;k++)
       {
         if(CCD[2][k]>smax)smax=CCD[2][k];            
         if(CCD[2][k]<smin)smin=CCD[2][k];                
       }
  
  
 if(2*smax>smin*4)//我觉得这个地方需要斟酌一下！是否要加入这样的判断
 fazhi1=(smax+smin)/2+30;
 else
 fazhi1=fazhi1;//
 
   for(k=0;k<128;k++)
    {  
      if(CCD[2][k]<fazhi1)
         {
           CCD[1][k]=0;
         }
         
         else
         {  CCD[1][k]=255;
         }
     }
 
   
  for(k=3;k<128;k++)
    
  {
    
  CCD_diff[0][k]=CCD[2][k]-CCD[2][k-3]; //这是在求最大差分值么？ 
  
  }
 
  
  for(k=2;k<126;k++)
    
  {   
    CCD[0][k]=(CCD[2][k+1]-CCD[2][k-1]+2*CCD[2][k+2]-2*CCD[2][k-2])+135;   //这是什么意思？
    if( CCD[0][k]>250)CCD[0][k]=250;
    if( CCD[0][k]<0)CCD[0][k]=0;  
  }
  
  for(k=0;k<127;k++)
       {
         if(CCD[1][k]==0)
       {
         blackline++;
       }
       else 
       {
         if(blackline<=3&&blackline!=0)
         {
             CCD[1][k]=255;
             CCD[1][k-1]=255;
             CCD[1][k-2]=255;
             blackline=0;
         }
           if(blackline>3)
         { 
           blackline=0;
         }
       
       }
       if(CCD[1][k]==255)
       {
         whiteline++;
       }
       else 
       {
         if(whiteline<=3&&whiteline!=0)
         {
           CCD[1][k]=0;
           CCD[1][k-1]=0;
           CCD[1][k-2]=0;
           whiteline=0;
         }
         if(whiteline>3)
         { 
           whiteline=0;
         }
       
       }
     
       }
     

  
 
  
 
  
 
}
void erzhihua()
{
  int k;
  int i;
  max2=0;
  min=255;
  for(k=1;k<127;k++)
       {
         CCD_BUFF[1][k]=(CCD_BUFF[1][k-1]+2*CCD_BUFF[1][k]+CCD_BUFF[1][k+1])/4;         
       }
  for(k=0;k<128;k++)
       {
         if(CCD_BUFF[1][k]>max2)max2=CCD_BUFF[1][k];
         
         
         if(CCD_BUFF[1][k]<min)min=CCD_BUFF[1][k];
         
         
       }
  
  Otsu();//为什么还在用大律法
 
    
  for(i=0;i<128;i++)
    {  if(CCD_BUFF[1][i]<fazhi2)
         {
           CCD2[1][i]=0;
         }
         
         else
         {  
           CCD2[1][i]=255;
         }
    }
  
  for(k=0;k<128;k++)
  {
    
    if(max2>0)
    
    CCD2[2][k]=CCD_BUFF[1][k]*200/(max2-0);
    
    
  }
 
  for(k=2;k<126;k++)
  {
    
    
    CCD2[0][k]=(8*(CCD2[2][k+1]-CCD2[2][k-1]+2*CCD2[2][k+2]-2*CCD2[2][k-2]))/4+135;
    
    if( CCD2[0][k]>250)CCD[0][k]=250;
    if( CCD2[0][k]<0)CCD[0][k]=0;
    
  }
  
 
  
  
  
}

/*
 * @file       erzhihua.h
 * @brief      大律法函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void Otsu()

{ 
   uint16 i;
   uint32 g=0,max=0;
   uint16 total=0,total_low=0;
   uint8 u0=0,u1=0,count=0;
   uint8 pc[256]={0};
   
  fazhi1=0;
  
  for(i=0;i<128;i++)
  {
    ++pc[CCD_BUFF[1][i]];
    total+=CCD_BUFF[1][i];
  }
  
  for(i=0;i<255;i++)
  {
    if(pc[i]==0)     
    continue;
    count+=pc[i];
    total_low+=pc[i]*i;
    u0=total_low/count;
    if(count<128)
    u1=(total-total_low)/(128-count);
    else
    u1=0;
    g=(u0-u1)*(u0-u1)*count*(128-count);
    
    if(g>max)
    {
      max=g;
      fazhi2=i;
      
    }
    if(count>=128)
      break;
    
  }
 
 
  
  
  
}



 
       

 