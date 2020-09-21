void rgb_write(Adafruit_PWMServoDriver& pwm,
               int start_pin,
               int r_c,int g_c,int b_c)
{
  pwm.setPWM(start_pin, 0, r_c*16);
  pwm.setPWM(start_pin + 1, 0, g_c*16);
  pwm.setPWM(start_pin + 2, 0, b_c*16);
}

//
//struct color_value{
//  int value0;
//  int value1;
//  int value2;
//  int light_pin;
//};

//-------------------------------------------------------------------------------------------------
void color_changing_mode0(int light_pin,int *c)
{
  //Serial.print(c[0]);Serial.print(" "); Serial.print(c[1]);Serial.print(" "); Serial.println(c[2]);
  delay(10);
  rgb_write(pwm0,light_pin,c[0],c[1],c[2]);
  if(c[0] == 255 && c[2] == 0 && c[1] < 255)
  {  
    c[1]+=5;
  }
   if(c[1] == 255 && c[2] ==0 && c[0] >0)
    {
    c[0]-=5;
    }
   if(c[1] ==255 && c[0] == 0 && c[2] < 255)
    {
      c[2]+=5;
    }
   if(c[2] == 255 && c[0] == 0 && c[1] > 0)
    {c[1]-=5;
    }
   if(c[2] == 255 && c[1] == 0 && c[0] < 255)
    {c[0]+=5;
    }
   if(c[0] == 255 && c[1] == 0 && c[2] > 0)
    {c[2]-=5;
    }
}

void color_changing_mode1(int light_pin,int *c)
{
  //Serial.print(c[0]);Serial.print(" "); Serial.print(c[1]);Serial.print(" "); Serial.println(c[2]);
  delay(10);
  rgb_write(pwm1,light_pin,c[0],c[1],c[2]);
  if(c[0] == 255 && c[2] == 0 && c[1] < 255)
  {  
    c[1]+=5;
  }
   if(c[1] == 255 && c[2] ==0 && c[0] >0)
    {
    c[0]-=5;
    }
   if(c[1] ==255 && c[0] == 0 && c[2] < 255)
    {
      c[2]+=5;
    }
   if(c[2] == 255 && c[0] == 0 && c[1] > 0)
    {c[1]-=5;
    }
   if(c[2] == 255 && c[1] == 0 && c[0] < 255)
    {c[0]+=5;
    }
   if(c[0] == 255 && c[1] == 0 && c[2] > 0)
    {c[2]-=5;
    }
}

void color_changing_mode_k(int *c)
{
  //Serial.print(c[0]);Serial.print(" "); Serial.print(c[1]);Serial.print(" "); Serial.println(c[2]);
  delay(10);
  pwm0.setPWM(15, 0, c[0]*16);
  pwm1.setPWM(0, 0, c[1]*16);
  pwm1.setPWM(1, 0, c[2]*16);
  if(c[0] == 255 && c[2] == 0 && c[1] < 255)
  {  
    c[1]+=5;
  }
   if(c[1] == 255 && c[2] ==0 && c[0] >0)
    {
    c[0]-=5;
    }
   if(c[1] ==255 && c[0] == 0 && c[2] < 255)
    {
      c[2]+=5;
    }
   if(c[2] == 255 && c[0] == 0 && c[1] > 0)
    {c[1]-=5;
    }
   if(c[2] == 255 && c[1] == 0 && c[0] < 255)
    {c[0]+=5;
    }
   if(c[0] == 255 && c[1] == 0 && c[2] > 0)
    {c[2]-=5;
    }
}

//----------------------------------------------------------------------
