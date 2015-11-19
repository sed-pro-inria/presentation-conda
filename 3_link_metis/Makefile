CC=gcc

CFLAGS = -I$(CONDA_ENV_PATH)/include
LIBDIR = $(CONDA_ENV_PATH)/lib
LDFLAGS = -L$(LIBDIR) -Wl,-rpath,$(LIBDIR) -lmetis

main: main.o
	$(CC) -o $@ $< $(LDFLAGS)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f main.o main
