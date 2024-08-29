index:
		gcc ponto.c -c -g
		gcc main.c ponto.o -o exec
clear:
		rm *.o
		rm exec
