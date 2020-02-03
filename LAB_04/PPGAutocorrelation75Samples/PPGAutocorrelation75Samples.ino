int len=75;//Length of input ppg signal
float sig[75]={-87.1730763754109,-109.549533301984,11.0003744438626,163.428651083375,199.149769274291,123.566000275567,56.2555857920532,11.8749570339706,-18.9772981263296,-42.9850713923412,-49.5043245212337,-44.9581951553012,-33.9320664244114,-28.5827561493291,-31.581099889945,-41.0802991997017,-54.4930736795945,-68.2627325882514,-80.6356024747688,-89.5326560071892,-97.9682553572733,-104.868826526092,-109.035435729227,-55.4279254731133,102.428906466599,215.935290654455,173.659279357024,95.2771306236299,38.6993430121057,2.58669911268712,-27.1180859655392,-41.5059205601701,-38.8811634521914,-27.5210618729797,-19.4397212719127,-21.3188810155791,-29.1986131384967,-42.0870332683741,-57.8319111754062,-69.5330363530109,-80.4628195277659,-88.3522679523337,-94.9709408231668,-102.206585235919,-97.7131921397864,4.17231992715059,174.727593109041,221.569715074344,147.842935952889,75.6186342937283,28.4890334640583,-4.64088307018155,-29.7699518670999,-35.8596281222211,-27.2681938711994,-12.2637373449533,-5.60255944596218,-9.18951717235939,-21.4811695264113,-38.0793873455779,-52.0178473656083,-63.3587989515551,-71.9347185519874,-79.0426127243086,-85.4265121042019,-86.8836420647809,-9.98433552552655,167.981065384969,251.611339878675,182.136789592575,108.006275081568,59.5490936475924,24.8996472412418,-5.4726680044669,-17.7793426698177};
float* acr=new float[len+1];//To store autocorrelation values from delay 0 to len
int L=20;
float* movAvg=new float[len];

float sumOfXSquared=0;//For NORMALIZATION of autocorrelation sequence

float Fs=25;//Sampling frequency

void setup() {
  Serial.begin(9600);
  for(int i=(len-L+1);i<len;i++)
  movAvg[i]=0;
  /* TEST FUNCTION SIN
  for(int i=0;i<len;i++)
  {
    sig[i]=sin((2*3.141593522*100*i)/Fs);
    }
    */
  acr[0]=1;acr[len]=0;//R(0)=1;R(len)=0; INITIAL SETUP SO THAT WE WILL RUN LOOP FOR AUTOCORRELATION FROM 1 TO LEN-1

  movingAveraging(sig,movAvg,L,len);
  doMeanAveraging(sig,len);
  doMeanAveraging(movAvg,len);
  doNormalization(movAvg,len);
  doNormalization(sig,len);
  sumOfXSquared=getSquaredSum(movAvg,len);
  doAutoCorrelation(movAvg,acr,len,sumOfXSquared);
  int loc=getFirstZC(acr,len+1);
  float locOfSecondMax=getMaximum(acr,loc,len,1);
  float timePeriod1=(locOfSecondMax)/Fs;//locationOfSecondMax is considered from 0 only as function looks from loc to len(not from 0)
  Serial.print("Pulse rate with moving average of Window ");Serial.print(L);Serial.print(" is ");Serial.println(60/timePeriod1);

  sumOfXSquared=getSquaredSum(sig,len);
  doAutoCorrelation(sig,acr,len,sumOfXSquared);
  loc=getFirstZC(acr,len+1);
  locOfSecondMax=getMaximum(acr,loc,len,1);
  float timePeriod=(locOfSecondMax)/Fs;//locationOfSecondMax is considered from 0 only as function looks from loc to len(not from 0)
  Serial.print("Pulse rate without moving average is ");Serial.println(60/timePeriod);

  float error=abs((timePeriod1-timePeriod)*100/timePeriod1);
  Serial.print("ERROR PERCENTAGE: ");Serial.print(error);Serial.println("%");

  int samplesperblock=25;
  for(int i=0;i<(len/samplesperblock);i++)
  {
    float* acrblock=new float[samplesperblock+1];acrblock[0]=1;acrblock[samplesperblock]=0;
    float* inpsig=new float[samplesperblock];
    for(int j=0;j<samplesperblock;j++)
    {
      inpsig[j]=movAvg[j+i*samplesperblock];
      }
      float sumOfXSquared2=getSquaredSum(inpsig,samplesperblock);
      doAutoCorrelation(inpsig,acrblock,samplesperblock,sumOfXSquared2);
      int loc2=getFirstZC(acrblock,samplesperblock+1);
      float locOfSecondMax2=getMaximum(acrblock,loc2,samplesperblock,1);
      float timePeriod=(locOfSecondMax2)/Fs;//locationOfSecondMax is considered from 0 only as function looks from loc to len(not from 0)
      Serial.print("Pulse rate is of block ");Serial.print(i);Serial.print(" is: ");Serial.println(60/timePeriod);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=0;i<len+1;i++)
{
  if(i==len)
  Serial.print(0);
  else
  {Serial.print(sig[i]+5);//Normalized Input PPG Signal
  Serial.print(',');
  Serial.print(movAvg[i]+2);}
  Serial.print(',');
  Serial.println(acr[i]);//Autocorrelation sequence
  }
}
