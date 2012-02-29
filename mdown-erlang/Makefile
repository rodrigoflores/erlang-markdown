CFLAGS=-g -O3 -fPIC -Wall -Werror -Wsign-compare
CC=gcc

FILES=autolink.c buffer.c houdini_href_e.c houdini_html_e.c html.c markdown.c markdown_nif.c stack.c

markdown.so: $(OBJECTS)
	gcc -o $@ -fpic -undefined dynamic_lookup -I/usr/local/Cellar/erlang/R15B/lib/erlang/erts-5.9/include -dynamiclib $(FILES) 

clean:
	rm markdown.so
#%.o: %.c
#	gcc $(CFLAGS) -c $^ -o $@

