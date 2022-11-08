/*************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Fall, 2021
* Author: Svillen Ranev - Paulo Sousa
* Professors: Paulo Sousa / Daniel Cormier
*************************************************************/

/*************************************************************
* File name: Parser.c
* Compiler: MS Visual Studio 2019
* Course: CST 8152 – Compilers, Lab Section: [011, 012]
* Assignment: A32.
* Date: Sep 01 2021
* Professor: Paulo Sousa
* Purpose: This file contains all functionalities from Parser.
* Function list: (...).
*************************************************************/

#ifndef COMPILERS_H_
#include "Compiler.h"
#endif

#ifndef PARSER_H_
#include "Parser.h"
#endif

monaco_int syntaxErrorNumber = 0;

/* TO_DO: For all functions adjust the datatypes used in your language */

/*************************************************************
 * Process Parser
 ************************************************************/
/* TO_DO: This is the function to start the parser - check your program definition */

monaco_nul startParser() {
	lookahead = tokenizer();
	if (lookahead.code != SEOF_T) {
		program();
	}
	matchToken(SEOF_T, NO_ATTR);
	printf("%s%s\n", STR_LANGNAME, ": Source file parsed");
}


/*************************************************************
 * Match Token
 ************************************************************/
/* TO_DO: This is the main code for match - check your definitions */

monaco_nul matchToken(monaco_int tokenCode, monaco_int tokenAttribute) {
	monaco_int matchFlag = 1;
	switch (lookahead.code) {
	case KW_T:
		if (lookahead.attribute.codeType != tokenAttribute)
			matchFlag = 0;
	default:
		if (lookahead.code != tokenCode)
			matchFlag = 0;
	}
	if (matchFlag && lookahead.code == SEOF_T)
		return;
	if (matchFlag) {
		lookahead = tokenizer();
		if (lookahead.code == ERR_T) {
			printError();
			lookahead = tokenizer();
			syntaxErrorNumber++;
		}
	}
	else
		syncErrorHandler(tokenCode);
}

/*************************************************************
 * Syncronize Error Handler
 ************************************************************/
/* TO_DO: This is the function to handler error - adjust basically datatypes */

monaco_nul syncErrorHandler(monaco_int syncTokenCode) {
	printError();
	syntaxErrorNumber++;
	while (lookahead.code != syncTokenCode) {
		if (lookahead.code == SEOF_T)
			exit(syntaxErrorNumber);
		lookahead = tokenizer();
	}
	if (lookahead.code != SEOF_T)
		lookahead = tokenizer();
}

/*************************************************************
 * Print Error
 ************************************************************/
/* TO_DO: This is the function to error printing - adjust basically datatypes */

monaco_nul printError() {
	Token t = lookahead;
	printf("%s%s%3d\n", STR_LANGNAME, ": Syntax error:  Line:", line);
	printf("*****  Token code:%3d Attribute: ", t.code);
	switch (t.code) {
	case ERR_T:
		printf("%s\n", t.attribute.errLexeme);
		break;
	case SEOF_T:
		printf("SEOF_T\t\t%d\t\n", t.attribute.seofType);
		break;
	case MNID_T:
		printf("%s\n", t.attribute.idLexeme);
		break;
	case STR_T:
		printf("%s\n", bufGetContent(stringLiteralTable, t.attribute.contentString));
		break;
	case KW_T:
		printf("%s\n", keywordTable[t.attribute.codeType]);
		break;
	case LPR_T:
	case RPR_T:
	case LBR_T:
	case RBR_T:
	/*case COM_T:*/
	case EOS_T:
		printf("NA\n");
		break;
	default:
		printf("%s%s%d\n", STR_LANGNAME, ": Scanner error: invalid token code: ", t.code);
	}
}

/*************************************************************
 * Program statement
 * BNF: <program> -> MAIN { <opt_statements> }
 * FIRST(<program>)= { MNID_T }.
 ************************************************************/
/* TO_DO: Adjust this function to respect your grammar */

monaco_nul program() {
	switch (lookahead.code) {
	case MNID_T:
		if (strncmp(lookahead.attribute.idLexeme, "MAIN&", 5) == 0) {
			matchToken(MNID_T, NO_ATTR);
			matchToken(LBR_T, NO_ATTR);
			dataSession();
			codeSession();
			matchToken(RBR_T, NO_ATTR);
			break;
		}
		else {
			printError();
		}
	case SEOF_T:
		; // Empty
		break;
	default:
		printError();
	}
	printf("%s%s\n", STR_LANGNAME, ": Program parsed");
}


/*************************************************************
 * dataSession
 * BNF: <dataSession> -> DATA { <opt_varlist_declarations> }
 * FIRST(<program>)= {KW_T (DATA)}.
 ************************************************************/


monaco_nul dataSession() {
	matchToken(KW_T, DATA);
	matchToken(LBR_T, NO_ATTR);
	optVarListDeclarations();
	matchToken(RBR_T, NO_ATTR);
	printf("%s%s\n", STR_LANGNAME, ": Data Session parsed");
}

/*************************************************************
 * Optional Var List Declarations
 * BNF: <opt_varlist_declarations> -> <varlist_declarations> | e
 * FIRST(<opt_varlist_declarations>) = { e, KW_T (FLOAT) }.
 ************************************************************/


monaco_nul optVarListDeclarations() {
	switch (lookahead.code) {
	default:
		; // Empty
	}
	printf("%s%s\n", STR_LANGNAME, ": Optional Variable List Declarations parsed");
}

/*************************************************************
 * codeSession statement
 * BNF: <codeSession> -> CODE { <opt_statements> }
 * FIRST(<???>) = { ??? }.
 ************************************************************/


monaco_nul codeSession() {
	matchToken(KW_T, CODE);
	matchToken(LBR_T, NO_ATTR);
	optionalStatements();
	matchToken(RBR_T, NO_ATTR);
	printf("%s%s\n", STR_LANGNAME, ": Code Session parsed");
}

/*************************************************************
 * Optional statement
 * BNF: <opt_statements> -> <statements> | ϵ
 * FIRST(<???>) = { ??? }.
 ************************************************************/


monaco_nul optionalStatements() {
	switch (lookahead.code) {
	case MNID_T:
		if ((strncmp(lookahead.attribute.idLexeme, "WRITE&", 6) == 0)) {
			statements();
			break;
		}
	default:
		; // Empty
	}
	printf("%s%s\n", STR_LANGNAME, ": Optional statements parsed");
}

/*************************************************************
 * Statements
 * BNF: <statements> -> <statement><statementsPrime>
 * FIRST(<???>) = { ??? }.
 ************************************************************/


monaco_nul statements() {
	statement();
	statementsPrime();
	printf("%s%s\n", STR_LANGNAME, ": Statements parsed");
}

/*************************************************************
 * Statements Prime
 * BNF: <statementsPrime>  <statement><statementsPrime> | ϵ
 * FIRST(<???>) = { ??? }.
 ************************************************************/


monaco_nul statementsPrime() {
	switch (lookahead.code) {
	case MNID_T:
		if ((strncmp(lookahead.attribute.idLexeme, "WRITE&", 6) == 0)) {
			statements();
			break;
		}
	default:
		; //empty string
	}
}

/*************************************************************
 * Single statement
 * BNF: <statement> ->  <assignment statement> | <input statement> | <output statement>
 * FIRST(<???>) = { ??? }.
 ************************************************************/


monaco_nul statement() {
	switch (lookahead.code) {
	case KW_T:
		switch (lookahead.attribute.codeType) {
		default:
			printError();
		}
		break;
	case MNID_T:
		if (strncmp(lookahead.attribute.idLexeme, "WRITE&", 6) == 0) {
			outputStatement();
		}
		break;
	default:
		printError();
	}
	printf("%s%s\n", STR_LANGNAME, ": Statement parsed");
}

/*************************************************************
 * Output Statement
 * BNF: <output statement> -> WRITE (<output statementPrime>);
 * FIRST(<???>) = { ??? }.
 ************************************************************/


monaco_nul outputStatement() {
	matchToken(MNID_T, NO_ATTR);
	matchToken(LPR_T, NO_ATTR);
	outputVariableList();
	matchToken(RPR_T, NO_ATTR);
	matchToken(EOS_T, NO_ATTR);
	printf("%s%s\n", STR_LANGNAME, ": Output statement parsed");
}

/*************************************************************
 * Output Variable List
 * BNF: <opt_variable list> -> <variable list> | ϵ
 * FIRST(<???>) = { ??? }.
 ************************************************************/


monaco_nul outputVariableList() {
	switch (lookahead.code) {
	case STR_T:
		matchToken(STR_T, NO_ATTR);
		break;
	default:
		;
	}
	printf("%s%s\n", STR_LANGNAME, ": Output variable list parsed");
}

/* TO_DO: Continue the development (all non-terminal functions) */

