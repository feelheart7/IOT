#include <SoftwareSerial.h>
#include <time.h>


SoftwareSerial mySerial(7, 6);  // TX-Pin11, RX-Pin10
void updateSerial()
{
  delay(1000);
  while (Serial.available()) {
    mySerial.write(Serial.read());//如果Serial收到数据则通过mySerial输出
  }
  while(mySerial.available()) {
    Serial.write(mySerial.read());//如果mySerial收到数据则通过Serial输出
  }
}   

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  randomSeed(analogRead(0));
}

void loop()
{ 
  int requestcode=1;
  int heartrateMin=50;
  int heartrateMax=150;
  
  int h=999;

  //随机值模拟实时
  srand((unsigned)time(NULL));
  int random1=150;
  h = random(60,90);
  
  //处理字节大小的问题
  int n1=0;
  int n2=0;
  if(h>=0&&h<10){n1=7;n2=11;}
  else if(h>=10&&h<100){n1=8;n2=111;}
  else{n1=9;n2=1111;}
  

  

switch(requestcode){

  
  case 0:                                 //只上传最新的一次
  {
//  mySerial.println("AT+GMR");          //读取固件版本 
//  updateSerial();
//  
//  mySerial.println("at+cpin?");          //查询卡是否插好 
//  updateSerial();
//  
//  mySerial.println("at+csq");          //查询设置信号质量 
//  updateSerial();
   mySerial.println("AT");          //握手测试，成功则返回OK 
   updateSerial(); 

   mySerial.println("AT+HTTPPARA=url,122.152.193.34/iot/servlet/Insert");          //设置 url 
   updateSerial(); 

   mySerial.println("AT+HTTPPARA=port,8080");          //设置目标端口号为 8080 
   updateSerial(); 
  
   mySerial.println("AT+HTTPSETUP");          //建立 HTTP 链接
   updateSerial(); 
   
   mySerial.print("AT+HTTPACTION=2,");          //post方式请求 POST 方式请求，POST 发 送 n个字节;
   mySerial.println(n1);
   updateSerial(); 

   mySerial.print("r=0&h=");          //输入需要上传的内容   
   mySerial.println(h);         
   mySerial.println(n2);
   
   updateSerial(); 
    
   mySerial.write(26);//结束符

   //停止
   while(1)
    { 
    if(mySerial.available()) 
    {
      Serial.write(mySerial.read());//如果mySerial收到数据则通过Serial输出
    }
    if(Serial.available())
    {
      mySerial.write(Serial.read());//如果Serial收到数据则通过mySerial输出
    }   
    }   
   break;
   }

    
case 1:
{
   mySerial.println("AT");          //握手测试，成功则返回OK 
   updateSerial(); 

   mySerial.println("AT+HTTPPARA=url,122.152.193.34/iot/servlet/Insert");          //设置 url 
   updateSerial(); 

   mySerial.println("AT+HTTPPARA=port,8080");          //设置目标端口号为 8080 
   updateSerial(); 
  
   mySerial.println("AT+HTTPSETUP");          //建立 HTTP 链接
   updateSerial(); 
   
   mySerial.print("AT+HTTPACTION=2,");          //post方式请求 POST 方式请求，POST 发 送 n个字节;
   mySerial.println(n1);
   updateSerial(); 

   mySerial.print("r=1&h=");          //输入需要上传的内容   
   mySerial.println(h);         
   mySerial.println(n2);
   
   updateSerial(); 
    
   mySerial.write(26);//结束符


  
  
  break;
  
  }
    


  
   }

  
      
}            
