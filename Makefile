CC = g++
COMPFLAGS = -Wall -std=c++11
OBJ = main.o Automate.o state.o symbole.o lexer.o 


ifdef MAP
  COMPFLAGS += -DMAP 
endif


analog: $(OBJ)
	$(CC) -o $@ $(OBJ)

lexer.o: lexer.cpp
	$(CC) $(COMPFLAGS) -c $<	

symbole.o: symbole.cpp
	$(CC) $(COMPFLAGS) -c $<	

state.o: state.cpp
	$(CC) $(COMPFLAGS) -c $<

Automate.o: Automate.cpp
	$(CC) $(COMPFLAGS) -c $<

main.o: main.cpp
	$(CC) $(COMPFLAGS) -c $<

clean:
	rm *.o run.exe