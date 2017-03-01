#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

int main() 
	{
	 int x = 0, y = 1, pirmoMasyvo, c = 0, type = 1;
	 char ch, TrumpCard;;
	 stringstream ss;
         string s;
	 string Masyvas1[20], antrasMasyvas[20], Masyvas2[20], MasyvasAntras[20];
	 char  rankMasyvas[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	 ifstream in("Data.txt");
	 in >> TrumpCard;
	 
	 while(in.get(ch))
	 {
	   if ((ch != '\n' && isupper(ch) || isdigit(ch)) && (type == 1))
	      {
		Masyvas1[x] = ch;
		x++;

	      }
	   if ((ch != '\n' && isupper(ch) || isdigit(ch)) && (type == 0) )
	      {
		Masyvas2[c] = ch;
	        c++;
	      }
	   if (ch =='|')
	      {
		type = 0;
	      }

	   else if ((ch == '\n'))
	      {
		pirmoMasyvo = x;
		x = 0;
		y++;
	      }


	   }

	   int w = 0;
	   string MasyvasPirmas[12], rank ;
	   
	   cout<<"Offence player cards:   |||  ";

	   for(int i = 0 ;i < pirmoMasyvo; i = i + 2)
	   {
	      rank = (Masyvas1[i] + Masyvas1[i + 1]);
	      MasyvasPirmas[w] = rank;
	      cout << MasyvasPirmas[w] <<" ";
              w++;
	   }

	   w=0;

	   cout<<"  |||"<<endl;
	   cout<<"defence player cards:   |||  ";
	   for(int i = 0 ;i < c; i =i+2)
           {
	     rank = (Masyvas2[i] + Masyvas2[i + 1]);
	     MasyvasAntras[w] = rank;
	     cout << MasyvasAntras[w] <<" ";
	     w++;
	   }
	     
	   cout<<"  |||"<<endl;;
           cout<<"Card ranks in ascending order:   ";

	   for (int i = 0; i < 13; i++)
	       {
		cout<<rankMasyvas[i]<<" ";
	       }



	   cout<<endl;
	   cout<<"Trump Card: "<<TrumpCard<<endl;
	   //string trumpoKorta  = string(TrumpCard);

	   ss<<TrumpCard;
	   ss>>s;
	   string trumpoKorta =s;
	
	   int nonTrumpcard;
         	
	   for (int i = 0; i < (pirmoMasyvo/2); i++)
           {
	      if((MasyvasPirmas[i].substr(0,1)) != trumpoKorta)
	 	{
	          nonTrumpcard++; //whaat ever.... =.=
	        }
	      else if ((MasyvasPirmas[i].substr(0,1)) == trumpoKorta)
	        {
			//trump kard codition missing
		}

	    }

 	   cout<<endl;
           cout<<nonTrumpcard<<endl;

	   /*
	   if (nonTrumpcard != 0)
	    {
	        for (int i = 0; i < (pirmoMasyvo / 2); i++)
	        {
		//COMPARINUUUU SKAICIUS !!
	            if((MasyvasPirmas[i].substr(1,1) == ) )
		        {
			      nonTrumpcard++; //whaat ever.... =.=
			}
		     else if ((MasyvasPirmas[i].substr(0,1)) == trumpoKorta)
			{

			}
 		}

	     }
					*/

						return 0;
}

