#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];
char buf2[1000][512];



int
strncmp(const char *p, const char *q, uint n)
{
  while(n > 0 && *p && *p == *q)
    n--, p++, q++;
  if(n == 0)
    return 0;
  return (uchar)*p - (uchar)*q;
}

char*
strncpy(char *s, const char *t, int n)
{
  char *os;
  
  os = s;
  while(n-- > 0 && (*s++ = *t++) != 0)
    ;
  while(n-- > 0)
    *s++ = 0;
  return os;
}


void sort(int fd)
{
  int n;
  int j;
  int i; i = 0;
  int num; num = 0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    //write(1, buf, n);
    num++;
	int it; it=0; 	    
    for(j = 0; j<n; j++){
		if(buf[j]=='\n'){
			i++;
            it=0;
		}
		else{
			buf2[i][it] = buf[j];
			it++;
		}    
	}
	
  }
 num = i;

   int c; int d; int comp; 
 
  for (c=0 ; c<num-1; c++){
    for (d=0; d<num-c-1; d++){
	  comp = strcmp(buf2[d],buf2[d+1]);
      if (comp>0){
		char *temp = (char *)malloc((strlen(buf2[d]) + 1) * sizeof(char));
        strcpy(temp, buf2[d]);
        strcpy(buf2[d], buf2[d+1]);
        strcpy(buf2[d+1], temp);
        free(temp);
      }
    }
  }

  j = 0;
  i = 0;
  for(i = 0; i < num; i++){
	for(j=0; j<strlen(buf2[i]); j++)
	   printf(1,"%c", buf2[i][j]);
    printf(1,"\n");
  } 

  if(n < 0){
    printf(1, "cat: read error\n");
    exit();
  }

}

int main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 1){
    sort(0);
    exit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit();
    }
    sort(fd);
    close(fd);
  }
  exit();
}
