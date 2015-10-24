CXX=clang
BIN=intlex

all: lex
	$(CXX) main.c lex.yy.c -o $(BIN) -ll

lex:
	flex lex.l

clean:
	rm lex.yy.c
	rm $(BIN)
