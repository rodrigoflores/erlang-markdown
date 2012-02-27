CFLAGS=-c -g -O3 -fPIC -Wall -Werror -Wsign-compare -Isrc -Ihtml
LDFLAGS=-g -O3 -Wall -Werror 
CC=gcc

default:
	gcc -o sum_nif.so -fpic -undefined dynamic_lookup -I/usr/local/Cellar/erlang/R15B/lib/erlang/erts-5.9/include -dynamiclib sum.c sum_nif.c

