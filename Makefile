# Choose your compiler
CC:=$(shell which clang || echo cc)

# Print the compiler found
$(info Using $(CC) as the compiler)

# Options
all: exec shared prof chrono

# The CLI executables
$(info Compiling the CLI executables)
exec:
	$(CC) -O3 utils.c fsma.c fsma-cli.c -o fsma-cli
	$(CC) -O3 utils.c sma.c sma-cli.c -o sma-cli

# The shared libraries, for Python and other CLIs of the project
$(info Compiling the shared libraries, for Python and other CLIs of the project)
shared:
	$(CC) -O3 -shared -fPIC fsma.c -o libfsma.so
	$(CC) -O3 -shared -fPIC sma.c -o libsma.so

# To profile executables to be used with Valgrind
$(info Compiling to profile executables to be used with Valgrind)
prof:
	$(CC) -pg utils.c fsma.c fsma-cli.c -o fsma-prof
	$(CC) -pg utils.c sma.c sma-cli.c -o sma-prof

# To measure the execution time of the algorithms
$(info Compiling to measure the execution time of the algorithms)
chrono:
	$(CC) utils.c sma.c sma-chrono.c -O3 -o sma-chrono
	$(CC) utils.c fsma.c fsma-chrono.c -O3 -o fsma-chrono