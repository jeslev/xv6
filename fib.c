#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int fib(int n){
    printf(1," %d", n);
    if(n<2){
        return 1;
    }
    return n*fib(n-1);
}


int main(){
    int fd = open("serie",O_CREATE|O_RDWR);
    if(fd>0){
        char input[100];
        gets(input,100);
        int num = atoi(input);
        
        printf(1,"\n");
        printf(fd,"\nfib(%d) = %d\n",num,fib(num));
        close(fd);
    }
    exit();
}
