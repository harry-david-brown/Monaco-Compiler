/*
************************************************************
* COMPILERS COURSE - Algonquin College
* Code version: Summer, 2022
* Author: Harry Brown
* Professors: Paulo Sousa
************************************************************
*/

/*
***********************************************************
* File name: buffer.c
* Compiler: gcc
* Purpose: Defines the data and functions of a buffer
* Function list:
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
#include <stdlib.h>
#include "Buffer.h"
#endif

/*
***********************************************************
* Function name: bufCreate
* Purpose: Creates the buffer according to capacity, increment
	factor and operational mode ('f', 'a', 'm')
* Author: Svillen Ranev / Paulo Sousa
* History/Versions: S22
* Called functions: calloc(), malloc()
* Parameters:
*   size = initial capacity
*   increment = increment factor
*   mode = operational mode
* Return value: bPointer (pointer to Buffer)
* Algorithm: Allocation of memory according to inicial (default) values.
* TODO ...................................................... 
*	- Adjust datatypes for your LANGUAGE.
*   - Use defensive programming
*	- Check boundary conditions
*	- Check flags.
*************************************************************
*/

BufferPointer bufCreate(monaco_int size, monaco_int increment, monaco_int mode) {
	BufferPointer b;
	/* TODO: Defensive programming: check validity of parameters */
	if (!size) {
		size = BUFFER_DEFAULT_SIZE;
		increment = BUFFER_DEFAULT_INCREMENT;
	}
	/* TODO: When there is no increment, mode: fixed */
	b = (BufferPointer)calloc(1, sizeof(Buffer));
	/* TODO: Defensive programming */
	if (b) {
		b->content = (monaco_chr*)malloc(size);
		b->size = size;
        b->mode = mode;
        b->increment = increment;
	}
	/* TODO: Defensive programming */
	/* TODO: Update buffer properties (mode, increment, flags) */


	return b;
}


/*
***********************************************************
* Function name: bAddChar
* Purpose: Adds a char to buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   ch = char to be added
* Return value:
*	bPointer (pointer to Buffer)
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/

BufferPointer bufAddChar(BufferPointer const pBuffer, monaco_chr ch) {
	monaco_chr* tempbuf = NULL;
	monaco_int newSize = 0;
	/* TODO: Defensive programming */
	/* TODO: Reset Realocation */
	/* TODO: Check if it is possible to be increased */
	/* TODO: Check if buffer is full */
	
	


	if (pBuffer->position.posWrte * (monaco_int)sizeof(monaco_chr) >= pBuffer->size) {
		
		switch (pBuffer->mode) {
		case MODE_FIXED:
			return pBuffer;
		case MODE_ADDIT:
			
			newSize = pBuffer->size + pBuffer->increment;
			if(newSize < 0)
				return NULL;
			
			break;

		case MODE_MULTI:
			
			newSize = pBuffer->size * pBuffer->increment;
			if(newSize < 0)
				return NULL;
			
			break;

		default:
			return NULL;
		}
	}
	/* TODO: Realloc the size for new buffer */
	/* TODO: Check the realocation by Defensive programming */
	/* TODO: If allowed, adjust the new buffer content */
	

	if(newSize==0)
		newSize = pBuffer->size;
		
	
	tempbuf = realloc(pBuffer->content, newSize);


	pBuffer->content = tempbuf;
	pBuffer->size = newSize;

	if(pBuffer->position.posWrte < pBuffer->size){
		pBuffer->content[pBuffer->position.posWrte++] = ch;
	}
	
	
	
	return pBuffer;
}

/*
***********************************************************
* Function name: bClear
* Purpose: Clears the buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufClear(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Clear the buffer reseting all positions and flags */
	return monaco_TRUE;
}

/*
***********************************************************
* Function name: bDestroy
* Purpose: Releases the buffer address
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufDestroy(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Free the buffer (content and struct) */
	return monaco_TRUE;
}

/*
***********************************************************
* Function name: bIsFull
* Purpose: Checks if buffer is full
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufChkFull(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Check flag if buffer is FUL and return correct value */
	return monaco_TRUE;
}


/*
***********************************************************
* Function name: bIsEmpty
* Purpose: Checks if buffer is empty.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufChkEmpty(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Check if it is empty */
	return monaco_TRUE;
}


/*
***********************************************************
* Function name: bSetMark
* Purpose: Adjust the position of mark in the buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   mark = mark position for char
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufSetMark(BufferPointer const pBuffer, monaco_int mark) {
	
	pBuffer->position.posMark = mark;

	return monaco_TRUE;
}


/*
***********************************************************
* Function name: bPrint
* Purpose: Prints the string in the buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Number of chars printed.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufPrint(BufferPointer const pBuffer) {
	monaco_int cont = 0;
	monaco_chr c;
	/* TODO: Defensive programming */
	c = bufGetChar(pBuffer);

	/* TODO: Print all chars */
	while (cont < pBuffer->position.posWrte) {
		cont++;
		printf("%c", c);
		c = bufGetChar(pBuffer);
	}
	return cont;
}

/*
***********************************************************
* Function name: bLoad
* Purpose: Loads the string in the buffer with the content of
	an specific file.
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   fi = pointer to file descriptor
* Return value:
*	Number of chars read and put in buffer.
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufLoad(BufferPointer const pBuffer, FILE* const fi) {
	monaco_int size = 0;
	monaco_chr c;
	/* TODO: Defensive programming */
	c = (monaco_chr)fgetc(fi);
	while (!feof(fi)) {


		if (!bufAddChar(pBuffer, c)) {
			
			ungetc(c, fi);
			return BUFFER_ERROR;
		}
		c = (char)fgetc(fi);
		size++;
	}
	/* TODO: Defensive programming */
	return size;
}


/*
***********************************************************
* Function name: bRecover
* Purpose: Rewinds the buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufRecover(BufferPointer const pBuffer) {
	
	pBuffer->position.posRead = 0;
	pBuffer->position.posMark = 0;

	return monaco_TRUE;
}


/*
***********************************************************
* Function name: bRetract
* Purpose: Retracts the buffer to put back the char in buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufRetract(BufferPointer const pBuffer) {
	if(pBuffer->position.posRead <= 0){
		return monaco_FALSE;
	} 

	pBuffer->position.posRead -= 1;
	return monaco_TRUE;
}


/*
***********************************************************
* Function name: bRestore
* Purpose: Resets the buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Boolean value about operation success
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_bol bufRestore(BufferPointer const pBuffer) {
	
	pBuffer->position.posRead = pBuffer->position.posMark;
	return monaco_TRUE;
	
}

/*
***********************************************************
* Function name: bGetChar
* Purpose: Returns the char in the getC position.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Char in the getC position.
* TODO ......................................................
*   - Use defensive programming
*	- Check boundary conditions
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_chr bufGetChar(BufferPointer const pBuffer) {
	/* TODO: Defensive programming */
	/* TODO: Adjust EOB if necessary */
	return pBuffer->content[pBuffer->position.posRead++];
}


/*
***********************************************************
* Function name: bGetContent
* Purpose: Returns the pointer to String.
* Parameters:
*   pBuffer = pointer to Buffer Entity
*   pos = position to get the pointer
* Return value:
*	Position of string char.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_chr* bufGetContent(BufferPointer const pBuffer, monaco_int pos) {
	return pBuffer->content;
}


/*
***********************************************************
* Function name: bGetReadPos
* Purpose: Returns the value of getCPosition.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	The readPos offset.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufGetPosRead(BufferPointer const pBuffer) {
	return pBuffer->position.posRead;
}


/*
***********************************************************
* Function name: bGetWritePos
* Purpose: Returns the position of char to be added
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	addcPosition value
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufGetPosWrte(BufferPointer const pBuffer) {
	return pBuffer->position.posWrte;
}


/*
***********************************************************
* Function name: bGetMarkPos
* Purpose: Returns the position of mark in the buffer
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	mark offset.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufGetPosMark(BufferPointer const pBuffer) {
	return 0;
}

/*
***********************************************************
* Function name: bGetSize
* Purpose: Returns the current buffer capacity
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Size of buffer.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufGetSize(BufferPointer const pBuffer) {
	return sizeof(pBuffer->size);
}


/*
***********************************************************
* Function name: bGetIncrement
* Purpose: Returns the buffer increment.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	The Buffer increment.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufGetInc(BufferPointer const pBuffer) {
	return pBuffer->increment;
}


/*
***********************************************************
* Function name: bGetMode
* Purpose: Returns the operational mode
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	operational mode.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_int bufGetMode(BufferPointer const pBuffer) {
	return pBuffer->mode;
}


/*
***********************************************************
* Function name: bGetFlags
* Purpose: Returns the entire flags of Buffer.
* Parameters:
*   pBuffer = pointer to Buffer Entity
* Return value:
*	Flags from Buffer.
* TODO ......................................................
*   - Use defensive programming
*	- Adjust for your LANGUAGE.
*************************************************************
*/
monaco_flg bufGetFlags(BufferPointer const pBuffer) {
	return pBuffer->flags;
}

