CC=gcc
CFLAGS=-Wall -g
LDFLAGS=
LEX=flex
BISON=bison
BFLAGS=--report=solved --defines

test_object: object.o

test_scanner: scanner.o

test_parser: scanner.o parser.o expr.o var.o freevar.o func.o never.o symtab.o typecheck.o gencode.o utils.o bytecode.o

test_symtab: symtab.o var.o freevar.o func.o expr.o

test_freevar: symtab.o var.o freevar.o func.o expr.o

gc: gc.o object.o scanner.o

%.c : %.y
	${BISON} ${BFLAGS} -o $@ $<

test_parser.o: test_parser.c parser.y expr.h var.h func.h never.h

expr.o: expr.c expr.h
var.o: var.c var.h
freevars.o: freevars.c freevars.h
func.o: func.c func.h
symtab.o: symtab.c symtab.h
typecheck.o: typecheck.c typecheck.h symtab.h expr.h var.h func.h
utils.o: utils.c utils.h
gencode.o: gencode.c gencode.h
bytecode.o: bytecode.c bytecode.h


