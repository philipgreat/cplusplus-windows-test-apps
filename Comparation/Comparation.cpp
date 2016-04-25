// Comparation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int checkbigstring(char* str1,char* str2);
int checkbigstring(char* str1,char* str2)
{
    int i=0,j,k,max = 0,tempcout;
    char *p1,*p2;
    cout<<strlen(str1)<<"  "<<strlen(str2)<<endl;
    if(strlen(str1)<strlen(str2))
    {
       p1 = str1;
       p2 = str2;
    }
    else
    {
       p1 = str2;
       p2 = str1;
    }
    while(*(p1+i) != 0)
    {
      j=0;
      while(*(p2+j)!=0)
      {
        if(*(p1+i) == *(p2+j))
        {
            k=0;
            tempcout = 0;
            while(*(p1+i+k) == *(p2+j+k))
            {
//              cout<<*(p1+i+k);
              if(*(p2+j+k)== 0 || *(p1+j+k)== 0)
                break;
              tempcout++;
              k++;
            }
        //    cout<<endl;
           
            if(tempcout>max)
              max = tempcout;
        }
        j++;
      }
      i++;
    }
    return max;
}
int main()
{
    char str1[]="abcdefghijkl";
    char str2[]= "efghijklmsdflsdfsd";
    int i=0;
    while(str1[i]!= 0)
    cout<<str1[i++]<<" ";
    cout<<endl;
    cout<<checkbigstring(str1,str2)<<endl;
    system("pause");
	return 0;
} 