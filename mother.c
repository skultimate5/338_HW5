#include <stdlib.h>
#include <stdio.h>
#include "Cookie.h"

int currentCookieNum = 20;
int numTinaGetsCookie = 0;
int destroyedCount = 0;

int *getmemycookie_1_svc(struct functionVals* vals, struct svc_req * req)
{
  int static aReturn;

  if (currentCookieNum == 0){	//if the cookie jar is empty set a value to -2
  	aReturn = -2;
  }
  else {
  	if (vals->b == 0){			//this is Tina
  		aReturn = 1;	//allow Tina to have a cookie
  		numTinaGetsCookie++;
  		currentCookieNum--;
	}
	else if (vals->b == 1){		//this is Judy
		if (numTinaGetsCookie >= 2){	//Tina has had two cookies, so Judy can have one
			aReturn = 1;
			currentCookieNum--;
			numTinaGetsCookie = 0;
		}
		else{				//Tina can't have a cookie because Judy hasn't had two
			aReturn = -1;
		}
  	}
  }


  if(aReturn == -2){
        printf("Cookie jar is empty, no more cookies for you\n");
  }
  else if(aReturn == -1){
        printf("Sorry Judy, you can't get a cookie right now\n");
  }
  else if(aReturn == 1){
        if (vals->b == 0){
                printf("Tina, you can have a cookie! There are %d cookies left. \n", currentCookieNum);
        }
        else{
                printf("Judy, you can have a cookie! There are %d cookies left. \n", currentCookieNum);
        }
  }


  return (&aReturn); 
}

void * addtodestroynum_1_svc(struct functionVals* vals, struct svc_req * req){
	destroyedCount++;
	if (destroyedCount == 2){
		exit(1);
	}
}


