  #include <bits/stdc++.h>

  using namespace std;

  int main()
  {
    int T;
    scanf("%d",&T);
    while(T--)
    {
      string s[100];
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
       for(int i = 0; i < 2*b+1; i++)
  	   {
  		  for(int j = 0; j < 2*b-i; j++)
  			 s[i] += ".";
  		  if(i%2 == 0)
  		   {
  		     for(int j = 0; j < a; j++)
  			 s[i] += "+-";
  		     s[i] += "+";
  		    }
  		  if(i%2 == 1)
  		   {
  		    for(int j = 0; j < a; j++)
  			 s[i] += "/.";
  		    s[i] += "/";
  		   }
  	    }
       int len = 2*b+1;
       for(int i = 0; i < 2*c; i++)
         {
  	    if(i % 2 == 0)
  	      {
  		for(int j = 0; j < a; j++)
  	          s[i+len] += "|.";
  	        s[i+len] += "|";
  	      }
              else
  	    {
  	        for(int j = 0; j < a; j++)
  	           s[i+len] += "+-";
                  s[i+len] += "+";
              }
         }


       for(int  i = 2*b; i > 0; i--)
         for(int j = 0; j < 2*c; j++)
           {
                if(i%2 == 0)
                   {
                     if(j % 2 == 0)
                         s[i+j] += '.';
                      else s[i+j] += '/';
                    }
                else {
                    if(j % 2 == 0)
                       s[i+j] += '|';
                    else s[i+j] += '+';
                }
           }

       for(int i = 0; i < 2*b; i++)
       {
  	     for(int j = 0; j < 2*b-i; j++)
  		    s[2*b+2*c-i] += '.';
       }
      for(int i = 0; i < 2*b+2*c+1; i++)
          cout << s[i] << endl;
     }
      return 0;
    }
