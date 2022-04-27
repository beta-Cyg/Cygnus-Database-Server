makefile_path=$(abspath $(lastword $(MAKEFILE_LIST)))
PATH_CDS=$(patsubst %/,%,$(dir $(makefile_path)))
add_lib=-L$(PATH_CDS)/lib
link_table=-ltable
link_md5=-lmd5
find_code=-I $(PATH_CDS)/include/

all: init table cds cygnus-db encrypt iot

table: include/core/table.cpp include/core/table.h
	g++ -c include/core/table.cpp -o lib/libtable.o -std=c++17
	ar rcs lib/libtable.a lib/libtable.o
	rm lib/libtable.o
	g++ -fPIC -shared -c include/core/table.cpp -o lib/libtable.dll -std=c++17

md5: include/core/md5.c
	gcc -c include/core/md5.c -o lib/libmd5.o -std=c11
	ar rcs lib/libmd5.a lib/libmd5.o
	rm lib/libmd5.o
	gcc -fPIC -shared -c include/core/md5.c -o lib/libmd5.dll -std=c11

cds: include/main.cpp table
	g++ include/main.cpp -o bin/cds $(add_lib) $(link_table) -std=c++17

cygnus-db: include/cygnus-db.cpp table
	g++ include/cygnus-db.cpp -o bin/cygnus-db $(add_lib) $(link_table) -std=c++17

iot: table include/test/io_test.cpp
	g++ include/test/io_test.cpp -o bin/iot $(add_lib) $(link_table) $(find_code) -std=c++17

encrypt: include/encrypt.c md5
	gcc include/encrypt.c -o bin/encrypt $(add_lib) $(link_md5) -std=c11

init:
	mkdir -p bin lib

clean:
	rm -rf bin lib
