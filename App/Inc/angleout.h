#ifndef __angleout_h__
#define __angleout_h__
extern int zhidaocishu;
extern int wandaocishu;
extern int zhangaicishu;
extern int shizhicishu;
extern int error;
extern int error1[4];
extern int lastError;
extern int Kpduoji;
extern int mid;
extern int duojiKp;
extern int duojiKd;
extern int Obstacleflag;
extern short int nextError;
extern short int nextError2;
extern short int nextError1;
extern short int speedaboutangle;
extern int Kd;
extern int Midroad;
extern int leftfangxiang;
extern int rightfangxiang;
extern int Kp;
extern int mid2;
extern int Mid1;
extern short int daolu;
extern int Mid2;
extern uint8 imagestore[8][4];
extern uint8 imagestore2[8][4];
extern int Obstacleflagup;
extern int Obstacleflagup2;
extern int Obstacleflagdown;
extern int16 out[5];
void angleout()
{   
      int16 angle1;
      int16 AD;
      int16 mid;
      if(Obstacleflagup==0)
{     mid=imagestore[0][2];
      error=Midroad-mid;
      Kpduoji=ABS(error)*0.95+duojiKd;
      //Kpduoji=duojiKd;
      AD=error-lastError;
      nextError=(Kpduoji*error+Kd*AD);
      lastError=error;
       if(nextError>0&&nextError>900)
      {
        nextError=900;
       
      }
      if(nextError<0&&nextError+900<0) 
      {  
        nextError=-900;
      
      }
    
      if((nextError>0&&nextError<30))
    {
       ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError);
    }
      else if(nextError<0&&nextError+30>0)
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError);
     }
   if((nextError>0)&&nextError>=30)
     {
      ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError);
       
     
     } 
      if ((nextError<0)&&(nextError+30<=0))
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError);
     
     }
}
   if(Obstacleflagup==1)
{     mid=imagestore2[0][2];
      error=Midroad-mid;
      Kpduoji=ABS(error)*0.95+duojiKd;
      //Kpduoji=duojiKd;
      AD=error-lastError;
      nextError1=(Kpduoji*error+Kd*AD);
      lastError=error;
               if(nextError1>0&&nextError1>900)
      {
        nextError1=900;
       
      }
      if(nextError1<0&&nextError1+900<0) 
      {  
        nextError1=-900;
      
      }
    
      if((nextError1>0&&nextError1<30))
    {
       ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError1);
    }
      else if(nextError1<0&&nextError1+30>0)
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError1);
     }
   if((nextError1>0)&&nextError1>=30)
     {
      ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError1);
       
     
     } 
      if ((nextError1<0)&&(nextError1+30<=0))
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7750+nextError1);
     
     }
      nextError=0;
     
}



      
     
      
      
      
      
      
     
    
  
    
     //vcan_sendccd(ccdbuff00,1*TSL1401_SIZE); 
     
   
}
void angleout2()
{     int16 angle1;
      int16 AD;
      int16 mid;
      int k=40;
      int temp;
      int temp1;
      temp=ABS(imagestore[1][1]-imagestore[1][0]);
      temp1=ABS(imagestore[0][1]-imagestore[0][0]);
      out[4]=out[3];
      out[3]=out[2];
      out[2]=out[1];
      out[1]=out[0];
      mid=imagestore[0][2];
     
     
      error=Midroad-mid;
      Kpduoji=ABS(error)*0.95+duojiKd;//ԭֵ0.95
      AD=error-lastError;
      nextError1=(Kpduoji*error+Kd*AD);
      lastError=error;
    // if(ABS(nextError-nextError1)<600)
     
      nextError=nextError1;
     
     
         if(nextError>0&&nextError>900)
      {
        nextError=900;
       
      }
      if(nextError<0&&nextError+900<0) 
      {  
        nextError=-900;
      
      }
    
    
      if((nextError>0&&nextError<30))
    {
       ftm_pwm_duty(FTM3, FTM_CH0,7810+nextError);
    }
      else if(nextError<0&&nextError+30>0)
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7810+nextError);
     }
   if((nextError>0)&&nextError>=30)
     {
      ftm_pwm_duty(FTM3, FTM_CH0,7810+nextError);
       
     
     } 
      if ((nextError<0)&&(nextError+30<=0))
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7810+nextError);
     
     }
  
      
      
      
       
    /* if(nextError>0&&nextError>900)
      {nextError=900;
           }
      if(nextError<0&&nextError+900<0) 
      {  nextError=-900;
      
      }
     if((nextError>0&&nextError<30))
    {
       ftm_pwm_duty(FTM3, FTM_CH0,7700);
    }
      else if(nextError<0&&nextError+30>0)
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7700);
     }
    if((nextError>0)&&nextError>=30)
     {
      ftm_pwm_duty(FTM3, FTM_CH0,7700+nextError);
       
     
     } 
      if ((nextError<0)&&(nextError+30<=0))
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7700+nextError);
     
     }*/
     
   // ftm_pwm_duty(FTM3, FTM_CH0,7500);
     //vcan_sendccd(ccdbuff00,1*TSL1401_SIZE); 
     
   
}
void angleout3()
{     int angle1;
      int AD;
      int mid;
      error1[3]=error1[2];
      error1[2]=error1[1];
      error1[1]=error1[0];
      mid=imagestore[0][2];
      error1[0]=Midroad-mid;
      error1[0]=(error1[3]+error1[2]+error1[1]+error1[0])/4;
      Kpduoji=(error1[0]*error1[0])/duojiKp+duojiKd;
      AD=error1[0]-error1[1];
      nextError1=(Kpduoji*error1[0]+Kd*AD);
   
      nextError=nextError1;
      
  
      
      
      
       
    /* if(nextError>0&&nextError>900)
      {nextError=900;
           }
      if(nextError<0&&nextError+900<0) 
      {  nextError=-900;
      
      }
     if((nextError>0&&nextError<30))
    {
       ftm_pwm_duty(FTM3, FTM_CH0,7700);
    }
      else if(nextError<0&&nextError+30>0)
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7700);
     }
    if((nextError>0)&&nextError>=30)
     {
      ftm_pwm_duty(FTM3, FTM_CH0,7700+nextError);
       
     
     } 
      if ((nextError<0)&&(nextError+30<=0))
     {
       ftm_pwm_duty(FTM3, FTM_CH0,7700+nextError);
     
     }*/
     
   // ftm_pwm_duty(FTM3, FTM_CH0,7500);
     //vcan_sendccd(ccdbuff00,1*TSL1401_SIZE); 
     
   
}


#endif
