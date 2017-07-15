 /*!
  *     COPYRIGHT NOTICE
  *     Copyright (c) 2013,ɽ��Ƽ�
  *     All rights reserved.
  *     �������ۣ�ɽ����̳ http://www.vcan123.com
  *
  *     ��ע�������⣬�����������ݰ�Ȩ����ɽ��Ƽ����У�δ����������������ҵ��;��
  *     �޸�����ʱ���뱣��ɽ��Ƽ��İ�Ȩ������
  *
  * @file       main.c
  * @brief      ɽ��K60 ƽ̨������
  * @author     ɽ��Ƽ�
  * @version    v5.0
  * @date       2013-08-28
���ϲ���������35������105����ֱ�����80��98������50��85
�������
  */

#include "common.h"
#include "include.h"
#include "MK60_port.h"
#include "MK60_gpio.h"
#include "VCAN_LED.H"
#include "angleout.h" 
#include "speedcontrol.h"
   
//����洢����CCDͼ�������
 uint8  var1, var2;
 uint16 var3, var4;
 uint32 var5, var6;
/**********************************************/
uint8  nrf_rx_buff[TSL1401_MAX*TSL1401_SIZE + 2*COM_LEN + DATA_PACKET];              //Ԥ��
uint8 nrf_tx_buff[TSL1401_MAX*TSL1401_SIZE + 2*COM_LEN + DATA_PACKET];              //Ԥ��
//uint8 *ccdbuff0 = (uint8 *)(((uint8 *)&nrf_tx_buff) + COM_LEN);                      //ͼ���ַ
//uint8 *ccdbuff1 = (uint8 *)(((uint8 *)&nrf_tx_buff) + COM_LEN + TSL1401_SIZE);       //ͼ���ַ
//uint8 *ccdbuff2 = (uint8 *)(((uint8 *)&nrf_tx_buff) + COM_LEN + 2*TSL1401_SIZE);     //ͼ���ַ
//uint8 *ccdbuff00 = (uint8 *)(((uint8 *)&nrf_rx_buff) + COM_LEN);                     //ͼ���ַ
//uint8 *ccdbuff22 = (uint8 *)(((uint8 *)&nrf_rx_buff) + COM_LEN + 2*TSL1401_SIZE);
void PIT0_IRQHandler();
void PORTE_IRQHandler();

Site_t site_1={10,10};
Site_t site_2={30,10};
Site_t site_3={50,10};
Site_t site_4={70,10};
Site_t site_5={90,10};
Site_t site_6={10,30};
Site_t site_7={30,30};
Site_t site_8={50,30};
Site_t site_9={70,30};
Site_t site_10={90,30};
int16 motorprotect;
int motorprotectflag;
int16 motor;
int16 gyroscope=0;
int16 gyroscope2=0;
int16 gyroscope1[5]={0,0,0,0,0 };
 /*******************************************/
uint8 CCD_BUFF[TSL1401_MAX*3][TSL1401_SIZE];
uint8 CCD[3][TSL1401_SIZE];
uint8 CCD2[3][TSL1401_SIZE];
int16 CCD_diff[1][128];
uint8 rightline[8][8];
uint8 leftline[8][8];
uint8 imagestore[8][4]={0,128,64,60,
                         0,128,64,60,
                         0,128,64,60,
                         0,128,64,60};
uint8 imagestore2[8][4]={0,128,64,60,
                         0,128,64,60,
                         0,128,64,60,
                         0,128,64,60};
uint8 rightline2[8][8];
uint8 leftline2[8][8];
uint8 upshu[128];
uint8 downshu[128];

int16 time2=0;
/********************************************///�˵�����
int8 Menu_set=15;//�˵����趨
int8 Menu_num;//�˵���
int8 Menu_num_old;
int16 Menu_data_num[20];//���ݴ洢��
int16 *Menu_Num=Menu_data_num;//����ָ��
int8 Window_Num=0;//������
int8 Window_Num_old;//��һ�δ�����
/*****************************************///����·����־
int fazhi2max=200;
int fazhi2min=160;//60����170-190//
int Crossflag;//ʮ�ֱ�־
int  Obstacleflag;
int Obstacleflagup=0;
int Obstacleflagup2=0;//�ϰ���־
int Obstacleflagdown=0;
int Straightflag;//ֱ�߱�־
int LeftBigBendflag;//��������־
int RightBigBendflag;//�Ҵ������־
int LittleBendflag;//С�����־
short int car_speedl;
short int car_speedr;
long int car_speed;
int fazhicaiji=2;//��ֵ�ɼ���־
int fazhicaijiover;//��ֵ�ɼ���ɱ�־
int fazhicaijiover2;//��ֵ����ֵ�޷�λ
int delayen;
int Motor_Protect;
int Kp;
int m,n;
short int daolu=100;
int Td;	
int Ti;			
int T;
int Kd;
int Ki;
int blackline;
int Midroad=64;
int duojiKp=20;//û�����ã�
int duojiKd=8;
int MotorKp=5;
int MotorKd=10;
int chashu=35;
int error;
int error1[4];
short int nextError2;
int Kdduoji;
int Kpduoji;
int lastError;
short int nextError;
short int nextError3;
short int nextError1;
short int angle1;
int hongwaiflag;
int AD;
int b;
short int speedaboutangle;
short int speedaboutangle2;
int fangxiang;
int leftfangxiang;
int rightfangxiang;
int wandao;
int wandaocishu;
int shizhi;
int shizhicishu;
int zhangai;
int zhangaicishu;
int zhidao;
int zhidaocishu;
int podaocishu;
int mid2=64;
int mid=64;
int Mid1;
int Mid2;
int max1[1][2];
int min1[1][2];
int16 smax;
int16 smin;
int s;
int zhidaocishu;
int shizicishu;
int wandaocishu;
int zhangaicishu;
int16 max3;
int16 min3;
int16 max2;
int16 min;
float p1=0.8043;//ԭֵ0.8043
float p2=1.0000;//ԭֵ1.0220
//float p1=0.0008056;
//float p2=0.6452;
//float p3=0.6765;
float y;
int stop=1;
long int rightval;
long int leftval;
short int speedreal;
long int speedreal2;
long int speedreal3;
long int speedwant=205;
long int speederror;
int speedup;
long int speederror2;
long int speedlasterror;
long int speedlasterror2;
long int speedout;
long int speedout2;
long int speedlastout;
int16 out[5];
 int whiteline;
 int times;
uint8 flag1=0;
uint8 flag2=0;
uint8 flag12=0;
uint8 flag22=0;
uint8 zuoflag3=0;
uint8 youflag3=0;
uint8 roadside;
uint8 roadside2;
uint8 roadwide=80;
uint8 roadwidemax=70;
uint8 roadwidemin=90;
int p=0;
int o=0;
int q=0;
int w=0;

int  rightdeadline=113;
int  leftdeadline=15;
unsigned char fazhi1;
unsigned char fazhi2;

unsigned char roadside;
unsigned char  roadside2;
unsigned char  roadside3;
void PIT0_IRQHandler();
void bin(uint8 *bin,uint8 * img,uint8 * difimg,uint16 len,uint8 maxdif);

void abs_diff(uint8 *dst,uint8 *src,uint16 len,uint8 * maxval,uint8 * avgval);
void maxvar(uint8 *buf,uint16 len,uint8  maxval);
void PIDInit()
{
	 Kp=10;		//Ѳ�߲��ȶ������Kp��Td��ֵ
	Td=0.2;		//�����ľ������������μ�λ��ʽPID������������
	Ti=150;			
	 T=2;
	 Kd=20;   //������
	 Ki=(Kp*T)/Ti;
	 error=0;
	 lastError=0;	 
}
void Menu_init()
{
  Menu_data_num[0]=speedwant;
  Menu_data_num[1]=duojiKp;
  Menu_data_num[2]=duojiKd;
  Menu_data_num[3]=MotorKp;
  Menu_data_num[4]=MotorKd;
  Menu_data_num[5]=daolu;
  Menu_data_num[6]=fazhi2max;
  Menu_data_num[7]=fazhi2min;
 
  
}
void Data_change()
{speedwant=Menu_data_num[0];
 duojiKp=Menu_data_num[1];  
 duojiKd=Menu_data_num[2];
 MotorKp=Menu_data_num[3];
 MotorKd= Menu_data_num[4];
 daolu=Menu_data_num[5];
 fazhi2max=Menu_data_num[6];
 fazhi2min=Menu_data_num[7];

}
/*
 *  @brief      main����
 *  @since      v5.0
 *  @note       ɽ�� ����CCD ����ʵ��
                �޸� PIT0 �Ķ�ʱʱ�伴���޸��ع�ʱ��
 */
 main(void)
//2016.5.20 ���Բ��� �ٶ�210�ʺ� 
//��ѹ7.82  ���duojiKd=5  Kd=20
//���Ki2=5 KP=9.0 18.0 27.0 
//�ɼ� 37.1������ ʱ��13.89  �ٶ�
{
    #define BIN_MAX 0x80
    uint8 time = 5;
    
   /****************************************/
 
    com_e     com;
   nrf_result_e nrf_result;
  NVIC_SetPriorityGrouping(4);            //�������ȼ�����,4bit ��ռ���ȼ�,û�������ȼ�
  NVIC_SetPriority(PORTE_IRQn,0);         //�������ȼ�
 NVIC_SetPriority(PIT0_IRQn,1); 
   while(!nrf_init());
  // �����жϷ�����
   set_vector_handler(PORTE_VECTORn ,PORTE_IRQHandler);                //���� PORTE ���жϷ�����Ϊ PORTE_VECTORn
    enable_irq(PORTE_IRQn);
    nrf_msg_init(); //����ģ����Ϣ��ʼ��
   // ����CCDģ�飬��Ҫ ���� ������� ���԰�ģ�飬����������� ����ͼ��ʧ�ܶ�������������
   q = 18;
while(q--)
  {
        nrf_msg_tx(COM_RETRAN,nrf_tx_buff);                              //���Ͷ�� �� �����ȥ��������� ���ն˵Ļ�������
    }
   /****************************************/ 
   
   
  
    gpio_init(PTA4,GPO,1);
    Site_t site = {10,20};   //x = 10 ,y = 20
    Site_t site1={0,0};                         //��ʾͼ�����Ͻ�λ��
    Site_t site11={0,0};
    Site_t site1b={0,40};                     //��ʾͼ�����Ͻ�λ��
    Site_t site1b2={20,20+40};
    Site_t site1max={TSL1401_SIZE+20,0};        //��ʾ�����ֵλ��
    Site_t site2={0,70};                        //��ʾͼ�����Ͻ�λ��
    Site_t site2b={0,70+30};                    //��ʾͼ�����Ͻ�λ��
    Site_t site3={0,140};                        //��ʾͼ�����Ͻ�λ��
    Site_t site3b={0,140+30};                    //��ʾͼ�����Ͻ�λ��
    Size_t imgsize={TSL1401_SIZE,1};            //ͼ���С
    Size_t size={TSL1401_SIZE,20};              //��ʾ�����С
    uint8  max[TSL1401_SIZE];
    uint8  avg[TSL1401_SIZE];
   
    //LCD_init();                                 //��ʼ��
    //��ʼ�� ����CCD
    key_init(KEY_MAX);

    LCD_init();
   led_init(LED0);
   led_init(LED1);
    led_init(LED2);
    //gpio_init(PTE2, GPO,1);
   adc_init (ADC0_SE16);
   gpio_init (PTC19, GPI,0); 
   // adc_init (ADC0_SE10);
    
    tsl1401_set_addrs(TSL1401_MAX,(uint8 *)&CCD_BUFF[0],(uint8 *)&CCD_BUFF[1],(uint8 *)&CCD_BUFF[2]);
    tsl1401_init(2); //��ʼ�� ����CCD ������ �ж�ʱ��Ϊ time
    //tsl1401_led_en(TSL1401_MAX);                //���������
    //tsl1401_led_dis(TSL1401_MAX);             //�رղ����
     
    ftm_pwm_init(FTM3, FTM_CH0,50,7700);
    
    ftm_pwm_init(FTM0, FTM_CH3,1000,0);
    ftm_pwm_init(FTM0, FTM_CH4,1000,0);
    ftm_pwm_init(FTM0, FTM_CH5,1000,0);
    ftm_pwm_init(FTM0, FTM_CH6,1000,0);
    ftm_quad_init(FTM1);
    ftm_quad_init(FTM2);
    //���� �жϺ��� �� ʹ���ж�
    set_vector_handler(PIT0_VECTORn,PIT0_IRQHandler);
    enable_irq(PIT0_IRQn);
    PIDInit();
    Menu_init();
    while(1)
    {    
        //�ɼ� ����CCD ͼ��
        
   
         
    // gyroscope=adc_once(ADC0_SE10, ADC_12bit);  
            
      
 
  
   //  CCD[1][imagestore[0][2]]=0;
      if(nextError>0)
   nrf_tx_buff[COM_LEN+2]=1;
   if(nextError<=0)
    nrf_tx_buff[COM_LEN+2]=2; 
    nrf_tx_buff[COM_LEN+4]=ABS(speedreal3/10);
    if(ABS(nextError)>900)nextError=900;
    nrf_tx_buff[COM_LEN+1]=ABS(nextError/10);
     
    nrf_tx_buff[COM_LEN+3]=(speedwant/10);
    stop=nrf_rx_buff[COM_LEN+1];
    Key_deal();
    Key_dealWindows();
  if(delayen==0)
 {
   
   
  
   Menu_Display();
  
   
 }
 if(stop==0)
 {
 Data_change();

    motorprotectflag=0;
    motorprotect=0;
 }
 if(Obstacleflagup==1)
     {
       speedwant=180;
     }
if(stop==1) 
{
 speedwant=5;

}

      //LCD_num_BC(site1b2,Window_Num,32, BLUE,RED);
    //���߷��ͺͽ���
   /***************************************************************/
   do
        {
            nrf_result = nrf_msg_rx(&com, nrf_rx_buff);
            if(nrf_result == NRF_RESULT_RX_VALID)
            {
                switch(com)
                {
                    case COM_CCD:
                        break;

                    case COM_VAR:

                        break;
                    default:
                        break;
                }
            }
        }while(nrf_result != NRF_RESULT_RX_NO);      //���ղ������� ���˳�

        //��ͼ�� ���ͳ�ȥ
       nrf_msg_tx(COM20,nrf_tx_buff);
       while(nrf_tx_state() == NRF_TXING);            //�ȴ��������

    
    /***************************************************************/
    //CCD[1][imagestore[0][2]]=255;

    }
}


/*!
 *  @brief      PIT0�жϷ�����
 *  @since      v5.0
 *  @note       ���� TSL1401_INT_TIME ���� Ϊ PIT0 �����ʹ�� PIT0
 */
void PIT0_IRQHandler()
{   
   static uint16 time1=0;
    
  int k;
    
 

 
 if(time1%5==0)
  {
   
     tsl1401_get_img();
     tsl1401_time_isr();
  }
   if(time1%5==1)
  {
                  
      yitaodaizou2(); 
      erzhihua();
      zhongxiantiqu3();
      zhongxiantiqu2();
      
   }
   if(time1%5==2)
    {
 
   //Avoid_mutation();
     Avoid3_mutation();
      //zhongxianchuli2(); 
     storeimage();
       angleout();
       //angleout2();
       
    
        
      
    }
      
      if(time1%5==3)
    {
   
     

   speedcontrol3();
 //  speedwant=Menu_data_num[0];
  if(motorprotectflag==1)
   {
     ftm_pwm_duty(FTM0, FTM_CH3,0);
    ftm_pwm_duty(FTM0, FTM_CH4,0);
    ftm_pwm_duty(FTM0, FTM_CH5,0);
    ftm_pwm_duty(FTM0, FTM_CH6,0);
     
   }
   
      
   }
 if(time1%5==4)
 {
   caiji();
    Trackdeal();
    //hongwaiflag=gpio_get (PTC19);
 }
  time1++;
   PIT_Flag_Clear(PIT0);
   // ftm_pwm_duty(FTM3, FTM_CH0,7500); 
    
 
}

void maxvar(uint8 *buf,uint16 len,uint8  maxval)
{
    while(len--)
    {
        if(buf[len] > maxval)
        {
            buf[len]= maxval;
        }
    }

}
/*!
 *  @brief      PORTE�жϷ�����
 *  @since      v5.0
 *  @note       ���� TSL1401_INT_TIME ���� Ϊ PIT0 �����ʹ�� PIT0
 */
void PORTE_IRQHandler()
{
    uint8  n;    //���ź�
    uint32 flag;

    flag = PORTE_ISFR;
    PORTE_ISFR  = ~0;                                   //���жϱ�־λ

    n = 27;
    if(flag & (1 << n))                                 //PTE27�����ж�
    {
        nrf_handler();
    }
}





