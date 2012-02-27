CC=gcc
CFLAGS=-g -O3 -fPIC -Wall -Werror -Wsign-compare

markdown: markdown-main.o buffer.o stack.o markdown.o autolink.o html.o houdini_html_e.o houdini_href_e.o
	$(CC) $(CFLAGS) $^ -o markdown

autolink.o: autolink.c
	$(CC) $(CFLAGS) -c autolink.c -o autolink.o 

buffer.o: buffer.c
	$(CC) $(CFLAGS) -c buffer.c -o buffer.o 

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c -o stack.o 

markdown.o: markdown.c
	$(CC) $(CFLAGS) -c markdown.c -o markdown.o 

html.o: html.c
	$(CC) $(CFLAGS) -c html.c -o html.o 

markdown-main.o: markdown-main.c
	$(CC) $(CFLAGS) -c markdown-main.c -o markdown-main.o

houdini_href_e.o: houdini_href_e.c
	$(CC) $(CFLAGS) -c houdini_href_e.c -o houdini_href_e.o

houdini_html_e.o: houdini_html_e.c
	$(CC) $(CFLAGS) -c houdini_html_e.c -o houdini_html_e.o

clean:
	rm -rf *.o markdown
