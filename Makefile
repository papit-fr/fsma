all: exec shared

exec:
	cc -O3 fsma.c -o fsma
	cc -O3 sma.c -o sma

shared:
	cc -O3 -shared -fPIC fsma.c -o libfsma.so
	cc -O3 -shared -fPIC sma.c -o libsma.so