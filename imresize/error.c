/*************************************
Dveloper: Sungjun Yoon
E-mail: sjyoon1671@gmail.com
Github: https://github.com/vujadeyoon

Title: error.c
Version: 171203a
Description: error function
**************************************/

#include "header.h"

void error(char *error_statement)
{
	printf("%s\n", error_statement);
	exit(-1);
}