char lineBufferinternal[128];
int lineBufferCountinternal=0;

int readLine(char* lineBuffer){
  int bytebuf=Serial.read();
  if(bytebuf==-1){
    return -1;
  }
  if((bytebuf=='\r')||(bytebuf=='\n')){
    memcpy(lineBuffer,lineBufferinternal,lineBufferCountinternal*sizeof(lineBufferinternal[0]));//首参数为目的，中间参数为源，末参数为要被复制的字节数
    lineBuffer[lineBufferCountinternal]='\0';
    int ret=lineBufferCountinternal;
    lineBufferCountinternal=0;
    return ret;
  }else{
    lineBufferinternal[lineBufferCountinternal]=bytebuf;
    lineBufferCountinternal++;
  }
  return -1;
}
