/* Struct for cookie function vals */
struct functionVals{
	int a;	/*-2 if cookie jar is empty, -1 if Judy can't get cookie, +1 			if cookie is successfully returned*/
	int b;	/* Indicates if Tina (0) or Judy (1) */
};

program COOKIE_PRG{
	version COOKIE_VER{
		int getmemycookie(functionVals) = 1;
		void addtodestroynum(functionVals) = 2;
	} = 1;
}  = 0x2defaced;
