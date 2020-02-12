void doMovingAverage(double* vReal,double* vRealMA,int samples,int window)
{
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
  }
