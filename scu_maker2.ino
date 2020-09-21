#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "project.h"



Adafruit_PWMServoDriver pwm0 = Adafruit_PWMServoDriver(&Wire, 0x40);
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(&Wire, 0x41);

char command[20];//receive command from bluetooth
int mode = 0;//the working mode of the light
int rgb[3];//store rgb value of a light
//-----------------------------------------------------------------------------------------------------
//objects to achieve color_changing mode
//in order to change every light's color in color_changing mode
int s_color[3] = {255,0,0}; int c_color[3] = {255,0,0}; int u_color[3] = {255,0,0}; int m_color[3] = {255,0,0};
int a_color[3] = {255,0,0}; int k_color[3] = {255,0,0}; int e_color[3] = {255,0,0}; int r_color[3] = {255,0,0};

unsigned long current_time_for_delay;//in order to turn on each light in sequence

//-----------------------------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  //init pwm-----------------
  pwm0.begin(); pwm1.begin();
  pwm0.setPWMFreq(120);
  pwm1.setPWMFreq(120);
  Wire.setClock(400000);
  //-------------------------
  //turn on all of the lights
  rgb_write(pwm0,0,255,255,255);
  rgb_write(pwm0,3,255,255,255);
  rgb_write(pwm0,6,255,255,255);
  rgb_write(pwm0,9,255,255,255);
  rgb_write(pwm0,12,255,255,255);
  pwm0.setPWM(15, 0, 255*16);
  pwm1.setPWM(0, 0, 255*16);
  pwm1.setPWM(1, 0, 255*16);
  rgb_write(pwm1,2,255,255,255);
  rgb_write(pwm1,5,255,255,255);
}

void loop() {
  
  int len=readLine(command);
  if(len != -1)
  {
    if(command[0]>='a' && command[0]<='z')
    {
      mode = 0;
      
      int light_number; bool pwm_number;

      switch(command[0])
      {
        case 's':{
          light_number = 0;
          pwm_number = 0;
          break;
        }
        case 'c':{
          light_number = 3;
          pwm_number = 0;
          break;
        }
        case 'u':{
          light_number = 6;
          pwm_number = 0;
          break;
        }
        case 'm':{
          light_number = 9;
          pwm_number = 0;
          break;
        }
        case 'a':{
          light_number = 12;
          pwm_number = 0;
          break;
        }
        case 'e':{
          light_number = 2;
          pwm_number = 1;
          break;
        }
        case 'r':{
          light_number = 5;
          pwm_number = 1;
          break;
        }
        break;
      }
      int rgb_value[3];
       //turn char value into int value
      command_transform(command,rgb_value);
      if(command[0] == 'k')
      {
        pwm0.setPWM(15, 0, rgb_value[0]*16);
        pwm1.setPWM(0, 0, rgb_value[1]*16);
        pwm1.setPWM(1, 0, rgb_value[2]*16);
      }
      else
      {
        if(pwm_number == 0)
          rgb_write(pwm0,light_number,
                  rgb_value[0],rgb_value[1],rgb_value[2]);
        
        else if(pwm_number == 1)
          rgb_write(pwm1,light_number,
                  rgb_value[0],rgb_value[1],rgb_value[2]);
      }
    }

    else if(strcmp(command,"SCU MAKER ON") == 0)
    {
      mode = 1;
      current_time_for_delay = millis();
    }
  }
 

  if(mode == 1)
  {
    color_changing_mode0(0,s_color);
    if(millis() - current_time_for_delay > 500)
      color_changing_mode0(3,c_color);
    if(millis() - current_time_for_delay > 600)
      color_changing_mode0(6,u_color);
    if(millis() - current_time_for_delay > 1200)
      color_changing_mode0(9,m_color);
    if(millis() - current_time_for_delay > 2000)
      color_changing_mode0(12,a_color);
    if(millis() - current_time_for_delay > 3600)
      color_changing_mode_k(k_color);
    if(millis() - current_time_for_delay > 4800)
    color_changing_mode1(2,e_color);
    if(millis() - current_time_for_delay > 6200)
      color_changing_mode1(5,r_color);
  }
}
