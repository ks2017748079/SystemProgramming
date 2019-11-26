void p1()
{ 
	    p2();
}
	
void p2() 
{
	    int error;
	    	
	        error = 1;
		    if (error) {
			            printf("오류 \n");
				            longjmp(env, 1);
					        }
}

