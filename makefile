makefile_path=$(abspath $(lastword $(MAKEFILE_LIST)))
PATH_CDS=$(patsubst %/,%,$(dir $(makefile_path)))
add_lib=-L$(PATH_CDS)/lib
link_table=-ltable
link_md5=-lmd5
find_code=-I $(PATH_CDS)/code/

all: table cds cygnus-db encrypt iot

table: $(PATH_CDS)/code/core/table.cpp
	g++ -c $(PATH_CDS)/code/core/table.cpp -o $(PATH_CDS)/lib/libtable.o -std=c++17
	ar rcs $(PATH_CDS)/lib/libtable.a $(PATH_CDS)/lib/libtable.o
md5: $(PATH_CDS)/code/core/md5.c
	gcc -c $(PATH_CDS)/code/core/md5.c -o $(PATH_CDS)/lib/libmd5.o -std=c11
	ar rcs $(PATH_CDS)/lib/libmd5.a $(PATH_CDS)/lib/libmd5.o

cds: $(PATH_CDS)/code/main.cpp
	g++ $(PATH_CDS)/code/main.cpp -o bin/cds $(add_lib) $(link_table) -std=c++17
cygnus-db: $(PATH_CDS)/code/main.cpp
	g++ $(PATH_CDS)/code/cygnus-db.cpp -o bin/cygnus-db $(add_lib) $(link_table) -std=c++17
iot: table $(PATH_CDS)/code/test/io_test.cpp
	g++ $(PATH_CDS)/code/test/io_test.cpp -o bin/iot $(add_lib) $(link_table) $(find_code) -std=c++17
encrypt: $(PATH_CDS)/code/encrypt.c md5
	gcc $(PATH_CDS)/code/encrypt.c -o bin/encrypt $(add_lib) $(link_md5) -std=c11

init:
	mkdir lib bin

clean:
	rm -f bin/* lib/*
