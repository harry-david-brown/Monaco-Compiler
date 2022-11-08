/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2022
* Author: Harry Brown
* Professors: Paulo Sousa
************************************************************
*/

/*
************************************************************
* File name: compilers.h
* Compiler: gcc
* Purpose: Defines the functions called by main
* Function list: mainBuffer(), mainScanner(), mainParser().
************************************************************
*/










#ifndef COMPILERS_H_
#define COMPILERS_H_

#define DEBUG 0

/*
 * ............................................................................
 * ADVICE 1:
 * Please check the "TODO" labels to develop your activity.
 *
 * ADVICE 2: This file must be updated according to each assignment
 * (see the progression: buffer > scanner > parser).
 * ............................................................................
 */



#define monaco_TRUE	1
#define monaco_FALSE 0



/* TODO: Define your typedefs */
typedef char			monaco_chr;
typedef int				monaco_int;
typedef float			monaco_flt;
typedef double			monaco_dbl;
typedef double long		monaco_dbl_lng;

typedef void			monaco_nul;
typedef unsigned char	monaco_bol;
typedef unsigned char	monaco_flg;



/*
------------------------------------------------------------
Programs:
1: Buffer - invokes MainBuffer code
2: Scanner - invokes MainScanner code
3: Parser - invokes MainParser code
------------------------------------------------------------
*/
enum PROGRAMS {
	PGM_BUFFER	= '1',
	PGM_SCANNER = '2',
	PGM_PARSER	= '3'
};

/*
------------------------------------------------------------
Main functions signatures
(Code will be updated during next assignments)
------------------------------------------------------------
*/
monaco_int mainBuffer	(monaco_int argc, monaco_chr** argv);
monaco_int mainScanner	(monaco_int argc, monaco_chr** argv);
monaco_int mainParser	(monaco_int argc, monaco_chr** argv);


#endif
