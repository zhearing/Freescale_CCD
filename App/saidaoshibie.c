#include "common.h"
#include "include.h"
#define turnleft 1
#define turnright 2
#define straight 3
extern int leftfangxiang;
extern int zhidaocishu;
extern int shizicishu;
extern int wandaocishu;
extern int zhangaicishu;
extern int rightfangxiang;
extern int LeftBigBendflag;//左大弯道标志
extern int RightBigBendflag;//右大弯道标志
extern int LittleBendflag;//小弯道标志
extern int Crossflag;
extern int Obstacleflagup;
extern int Obstacleflagup2;
extern int Obstacleflagdown;
extern int Straightflag;
extern unsigned char ccd[3][128];
extern unsigned char right[8][8];
extern unsigned char right[8][8];
extern unsigned char left[8][8];
extern uint8 rightline[8][8];
extern uint8 leftline[8][8];
extern uint8 imagestore[8][4];
extern int  rightdeadline;
extern short int nextError;
extern uint8 zuoflag3;
extern uint8 youflag3;
extern int16 gyroscope2;
extern int q;
extern int w;
extern int16 gyroscope;
extern int16 gyroscope1[5];
extern int  leftdeadline;
extern int LeftBigBendflag;//左大弯道标志
extern int RightBigBendflag;//右大弯道标志
extern int LittleBendflag;//小弯道标志

/*
 * @file       zhongxianchuli.h
 * @brief      十字识别函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
*/
void crossroads()
{  int Rline,Lline,Rline_now,Lline_now,Rline_last,Lline_last,Rline_last_last,Lline_last_last;
   int i;
    for(i=0;i<3;i++)
    {
    if((rightline[0][i]!=128)&&(rightline[0][i]>leftdeadline)&&(rightline[0][i]<leftdeadline))Rline++;
    }
    for(i=0;i<2;i++)
    {
    if((leftline[0][i]!=0)&&(leftline[0][i]>leftdeadline)&&(leftline[0][i]<leftdeadline))Lline++;
    }
    if((!Lline)&&(Rline))
    {if((rightline[0][0]>imagestore[0][2])&&(rightline[0][0]<rightdeadline))
         Rline_now=rightline[0][0];
     if((rightline[0][1]>imagestore[1][2])&&(rightline[0][1]<rightdeadline))
         Rline_last=rightline[0][1];
     if((rightline[0][2]>imagestore[2][2])&&(rightline[0][2]<rightdeadline))
         Rline_last_last=rightline[0][2];
     if((Rline_now-Rline_last)>5&&(Rline_now-Rline_last)<10&&(Rline_last-Rline_last_last)>5&&(Rline_last-Rline_last_last)<10)
       Crossflag=turnleft;//need turnleft
      
    }
    if((Lline)&&(!Rline))
    {if((leftline[0][0]<imagestore[0][2])&&(leftline[0][0]>leftdeadline))
         Lline_now=leftline[0][0];
     if((leftline[0][1]<imagestore[1][2])&&(leftline[0][1]>leftdeadline))
         Lline_last=leftline[0][1];
     if((leftline[0][2]<imagestore[2][2])&&(leftline[0][2]>leftdeadline))
         Lline_last_last=leftline[0][2];
     if((Lline_now-Lline_last)>5&&(Lline_now-Lline_last)<10&&(Lline_last-Lline_last_last)>5&&(Lline_last-Lline_last_last)<10)
       Crossflag=turnright;//need turnright
      
    }
    if((!Lline)&&(!Rline))
    {if((leftline[0][0]<imagestore[0][2])&&(leftline[0][0]>leftdeadline)&&(leftline[0][0]>imagestore[0][2])&&(leftline[0][0]>leftdeadline))
         Rline_now=leftline[0][0];
     if((leftline[0][1]<imagestore[1][2])&&(leftline[0][1]>leftdeadline)&&(leftline[0][1]>imagestore[1][2])&&(leftline[0][1]>leftdeadline))
         Rline_last=leftline[0][1];
     if((leftline[0][2]<imagestore[2][2])&&(leftline[0][2]>leftdeadline)&&(leftline[0][2]>imagestore[2][2])&&(leftline[0][2]>leftdeadline))
         Rline_last_last=leftline[0][2];
     if((Rline_now-Rline_last)<5&&(Rline_last-Rline_last_last)<5&&(Rline_now-Rline_last)<5&&(Rline_last-Rline_last_last)<5)
       Crossflag=straight;//need Go straight
      
    }
    
    
  

}
void caiji()

{   
    int k;
    int i;
    gyroscope=0;
    for(i=4;i>0;i--)
        {
          gyroscope1[i]=gyroscope1[i-1];
          
        }
   for(k=0;k<5;k++)
        {
          gyroscope=gyroscope+adc_once(ADC0_SE16, ADC_8bit);
        }
    
        gyroscope=0.2*gyroscope;
        gyroscope1[0]=gyroscope;
        gyroscope2=(gyroscope1[1]+gyroscope1[0])*0.5;
  
}
/*
 * @file       zhongxianchuli.h
 * @brief      障碍识别函数
 * @author     方希康
 * @version    v5.1
 * @date       2016-03-13
*/
void Obstacle()
{ int Rline,Lline,Rline_now,Lline_now,Rline_last,Lline_last,Rline_last_last,Lline_last_last;
  int temp1,temp2,temp3,temp4,temp5,temp6,temp7;
   if((rightline[0][0]<rightdeadline)&&(rightline[0][0]>imagestore[0][2]))
     Rline_now=rightline[0][0];
   if((rightline[0][1]<rightdeadline)&&(rightline[0][1]>imagestore[1][2]))
     Rline_last=rightline[0][1];
   if((rightline[0][2]<rightdeadline)&&(rightline[0][2]>imagestore[2][2]))
     Rline_last_last=rightline[0][2];
   if((leftline[0][0]>leftdeadline)&&(leftline[0][0]<imagestore[0][2]))
     Lline_now=leftline[0][0];
   if((leftline[0][1]>leftdeadline)&&(leftline[0][1]<imagestore[1][2]))
     Lline_last=leftline[0][1];
   if((leftline[0][2]>leftdeadline)&&(leftline[0][2]<imagestore[2][2]))
     Lline_last_last=leftline[0][2];
   temp5=imagestore[1][3]-imagestore[2][3];
   temp5=ABS(temp5);
   temp6=imagestore[2][3]-imagestore[3][3];
   temp6=ABS(temp6);
   temp7=imagestore[3][3]-imagestore[4][3];
   temp7=ABS(temp7);
     if((temp5<6)&&(temp6<6)&&(temp7<6))
     {
   temp1=Rline_now-Rline_last;
   temp1=ABS(temp1);
   temp2=Lline_now-Lline_last;
   temp2=ABS(temp2);
   temp3=Rline_last-Rline_last_last;
   temp3=ABS(temp3);
   temp4=Lline_last-Lline_last_last;
   temp4=ABS(temp4);
   if((temp1>10)&&(temp3<6)&&(temp4<6)&&(temp2<6))
     Obstacleflagup=turnleft;//需要左转
   if((temp2>10)&&(temp3<6)&&(temp4<6)&&(temp1<6))
     Obstacleflagup=turnright;//需要右转
     
     }
 
}
/*
* @file       saidaoshibie.h
* @brief      直线识别函数
* @author     方希康
* @version    v5.1
* @date       2016-03-13
*/
void Straightline()
{
   int Rline,Lline,Rline_now,Lline_now,Rline_last,Lline_last,Rline_last_last,Lline_last_last;
  int temp1,temp2,temp3,temp4,temp5,temp6,temp7;
  /* temp1=imagestore[0][2]-imagestore[1][2];
   temp1=ABS(temp1);
  temp2=imagestore[1][2]-imagestore[2][2];
   temp2=ABS(temp2);
   temp3=imagestore[0][0]-imagestore[1][0];
   temp3=ABS(temp3);
   temp4=imagestore[1][0]-imagestore[2][0];
   temp4=ABS(temp4);
   temp5=imagestore[1][3]-imagestore[2][3];
   temp5=ABS(temp5);
   temp6=imagestore[2][3]-imagestore[3][3];
   temp6=ABS(temp6);
   temp7=imagestore[3][3]-imagestore[4][3];
   temp7=ABS(temp7);*/
  
    
     if(gyroscope2>100)
     
     {   
       
     shizicishu++;
    
    }   
   if(shizicishu>=2&&gyroscope2<5)
     {
       Obstacleflagup=1;
       shizicishu=0;
       
     }
   
      
   
      if(gyroscope2>100&&Obstacleflagup==1)
     {
       
       
    zhangaicishu++;//
     
     
     }
     if(zhangaicishu>=2&&gyroscope2<5)
     {
       Obstacleflagup=0;
       zhangaicishu=0;
     }
    
     if(ABS(nextError)<150)
     {
       zhidaocishu++;
       
     }
     if(zhidaocishu>50)
     {
       Straightflag=1;
       LittleBendflag=0;
       
     }
     if(ABS(nextError)>200)
     {
       wandaocishu++;
       
     }
     if(wandaocishu>20)
     {
       LittleBendflag=1;
       
       
     }
     
    
    
   

}
/*
* @file       saidaoshibie.h
* @brief      大弯道识别函数
* @author     方希康
* @version    v5.1
* @date       2016-03-13
*/
void Bendroad()
{
  
  int Rline,Lline,Rline_now,Lline_now,Rline_last,Lline_last,Rline_last_last,Lline_last_last;
  
    //晚上
    if((rightline[0][0]<105)&&(rightline[0][1]<105)&&(rightline[0][2]<105)&&(ABS(rightline[0][0]-leftline[0][0])<85)&&(leftline[0][0]<35)&&(leftline[0][1]<35)) LeftBigBendflag=1;
    
    
    if((leftline[0][0]>30)&&(leftline[0][1]>30)&&(ABS(rightline[0][0]-leftline[0][0])<85)&&(rightline[0][0]>105)&&(rightline[0][1]>105))RightBigBendflag=1;
   //白天
    // if((leftline[0][0]>25)&&(rightline[0][0]>120)&&(ABS(rightline[0][0]-leftline[0][0])<90)&&(ABS(rightline[0][0]-leftline[0][0])>50)) LeftBigBendflag=1;
    
    
    //if((rightline[0][0]<118)&&(leftline[0][0]<15)&&(ABS(rightline[0][0]-leftline[0][0])<90)&&(ABS(rightline[0][0]-leftline[0][0])>50))RightBigBendflag=1;
   
    
   // if((!Lline)&&(Rline))
   // { LeftBigBendflag=1;
      //if((rightline[0][0]>imagestore[0][2])&&(rightline[0][0]<rightdeadline))
        // Rline_now=rightline[0][0];
     //if((rightline[0][1]>imagestore[1][2])&&(rightline[0][1]<rightdeadline))
       //  Rline_last=rightline[0][1];
     //if((rightline[0][2]>imagestore[2][2])&&(rightline[0][2]<rightdeadline))
      //   Rline_last_last=rightline[0][2];
     //if((Rline_last-Rline_now)>5&&(Rline_last_last-Rline_last)>5)
      // LeftBigBendflag=1;//need bigturnleft
     
      
   // }
    //if((Lline)&&(!Rline))
   // { RightBigBendflag=1;
      //if((leftline[0][0]>imagestore[0][2])&&(leftline[0][0]>leftdeadline))
       //  Lline_now=leftline[0][0];
     //if((leftline[0][1]>imagestore[1][2])&&(leftline[0][1]>leftdeadline))
      //   Lline_last=leftline[0][1];
    // if((leftline[0][2]>imagestore[2][2])&&(leftline[0][2]>leftdeadline))
      //   Lline_last_last=leftline[0][2];
    // if((Lline_last-Lline_now)>10&&(Lline_last_last-Lline_last)>10)
       //RightBigBendflag=1;//need bigturnright
   
      
    
  
}
/*
* @file       saidaoshibie.h
* @brief      小弯道识别函数
* @author     方希康
* @version    v5.1
* @date       2016-03-13
*/
void bendroad()
{   int temp1,temp2,temp3,temp4,temp5,temp6,temp7;
  temp5=imagestore[1][3]-imagestore[2][3];
   temp5=ABS(temp5);
   temp6=imagestore[2][3]-imagestore[3][3];
   temp6=ABS(temp6);
   temp7=imagestore[3][3]-imagestore[4][3];
   temp7=ABS(temp7);
     if((temp5<4)&&(temp6<4)&&(temp7<4))
     {
   temp1=rightline[0][0]-rightline[0][1];
   temp1=ABS(temp1);
   temp2=leftline[0][0]-leftline[0][0];
   temp2=ABS(temp2);
   temp3=rightline[0][0]-rightline[0][1];
   temp3=ABS(temp3);
   temp4=leftline[0][1]-leftline[0][2];
   temp4=ABS(temp4);
   if(((temp1>5)&&(temp2>5)&&(temp1<12)&&(temp2<12))||((temp3>5)&&(temp4>5)&&(temp3<12)&&(temp4<12)))
   {
     
     LittleBendflag=1;
     
   }
     
     }
  /*   led_init(LED0);                         //初始化LED0
    led_init(LED1);                         //初始化LED1

    while(1)
    {        
        led(LED0, LED_ON);                  //LED0 亮
        led_turn(LED1);                     //LED1翻转

        DELAY_MS(500);                      //延时500ms

        led(LED0, LED_OFF);                 //LED0 灭
        led_turn(LED1);                     //LED1翻转

        DELAY_MS(500);                      //延时500ms
    }*/
  
  
}
/*
* @file       saidaoshibie.h
* @brief      赛道标志及赛道快速处理函数
* @author     方希康
* @version    v5.1
* @date       2016-03-13
*/
void Trackdeal()
{
  
    Straightline();
  
    
}