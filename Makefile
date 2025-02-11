# compiles and links everything all at once. Error occurs with Py_Array_API once fixes will improve build separation of files here

PYTHON_CONFIG = python3.12-config
NUMPY_INCLUDE = $(shell python3 -c "import numpy; print(numpy.get_include())")

CFLAGS = -Wall -shared -fPIC -I$(NUMPY_INCLUDE) $(shell $(PYTHON_CONFIG) --includes)
LDFLAGS = $(shell $(PYTHON_CONFIG) --ldflags)

TARGET = jmod.so
#SRC = jmod.c
SRC = jmod.c jbit.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) *.o

