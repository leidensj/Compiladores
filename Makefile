etapa1: hash.o lex.yy.o main.o
	gcc hash.o lex.yy.o main.o -o etapa1
hash.o: hash.c
	gcc -c hash.c
main.o: main.c
	gcc -c main.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c
lex.yy.c: scanner.l
	lex scanner.l
clean:
	rm *.o etapa1 lex.yy.c