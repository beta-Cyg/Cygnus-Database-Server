makefile_path=$(abspath $(lastword $(MAKEFILE_LIST)))
PATH_CDS=$(patsubst %/,%,$(dir $(makefile_path)))
add_lib=-L$(PATH_CDS)/lib
link_table=-ltable
link_md5=-lmd5
find_code=-I $(PATH_CDS)/include/

all: clean init table cds cygnus-db encrypt iot

table: $(PATH_CDS)/include/core/table.cpp
	g++ -c $(PATH_CDS)/include/core/table.cpp -o $(PATH_CDS)/lib/libtable.o -std=c++17
	ar rcs $(PATH_CDS)/lib/libtable.a $(PATH_CDS)/lib/libtable.o
	rm $(PATH_CDS)/lib/libtable.o
	g++ -fPIC -shared -c $(PATH_CDS)/include/core/table.cpp -o $(PATH_CDS)/lib/libtable.dll -std=c++17

md5: $(PATH_CDS)/include/core/md5.c
	gcc -c $(PATH_CDS)/include/core/md5.c -o $(PATH_CDS)/lib/libmd5.o -std=c11
	ar rcs $(PATH_CDS)/lib/libmd5.a $(PATH_CDS)/lib/libmd5.o
	rm $(PATH_CDS)/lib/libmd5.o
	gcc -fPIC -shared -c $(PATH_CDS)/include/core/md5.c -o $(PATH_CDS)/lib/libmd5.dll -std=c11

cds: $(PATH_CDS)/include/main.cpp table
	g++ $(PATH_CDS)/include/main.cpp -o bin/cds $(add_lib) $(link_table) -std=c++17

cygnus-db: $(PATH_CDS)/include/cygnus-db.cpp table
	g++ $(PATH_CDS)/include/cygnus-db.cpp -o bin/cygnus-db $(add_lib) $(link_table) -std=c++17

iot: table $(PATH_CDS)/include/test/io_test.cpp
	g++ $(PATH_CDS)/include/test/io_test.cpp -o bin/iot $(add_lib) $(link_table) $(find_code) -std=c++17

encrypt: $(PATH_CDS)/include/encrypt.c md5
	gcc $(PATH_CDS)/include/encrypt.c -o bin/encrypt $(add_lib) $(link_md5) -std=c11

init:
	mkdir -p bin lib

clean:
	rm -rf $(PATH_CDS)/bin $(PATH_CDS)/lib
