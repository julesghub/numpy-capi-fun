# compiles and links everything all at once. Error occurs with Py_Array_API once fixes will improve build separation of files here

PYTHON_CONFIG = python3.12-config
NUMPY_INCLUDE = $(shell python3 -c "import numpy; print(numpy.get_include())")

CC = gcc
CFLAGS = -Wall -fPIC -I$(NUMPY_INCLUDE) $(shell $(PYTHON_CONFIG) --includes)
LDFLAGS = $(shell $(PYTHON_CONFIG) --ldflags)

SOURCES = jmod.c jbit.c
#SOURCES = jmod.c
OBJECTS = $(SOURCES:.c=.o)
MODULE = jmod.so

all: $(MODULE)

$(MODULE): $(OBJECTS)
	$(CC) $(CFLAGS) -shared -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MODULE) *.o
