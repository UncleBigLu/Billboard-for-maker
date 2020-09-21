//Serial readline
int readLine(char* lineBuffer);

//----------------------------------------------
//rgb_write
void rgb_write(Adafruit_PWMServoDriver& pwm,
               int start_pin,
               int r_c,int g_c,int b_c);

//change color mode

//just for the color_changing mode

void color_changing_mode0(int light_pin,int *c);
void color_changing_mode1(int light_pin,int *c);
void change_mode();

//command_transform
int command_transform(char* command,int* data);
