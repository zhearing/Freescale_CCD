#ifndef __speedcontrol_h__
#define __speedcontrol_h__
extern long int speederror;
extern long int speederror2;
extern long int speedwant;
extern long int speedout;
extern long int speedout2;
extern long int speedlasterror;
extern long int speedlasterror2;
extern int MotorKp;
extern int MotorKd;
extern long int rightval;
extern long int leftval;
extern short int speedreal;
extern long int speedreal2;
extern long int speedreal3;
extern short int speedaboutangle;
extern short int speedaboutangle2;
extern short int nextError;
extern short int nextError2;
extern short int nextError1;
extern short int nextError3;
extern int error;
extern int chashu;
extern float p1;
extern float p2;
extern int speedup;
extern float p3;
extern float y;
extern int16 motorprotect;
extern int16 motor;
extern int motorprotectflag;
extern short int daolu;
void speedcontrol()
{   static short int i=0;
  float k1=1;
  float k2=1;
  i++;
   static float Kp=4;
   static float Ki=4;
   short int speedwant_R;
   short int speedwant_L;
   static int16 speedreal_counter;
   static int16 speedreal2_counter;
   int16 speedreal_counter_change;
   rightval =ftm_quad_get(FTM1);
   ftm_quad_clean(FTM1);
   leftval =ftm_quad_get(FTM2);
   ftm_quad_clean(FTM2);
 
    speedreal=ABS(rightval);
      speedreal2=ABS(leftval);
speedreal3=(speedreal+speedreal2)/2;
    if(nextError>0&&nextError>900)
      {nextError=900;
           }
      if(nextError<0&&nextError+900<0) 
      {  nextError=-900;
      
      }
    if((nextError>0&&nextError<30))
    {
      speedwant_R=speedwant;
      speedwant_L=speedwant;
      speedreal_counter_change=(speedreal_counter+speedreal2_counter+(speedwant_R-speedreal)+(speedwant_L-speedreal2))/2;
      float I_endless=speedreal_counter_change*Ki;
      if(I_endless>960)speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
       if(I_endless<-960) speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
      if(ABS(I_endless)<=960)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal);
      speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2);
      }
      int16 v_counter=(speedreal_counter+speedreal2_counter)/2;
      speederror=((speedwant_R-speedreal)+(speedwant_L-speedreal2))/2;
      
      
      speedout=Kp*speederror+Ki*v_counter;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout;
    }
    if(nextError>=30)
    { // daolu=(2.864)*speedreal-400;
      y=(p1*ABS(nextError))*0.001+p2;
     
     // y=(0.000001*(p1*ABS(nextError)*ABS(nextError)*ABS(nextError))-0.000001*(p2*ABS(nextError)*ABS(nextError))+0.001*p3*ABS(nextError)+1.001);
     speedwant_R=(2*speedwant*y)/(1+y);
     speedwant_L=(2*speedwant)/(1+y);
     speedreal_counter_change=(speedreal_counter+speedreal2_counter+1.2*(speedwant_R-speedreal)+0.8*(speedwant_L-speedreal2))/2;
      float I_endless=speedreal_counter_change*Ki;
      if(I_endless>960)speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
       if(I_endless<-960) speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
      if(ABS(I_endless)<=960)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal);
      speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2);
      }
      int16 v_counter=(speedreal_counter+speedreal2_counter)/2;
      speederror=((speedwant_R-speedreal)+(speedwant_L-speedreal2))/2;
      
      
      speedout=Kp*speederror+Ki*v_counter;
      
      
      
     
      
      speedaboutangle=(2*speedout*y)/(1+y);
      speedaboutangle2=(2*speedout)/(1+y);
     // speedaboutangle2=(2*speedout)/(1+y);
     // speedaboutangle=(2*speedout*y)/(1+y);
     // speedaboutangle=speedout+(400*(nextError3+daolu))/10000;
   //speedaboutangle2=speedout-(400*(nextError3+daolu))/10000;
      
    }
     if((nextError<=0&&nextError+30>0))
    {
     speedwant_R=speedwant;
      speedwant_L=speedwant;
      speedreal_counter_change=(speedreal_counter+speedreal2_counter+0.8*(speedwant_R-speedreal)+1.2*(speedwant_L-speedreal2))/2;
      if(speedreal_counter>960)speedreal_counter=960;
      if(speedreal_counter<-960)speedreal_counter=-960;
      if(speedreal2_counter>960)speedreal2_counter=960;
      if(speedreal2_counter<-960)speedreal2_counter=-960;
      float I_endless=speedreal_counter_change*Ki;
      if(I_endless>960)speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
       if(I_endless<-960) speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
      if(ABS(I_endless)<=960)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal);
      speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2);
      }
      int16 v_counter=(speedreal_counter+speedreal2_counter)/2;
      speederror=((speedwant_R-speedreal)+(speedwant_L-speedreal2))/2;
      
      
      speedout=Kp*speederror+Ki*v_counter;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout;
    }
     if((nextError+30<=0))
    { 
     // y=(0.000001*(p1*ABS(nextError3)*ABS(nextError)*ABS(nextError))-0.000001*(p2*ABS(nextError)*ABS(nextError))+0.001*p3*ABS(nextError)+1.001);
      y=(p1*ABS(nextError))*0.001+p2;
     speedwant_R=(2*speedwant)/(1+y);
     speedwant_L=(2*speedwant*y)/(1+y);
     speedreal_counter_change=(speedreal_counter+speedreal2_counter+(speedwant_R-speedreal)+(speedwant_L-speedreal2))/2;
      float I_endless=speedreal_counter_change*Ki;
      if(I_endless>960)speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
       if(I_endless<-960) speedreal_counter_change=(speedreal_counter+speedreal2_counter)/2;
      if(ABS(I_endless)<=960)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal);
      speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2);
      }
      int16 v_counter=(speedreal_counter+speedreal2_counter)/2;
      speederror=((speedwant_R-speedreal)+(speedwant_L-speedreal2))/2;
      
      
      speedout=Kp*speederror+Ki*v_counter;
      
      speedaboutangle=(2*speedout)/(1+y);
      speedaboutangle2=(2*speedout*y)/(1+y);
     // speedaboutangle=(2*speedout)/(1+y);
     // speedaboutangle2=(2*speedout*y)/(1+y);
      //daolu=(0-2.864)*speedreal+400;
    // speedaboutangle=speedout+(400*(nextError3-daolu))/10000;
   //speedaboutangle2=speedout-(400*(nextError3-daolu))/10000;
    }
    // speedaboutangle=speedout+(400*(nextError3+2))/900;
  // speedaboutangle2=speedout-(400*(nextError3)+2)/900;
    
     if(speedaboutangle>1000)speedaboutangle=1000;
      if(speedaboutangle+1000<0)speedaboutangle=-1000;
      if(speedaboutangle2>1000)speedaboutangle2=1000;
      if(speedaboutangle2+1000<0)speedaboutangle2=-1000;
      
   if(speedaboutangle>0)
    {ftm_pwm_duty(FTM0, FTM_CH3,speedaboutangle);
    ftm_pwm_duty(FTM0, FTM_CH4,0);
    }
    if(speedaboutangle<0)
    {ftm_pwm_duty(FTM0, FTM_CH3,0);
    ftm_pwm_duty(FTM0, FTM_CH4,-speedaboutangle);}
    
   if(speedaboutangle2>0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,speedaboutangle2);
    ftm_pwm_duty(FTM0, FTM_CH6,0);
   }
   if(speedaboutangle2<0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,0);
    ftm_pwm_duty(FTM0, FTM_CH6,-speedaboutangle2);
   } 
   speedlasterror=speederror;
  
  
}
/*void speedcontrol2()
{   
  float k1=1;
  float k2=1;
 
  
   rightval =ftm_quad_get(FTM1);
   ftm_quad_clean(FTM1);
   leftval =ftm_quad_get(FTM2);
   ftm_quad_clean(FTM2);
   speedreal=(ABS(rightval)+ABS(leftval))/2;
  
   speederror=speedwant-speedreal;
  
   nextError3=(nextError*8)/10+(nextError1)*2/10;
   speedout=speedout+(MotorKd/10)*speederror+MotorKp*(speederror-speedlasterror);
   
    speedlasterror=speederror;
    if(speedout>0&&speedout>900)
    {
      speedout=900;
    }
    if(speedout<0&&speedout+900<0)
    {
      speedout=-900;
    }
    if(nextError>0&&nextError>900)
      {nextError=900;
           }
      if(nextError<0&&nextError+900<0) 
      {  nextError=-900;
      
      }
    if((nextError>0&&nextError<30))
    {
     speedaboutangle=speedout;
   speedaboutangle2=speedout;
    }
    if(nextError>=30)
    { // daolu=(2.864)*speedreal-400;
      //y=(p1*ABS(nextError))*0.001+p2;
      if(speedout>700)speedout=700;
      y=(0.000001*(p1*ABS(nextError)*ABS(nextError)*ABS(nextError))-0.000001*(p2*ABS(nextError)*ABS(nextError))+0.001*p3*ABS(nextError)+1.001);
      
    speedaboutangle2=(2*speedout)/(1+y);
    speedaboutangle=(2*speedout*y)/(1+y);
     // speedaboutangle=speedout+(400*(nextError3+daolu))/10000;
   //speedaboutangle2=speedout-(400*(nextError3+daolu))/10000;
      
    }
     if((nextError<=0&&nextError+30>0))
    {
     speedaboutangle=speedout;
   speedaboutangle2=speedout;
    }
     if((nextError+30<=0))
    { if(speedout>700)speedout=700;
      y=(0.000001*(p1*ABS(nextError)*ABS(nextError)*ABS(nextError))-0.000001*(p2*ABS(nextError)*ABS(nextError))+0.001*p3*ABS(nextError)+1.001);
      //y=(p1*ABS(nextError))*0.001+p2;
      speedaboutangle=(2*speedout)/(1+y);
      speedaboutangle2=(2*speedout*y)/(1+y);
      //daolu=(0-2.864)*speedreal+400;
    // speedaboutangle=speedout+(400*(nextError3-daolu))/10000;
   //speedaboutangle2=speedout-(400*(nextError3-daolu))/10000;
    }
    // speedaboutangle=speedout+(400*(nextError3+2))/900;
  // speedaboutangle2=speedout-(400*(nextError3)+2)/900;
    
     if(speedaboutangle>1000)speedaboutangle=1000;
      if(speedaboutangle+1000<0)speedaboutangle=-1000;
      if(speedaboutangle2>1000)speedaboutangle2=1000;
      if(speedaboutangle2+1000<0)speedaboutangle2=-1000;
      
    if(speedaboutangle>0)
    {ftm_pwm_duty(FTM0, FTM_CH3,speedaboutangle);
    ftm_pwm_duty(FTM0, FTM_CH4,0);
    }
    if(speedaboutangle<0)
    {ftm_pwm_duty(FTM0, FTM_CH3,0);
    ftm_pwm_duty(FTM0, FTM_CH4,-speedaboutangle);}
    
   if(speedaboutangle2>0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,speedaboutangle2);
    ftm_pwm_duty(FTM0, FTM_CH6,0);
   }
   if(speedaboutangle2<0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,0);
    ftm_pwm_duty(FTM0, FTM_CH6,-speedaboutangle2);
   } 
  
}*/
void speedcontrol3()
{  
   static float Kp2=10.6;
   static float Ki2=6;//原始值2
   static float Kp22=10;
   static float Ki22=6;//原始值2
   static int16 speedwant_R;
   static  int16 speedwant_L;
   static int16 speedreal_counter;
   static int16 speedreal2_counter;
   static int16 I=750;//速度高震荡大810！
   float Erule[7]={-3.0,-2.0,-1.0,0.0,1.0,2.0,3.0};
   float ECrule[7]={-3.0,-2.0,-1.0,0.0,1.0,2.0,3.0};
   float Efuzzy[2]={0.0,0.0};
   float ECfuzzy[2]={0.0,0.0};
   float E2fuzzy[2]={0.0,0.0};
   float EC2fuzzy[2]={0.0,0.0};
   float Kprule[4]={0.0,11.0,22.0,33.0};
   float Kpfuzzy[4]={0.0,0.0,0.0,0.0};
   float Kp2fuzzy[4]={0.0,0.0,0.0,0.0};
   int KpRule[7][7]=
   {2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,
    1,1,1,1,1,1,1,
    0,0,0,0,0,0,0,
    1,1,1,1,1,1,1,
    2,2,2,3,3,3,3,
    3,3,3,3,3,3,3
     };
   float ec=0;
   float ecec=0;
   float ec2=0;
   float ecec2=0;
   int num;
   int num2;
   uint8 pc=0;
   uint8 pcpc=0;
   uint8 pc2=0;
   uint8 pcpc2=0;
   
    int16 speedreal_counter_change;
    int16 speedreal2_counter_change;
   rightval =ftm_quad_get(FTM1);
   ftm_quad_clean(FTM1);
   leftval =ftm_quad_get(FTM2);
   ftm_quad_clean(FTM2);
   motor=motor+(ABS(rightval)+ABS(leftval))/2;
  
 /* if(ABS(nextError)<=100)
   {
     
     speedup++;
      
   }
   else
   {
    speedup=0; 
     
   }
   if(speedup>30)speedup=30;
   speedwant=speedwant+speedup;*/
   if(motor>25000)motor=25000;
   if(motor>20000&&(ABS(rightval)<20||ABS(leftval)<20))
   {
     motorprotect++;
     
   }
   else
   {
    motorprotect=0; 
   }
   if(motorprotect>10)
   {
    motorprotectflag=1; 
   }
  speedreal=ABS(rightval);
      speedreal2=ABS(leftval);
       speedreal3=(speedreal+speedreal2)/2;
 //  nextError=10;
   if(nextError<30&&nextError>0)
   {
      
      speedwant_R=speedwant;
      speedwant_L=speedwant;
      ec=(((speedwant_R-speedreal)+0.5*(speedreal2-speedreal))*3)/speedwant;
      ecec=((speedlasterror-((speedwant_R-speedreal)+0.5*(speedreal2-speedreal)))*3)/speedwant;
      ec2=(((speedwant_L-speedreal2)+0.5*(speedreal-speedreal2))*3)/speedwant;
      ecec2=((speedlasterror2-((speedwant_L-speedreal2)+0.5*(speedreal-speedreal2)))*3)/speedwant;
      if(ec<Erule[0])
      {
        Efuzzy[0]=1;
              pc=0;
        
      }
      if(ec<Erule[1]&&ec>=Erule[0])
      {Efuzzy[0]=(ec-Erule[0])/(Erule[1]-Erule[0]);
      pc=0;
        
      }
      if(ec<Erule[2]&&ec>=Erule[1])
      {Efuzzy[0]=(ec-Erule[1])/(Erule[2]-Erule[1]);
      pc=1;
        
      }
      if(ec<Erule[3]&&ec>=Erule[2])
      {Efuzzy[0]=(ec-Erule[2])/(Erule[3]-Erule[2]);
      pc=2;
        
      }
      if(ec<Erule[4]&&ec>=Erule[3])
      {Efuzzy[0]=(ec-Erule[3])/(Erule[4]-Erule[3]);
      pc=3;
        
      }
      if(ec<Erule[5]&&ec>=Erule[4])
      {Efuzzy[0]=(ec-Erule[4])/(Erule[5]-Erule[4]);
      pc=4;
        
      }
      if(ec<Erule[6]&&ec>=Erule[5])
      {
        Efuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc=5;
        
      }
      if(ec>=Erule[6])
      {Efuzzy[0]=1;
        pc=5;
        
      }
      Efuzzy[1]=1-Efuzzy[0];
      if(ecec<ECrule[0])
      {ECfuzzy[0]=1;
      pcpc=0;
        
      }
       if(ecec<ECrule[1]&&ecec>=ECrule[0])
      {
        ECfuzzy[0]=(ecec-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc=0;
        
      }
      if(ecec<ECrule[2]&&ecec>=ECrule[1])
      {
        ECfuzzy[0]=(ecec-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc=1;
        
      }
       if(ecec<ECrule[3]&&ecec>=ECrule[2])
      {
        ECfuzzy[0]=(ecec-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc=2;
        
      }
      if(ecec<ECrule[4]&&ecec>=ECrule[3])
      {
        ECfuzzy[0]=(ecec-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc=3;
        
      }
      if(ecec<ECrule[5]&&ecec>=ECrule[4])
      {
        ECfuzzy[0]=(ecec-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc=4;
        
      }
      if(ecec<ECrule[6]&&ecec>=ECrule[5])
      {
        ECfuzzy[0]=(ecec-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc=5;
        
      }
      if(ecec>=ECrule[6])
      {
        ECfuzzy[0]=1;
      pcpc=5;
        
      }
      ECfuzzy[1]=1-ECfuzzy[0];
      num=KpRule[pc][pcpc];
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[0];
      num=KpRule[pc][pcpc+1];
       Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[0];
      num=KpRule[pc+1][pcpc]; 
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[1];
      num=KpRule[pc+1][pcpc+1]; 
      Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[1];
      Kp2=Kprule[0]*Kpfuzzy[0]+Kprule[1]*Kpfuzzy[1]+Kprule[2]*Kpfuzzy[2]+Kprule[3]*Kpfuzzy[3];
       if(ec2<Erule[0])
      {E2fuzzy[0]=1;
              pc2=0;
        
      }
      if(ec2<Erule[1]&&ec2>=Erule[0])
      {E2fuzzy[0]=(ec2-Erule[0])/(Erule[1]-Erule[0]);
      pc2=0;
        
      }
      if(ec2<Erule[2]&&ec2>=Erule[1])
      {E2fuzzy[0]=(ec2-Erule[1])/(Erule[2]-Erule[1]);
      pc2=1;
        
      }
      if(ec2<Erule[3]&&ec2>=Erule[2])
      {E2fuzzy[0]=(ec2-Erule[2])/(Erule[3]-Erule[2]);
      pc2=2;
        
      }
      if(ec2<Erule[4]&&ec2>=Erule[3])
      {E2fuzzy[0]=(ec2-Erule[3])/(Erule[4]-Erule[3]);
      pc2=3;
        
      }
      if(ec2<Erule[5]&&ec2>=Erule[4])
      {E2fuzzy[0]=(ec2-Erule[4])/(Erule[5]-Erule[4]);
      pc2=4;
        
      }
      if(ec2<Erule[6]&&ec2>=Erule[5])
      {
        E2fuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc2=5;
        
      }
      if(ec2>=Erule[6])
      {E2fuzzy[0]=1;
        pc2=5;
        
      }
      E2fuzzy[1]=1-E2fuzzy[0];
      if(ecec2<ECrule[0])
      {EC2fuzzy[0]=1;
      pcpc2=0;
        
      }
       if(ecec2<ECrule[1]&&ecec2>=ECrule[0])
      {
        EC2fuzzy[0]=(ecec2-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc2=0;
        
      }
      if(ecec2<ECrule[2]&&ecec2>=ECrule[1])
      {
        EC2fuzzy[0]=(ecec2-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc2=1;
        
      }
       if(ecec2<ECrule[3]&&ecec2>=ECrule[2])
      {
        EC2fuzzy[0]=(ecec2-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc2=2;
        
      }
      if(ecec2<ECrule[4]&&ecec2>=ECrule[3])
      {
        EC2fuzzy[0]=(ecec2-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc2=3;
        
      }
      if(ecec2<ECrule[5]&&ecec2>=ECrule[4])
      {
        EC2fuzzy[0]=(ecec2-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc2=4;
        
      }
      if(ecec2<ECrule[6]&&ecec2>=ECrule[5])
      {
        EC2fuzzy[0]=(ecec2-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc2=5;
        
      }
      if(ecec2>=ECrule[6])
      {
        EC2fuzzy[0]=1;
      pcpc2=5;
        
      }
      EC2fuzzy[1]=1-EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2];
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2+1];
       Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[0];
      num2=KpRule[pc2+1][pcpc2]; 
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[1];
      num2=KpRule[pc2+1][pcpc2+1]; 
      Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[1];
      Kp22=Kprule[0]*Kp2fuzzy[0]+Kprule[1]*Kp2fuzzy[1]+Kprule[2]*Kp2fuzzy[2]+Kprule[3]*Kp2fuzzy[3];
      speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.5*(speedreal2-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     //if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal);
     
      }
      //if(I_endless2>I)speedreal2_counter=I;
      //if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.5*(speedreal2-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
   }
      if(nextError+30>0&&nextError<=0)
      {
  speedwant_R=speedwant;
      speedwant_L=speedwant;
       ec=(((speedwant_R-speedreal)+0.5*(speedreal2-speedreal))*3)/speedwant;
      ecec=((speedlasterror-((speedwant_R-speedreal)+0.5*(speedreal2-speedreal)))*3)/speedwant;
      ec2=(((speedwant_L-speedreal2)+0.5*(speedreal-speedreal2))*3)/speedwant;
      ecec2=((speedlasterror-((speedwant_L-speedreal2)+0.5*(speedreal-speedreal2)))*3)/speedwant;
      if(ec<Erule[0])
      {Efuzzy[0]=1;
              pc=0;
        
      }
      if(ec<Erule[1]&&ec>=Erule[0])
      {Efuzzy[0]=(ec-Erule[0])/(Erule[1]-Erule[0]);
      pc=0;
        
      }
      if(ec<Erule[2]&&ec>=Erule[1])
      {Efuzzy[0]=(ec-Erule[1])/(Erule[2]-Erule[1]);
      pc=1;
        
      }
      if(ec<Erule[3]&&ec>=Erule[2])
      {Efuzzy[0]=(ec-Erule[2])/(Erule[3]-Erule[2]);
      pc=2;
        
      }
      if(ec<Erule[4]&&ec>=Erule[3])
      {Efuzzy[0]=(ec-Erule[3])/(Erule[4]-Erule[3]);
      pc=3;
        
      }
      if(ec<Erule[5]&&ec>=Erule[4])
      {Efuzzy[0]=(ec-Erule[4])/(Erule[5]-Erule[4]);
      pc=4;
        
      }
      if(ec<Erule[6]&&ec>=Erule[5])
      {
        Efuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc=5;
        
      }
      if(ec>=Erule[6])
      {Efuzzy[0]=1;
        pc=5;
        
      }
      Efuzzy[1]=1-Efuzzy[0];
      if(ecec<ECrule[0])
      {ECfuzzy[0]=1;
      pcpc=0;
        
      }
       if(ecec<ECrule[1]&&ecec>=ECrule[0])
      {
        ECfuzzy[0]=(ecec-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc=0;
        
      }
      if(ecec<ECrule[2]&&ecec>=ECrule[1])
      {
        ECfuzzy[0]=(ecec-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc=1;
        
      }
       if(ecec<ECrule[3]&&ecec>=ECrule[2])
      {
        ECfuzzy[0]=(ecec-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc=2;
        
      }
      if(ecec<ECrule[4]&&ecec>=ECrule[3])
      {
        ECfuzzy[0]=(ecec-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc=3;
        
      }
      if(ecec<ECrule[5]&&ecec>=ECrule[4])
      {
        ECfuzzy[0]=(ecec-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc=4;
        
      }
      if(ecec<ECrule[6]&&ecec>=ECrule[5])
      {
        ECfuzzy[0]=(ecec-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc=5;
        
      }
      if(ecec>=ECrule[6])
      {
        ECfuzzy[0]=1;
      pcpc=5;
        
      }
      ECfuzzy[1]=1-ECfuzzy[0];
      num=KpRule[pc][pcpc];
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[0];
      num=KpRule[pc][pcpc+1];
       Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[0];
      num=KpRule[pc+1][pcpc]; 
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[1];
      num=KpRule[pc+1][pcpc+1]; 
      Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[1];
      Kp2=Kprule[0]*Kpfuzzy[0]+Kprule[1]*Kpfuzzy[1]+Kprule[2]*Kpfuzzy[2]+Kprule[3]*Kpfuzzy[3];
       if(ec2<Erule[0])
      {E2fuzzy[0]=1;
              pc2=0;
        
      }
      if(ec2<Erule[1]&&ec2>=Erule[0])
      {E2fuzzy[0]=(ec2-Erule[0])/(Erule[1]-Erule[0]);
      pc2=0;
        
      }
      if(ec2<Erule[2]&&ec2>=Erule[1])
      {E2fuzzy[0]=(ec2-Erule[1])/(Erule[2]-Erule[1]);
      pc2=1;
        
      }
      if(ec2<Erule[3]&&ec2>=Erule[2])
      {E2fuzzy[0]=(ec2-Erule[2])/(Erule[3]-Erule[2]);
      pc2=2;
        
      }
      if(ec2<Erule[4]&&ec2>=Erule[3])
      {E2fuzzy[0]=(ec2-Erule[3])/(Erule[4]-Erule[3]);
      pc2=3;
        
      }
      if(ec2<Erule[5]&&ec2>=Erule[4])
      {E2fuzzy[0]=(ec2-Erule[4])/(Erule[5]-Erule[4]);
      pc2=4;
        
      }
      if(ec2<Erule[6]&&ec2>=Erule[5])
      {
        E2fuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc2=5;
        
      }
      if(ec2>=Erule[6])
      {E2fuzzy[0]=1;
        pc2=5;
        
      }
      E2fuzzy[1]=1-E2fuzzy[0];
      if(ecec2<ECrule[0])
      {EC2fuzzy[0]=1;
      pcpc2=0;
        
      }
       if(ecec2<ECrule[1]&&ecec2>=ECrule[0])
      {
        EC2fuzzy[0]=(ecec2-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc2=0;
        
      }
      if(ecec2<ECrule[2]&&ecec2>=ECrule[1])
      {
        EC2fuzzy[0]=(ecec2-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc2=1;
        
      }
       if(ecec2<ECrule[3]&&ecec2>=ECrule[2])
      {
        EC2fuzzy[0]=(ecec2-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc2=2;
        
      }
      if(ecec2<ECrule[4]&&ecec2>=ECrule[3])
      {
        EC2fuzzy[0]=(ecec2-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc2=3;
        
      }
      if(ecec2<ECrule[5]&&ecec2>=ECrule[4])
      {
        EC2fuzzy[0]=(ecec2-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc2=4;
        
      }
      if(ecec2<ECrule[6]&&ecec2>=ECrule[5])
      {
        EC2fuzzy[0]=(ecec2-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc2=5;
        
      }
      if(ecec2>=ECrule[6])
      {
        EC2fuzzy[0]=1;
      pcpc2=5;
        
      }
      EC2fuzzy[1]=1-EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2];
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2+1];
       Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[0];
      num2=KpRule[pc2+1][pcpc2]; 
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[1];
      num2=KpRule[pc2+1][pcpc2+1]; 
      Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[1];
      Kp22=Kprule[0]*Kp2fuzzy[0]+Kprule[1]*Kp2fuzzy[1]+Kprule[2]*Kp2fuzzy[2]+Kprule[3]*Kp2fuzzy[3];
      speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.5*(speedreal2-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     // if(I_endless>I)I_endless=I;
    //  if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
     // if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.5*(speedreal2-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      }
      if(nextError>=30)
    { 
     // y=(0.000001*(p1*ABS(nextError3)*ABS(nextError3)*ABS(nextError3))-0.000001*(p2*ABS(nextError3)*ABS(nextError3))+0.001*p3*ABS(nextError3)+1.001);
     y=(p1*ABS(nextError))*0.001+p2;
      speedwant_R=(2*y*speedwant)/(1+y);
      speedwant_L=(2*speedwant)/(1+y);
       ec=(((speedwant_R-speedreal)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal))*3)/speedwant;
      ecec=((speedlasterror-((speedwant_R-speedreal)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal)))*3)/speedwant;
      ec2=(((speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2))*3)/speedwant;
      ecec2=((speedlasterror2-((speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2)))*3)/speedwant;
      if(ec<Erule[0])
      {Efuzzy[0]=1;
              pc=0;
        
      }
      if(ec<Erule[1]&&ec>=Erule[0])
      {Efuzzy[0]=(ec-Erule[0])/(Erule[1]-Erule[0]);
      pc=0;
        
      }
      if(ec<Erule[2]&&ec>=Erule[1])
      {Efuzzy[0]=(ec-Erule[1])/(Erule[2]-Erule[1]);
      pc=1;
        
      }
      if(ec<Erule[3]&&ec>=Erule[2])
      {Efuzzy[0]=(ec-Erule[2])/(Erule[3]-Erule[2]);
      pc=2;
        
      }
      if(ec<Erule[4]&&ec>=Erule[3])
      {Efuzzy[0]=(ec-Erule[3])/(Erule[4]-Erule[3]);
      pc=3;
        
      }
      if(ec<Erule[5]&&ec>=Erule[4])
      {Efuzzy[0]=(ec-Erule[4])/(Erule[5]-Erule[4]);
      pc=4;
        
      }
      if(ec<Erule[6]&&ec>=Erule[5])
      {
        Efuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc=5;
        
      }
      if(ec>=Erule[6])
      {Efuzzy[0]=1;
        pc=5;
        
      }
      Efuzzy[1]=1-Efuzzy[0];
      if(ecec<ECrule[0])
      {ECfuzzy[0]=1;
      pcpc=0;
        
      }
       if(ecec<ECrule[1]&&ecec>=ECrule[0])
      {
        ECfuzzy[0]=(ecec-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc=0;
        
      }
      if(ecec<ECrule[2]&&ecec>=ECrule[1])
      {
        ECfuzzy[0]=(ecec-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc=1;
        
      }
       if(ecec<ECrule[3]&&ecec>=ECrule[2])
      {
        ECfuzzy[0]=(ecec-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc=2;
        
      }
      if(ecec<ECrule[4]&&ecec>=ECrule[3])
      {
        ECfuzzy[0]=(ecec-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc=3;
        
      }
      if(ecec<ECrule[5]&&ecec>=ECrule[4])
      {
        ECfuzzy[0]=(ecec-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc=4;
        
      }
      if(ecec<ECrule[6]&&ecec>=ECrule[5])
      {
        ECfuzzy[0]=(ecec-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc=5;
        
      }
      if(ecec>=ECrule[6])
      {
        ECfuzzy[0]=1;
      pcpc=5;
        
      }
      ECfuzzy[1]=1-ECfuzzy[0];
      num=KpRule[pc][pcpc];
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[0];
      num=KpRule[pc][pcpc+1];
       Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[0];
      num=KpRule[pc+1][pcpc]; 
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[1];
      num=KpRule[pc+1][pcpc+1]; 
      Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[1];
      Kp2=Kprule[0]*Kpfuzzy[0]+Kprule[1]*Kpfuzzy[1]+Kprule[2]*Kpfuzzy[2]+Kprule[3]*Kpfuzzy[3];
       if(ec2<Erule[0])
      {E2fuzzy[0]=1;
              pc2=0;
        
      }
      if(ec2<Erule[1]&&ec2>=Erule[0])
      {E2fuzzy[0]=(ec2-Erule[0])/(Erule[1]-Erule[0]);
      pc2=0;
        
      }
      if(ec2<Erule[2]&&ec2>=Erule[1])
      {E2fuzzy[0]=(ec2-Erule[1])/(Erule[2]-Erule[1]);
      pc2=1;
        
      }
      if(ec2<Erule[3]&&ec2>=Erule[2])
      {E2fuzzy[0]=(ec2-Erule[2])/(Erule[3]-Erule[2]);
      pc2=2;
        
      }
      if(ec2<Erule[4]&&ec2>=Erule[3])
      {E2fuzzy[0]=(ec2-Erule[3])/(Erule[4]-Erule[3]);
      pc2=3;
        
      }
      if(ec2<Erule[5]&&ec2>=Erule[4])
      {E2fuzzy[0]=(ec2-Erule[4])/(Erule[5]-Erule[4]);
      pc2=4;
        
      }
      if(ec2<Erule[6]&&ec2>=Erule[5])
      {
        E2fuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc2=5;
        
      }
      if(ec2>=Erule[6])
      {E2fuzzy[0]=1;
        pc2=5;
        
      }
      E2fuzzy[1]=1-E2fuzzy[0];
      if(ecec2<ECrule[0])
      {EC2fuzzy[0]=1;
      pcpc2=0;
        
      }
       if(ecec2<ECrule[1]&&ecec2>=ECrule[0])
      {
        EC2fuzzy[0]=(ecec2-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc2=0;
        
      }
      if(ecec2<ECrule[2]&&ecec2>=ECrule[1])
      {
        EC2fuzzy[0]=(ecec2-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc2=1;
        
      }
        if(ecec2<ECrule[3]&&ecec2>=ECrule[2])
      {
        EC2fuzzy[0]=(ecec2-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc2=2;
        
      }
      if(ecec2<ECrule[4]&&ecec2>=ECrule[3])
      {
        EC2fuzzy[0]=(ecec2-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc2=3;
        
      }
      if(ecec2<ECrule[5]&&ecec2>=ECrule[4])
      {
        EC2fuzzy[0]=(ecec2-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc2=4;
        
      }
      if(ecec2<ECrule[6]&&ecec2>=ECrule[5])
      {
        EC2fuzzy[0]=(ecec2-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc2=5;
        
      }
      if(ecec2>=ECrule[6])
      {
        EC2fuzzy[0]=1;
      pcpc2=5;
        
      }
      EC2fuzzy[1]=1-EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2];
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2+1];
       Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[0];
      num2=KpRule[pc2+1][pcpc2]; 
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[1];
      num2=KpRule[pc2+1][pcpc2+1]; 
      Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[1];
      Kp22=Kprule[0]*Kp2fuzzy[0]+Kprule[1]*Kp2fuzzy[1]+Kprule[2]*Kp2fuzzy[2]+Kprule[3]*Kp2fuzzy[3];
       speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     // if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
     // if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.2*((speedreal+speedreal2)/(1+y)-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      
    }
    if((nextError+30<=0))
    { 
      //y=(0.000001*(p1*ABS(nextError3)*ABS(nextError3)*ABS(nextError3))-0.000001*(p2*ABS(nextError3)*ABS(nextError3))+0.001*p3*ABS(nextError3)+1.001);
     y=(p1*ABS(nextError))*0.001+p2;
      speedwant_R=(2*speedwant)/(1+y);
      speedwant_L=(2*y*speedwant)/(1+y);
      ec=(((speedwant_R-speedreal)+0.2*((speedreal+speedreal2)/(1+y)-speedreal))*3)/speedwant;
      ecec=((speedlasterror-((speedwant_R-speedreal)+0.2*((speedreal+speedreal2)/(1+y)-speedreal)))*3)/speedwant;
      ec2=(((speedwant_L-speedreal2)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal2))*3)/speedwant;
      ecec2=((speedlasterror2-((speedwant_L-speedreal2)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal2)))*3)/speedwant;
      if(ec<Erule[0])
      {Efuzzy[0]=1;
              pc=0;
        
      }
      if(ec<Erule[1]&&ec>=Erule[0])
      {Efuzzy[0]=(ec-Erule[0])/(Erule[1]-Erule[0]);
       pc=0;
        
      }
      if(ec<Erule[2]&&ec>=Erule[1])
      {Efuzzy[0]=(ec-Erule[1])/(Erule[2]-Erule[1]);
       pc=1;
        
      }
      if(ec<Erule[3]&&ec>=Erule[2])
      {Efuzzy[0]=(ec-Erule[2])/(Erule[3]-Erule[2]);
       pc=2;
        
      }
      if(ec<Erule[4]&&ec>=Erule[3])
      {Efuzzy[0]=(ec-Erule[3])/(Erule[4]-Erule[3]);
      pc=3;
        
      }
      if(ec<Erule[5]&&ec>=Erule[4])
      {Efuzzy[0]=(ec-Erule[4])/(Erule[5]-Erule[4]);
      pc=4;
        
      }
      if(ec<Erule[6]&&ec>=Erule[5])
      {
        Efuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc=5;
        
      }
      if(ec>=Erule[6])
      {Efuzzy[0]=1;
        pc=5;
        
      }
      Efuzzy[1]=1-Efuzzy[0];
      if(ecec<ECrule[0])
      {ECfuzzy[0]=1;
      pcpc=0;
        
      }
       if(ecec<ECrule[1]&&ecec>=ECrule[0])
      {
        ECfuzzy[0]=(ecec-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc=0;
        
      }
      if(ecec<ECrule[2]&&ecec>=ECrule[1])
      {
        ECfuzzy[0]=(ecec-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc=1;
        
      }
       if(ecec<ECrule[3]&&ecec>=ECrule[2])
      {
        ECfuzzy[0]=(ecec-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc=2;
        
      }
      if(ecec<ECrule[4]&&ecec>=ECrule[3])
      {
        ECfuzzy[0]=(ecec-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc=3;
        
      }
      if(ecec<ECrule[5]&&ecec>=ECrule[4])
      {
        ECfuzzy[0]=(ecec-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc=4;
        
      }
      if(ecec<ECrule[6]&&ecec>=ECrule[5])
      {
        ECfuzzy[0]=(ecec-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc=5;
        
      }
      if(ecec>=ECrule[6])
      {
        ECfuzzy[0]=1;
      pcpc=5;
        
      }
      ECfuzzy[1]=1-ECfuzzy[0];
      num=KpRule[pc][pcpc];
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[0];
      num=KpRule[pc][pcpc+1];
       Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[0];
      num=KpRule[pc+1][pcpc]; 
      Kpfuzzy[num]+=Efuzzy[0]*ECfuzzy[1];
      num=KpRule[pc+1][pcpc+1]; 
      Kpfuzzy[num]+=Efuzzy[1]*ECfuzzy[1];
      Kp2=Kprule[0]*Kpfuzzy[0]+Kprule[1]*Kpfuzzy[1]+Kprule[2]*Kpfuzzy[2]+Kprule[3]*Kpfuzzy[3];
       if(ec2<Erule[0])
      {E2fuzzy[0]=1;
              pc2=0;
        
      }
      if(ec2<Erule[1]&&ec2>=Erule[0])
      {E2fuzzy[0]=(ec2-Erule[0])/(Erule[1]-Erule[0]);
      pc2=0;
        
      }
      if(ec2<Erule[2]&&ec2>=Erule[1])
      {E2fuzzy[0]=(ec2-Erule[1])/(Erule[2]-Erule[1]);
      pc2=1;
        
      }
      if(ec2<Erule[3]&&ec2>=Erule[2])
      {E2fuzzy[0]=(ec2-Erule[2])/(Erule[3]-Erule[2]);
      pc2=2;
        
      }
      if(ec2<Erule[4]&&ec2>=Erule[3])
      {E2fuzzy[0]=(ec2-Erule[3])/(Erule[4]-Erule[3]);
      pc2=3;
        
      }
      if(ec2<Erule[5]&&ec2>=Erule[4])
      {E2fuzzy[0]=(ec2-Erule[4])/(Erule[5]-Erule[4]);
      pc2=4;
        
      }
      if(ec2<Erule[6]&&ec2>=Erule[5])
      {
        E2fuzzy[0]=(ec-Erule[5])/(Erule[6]-Erule[5]);
      pc2=5;
        
      }
      if(ec2>=Erule[6])
      {E2fuzzy[0]=1;
        pc2=5;
        
      }
      E2fuzzy[1]=1-E2fuzzy[0];
      if(ecec2<ECrule[0])
      {EC2fuzzy[0]=1;
      pcpc2=0;
        
      }
       if(ecec2<ECrule[1]&&ecec2>=ECrule[0])
      {
        EC2fuzzy[0]=(ecec2-ECrule[0])/(ECrule[1]-ECrule[0]);
      pcpc2=0;
        
      }
      if(ecec2<ECrule[2]&&ecec2>=ECrule[1])
      {
        EC2fuzzy[0]=(ecec2-ECrule[1])/(ECrule[2]-ECrule[1]);
      pcpc2=1;
        
      }
       if(ecec2<ECrule[3]&&ecec2>=ECrule[2])
      {
        EC2fuzzy[0]=(ecec2-ECrule[2])/(ECrule[3]-ECrule[2]);
      pcpc2=2;
        
      }
      if(ecec2<ECrule[4]&&ecec2>=ECrule[3])
      {
        EC2fuzzy[0]=(ecec2-ECrule[3])/(ECrule[4]-ECrule[3]);
      pcpc2=3;
        
      }
      if(ecec2<ECrule[5]&&ecec2>=ECrule[4])
      {
        EC2fuzzy[0]=(ecec2-ECrule[4])/(ECrule[5]-ECrule[4]);
      pcpc2=4;
        
      }
      if(ecec2<ECrule[6]&&ecec2>=ECrule[5])
      {
        EC2fuzzy[0]=(ecec2-ECrule[5])/(ECrule[6]-ECrule[5]);
      pcpc2=5;
        
      }
      if(ecec2>=ECrule[6])
      {
        EC2fuzzy[0]=1;
      pcpc2=5;
        
      }
      EC2fuzzy[1]=1-EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2];
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[0];
      num2=KpRule[pc2][pcpc2+1];
       Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[0];
      num2=KpRule[pc2+1][pcpc2]; 
      Kp2fuzzy[num2]+=E2fuzzy[0]*EC2fuzzy[1];
      num2=KpRule[pc2+1][pcpc2+1]; 
      Kp2fuzzy[num2]+=E2fuzzy[1]*EC2fuzzy[1];
      Kp22=Kprule[0]*Kp2fuzzy[0]+Kprule[1]*Kp2fuzzy[1]+Kprule[2]*Kp2fuzzy[2]+Kprule[3]*Kp2fuzzy[3];
     
       speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*((speedreal+speedreal2)/(1+y)-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
      //if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.1*((speedreal+speedreal2)/(1+y)-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
    //  if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.2*((speedreal+speedreal2)/(1+y)-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      
    }
      
    if(speedaboutangle>1000)speedaboutangle=1000;
      if(speedaboutangle+1000<0)speedaboutangle=-1000;
      if(speedaboutangle2>1000)speedaboutangle2=1000;
      if(speedaboutangle2+1000<0)speedaboutangle2=-1000;
      
    if(speedaboutangle>0)
    {ftm_pwm_duty(FTM0, FTM_CH3,speedaboutangle);
    ftm_pwm_duty(FTM0, FTM_CH4,0);
    }
    if(speedaboutangle<0)
    {ftm_pwm_duty(FTM0, FTM_CH3,0);
    ftm_pwm_duty(FTM0, FTM_CH4,-speedaboutangle);}
    
   if(speedaboutangle2>0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,speedaboutangle2);
    ftm_pwm_duty(FTM0, FTM_CH6,0);
   }
   if(speedaboutangle2<0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,0);
    ftm_pwm_duty(FTM0, FTM_CH6,-speedaboutangle2);
   }
   speedlasterror=speederror;
   speedlasterror2=speederror2;
  
}
void speedcontrol4()
{ 
  static float Kp2=8.5;
   static float Ki2=2;
    static float Kp22=8;
   static float Ki22=2;
  static int16 speedwant_R;
  static  int16 speedwant_L;
   static int16 speedreal_counter;
   static int16 speedreal2_counter;
   static int16 I=500;
    int16 speedreal_counter_change;
    int16 speedreal2_counter_change;
   rightval =ftm_quad_get(FTM1);
   ftm_quad_clean(FTM1);
   leftval =ftm_quad_get(FTM2);
   ftm_quad_clean(FTM2);
    
  speedreal=ABS(rightval);
      speedreal2=ABS(leftval);
 //  nextError=10;
   if(nextError<30&&nextError>0)
   {
      
      speedwant_R=speedwant;
      speedwant_L=speedwant;
      speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*(speedreal2-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*(speedreal-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     //if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.1*(speedreal2-speedreal);
     
      }
      //if(I_endless2>I)speedreal2_counter=I;
      //if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.1*(speedreal-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.1*(speedreal-speedreal2);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.1*(speedreal2-speedreal);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
   }
      if(nextError+30>0&&nextError<=0)
      {
  speedwant_R=speedwant;
      speedwant_L=speedwant;
      speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*(speedreal2-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*(speedreal-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     // if(I_endless>I)I_endless=I;
    //  if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+0.1*(speedwant_R-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
     // if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+0.1*(speedwant_L-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.1*(speedreal-speedreal2);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.1*(speedreal2-speedreal);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      }
      if(nextError>=30)
    { 
     // y=(0.000001*(p1*ABS(nextError3)*ABS(nextError3)*ABS(nextError3))-0.000001*(p2*ABS(nextError3)*ABS(nextError3))+0.001*p3*ABS(nextError3)+1.001);
     y=(p1*ABS(nextError))*0.001+p2;
      speedwant_R=(2*y*speedwant)/(1+y);
      speedwant_L=(2*speedwant)/(1+y);
       speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     // if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
     // if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      
    }
    if((nextError+30<=0))
    { 
      //y=(0.000001*(p1*ABS(nextError3)*ABS(nextError3)*ABS(nextError3))-0.000001*(p2*ABS(nextError3)*ABS(nextError3))+0.001*p3*ABS(nextError3)+1.001);
     y=(p1*ABS(nextError))*0.001+p2;
      speedwant_R=(2*speedwant)/(1+y);
      speedwant_L=(2*y*speedwant)/(1+y);
       speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*((speedreal+speedreal2)/(1+y)-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
      //if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.1*((speedreal+speedreal2)/(1+y)-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
    //  if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.1*((speedreal+speedreal2)/(1+y)-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      
    }
      
    if(speedaboutangle>1000)speedaboutangle=1000;
      if(speedaboutangle+1000<0)speedaboutangle=-1000;
      if(speedaboutangle2>1000)speedaboutangle2=1000;
      if(speedaboutangle2+1000<0)speedaboutangle2=-1000;
      
    if(speedaboutangle>0)
    {ftm_pwm_duty(FTM0, FTM_CH3,speedaboutangle);
    ftm_pwm_duty(FTM0, FTM_CH4,0);
    }
    if(speedaboutangle<0)
    {ftm_pwm_duty(FTM0, FTM_CH3,0);
    ftm_pwm_duty(FTM0, FTM_CH4,-speedaboutangle);}
    
   if(speedaboutangle2>0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,speedaboutangle2);
    ftm_pwm_duty(FTM0, FTM_CH6,0);
   }
   if(speedaboutangle2<0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,0);
    ftm_pwm_duty(FTM0, FTM_CH6,-speedaboutangle2);
   } 
  
  
}
void speedcontrol5()
{ 
  static float Kp2=10.6;
   static float Ki2=2;
    static float Kp22=10;
   static float Ki22=2;
  static int16 speedwant_R;
  static  int16 speedwant_L;
   static int16 speedreal_counter;
   static int16 speedreal2_counter;
   static int16 I=500;
    int16 speedreal_counter_change;
    int16 speedreal2_counter_change;
   rightval =ftm_quad_get(FTM1);
   ftm_quad_clean(FTM1);
   leftval =ftm_quad_get(FTM2);
   ftm_quad_clean(FTM2);
    
  speedreal=ABS(rightval);
      speedreal2=ABS(leftval);
 //  nextError=10;
   if(nextError<30&&nextError>0)
   {
      
      speedwant_R=speedwant;
      speedwant_L=speedwant;
      speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.5*(speedreal2-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     //if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.5*(speedreal2-speedreal);
     
      }
      //if(I_endless2>I)speedreal2_counter=I;
      //if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.5*(speedreal2-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
   }
      if(nextError+30>0&&nextError<=0)
      {
  speedwant_R=speedwant;
      speedwant_L=speedwant;
      speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.5*(speedreal2-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     // if(I_endless>I)I_endless=I;
    //  if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+0.5*(speedwant_R-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
     // if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+0.5*(speedwant_L-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.5*(speedreal2-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.5*(speedreal-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      }
      if(nextError>=30)
    { 
     // y=(0.000001*(p1*ABS(nextError3)*ABS(nextError3)*ABS(nextError3))-0.000001*(p2*ABS(nextError3)*ABS(nextError3))+0.001*p3*ABS(nextError3)+1.001);
     y=(p1*ABS(nextError))*0.001+p2;
      speedwant_R=(2*y*speedwant)/(1+y);
      speedwant_L=(2*speedwant)/(1+y);
       speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
     // if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
     // if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.1*((speedreal+speedreal2)/(1+y)-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.2*((speedreal+speedreal2)/(1+y)-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      
    }
    if((nextError+30<=0))
    { 
      //y=(0.000001*(p1*ABS(nextError3)*ABS(nextError3)*ABS(nextError3))-0.000001*(p2*ABS(nextError3)*ABS(nextError3))+0.001*p3*ABS(nextError3)+1.001);
     y=(p1*ABS(nextError))*0.001+p2;
      speedwant_R=(2*speedwant)/(1+y);
      speedwant_L=(2*y*speedwant)/(1+y);
       speedreal_counter_change=(speedreal_counter+(speedwant_R-speedreal)+0.1*((speedreal+speedreal2)/(1+y)-speedreal));
      speedreal2_counter_change=(speedreal2_counter+(speedwant_L-speedreal2)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal2));
      float I_endless=speedreal_counter_change*Ki2;
      float I_endless2=speedreal2_counter_change*Ki2;
      //if(I_endless>I)I_endless=I;
      //if(I_endless+I<0)I_endless=-I;
      
      if(ABS(I_endless)<=I)
      {
        speedreal_counter=speedreal_counter+(speedwant_R-speedreal)+0.1*((speedreal+speedreal2)/(1+y)-speedreal);
     
      }
     // if(I_endless2>I)speedreal2_counter=I;
    //  if(I_endless2+I<0)speedreal2_counter=-I;
      if(ABS(I_endless2)<=I)
      {
        speedreal2_counter=speedreal2_counter+(speedwant_L-speedreal2)+0.1*(y*(speedreal+speedreal2)/(1+y)-speedreal2);
     
      }
      int16 v_counter=speedreal_counter;
      speederror=(speedwant_R-speedreal)+0.2*((speedreal+speedreal2)/(1+y)-speedreal);
      int16 v_counter2=speedreal2_counter;
      speederror2=(speedwant_L-speedreal2)+0.2*(y*(speedreal+speedreal2)/(1+y)-speedreal2);
      
      
      speedout=Kp2*speederror+Ki2*v_counter;
      speedout2=Kp22*speederror2+Ki22*v_counter2;
      
      
      speedaboutangle=speedout;
      speedaboutangle2=speedout2;
      
    }
      
    if(speedaboutangle>1000)speedaboutangle=1000;
      if(speedaboutangle+1000<0)speedaboutangle=-1000;
      if(speedaboutangle2>1000)speedaboutangle2=1000;
      if(speedaboutangle2+1000<0)speedaboutangle2=-1000;
      
    if(speedaboutangle>0)
    {ftm_pwm_duty(FTM0, FTM_CH3,speedaboutangle);
    ftm_pwm_duty(FTM0, FTM_CH4,0);
    }
    if(speedaboutangle<0)
    {ftm_pwm_duty(FTM0, FTM_CH3,0);
    ftm_pwm_duty(FTM0, FTM_CH4,-speedaboutangle);}
    
   if(speedaboutangle2>0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,speedaboutangle2);
    ftm_pwm_duty(FTM0, FTM_CH6,0);
   }
   if(speedaboutangle2<0)
   {
   ftm_pwm_duty(FTM0, FTM_CH5,0);
    ftm_pwm_duty(FTM0, FTM_CH6,-speedaboutangle2);
   } 
  
  
}


#endif
