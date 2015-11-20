#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "Cookie.h"

char *server;
CLIENT *client1;
char machine[200];

void callGetMeMyCookie();

int main(int argc, char *argv[]) {
 
  if (argc < 2) {       //check that server is specified
    printf("The server must be specified\n");
    printf("Usage: %s <hostname> \n",argv[0]);
    exit(1);
  }
  server=argv[1];       //set server name

  gethostname(machine,200);     //set machine name

  while(1){
    sleep(rand() % 5);
    printf("Judy is requesting a cookie\n");
    callGetMeMyCookie();
  }

  return(0);
}

void callGetMeMyCookie() {
  struct functionVals vals= {0, 1};


  if (client1==NULL) {        //if no connection, connect
    if ((client1 = clnt_create(server,COOKIE_PRG,COOKIE_VER,"udp"))==NULL) {
      clnt_pcreateerror(server);
      exit(1);
    }
  }

  int a=*getmemycookie_1(&vals,client1);

  if (a == -2){
	printf("Goodbye Judy\n");
	addtodestroynum_1(&vals, client1);
      clnt_destroy(client1);
      exit(1);
  }
}
