makefile_path=$(abspath $(lastword $(MAKEFILE_LIST)))
PATH_CDS=$(patsubst %/,%,$(dir $(makefile_path)))

all: cds cygnus-db

cds: $(PATH_CDS)/code/main.cpp
	g++ $(PATH_CDS)/code/main.cpp -o cds -I $(PATH_CDS) -std=c++17
cygnus-db: $(PATH_CDS)/code/main.cpp
	g++ $(PATH_CDS)/code/cygnus-db.cpp -o cygnus-db -I $(PATH_CDS) -std=c++17
clean:
	rm *.o

