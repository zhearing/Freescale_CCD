#include "common.h"
#include "include.h"
extern int8 Menu_num;//菜单数
extern int16 Menu_data_num[20];//数据存储区
extern int16 *Menu_Num;//数组指针
extern int8 Window_Num;//窗口数   
extern int8 Menu_set;//菜单页数设定
extern int mid2;
extern uint8 CCD2[3][TSL1401_SIZE];
extern short int speedaboutangle;
extern unsigned char roadside;
extern int16 max3;
extern int daolu;
extern int16 min3;
extern int16 smax;
extern int16 smin;
extern int Crossflag;
extern int Obstacleflagup2;
extern uint8 zuoflag3;
extern uint8 youflag3;
extern int hongwaiflag;
extern Site_t site_1;//{10,10}
extern Site_t site_2;//
extern Site_t site_3;
extern Site_t site_4;
extern Site_t site_5;
extern Site_t site_6;
extern Site_t site_7;
extern Site_t site_8;
extern Site_t site_9;
extern Site_t site_10;
extern uint8 flag1;
extern uint8 flag2;
extern int16 gyroscope1[5];
extern int Obstacleflagup;
extern int Obstacleflagdown;
extern int Straightflag;
extern int LeftBigBendflag;//左大弯道标志
extern int RightBigBendflag;//右大弯道标志
extern short int car_speedl;
extern short int car_speedl;
extern short int car_speedr;
extern long int car_speed;
Site_t site1b2={20,20+40};
Site_t site1b3={20,40+40};
Site_t site1b4={20,40+60};
Site_t site1b5={60,40+40};
extern uint8 imagestore[8][4];
Site_t site1={0,0};
Site_t site2={0,25};
Site_t site3={0,50};
Site_t site4={0,75};
Site_t site21={0,70};
Site_t site22={0,70};
Site_t site11={0,0};
Site_t site12={0,0};
Site_t sitey1={10,10};
Site_t sitey1x={40,10};
Site_t sitey2={10,30};
Site_t sitey2x={40,30};
Site_t sitey3={10,50};
Site_t sitey3x={40,50};
Site_t sitey4={10,70};
Site_t sitey4x={40,70};
Site_t sitey5={10,90};
Site_t sitey5x={40,90};
Site_t sitey6={10,110};
Site_t sitey6x={40,110};
Site_t sitey7={70,10};
Site_t sitey7x={100,10};
Site_t sitey8={70,30};
Site_t sitey8x={100,30};
Site_t sitey9={70,50};
Site_t sitey9x={100,50};
Site_t sitey10={70,70};
Site_t sitey10x={100,70};
Site_t sitey11={70,90};
Site_t sitey11x={100,90};
extern int16 gyroscope;
extern int m,n;
extern uint8 rightline[8][8];
extern uint8 leftline[8][8];
extern uint8 rightline2[8][8];
extern uint8 leftline2[8][8];
extern short int nextError;
extern unsigned char fazhi1;
extern long int rightval;
extern long int leftval;
extern short int speedreal;
extern long int speedreal2;
extern int8 Menu_num_old;
extern uint8 Window_Num_old;
extern Site_t site11;
extern int fazhi2max;
extern uint8 CCD[3][TSL1401_SIZE];
extern uint8 CCD_BUFF[TSL1401_MAX*3][TSL1401_SIZE];
extern Size_t size={TSL1401_SIZE,20};
extern Size_t imgsize={TSL1401_SIZE,1}; 
extern int delayen;
extern int error;
extern int fazhi2min;
extern int stop;
extern long int speedwant;
void Key_init()
{
key_init(KEY_U);
key_init(KEY_D);
key_init(KEY_L);
key_init(KEY_R);
key_init(KEY_B);

}
void Key_deal()
{   int i=0;
  Menu_num=Menu_Num-Menu_data_num;
  if(Menu_num>Menu_set)
  {Menu_Num=Menu_data_num;
    Menu_num=0;
  }
    if(Menu_num<0)
    {Menu_Num=Menu_data_num+Menu_set-1;
    Menu_num=Menu_set-1;
    }
  
  if(key_get(KEY_U) == KEY_DOWN)
    {  delayen=0;
        DELAY_MS(20);
        if( key_get(KEY_U) == KEY_DOWN)
        {  
          while(key_get(KEY_U) == KEY_DOWN)
          {  DELAY_MS(20);
              i++;
              if(i>100)
              {   i=90;
               (*Menu_Num)=(*Menu_Num)+2;
               LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);
              }
            
          }
            
            
          (*Menu_Num)=(*Menu_Num)+1;  
        }
     DELAY_MS(20);
    
    }
   if(key_get(KEY_D) == KEY_DOWN)
    {    i=0;
        
       delayen=0;
        
        if( key_get(KEY_D) == KEY_DOWN)
        {  
          while(key_get(KEY_D) == KEY_DOWN)
          {  DELAY_MS(20);
              i++;
              if(i>100)
              {  i=90;
               (*Menu_Num)=(*Menu_Num)-2;
              LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);
              }
            
          }
            
            
          (*Menu_Num)=(*Menu_Num)-1;  
        }
    
    
    
    DELAY_MS(20);
    
    }
  if(key_get(KEY_L) == KEY_DOWN)
    {   i=0;
        DELAY_MS(20);
        
          
          while(key_get(KEY_L) == KEY_DOWN)
          {  DELAY_MS(50);
              i++;
              if(i>20)
              {delayen++;
              DELAY_MS(100);
               //Menu_Num=Menu_Num+9; 
              }
            
          }
            
            
          Menu_Num=Menu_Num+1;  
        
    
    
    }
  if(key_get(KEY_R) == KEY_DOWN)
    {    i=0;
        DELAY_MS(20);
        if( key_get(KEY_R) == KEY_DOWN)
        {  
          while(key_get(KEY_R) == KEY_DOWN)
          {  DELAY_MS(10);
              i++;
              if(i>100)
              {
                delayen++;
                DELAY_MS(100);
              // Menu_Num=Menu_Num-9; 
              }
            
          }
            
            
          Menu_Num=Menu_Num-1;  
        }
    
    
    }
  
  
  
  
  
}
void Key_dealWindows()
{  int i=0;
  if(key_get(KEY_B) == KEY_DOWN)
    {  if(delayen==1)
      delayen=0;
        DELAY_MS(10);
         if(key_get(KEY_B) == KEY_DOWN)
         { while(key_get(KEY_B) == KEY_DOWN)
          {  DELAY_MS(10);
              i++;
              if(i>100)
              {
            // Window_Num=Window_Num+2;
             delayen++;
             DELAY_MS(100);
              }
            
          }
            
            
          Window_Num=Window_Num+1;  
        
         }
    
    }
  if(Window_Num>3)
    {
      Window_Num=0;
    }
  
  
}
void Menu_data_Display()
{   
  if(Menu_num_old!=Menu_num)
  {//LCD_str (site_7,"change", BLUE, RED);
    LCD_clear(RED);
  }
    
  switch(Menu_num)
  { case 0:LCD_str (site_2,"speedwant", BLUE, RED);LCD_num_BC(site1b2,speedwant,32, BLUE,RED);
  
          break;
    case 1:LCD_str (site_2,"duojiKp", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 2:LCD_str (site_2,"duojikd", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 3:LCD_str (site_2,"MotorKp warning", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 4:LCD_str (site_2,"MotorKd", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 5:LCD_str (site_2,"daolu", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 6:LCD_str (site_2,"fazhi2max", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 7:LCD_str (site_2,"fazhi2min", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 8:LCD_str (site_2,"fazhimin", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 9:LCD_str (site_2,"ko", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 10:LCD_str (site_2,"ka", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 11:LCD_str (site_2,"ks", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 12:LCD_str (site_2,"kd", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 13:LCD_str (site_2,"kf", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 14:LCD_str (site_2,"kg", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
    case 15:LCD_str (site_2,"kh", BLUE, RED);LCD_num_BC(site1b2,Menu_data_num[Menu_num],32, BLUE,RED);break;
  
  

 
 }
 Menu_num_old=Menu_num;
  
  
  
}
 void Menu_Display()
{ 
   int temp1,temp2;
   if(Window_Num_old!=Window_Num)
  {//LCD_str (site_7,"change", BLUE, RED);
    LCD_clear(RED);
  }
 temp1=gyroscope1[0];
  
  switch(Window_Num)
  { 
    case 0:Menu_data_Display();break;//显示数据
    case 1:LCD_Img_gray_Z(site1,size,(uint8 *)&CCD[2],imgsize);
            LCD_Img_gray_Z(site2,size,(uint8 *)&CCD_BUFF[0],imgsize);
            LCD_wave_display(site11,site12,site1,size,(uint8 *)&CCD[2],fazhi2max,fazhi2min,0xff,BLUE );
           // LCD_wave_display(site11,site12,site1,size,(uint8 *)&CCD[0],fazhi2max,fazhi2min,0xff,GREEN);
            LCD_wave_display(site21,site22,site2,size,(uint8 *)&CCD_BUFF[0],fazhi2max,fazhi2min,0xff,BLUE );
            LCD_Img_gray_Z(site3,size,(uint8 *)&CCD[1],imgsize);
            LCD_Img_gray_Z(site4,size,(uint8 *)&CCD2[1],imgsize);break;//
    case 2: 
           LCD_str (sitey1,"sd", BLUE, RED);
           LCD_str (sitey2,"yz", BLUE, RED);
           LCD_str (sitey3,"stop", BLUE, RED);
           LCD_str (sitey4,"Hmn", BLUE, RED);
           LCD_str (sitey5,"Zb", BLUE, RED);
           LCD_str (sitey6,"Yb", BLUE, RED);
           LCD_str (sitey7,"UP", BLUE, RED);
           LCD_str (sitey8,"DN", BLUE, RED);
           LCD_str (sitey9,"TLY", BLUE, RED);
           LCD_str (sitey10,"Zx", BLUE, RED);
           LCD_num_BC(sitey1x,imagestore[0][3],32, BLUE,RED);
           LCD_num_BC(sitey2x,(smax+smin)/2,32, BLUE,RED);
           LCD_num_BC(sitey3x,stop,32, BLUE,RED);
           LCD_num_BC(sitey4x,smin,32, BLUE,RED);
           LCD_num_BC(sitey5x,ABS(imagestore[0][0]),32, BLUE,RED);
           LCD_num_BC(sitey6x,imagestore[0][1],32, BLUE,RED);
           LCD_num_BC(sitey7x,Obstacleflagup,32, BLUE,RED);
           LCD_num_BC(sitey8x,Obstacleflagdown,32, BLUE,RED);
           LCD_num_BC(sitey9x,gyroscope,32, BLUE,RED);
           LCD_num_BC(sitey10x,imagestore[0][2],32, BLUE,RED);
          
           if(rightval<=0)
           {
           LCD_str (sitey11,"PC-", BLUE, RED);
           LCD_num_BC(sitey11x,ABS(rightval),32, BLUE,RED);}
           if(rightval>0)
           {
           LCD_str (sitey11,"PC+", BLUE, RED);
           LCD_num_BC(sitey11x,ABS(rightval),32, BLUE,RED);}
          break;
    case 3:LCD_num_BC(site1b2,ABS(rightval),32, BLUE,RED);LCD_num_BC(site1b3,ABS(leftval),32, BLUE,RED);LCD_num_BC(site1b4,ABS(car_speed),32, BLUE,RED);break;//speedreal
    //case 4:LCD_str (site_7,"windows4", BLUE, RED); LCD_Img_gray_Z(site1,size,(uint8 *)&CCD[1],imgsize);break;//
    //case 5:LCD_str (site_7,"windows5", BLUE, RED); LCD_Img_gray_Z(site1,size,(uint8 *)&CCD_BUFF[0],imgsize);break;//
    
  }
  Window_Num_old=Window_Num;
  
}


