void doAutoCorrelation(float* movAvg,float* acr,int len,float sumOfXSquared)
{
  for(int delayTow=1;delayTow<len;delayTow++)
  {
    float sum=0;
    for(int j=delayTow;j<len;j++)
    {
      sum+=(movAvg[j]*movAvg[j-delayTow]);
      }
      acr[delayTow]=sum/sumOfXSquared;
  } 
  }

void movingAveraging(float* sig,float* mov,int L,int len)
{
 for(int i=0;i<(len-L+1);i++)
 {
  float sum=0;
  for(int j=i;j<L+i;j++)
  {
   sum+=sig[j];
   }
   mov[i]=sum/L;
  } 
  }
/*Function to do mean averaging of the signal
If you dont mean average then your autocorrelation will be always positive and will reduce from 1 to 0 without being negative
This happens as data is not centered around zero, hence autocorrelation will always result in a positive number*/
void doMeanAveraging(float* sig,int len)
{
  float sum=0;
  for(int i=0;i<len;i++)
  {
    sum+=(sig[i]);
    }
    sum/=len;
    for(int j=0;j<len;j++)
    {
      sig[j]-=sum;
      }
 }

/*Function to get maximum value in an array or signal*/
 float getMaximum(float* sig,int startLookingFrom,int endLookingAt,int locationNotMax)
 {
  float maxInSig=-1000;float location=0;
  for(int i=startLookingFrom;i<=endLookingAt;i++)
  {
    if(sig[i]>maxInSig)
      {
        maxInSig=sig[i];
        location=i;
        }
    }
    if(locationNotMax==1)
    return location;
    else
    return maxInSig;
  }

/*Function to perform normalization in signal
If a signal is normalized, then it can be plotted with autocorrelation as both range from -1 to 1*/
 void doNormalization(float* sig,int len)
 {
  float maxInSig=getMaximum(sig,0,len-1,0);
  for(int i=0;i<len;i++)
  {
    sig[i]/=abs(maxInSig);
    }
  }

/*Function to get sum of squared elements of signal; Required to perform normalization on acr*/
  float getSquaredSum(float* sig,int len)
  {
    float sumOfXSquared=0;
    for(int i=0;i<len;i++)
    {
      sumOfXSquared+=(sig[i]*sig[i]);//Finding sum of square values of individual elements(0 delay in a sense) for NORMALIZATION of acr
      }
      return sumOfXSquared;
    }

/*Function to get first Zero Crossing Point; Required to reduce autocorrelation sequence to get second maximum*/
  int getFirstZC(float acr[],int len1)
  {
    for(int i=1;i<len1;i++)
    {
      if((acr[i]*acr[i-1])<=0)
        return i;
      }
    }
