#include<Wire.h>
#define MAX_ADDRESS 255
#define MAX_BIT 255

//address max:255
void PCFWrite(int address,int value){
  Wire.beginTransmission(80);
  Wire.write(address);
  Wire.write(value);
  Wire.endTransmission();
  delay(1000);
}
int PCFRead(int address){
  Wire.beginTransmission(80);
  Wire.write(address);
  Wire.endTransmission();
  Wire.requestFrom(80,1);
  return Wire.read();
}

void PCFWriteC(int address,char c){
  PCFWrite(address,(int)c);
}

char PCFReadC(int address){
  return (char)PCFRead(address); 
}
