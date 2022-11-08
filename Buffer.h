/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2022
* Author: Svillen Ranev - Paulo Sousa
* Professors: Paulo Sousa
************************************************************
*/

/*
************************************************************
* File name: Buffer.h
* Compiler: MS Visual Studio 2022
* Author: Paulo Sousa
* Course: CST 8152 � Compilers, Lab Section: [011, 012, 013]
* Assignment: A12.
* Date: May 01 2022
* Professor: Paulo Sousa
* Purpose: This file is the main header for Buffer (.h)
************************************************************
*/

/*
 *.............................................................................
 * MAIN ADVICE:
 * - Please check the "TODO" labels to develop your activity.
 * - Review the functions to use "Defensive Programming".
 *.............................................................................
 */

#ifndef COMPILERS_H_
#include "Compiler.h"
#endif

#ifndef BUFFER_H_
#define BUFFER_H_

/* TIP: Do not change pragmas, unless necessary .......................................*/
/*#pragma warning(1:4001) *//*to enforce C89 type comments  - to make //comments an warning */
/*#pragma warning(error:4001)*//* to enforce C89 comments - to make // comments an error */

/* standard header files */
#include <stdio.h>  /* standard input/output */
#include <stdlib.h> /* for dynamic memory allocation*/
#include <limits.h> /* implementation-defined data type ranges and limits */

/* CONSTANTS DEFINITION: GENERAL (NOT LANGUAGE DEPENDENT) .................................. */

/* Modes (used to create buffer) */
enum BUFFERMODES {
	MODE_FIXED = 'f', /* Fixed mode (constant size) */
	MODE_ADDIT = 'a', /* Additive mode (constant increment to be added) */
	MODE_MULTI = 'm'  /* Multiplicative mode (constant increment to be multiplied) */
};

/* Constants about controls (not need to change) */
#define BUFFER_ERROR (-1)					/* General error message */
#define BUFFER_EOF '\0'						/* General EOF */

/* TODO: Check the limit of your buffer */
#define BUFFER_MAX_SIZE	INT_MAX-1	/* maximum capacity */ 

/* CONSTANTS DEFINITION: PREFIXED BY LANGUAGE NAME (monaco) .................................. */
#define BUFFER_DEFAULT_SIZE			100		/* default initial buffer capacity */
#define BUFFER_DEFAULT_INCREMENT	10		/* default increment factor */

/* Add your bit-masks constant definitions here - Defined for monaco */
/* BITS                                (7654.3210) */
#define BUFFER_DEFAULT_FLAG 0x00 	/* (0000.0000)_2 = (000)_10 */
#define RLB 0x8
#define EOB 0x4
#define FUL 0x2
#define EMP 0x1

/* TODO: BIT 3: RLB = Relocation - Define masks for SET, RST, CHK */
/* TODO: BIT 2: EOB = EndOfBuffer - Define masks for SET, RST, CHK */
/* TODO: BIT 1: FUL = Full - Define masks for SET, RST, CHK */
/* TODO: BIT 0: EMP = Empty - Define masks for SET, RST, CHK */

/* STRUCTURES DEFINITION: SUFIXED BY LANGUAGE NAME (monaco) .................................. */

/* TODO: Adjust datatypes */

/* Offset declaration */
typedef struct position {
	monaco_int posMark;			/* the offset to the mark position (in chars) */
	monaco_int posRead;			/* the offset to the get a char position (in chars) */
	monaco_int posWrte;			/* the offset to the add chars (in chars) */
} Position;

/* Buffer structure */
typedef struct buffer {
	monaco_chr*	content;		/* pointer to the beginning of character array (character buffer) */
	monaco_int	size;		    /* current dynamic memory size (in bytes) allocated to character buffer */
	monaco_int	increment;		/* character array increment factor */
	monaco_int	mode;			/* operational mode indicator */
	monaco_flg	flags;			/* contains character array reallocation flag and end-of-buffer flag */
	Position	position;		/* Offset / position field */
} Buffer, * BufferPointer;

/* FUNCTIONS DECLARATION:  .................................. */
/* General Operations */
BufferPointer	bufCreate(monaco_int, monaco_int, monaco_int);
BufferPointer	bufAddChar(BufferPointer const, monaco_chr);
monaco_bol		bufClear(BufferPointer const);
monaco_bol		bufDestroy(BufferPointer const);
monaco_bol		bufChkFull(BufferPointer const);
monaco_bol		bufChkEmpty(BufferPointer const);
monaco_bol		bufSetMark(BufferPointer const, monaco_int);
monaco_int		bufPrint(BufferPointer const);
monaco_int		bufLoad(BufferPointer const, FILE* const);
monaco_bol		bufRecover(BufferPointer const);
monaco_bol		bufRetract(BufferPointer const);
monaco_bol		bufRestore(BufferPointer const);
/* Getters */
monaco_chr		bufGetChar(BufferPointer const);
monaco_chr*		bufGetContent(BufferPointer const, monaco_int);
monaco_int		bufGetPosRead(BufferPointer const);
monaco_int		bufGetPosWrte(BufferPointer const);
monaco_int		bufGetPosMark(BufferPointer const);
monaco_int		bufGetSize(BufferPointer const);
monaco_int		bufGetInc(BufferPointer const);
monaco_int		bufGetMode(BufferPointer const);
monaco_flg		bufGetFlags(BufferPointer const);

#endif
