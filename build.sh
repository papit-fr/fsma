# FSMA
clang -O3 -Wall -shared -fPIC fsma.c -o fsma.so
clang -O3 fsma.c -o fsma
# SMA
clang -O3 -Wall -shared -fPIC sma.c -o sma.so
clang -O3 sma.c -o sma