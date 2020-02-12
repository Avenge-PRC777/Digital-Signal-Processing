void doMovingAverage(float* sig,float* mov,int window,int n)
{
  for(int i=(window-n+1);i<n;i++)
  mov[i]=0;
  for(int i=0;i<(n-window+1);i++)
 {
  float sum=0;
  for(int j=i;j<window+i;j++)
  {
   sum+=sig[j];
   }
   mov[i]=sum/L;
  } 
  }

void doNormalization(float sig[])
{
  float maxm=-1000;
  for(int i=0;i<74;i++)
  {
    if(sig[i]>maxm)
    maxm=sig[i];
    }
    for(int i=0;i<75;i++)
    {
      sig[i]=sig[i]/abs(maxm);
      }
  }
