
#include "arduinoFFT.h"

arduinoFFT FFT = arduinoFFT(); /* Create FFT object */
/*
These values can be changed in order to evaluate the functions
*/
const uint16_t samples = 128; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = 25;
/*
These are the input and output vectors
Input vectors receive computed results from FFT
*/
double vReal[samples]={-87.1730763754109,-109.549533301984,11.0003744438626,163.428651083375,199.149769274291,123.566000275567,56.2555857920532,11.8749570339706,-18.9772981263296,-42.9850713923412,-49.5043245212337,-44.9581951553012,-33.9320664244114,-28.5827561493291,-31.581099889945,-41.0802991997017,-54.4930736795945,-68.2627325882514,-80.6356024747688,-89.5326560071892,-97.9682553572733,-104.868826526092,-109.035435729227,-55.4279254731133,102.428906466599,215.935290654455,173.659279357024,95.2771306236299,38.6993430121057,2.58669911268712,-27.1180859655392,-41.5059205601701,-38.8811634521914,-27.5210618729797,-19.4397212719127,-21.3188810155791,-29.1986131384967,-42.0870332683741,-57.8319111754062,-69.5330363530109,-80.4628195277659,-88.3522679523337,-94.9709408231668,-102.206585235919,-97.7131921397864,4.17231992715059,174.727593109041,221.569715074344,147.842935952889,75.6186342937283,28.4890334640583,-4.64088307018155,-29.7699518670999,-35.8596281222211,-27.2681938711994,-12.2637373449533,-5.60255944596218,-9.18951717235939,-21.4811695264113,-38.0793873455779,-52.0178473656083,-63.3587989515551,-71.9347185519874,-79.0426127243086,-85.4265121042019,-86.8836420647809,-9.98433552552655,167.981065384969,251.611339878675,182.136789592575,108.006275081568,59.5490936475924,24.8996472412418,-5.4726680044669,-17.7793426698177};
double vImag[samples]={0};
double maxim=-10000.0;int kindex=0;
int window=10;double sum=0;
double vRealMA[samples];

void setup()
{
  Serial.begin(9600);
  for(int i=75;i<128;i++)
    vReal[i]=0;

    //MOVING AVERAGE
  for(int i=(samples-window+1);i<samples;i++)
  vRealMA[i]=0;
  for(int i=0;i<(samples-window+1);i++)
 {
  float sum=0;
  for(int j=i;j<window+i;j++)
  {
   sum+=vReal[j];
   }
   vRealMA[i]=sum/window;
  }
    
  FFT.Windowing(vRealMA, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);  /* Weigh data */
  FFT.Compute(vRealMA, vImag, samples, FFT_FORWARD); /* Compute FFT */
  for(int i=0;i<samples;i++)
  {
    double temp=sqrt(vRealMA[i]*vRealMA[i]+vImag[i]+vImag[i]);
    if((temp>maxim)&&(i<samples/2))
    {
      maxim=temp;kindex=i;
      }
    Serial.print(temp);
    Serial.println(',');
  }
  Serial.print("Pulse rate using FFT Library and with moving average window ");Serial.print(window);Serial.print(" is: ");Serial.print((60*kindex*samplingFrequency)/samples);Serial.println(" BPM");
}

void loop()
{
}
