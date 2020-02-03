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
