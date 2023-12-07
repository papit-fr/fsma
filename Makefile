all: exec shared prof chrono

exec:
	cc -O3 utils.c fsma.c fsma-cli.c -o fsma-cli
	cc -O3 utils.c sma.c sma-cli.c -o sma-cli

shared:
	cc -O3 -shared -fPIC fsma.c -o libfsma.so
	cc -O3 -shared -fPIC sma.c -o libsma.so

prof:
	cc -pg utils.c fsma.c fsma-cli.c -o fsma-prof
	cc -pg utils.c sma.c sma-cli.c -o sma-prof

chrono:
	cc utils.c sma.c sma-chrono.c -O3 -o sma-chrono
	cc utils.c fsma.c fsma-chrono.c -O3 -o fsma-chrono