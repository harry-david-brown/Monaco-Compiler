/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2022
* Author: Harry Brown
* Professor: Paulo Sousa
************************************************************
*/

/*
************************************************************
* File name: compilers.c
* Compiler: gcc
* Author: Harry Brown
* Course: CST8152 Compilers, Lab Section: 011
* Assignment: A12
* Date: June 11, 2022
* Professor: Paulo Sousa
* Purpose: Main file of compilers project
* Function list: main()
************************************************************
*/









/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment 
 * (see the progression: buffer > scanner > parser).
 * ............................................................................
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef COMPILERS_H_
#include "Compiler.h"
#endif

 /*
  * TODO:
  * Basically, change all datatypes to your language definitions
  * (see "Compilers.h")
  */

/*
***********************************************************
* Function name: 
*       main
* Purpose: 
*       Main function
* Parameters: 
*       argc, argv - Command line arguments
* Return value: 
*       Success or failure
* Called functions: 
*       mainBuffer(), mainScanner(), mainParser()
*************************************************************
*/




monaco_int main(int argc, char** argv) {
	monaco_int i;
	if (DEBUG) {
		for (i = 0; i < argc; ++i)
			printf("argv[%d] = %s\n", i, argv[i]);
	}
	if (argc < 2) {
		printf("%s%s%c%s%c%s%c%s", argv[0], ": OPTIONS [",
			PGM_BUFFER, "] - Buffer, [",
			PGM_SCANNER, "] - Scanner, [",
			PGM_PARSER, "] - Parser\n");
		return EXIT_FAILURE;
	}
	monaco_chr option = argv[1][0];
	switch (option) {
	case PGM_BUFFER:
		mainBuffer(argc, argv);
		break;
	case PGM_SCANNER:
		mainScanner(argc, argv);
		break;
	case PGM_PARSER:
		mainParser(argc, argv); 
		break;
	default:
		printf("%s%s%c%s%c%s%c%s", argv[0], ": OPTIONS [",
			PGM_BUFFER, "] - Buffer, [",
			PGM_SCANNER, "] - Scanner, [",
			PGM_PARSER, "] - Parser\n");
		break;
	}
	return EXIT_SUCCESS;
}
