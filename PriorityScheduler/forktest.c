// Test that fork fails gracefully.
//File given by Michael Allen Bond 

// Tiny executable so that the limit can be filling the proc table.

#include "types.h"
#include "stat.h"
#include "user.h"

#define LIMIT 10000000
#define MAX 10
#define N  4

void
printf(int fd, char *s, ...)
{
  write(fd, s, strlen(s));
}
void
printpid(int fd, char *s, char *n, char *f){
  write(fd, "PID = ", strlen("PID = "));
  write(fd, s, strlen(s));
  write(fd, " : PRIORITY = ", strlen(" : PRIORITY = "));
  write(fd, n, strlen(n));
  write(fd, f, strlen(f));
  write(fd, "\n",1);
}
void itoa(int n, char out[]){
  int intsize=0;
  while(n!=0){
    int digit = n%10;
    n=(n-digit)/10;
    char c = digit +'0';
    for (int i=intsize; i>0; i--){
      out[i]=out[i-1];
    }
    out[0]=c;
    intsize++;
  }
  return;
}

void
forktest(void)
{
  int n, pid;

  printf(1, "fork test\n");
  setpriority(0);
  for(n=0; n<N; n++){
    pid = fork();
    if(pid < 0)
      break;
    if(pid == 0){
      int priority = 100-n;
      setpriority(priority);
      char stringpid[MAX];
      int procid = getpid();
      itoa(procid,stringpid);
      char stringn[MAX];
      itoa(priority,stringn);
      int counter =0;
      while(counter<LIMIT){
        counter++;
      //  if (counter == LIMIT/2)
        //  printpid(1,stringpid,stringn, " Halfway done.");
      }
      printpid(1,stringpid,stringn, " FINISHED.");
      exit();
    }
  }
  
  
  if(n == N){

    
    for(; n > 0; n--){
      if(wait() < 0){
        printf(1, "wait stopped early\n");
        exit();
      }

      //printf(1, "fork claimed to work N times!\n", N);
    }
  }
  
  if(wait() != -1){
    printf(1, "wait got too many\n");
    exit();
  }
  
  printf(1, "fork test OK\n");
}

int
main(void)
{
  setpriority(0);
  forktest();
  exit();
}
