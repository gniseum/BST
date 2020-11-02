CPPFLAGS += -Wall -Wextra -Wpedantic

CFLAGS += -std=c11

ARFLAGS += -U

BINS = bstTest

LIBS = bst.a

CC = gcc

all: $(BINS)

lib: $(LIBS)

bstTest: SRC/bstTest.o bst.a
	gcc SRC/bstTest.o bst.a -o bstTest
	$(RM) SRC/bstTest.o

bst.a: bst.a(SRC/bst.o)

debug: CFLAGS += -g
debug: all

profile: CFLAGS += -pg
profile: all

.PHONY: clean all

clean:
	$(RM) *.o *.a $(BINS) $(FILES)
	$(RM) -rf $(DIRS)
