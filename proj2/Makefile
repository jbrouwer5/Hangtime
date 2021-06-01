play: pos.h pos.c board.h board.c logic.h logic.c play.c
	clang -Wall -g -O0 -lm -o play pos.c board.c logic.c play.c

evidence: pos.h pos.c board.h board.c logic.h logic.c evidence.c
	clang -Wall -g -O0 -lm -o evidence pos.c board.c logic.c evidence.c

evidencebits: pos.h pos.c board.h board.c logic.h logic.c evidencebits.c
	clang -Wall -g -O0 -lm -o evidencebits pos.c board.c logic.c evidencebits.c
	
clean:
	rm -rf evidence play *.o *~ *dSYM