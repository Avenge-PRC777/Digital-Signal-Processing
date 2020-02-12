void doMeanAveraging(double* vReal,int samples)
{
  double sum=0,maxm=-1000;
  for(int i=0;i<samples;i++)
  {
    sum+=vReal[i];
  }
    
    sum/=samples;
    
    for(int i=0;i<samples;i++)
    {
      vReal[i]-=(sum);
      if(vReal[i]>maxm)
        maxm=vReal[i];
      }

      for(int i=0;i<samples;i++)
      {
        vReal[i]/=(abs(maxm));
      }
  }
