const int L=75;
const int N=75;
float pi=3.141593522;
float sig[75]={-87.1730763754109,-109.549533301984,11.0003744438626,163.428651083375,199.149769274291,123.566000275567,56.2555857920532,11.8749570339706,-18.9772981263296,-42.9850713923412,-49.5043245212337,-44.9581951553012,-33.9320664244114,-28.5827561493291,-31.581099889945,-41.0802991997017,-54.4930736795945,-68.2627325882514,-80.6356024747688,-89.5326560071892,-97.9682553572733,-104.868826526092,-109.035435729227,-55.4279254731133,102.428906466599,215.935290654455,173.659279357024,95.2771306236299,38.6993430121057,2.58669911268712,-27.1180859655392,-41.5059205601701,-38.8811634521914,-27.5210618729797,-19.4397212719127,-21.3188810155791,-29.1986131384967,-42.0870332683741,-57.8319111754062,-69.5330363530109,-80.4628195277659,-88.3522679523337,-94.9709408231668,-102.206585235919,-97.7131921397864,4.17231992715059,174.727593109041,221.569715074344,147.842935952889,75.6186342937283,28.4890334640583,-4.64088307018155,-29.7699518670999,-35.8596281222211,-27.2681938711994,-12.2637373449533,-5.60255944596218,-9.18951717235939,-21.4811695264113,-38.0793873455779,-52.0178473656083,-63.3587989515551,-71.9347185519874,-79.0426127243086,-85.4265121042019,-86.8836420647809,-9.98433552552655,167.981065384969,251.611339878675,182.136789592575,108.006275081568,59.5490936475924,24.8996472412418,-5.4726680044669,-17.7793426698177};
float Fs=25;//25 Hz
float* movavg=new float[75];
int window=10;
float* dftReal=new float[75];
float* dftImag=new float[75];
float** dftmatrixRealPart=new float*[75];
float** dftmatrixImagPart=new float*[75];
float* inversesig=new float[75];
//float dftmatrixRealPart[150][150];
//float dftmatrixImagPart[150][150];
//float dftReal[150];
//float dftImag[150];
float maxm=-1000;
int kindex=0;


//Frequency is kFs/L;
void setup() {
    Serial.begin(9600);
    for(int i=0;i<75;i++)
    {
     dftmatrixRealPart[i]=new float[75];
     dftmatrixImagPart[i]=new float[75];
      }
    
    for(int n=0;n<L;n++)
    {
      dftmatrixRealPart[0][n]=1;dftmatrixRealPart[n][0]=1;//This block assumes N==L so loop is equal for column and row
      dftmatrixImagPart[0][n]=0;dftmatrixImagPart[n][0]=0;
      }
      
    for(int k=1;k<N-1;k++)
    {
      for(int n=k;n<L;n++)
      {
        dftmatrixRealPart[k][n]=cos((2*pi*k*n)/N);
        dftmatrixImagPart[k][n]=sin((2*pi*k*n)/N)*(-1);
        if(n!=k)
        {
         dftmatrixRealPart[n][k]=dftmatrixRealPart[k][n];
         dftmatrixImagPart[n][k]=dftmatrixImagPart[k][n];
          }
        }
      }
      
     doMovingAverage(sig,movavg,10,75);
     
     for(int k=0;k<N;k++)
     {
      float sumReal=0,sumImag=0;
      for(int n=0;n<L;n++)
      {
        sumReal+=(dftmatrixRealPart[k][n]*movavg[n]);
        sumImag+=(dftmatrixImagPart[k][n]*movavg[n]);
        }
        dftReal[k]=sumReal;
        dftImag[k]=sumImag;
      }
    
      for(int k=0;k<(N-1);k++)
      {
        float xy=sqrt((dftReal[k]*dftReal[k])+(dftImag[k]*dftImag[k]));
        if(xy>maxm&&(k<N/2))
        {
          maxm=xy;
          kindex=k;
          }
        }
        //Serial.print("Frequency for maximum magnitude spectrum is ");Serial.print((kindex*Fs)/N);Serial.println(" Hz");
        //Serial.print("Pulse period is ");Serial.print(60*(kindex*Fs)/N);Serial.println(" BPM");

      //Inverse DFT MATRIX Computation
      for(int k=1;k<N-1;k++)
     {
      for(int n=k;n<L;n++)
      {
        dftmatrixImagPart[k][n]=-1*dftmatrixImagPart[k][n];
        if(n!=k)
        {
         dftmatrixImagPart[n][k]=dftmatrixImagPart[k][n];
          }
        }
      }
      
     //Inverse DFT Computation
     for(int k=0;k<N;k++)
     {
      float sumReal=0,sumImag=0;
      for(int n=0;n<L;n++)
      {
        sumReal+=(dftmatrixRealPart[k][n]*dftReal[n]);
        sumImag+=(dftmatrixImagPart[k][n]*dftImag[n]);
        }
        inversesig[k]=sqrt(sumReal*sumReal+sumImag*sumImag);
      }

      doNormalization(inversesig);
      doNormalization(sig);
      doNormalization(movavg);
}

void loop() {
  for(int k=0;k<74;k++)
    {
      Serial.print(sig[k]);
      Serial.print(',');
      Serial.print(movavg[k]+2);
      Serial.print(',');
      Serial.print(inversesig[k]+4);
      Serial.println(',');
      }
}
