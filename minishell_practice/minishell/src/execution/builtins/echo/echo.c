#include <stdbool.h>
#include <stdio.h>

bool	option(char *a)
{
	if(*a != '-') 
		return false;
		a++;
	while(*a)
	{
		if(*a != 'n')
			return false;
			a++;
	}
	return true;
}
//fucntio echo_args 
//what it does is that, it prints out all the argunments after the echo command, 
//handles the -n options(no newlines at the end).


#include <stdio.h>


void	echo_args(char **args , int start , int args_len)
{
	for(int i = start; ,i < args_len; i++){
		printf("%s", args[i]);
		if ( i < arrgs_len - 1){
			printf("  ");
		}
	}
	printf("/n");
}

//Wel;l as for this fcuntion what it does is that, the main function
//to execute the echo logic and parses the arguments, checks the options finally 
//prints the output.
