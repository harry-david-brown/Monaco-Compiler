/*************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2021
*************************************************************
* File name: Parser.h
* Compiler: MS Visual Studio 2019
* Author: Paulo Sousa (based on prof. Svillen Ranev work)
* Course: CST 8152 � Compilers, Lab Section: [011, 012]
* Assignment: A3.
* Date: Dec 11 2021
* Purpose: This file is the main header for Parser (.h)
*************************************************************/

#ifndef PARSER_H_
#define PARSER_H_

/* Inclusion section */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#ifndef COMPILERS_H_
#include "Compiler.h"
#endif
#ifndef BUFFER_H_
#include "Buffer.h"
#endif
#ifndef SCANNER_H_
#include "Scanner.h"
#endif

/* Global vars */


static Token lookahead;
extern Buffer* stringLiteralTable;
extern monaco_int line;
extern Token tokenizer();
extern monaco_chr* keywordTable[];


#define STR_LANGNAME "monaco"



/* Constants */
enum KEYWORDS {
	NO_ATTR = -1,
	DATA,
	CODE,
	INT,
	FLOAT,
	STRING,
	IF,
	THEN,
	ELSE,
	WHILE,
	DO
};

/* Function definitions */
monaco_nul startParser();
monaco_nul matchToken(monaco_int, monaco_int);
monaco_nul syncErrorHandler(monaco_int);
monaco_nul printError();


monaco_nul codeSession();
monaco_nul dataSession();
monaco_nul optVarListDeclarations();
monaco_nul optionalStatements();
monaco_nul outputStatement();
monaco_nul outputVariableList();
monaco_nul program();
monaco_nul statement();
monaco_nul statements();
monaco_nul statementsPrime();

#endif
