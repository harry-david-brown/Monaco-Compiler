
output: Compiler.o MainBuffer.o Buffer.o MainScanner.o Scanner.o MainParser.o Parser.o
	gcc Compiler.o MainBuffer.o Buffer.o MainScanner.o Scanner.o MainParser.o Parser.o -o output

Compiler.o: Compiler.c Compiler.h
	gcc -c Compiler.c

MainBuffer.o: MainBuffer.c Compiler.h Buffer.h
	gcc -c MainBuffer.c

Buffer.o: Buffer.c Compiler.h Buffer.h
	gcc -c Buffer.c

MainScanner.o: MainScanner.c Compiler.h Buffer.h Scanner.h
	gcc -c MainScanner.c

Scanner.o: Scanner.c Compiler.h Buffer.h Scanner.h
	gcc -c Scanner.c

MainParser.o: MainParser.c Compiler.h Buffer.h Scanner.h Parser.h
	gcc -c MainBuffer.c

Parser.o: Parser.c Compiler.h Parser.h
	gcc -c Parser.c

clean:
	rm *.o *.pdb

