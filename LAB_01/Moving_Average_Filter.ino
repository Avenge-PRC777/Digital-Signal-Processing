float sig[1000]={-194.7293734,-228.7205774,-241.1012313,-274.3287909,-258.4301079,-244.645154,-267.9013166,-246.6050094,-242.4746091};
int len=10;
float L=8;
float* movingav=new float[len];
float* diff=new float[len];
float* three=new float[len];

void setup()
{
Serial.begin(9600);
diff[0]=0;three[0]=0;three[1]=0;
for(int i=(len-L+1);i<len;i++)
movingav[i]=0;
for(int i=0;i<(len-L+1);i++)
 {
  float sum=0;
  for(int j=i;j<L+i;j++)
  {
   sum+=sig[j];
   }
   movingav[i]=sum/L;
 }
 for(int i=1;i<len;i++)
 diff[i]=movingav[i]-movingav[i-1];
 
 for(int i=2;i<len;i++)
 three[i]=movingav[i]-movingav[i-2];
}

void loop()
{
 
 for(int i=0;i<len;i++)
 {
  Serial.print(sig[i]);
  Serial.print(',');
  Serial.print(movingav[i]+200);
  Serial.print(',');
  Serial.print(diff[i]+400);
  Serial.print(',');
  Serial.println(three[i]+600);
 }
}
