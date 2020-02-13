#include <stdio.h>
#include <math.h>

int main(){
	unsigned int N, M;
	unsigned short int R, G, B;
	long int var, i;
	float x, R1, G1, B1, H, S, V, Cmax, Cmin, delta;
    char c;

    scanf("%u%u", &N, &M);   // Citim N latimea si M inaltimea.
    scanf(" %c", &c);        // Citim litera prin care se face selectia operatiei aplicate.
    scanf("%f", &x);         // Citim factorul de modificare a caracteristicii.
    
     var = N * M;            // Pentru citirea a N*M elemente si executarea a N*M pasi.
   
   for (i = 1; i <= var; i++)
   {
   	scanf("%hu%hu%hu", &R, &G, &B); /* Citim tripletul (R, G, B)
                                      pentru fiecare pixel. */

   R1 = (float)R / 255;  // Modificam intervalul [0,255] in [0,1].
   G1 = (float)G / 255;
   B1 = (float)B / 255;

Cmax = R1;
  if (Cmax < G1) 
      Cmax = G1;        // Aflam maximul dintre (R1, G1, B1).
  if (Cmax < B1) 
  	  Cmax = B1;

Cmin = R1;
  if (Cmin > G1)
   Cmin = G1;           // Aflam minimul dintre (R1, G1, B1).
  if (Cmin > B1) 
   	Cmin = B1;

delta = Cmax - Cmin;    // Aflam valoarea variabilei delta.

   if(delta == 0)
    H = 0;                   // Calculul valorii H (hue).
        else if (Cmax == R1)
 	     {H = 60 * (fmod((G1 - B1) / delta, 6));
 	    }
 	    else if (Cmax == G1)
 	  	  	 {H = 60 * (((B1 - R1) / delta) + 2);
 	  	  	}
 	  	  	  else {H = 60 * (((R1 - G1) / delta) + 4);
 	  	  	         }
 
 	if (H < 0) 
 	    {H = (H + 360) / 360; // Normam valoarea variabilei H care apartine lui [0,1]
 	    }                       
 	  else H = H / 360;

  
    if (Cmax == 0)        // Calculul valorii S (saturation).
        S = 0;
      else S = delta / Cmax;
   
    if (S > 1)
  	  S = S / 100;         // Normam valoarea variabilei S care apartine lui [0,1]
                          
   V = Cmax;           // Calculul valorii V(value) (V nu trebuie normat).
  
   if (c == 'h')        // Selectaea caracteristicii care va fi modificata     
     {H = H + x;          // pentru fiecare pixel.
   		if (H > 1)
   		    H = 1;       // H trebuie sa ramana in [0,1].
   		if (H < 0) 
   			H = 0;  
    }
   	else if (c == 's')
   	 {S = S * x;
   		if (S > 1) S = 1; // S trebuie sa ramana in [0,1].
   		if (S < 0) S = 0;
   	}
   	else {V = V * x;
   		if (V > 1)       // V trebuie sa ramana in [0,1].
   			V = 1;
   		if (V < 0)
   			V = 0;
   	    }

   	printf("%.5f %.5f %.5f\n", H, S, V);

   	 
   	}
   	return 0;
}



    
  

 	