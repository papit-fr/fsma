all: exec shared prof

exec:
	cc -O3 fsma.c -o fsma
	cc -O3 sma.c -o sma

shared:
	cc -O3 -shared -fPIC fsma.c -o libfsma.so
	cc -O3 -shared -fPIC sma.c -o libsma.so

prof:
	cc -pg fsma.c -o fsma-prof
	cc -pg sma.c -o sma-prof