project : main.o complex.o stat.o myqueue.o eval.o getnext.o infix.o
	cc main.o complex.o stat.o myqueue.o eval.o getnext.o infix.o interest.o -lm -o project	
main.o : main.c
	cc main.c -c -lm
complex.o : complex.c
	cc complex.c -c -lm
stat.o : stat.c
	cc stat.c -c -lm
myqueue.o: myqueue.h myqueue.c
	cc myqueue.c -c 
eval.o : eval.c myqueue.h myqueue.c
	cc eval.c -c
	cc myqueue.c -c
getnext.o:getnext.c myqueue.h myqueue.c
	cc getnext.c -c
	cc myqueue.c -c
infix.o:getnext.c myqueue.h myqueue.c eval.c infix.c
	cc getnext.c -c
	cc myqueue.c -c
	cc eval.c -c
	cc infix.c -c
interest.o :interest.c
	cc interest.c -c -lm
