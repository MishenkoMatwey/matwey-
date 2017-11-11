menu: menu.o index_first_zero.o index_last_zero.o sum_before_and_after.o sum_between.o
	gcc menu.o index_first_zero.o index_last_zero.o sum_before_and_after.o sum_between.o -o menu
menu.o: menu.c index_first_zero.h index_last_zero.h sum_before_and_after.h sum_between.h
	gcc -c menu.c
index_first_zero.o: index_first_zero.h index_first_zero.c
	gcc -c index_first_zero.c
index_last_zero.o: index_last_zero.h index_last_zero.c
	gcc -c index_last_zero.c
sum_before_and_after.o: sum_before_and_after.c sum_before_and_after.h 
	gcc -c  sum_before_and_after.c 
sum_between.o: sum_between.h sum_between.c  
	gcc -c sum_between.c
clear:
	rm -rf *.o
