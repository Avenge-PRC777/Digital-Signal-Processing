int len=1000;
//float* input=new float[len];
//float* moving=new float [len];
float input[1000];
float in,mov;
float moving[1000];
int w=8;
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  mov=0;
  for(int i=0;i<w;i++)
  {
    input[i]=analogRead(A0);
    mov+=input[i]/w;
    delay(10);
  }
 // Serial.print(mov);
 // moving[0]=0;
// for(int i=0;i<w;i++)
  //moving[0]+=input[i];
  //moving[0]=moving[0]/w;
  for(int i=w;i<len;i++)
  {input[i]=analogRead(A0);delay(10);
  //moving[i-w+1]=moving[i-w]+input[i]/w-input[i-w]/w;
  mov=mov+input[i]/w-input[i-w]/w;
  Serial.print(input[i]);
  Serial.print(',');
  Serial.println(mov+200);
  }
  //for(int i=0;i<len;i++)
  //Serial.println(moving[i]);
}
