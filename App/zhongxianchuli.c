#include "common.h"
#include "include.h"
extern int mid2;
extern int mid;
extern uint8 roadside;
extern int b;
extern uint8 CCD[3][TSL1401_SIZE];
extern uint8 CCD2[3][TSL1401_SIZE];
extern uint8 rightline[8][100];
extern uint8 leftline[8][100];
extern uint8 rightline2[8][100];
extern uint8 leftline2[8][100];
extern uint8 flag1;
extern uint8 flag2;
extern int  rightdeadline;
extern int  leftdeadline;
extern uint8 roadwide;
extern uint8 roadwidemax;
extern uint8 roadwidemin;
extern uint8 imagestore[8][4];
extern uint8 imagestore2[8][4];
extern int Mid1;
extern int Mid2;
extern int daolu;

/*
 * @file       zhongxianchuli.h
 * @brief      边界处理函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void zhongxianchuli()
{     
          Mid2=Mid1;
          Mid1=mid;
       /* two line in visual feild  */
      if(leftline[0][0]>leftdeadline&&rightline[0][0]<rightdeadline)
       { //mid=(leftline[0][0]+rightline[0][0])/2;
         //mid2=(leftline[0][0]+rightline[0][0])/2;
            if(leftline[0][1]>=leftdeadline&&rightline[0][1]<=rightdeadline)
            {
              mid=(leftline[0][0]+rightline[0][0])/2;
              mid2=(leftline[0][0]+rightline[0][0])/2;
            
            }
            if(leftline[0][1]<=leftdeadline&&rightline[0][1]>=rightdeadline) 
            {
              mid=(leftline[0][0]+rightline[0][0])/2;
              mid2=(leftline[0][0]+rightline[0][0])/2;
            
            }
            if(leftline[0][1]<=leftdeadline&&rightline[0][1]<rightdeadline) 
            {  if(rightline[0][1]-rightline[0][0]>15||rightline[0][1]<=25)
            {  leftline[0][0]=leftline[0][1];
               rightline[0][0]=rightline[0][1];
               mid=(leftline[0][0]+rightline[0][0])/2;
               mid2=(leftline[0][0]+rightline[0][0])/2;
               
            
            }
            else
            {  mid=(leftline[0][0]+rightline[0][0])/2;
               mid2=(leftline[0][0]+rightline[0][0])/2;
               
            }
            
            }
            if(leftline[0][1]>leftdeadline&&rightline[0][1]>=rightdeadline)
            { if(leftline[0][0]-leftline[0][1]>15||leftline[0][1]>103)
            {   leftline[0][0]=leftline[0][1];
               rightline[0][0]=rightline[0][1];
                mid=(leftline[0][0]+rightline[0][0])/2;
               mid2=(leftline[0][0]+rightline[0][0])/2;
               
            }
            else
            {mid=(leftline[0][0]+rightline[0][0])/2;
             mid2=(leftline[0][0]+rightline[0][0])/2;}
            
            }
        
       }
     //oniy left line in visual view
      if(leftline[0][0]>leftdeadline&&rightline[0][0]>=rightdeadline)
       {  
          if(leftline[0][1]>leftdeadline&&rightline[0][1]>=rightdeadline)
          {  

            mid=leftline[0][0]+95/2;
            mid2=(leftline[0][0]+rightline[0][0])/2;
           
          }
         if(leftline[0][1]<=leftdeadline&&rightline[0][1]<rightdeadline)
         { if(ABS(leftline[0][0]-leftline[0][1])>20)    
           leftline[0][0]=leftline[0][1];
            rightline[0][0]=rightline[0][1];
            mid=leftline[0][0]+67/2;
            mid2=(leftline[0][0]+rightline[0][0])/2;
         
           
         }
         else
         {
           mid=leftline[0][0]+68/2;
            mid2=(leftline[0][0]+rightline[0][0])/2;
         }
         if(leftline[0][1]<=leftdeadline&&rightline[0][1]>=rightdeadline)
         {
            mid=leftline[0][0]+68/2;
            mid2=(leftline[0][0]+rightline[0][0])/2;
          
           
         }
         if(leftline[0][1]>leftdeadline&&rightline[0][1]<rightdeadline)
         {  
            mid=leftline[0][0]+68/2;
            mid2=(leftline[0][0]+rightline[0][0])/2;
        
           
         }
         
       }
      //only right line in visual view
     if(leftline[0][0]<=leftdeadline&&rightline[0][0]<rightdeadline)
      {   
           if(leftline[0][1]<=leftdeadline&&rightline[0][1]<rightdeadline)
          {  
           mid=(rightline[0][0]-(67/2));//
          mid2=(leftline[0][0]+rightline[0][0])/2;//
          }
           
          
          if(leftline[0][1]>leftdeadline&&rightline[0][1]>=rightdeadline)
          { if(ABS(rightline[0][0]-rightline[0][1])>20)
          {leftline[0][0]=leftline[0][1];
           rightline[0][0]=rightline[0][1];
           mid=(rightline[0][0]-(67/2));
          mid2=(leftline[0][0]+rightline[0][0])/2;
          
          }
          else
          {
            mid=(rightline[0][0]-(67/2));
          mid2=(leftline[0][0]+rightline[0][0])/2;
          }
          
          }
           
        if(leftline[0][1]<=leftdeadline&&rightline[0][1]>=rightdeadline)
        {  mid=(rightline[0][0]-(67/2));
          mid2=(leftline[0][0]+rightline[0][0])/2;
          
        }
     if(leftline[0][1]>leftdeadline&&rightline[0][1]<rightdeadline)
        {if(ABS(rightline[0][0]-rightline[0][1])>daolu)//15虽前瞻变而随时调整
          { leftline[0][0]=leftline[0][1];
           rightline[0][0]=rightline[0][1];
           mid=(rightline[0][0]-(67/2));//
          mid2=(leftline[0][0]+rightline[0][0])/2;//
          }
           else
           {mid=(rightline[0][0]-(67/2));
          mid2=(leftline[0][0]+rightline[0][0])/2;}
          b=1;
      }
        
      }
      //two line not in visual view
     if(leftline[0][0]<=leftdeadline&&rightline[0][0]>=rightdeadline)
      { 
       
        /* int l,r;
        if(((leftline[0][3]-leftline[0][2])>5)&&((leftline[0][2]-leftline[0][1])>5)&&((leftline[0][1]-leftline[0][0])>5))
        {
          leftline[0][0]=leftline[0][2]+5;
          rightline[0][0]=rightline[0][2]+5;
          mid=(leftline[0][0]+rightline[0][0])/2;//
          mid2=(leftline[0][0]+rightline[0][0])/2;
          l=1;
          
        }
        if(((rightline[0][0]-rightline[0][1])>5)&&((rightline[0][1]-rightline[0][2])>5)&&((rightline[0][2]-rightline[0][3])>5))
        {
          leftline[0][0]=leftline[0][2]-5;
          rightline[0][0]=rightline[0][2]-5;
          mid=(leftline[0][0]+rightline[0][0])/2;//
          mid2=(leftline[0][0]+rightline[0][0])/2;
          r=1;
          
        }
        if((!l)&&(!r))
        { leftline[0][0]=leftline[0][1];
           rightline[0][0]=rightline[0][1];
           mid=(leftline[0][0]+rightline[0][0])/2;//
          mid2=(leftline[0][0]+rightline[0][0])/2;//
        }
        if(leftline[0][1]>75)
      {mid=leftline[0][0]+roadside/2;
       leftline[0][0]=rightdeadline-20;
       mid2=rightdeadline-20;
      }
      else if(rightline[0][1]<50)
      {mid=rightline[0][0]-roadside/2;
       leftline[0][0]=rightdeadline-10;
       mid2=rightdeadline-10;
        
      }*/
      if(leftline[0][1]>leftdeadline&&rightline[0][1]<rightdeadline)
      {  
         leftline[0][0]=leftline[0][1];
         rightline[0][0]=rightline[0][1];
         mid=(leftline[0][0]+rightline[0][0])/2;//
        mid2=(leftline[0][0]+rightline[0][0])/2;//
      }
      if(leftline[0][1]<=leftdeadline&&rightline[0][1]<rightdeadline)
      {  
         leftline[0][0]=leftline[0][1];
         rightline[0][0]=rightline[0][1];
         mid=(leftline[0][0]+rightline[0][0])/2;//
        mid2=(leftline[0][0]+rightline[0][0])/2;//
      }
      if(leftline[0][1]>leftdeadline&&rightline[0][1]>=rightdeadline)
      {  
         leftline[0][0]=leftline[0][1];
         rightline[0][0]=rightline[0][1];
         mid=(leftline[0][0]+rightline[0][0])/2;//
        mid2=(leftline[0][0]+rightline[0][0])/2;//

      }
      
      } 
  
}
/*
 * @file       zhongxianchuli.h
 * @brief      边界处理函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void zhongxianchuli2()
{     
       Mid2=Mid1;
          Mid1=mid;//白天60晚上40
       /* two line in visual feild  */
      if(imagestore[0][0]>leftdeadline&&imagestore[0][1]<rightdeadline)
       { imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
        
       if(imagestore[1][0]>leftdeadline&&imagestore[1][1]<rightdeadline)
        {
         
           
           
           
         
         
          imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
         
        }
        if(imagestore[1][0]<=leftdeadline&&imagestore[1][1]>=rightdeadline) 
        {
          
           imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
           
            imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
           
        
        
        }
        if(imagestore[1][0]<=leftdeadline&&imagestore[1][1]<rightdeadline) 
        {  if(ABS(imagestore[1][1]-imagestore[0][1])>20||ABS(imagestore[1][0]-imagestore[0][0])>20)
        {  imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
          imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
           
        
        }
        else
        {  imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
           
        }
        
        }
        if(imagestore[1][0]>leftdeadline&&imagestore[1][1]>=rightdeadline)
        { if(ABS(imagestore[0][0]-imagestore[1][0])>20||ABS(imagestore[0][0]-imagestore[1][0])>20)
        {  imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
            imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
           
        }
        else
        { imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
        }
        
        }
        
       }
     //oniy left line in visual view
      if(imagestore[0][0]>leftdeadline&&imagestore[0][1]>=rightdeadline)
       {  imagestore[0][2]=imagestore[0][0]+imagestore[0][3]/2;
          if(imagestore[1][0]>leftdeadline&&imagestore[1][1]>=rightdeadline)
          {  
      imagestore[0][2]=imagestore[0][0]+imagestore[0][3]/2;
           
           
          }
         if(imagestore[1][0]<=leftdeadline&&imagestore[1][1]<rightdeadline)
         { if(ABS(imagestore[1][0]-imagestore[0][0])>20)    
         {imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
            imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
         }
           
         
         else
         {
           imagestore[0][2]=imagestore[0][0]+imagestore[0][3]/2;
         }
         }
         if(imagestore[1][0]<leftdeadline&&imagestore[1][1]>rightdeadline)
         {
           imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
          
           
         }
         if(imagestore[1][0]>leftdeadline&&imagestore[1][1]<rightdeadline)
         {  
           if(ABS(imagestore[1][0]-imagestore[0][0])>20)    
         {imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
            imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
         }
           
         
         else
         {
           imagestore[0][2]=imagestore[0][0]+imagestore[0][3]/2;
         }
         }
         
       }
      //only right line in visual view
     if(imagestore[0][0]<=leftdeadline&&imagestore[0][1]<rightdeadline)
      {   
           if(imagestore[1][0]<=leftdeadline&&imagestore[1][1]<rightdeadline)
          {  
           imagestore[0][2]=(imagestore[0][1]-(imagestore[0][3]/2));
         
          }
           
          
          if(imagestore[1][0]>leftdeadline&&imagestore[1][1]>=rightdeadline)
          { if(ABS(imagestore[1][0]-imagestore[1][1])>20)
          {imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
         imagestore[0][2]=(imagestore[0][1]-imagestore[0][3]/2);
          
          
          }
          else
          {
            imagestore[0][2]=(imagestore[0][1]-imagestore[0][3]/2);
     
          }
          
          }
           
        if(imagestore[1][0]<leftdeadline&&imagestore[1][1]>rightdeadline)
        { imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
          
        }
     if(imagestore[1][0]>leftdeadline&&imagestore[1][1]<rightdeadline)
        {if(ABS(imagestore[1][1]-imagestore[0][1])>20)//15虽前瞻变而随时调整
          { imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
          imagestore[0][2]=(imagestore[0][1]-imagestore[0][3]/2);
          }
           else
           {imagestore[0][2]=(imagestore[0][1]-imagestore[0][3]/2);
           }
          b=1;  
      }
        
      }
      //two line not in visual view
     if(imagestore[0][0]<=leftdeadline&&imagestore[0][1]>=rightdeadline)
      { 
      // imagestore[0][2]= imagestore[1][2];
        
      if(imagestore[1][0]>leftdeadline&&imagestore[1][1]<rightdeadline)
      {  
         imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
            imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
      }
      if(imagestore[1][0]<=leftdeadline&&imagestore[1][1]<rightdeadline)
      {  
        imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
            imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;
      }
      if(imagestore[1][0]>leftdeadline&&imagestore[1][1]>=rightdeadline)
      {  
         imagestore[0][0]=imagestore[1][0];
           imagestore[0][1]=imagestore[1][1];
            imagestore[0][2]=(imagestore[0][0]+imagestore[0][1])/2;

      }
      
      } 
  
}




/*
 * @file       zhongxianchuli.h
 * @brief      图像存储函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
 */
void storeimage()
{  int i,j;
  for(i=7;i>0;i--)
  {imagestore[i][0]=imagestore[i-1][0];
   imagestore[i][1]=imagestore[i-1][1]; 
   imagestore[i][2]=imagestore[i-1][2];
   imagestore[i][3]=imagestore[i-1][3];
   
  }
   for(i=7;i>0;i--)
  {imagestore2[i][0]=imagestore2[i-1][0];
   imagestore2[i][1]=imagestore2[i-1][1]; 
   imagestore2[i][2]=imagestore2[i-1][2];
   imagestore2[i][3]=imagestore2[i-1][3];
   
  }
  
     
  
  
}