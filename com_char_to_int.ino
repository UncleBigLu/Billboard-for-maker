int command_transform(char* command,int* data)
{
  int command_buffer_counter = 2;//command start from the third byte
  char tem_com[5];
  int tem_com_counter = 0;//tem_com start from the first byte
  int data_counter = 0;//data start from the first unit
  while(command[command_buffer_counter] != '\0')
  {
    while(command[command_buffer_counter] != ' ' && command[command_buffer_counter] != '\0')
   {
     tem_com[tem_com_counter] = command[command_buffer_counter];
     ++tem_com_counter; ++command_buffer_counter;
   }
     tem_com[tem_com_counter] = '\0';
     //transform char command to int command 
      sscanf(tem_com,"%d",&(data[data_counter]));
      ++data_counter; 
      if(command[command_buffer_counter] != '\0')
        ++command_buffer_counter;
     
     //init buffer and counter
      tem_com_counter = 0;
      memset(tem_com,0,5*sizeof(char));
  }
  
}
