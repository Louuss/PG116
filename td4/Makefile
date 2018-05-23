SET_DIR=set
SEN_DIR=sentinel
DYN_DIR=dynamic
LNK_DIR=link

BIN=sentinel_func

CC=gcc
CPPFLAGS=-I ${SET_DIR} -I ${SEN_DIR} -I ${DYN_DIR} -I ${LNK_DIR}
CFLAGS=-Wall -Wextra -std=c99

all: test

build: ${BIN}

test: ${BIN}
	@for e in ${BIN}; do \
	echo $${e}; ./$${e}; \
	done

clean:
	rm -f *.o ${BIN}

#set
test_set_func.o : ${SET_DIR}/test_set_func.c ${SET_DIR}/set.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${SET_DIR}/test_set_func.c -c

#sentinel
set_sentinel.o: 
	${CC} ${CPPFLAGS} ${CFLAGS} ${SEN_DIR}/set_sentinel.c -c

sentinel_func: test_set_func.o set_sentinel.o
	${CC} test_set_func.o set_sentinel.o -o $@
