#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kmp(char* str, int m, int* niz){
  int j=0;
  int i=1;
  niz[0]=0;
  while(i<m){
    if(str[i]==str[j]){
      niz[i]=j+1;
      i++;
      j++;
    }else{
      if(j!=0)j=niz[j-1];
      else{
        niz[i]=0;
        i++;
      }
    }
  }
}

int main(){
  char str[128];
  char podstr[127];

  fgets(str,127,stdin);
  fgets(podstr,126,stdin);

  str[strcspn(str,"\n")]='\0';
  podstr[strcspn(podstr,"\n")]='\0';
  int n=strlen(str);
  int m=strlen(podstr);
  printf("n:%i,m:%i\n", n, m);

  int niz[m];
  kmp(str, m, niz);
  for(int z=0;z<m;z++){
    printf("%i\n", niz[z]);
  }

  int j=0;
  int i=0;
  while(i<n){
    if(str[i]==podstr[j]){
      i++;
      j++;
    }else{
      if(j!=0) j=niz[j-1];
      else i++;
    }
  if(j==m){
      printf("\nNadjen na %i", i-j);
      j=niz[j-1];
    }
  }
}
