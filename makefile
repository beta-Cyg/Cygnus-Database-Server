makefile_path=$(abspath $(lastword $(MAKEFILE_LIST)))
PATH_CDS=$(patsubst %/,%,$(dir $(makefile_path)))
add_lib=-L$(PATH_CDS)/lib
link_table=-ltable
find_core=-I $(PATH_CDS)/code/core
find_code=-I $(PATH_CDS)

all: clean table cds cygnus-db md5

table: $(PATH_CDS)/code/core/table.cpp
	g++ -c $(PATH_CDS)/code/core/table.cpp -o $(PATH_CDS)/lib/libtable.o -std=c++17
	ar rcs $(PATH_CDS)/lib/libtable.a $(PATH_CDS)/lib/libtable.o
cds: $(PATH_CDS)/code/main.cpp
	g++ $(PATH_CDS)/code/main.cpp -o bin/cds $(add_lib) $(link_table) $(find_core) $(find_code) -std=c++17
cygnus-db: $(PATH_CDS)/code/main.cpp
	g++ $(PATH_CDS)/code/cygnus-db.cpp -o bin/cygnus-db $(add_lib) $(link_table) $(find_core) $(find_code) -std=c++17

md5: $(PATH_CDS)/code/core/md5.c
	gcc $(PATH_CDS)/code/core/md5.c -o bin/md5 -I $(PATH_CDS) -std=c11
clean:
	rm bin/*.exe
	rm lib/*.o
	rm lib/*.a
