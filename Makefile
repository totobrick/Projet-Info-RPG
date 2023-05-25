EXECUTABLE=app.out

.DEFAULT_GOAL:=$(EXECUTABLE)

#SRCS:=$(wildcard *.c)
SRCS:=Brouillon_affichage.c

clean:
	@rm -f *.o
	@rm -f *.h.gch
	@rm -f $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	@echo "Building application..."
	@gcc $(SRCS) -o $(EXECUTABLE) -Wall -Werror

run: $(EXECUTABLE)
	@echo "Running application..."
	@./$(EXECUTABLE)



//ce que j'en ai compris
/*CC= gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: exec

Affichage.o: Affichage.c Header.h
    $(CC) -c $< -o $@

Board_card.o: Board_card.c Header.h
    $(CC) -c $< -o $@

Combat.o: Combat.c Header.h
    $(CC) -c $< -o $@
    
Brouillon_curses.o: Brouillon_curses.c Header.h
    $(CC) -c $< -o $@
    
    Deplacement.o: Deplacement.c Header.h
    $(CC) -c $< -o $@
    
    Déroulement_joueur.o: Déroulement_joueur.c Header.h
    $(CC) -c $< -o $@
    
    Event.o: Event.c Header.h
    $(CC) -c $< -o $@
    
    Graphisme.o: Graphisme.c Header.h
    $(CC) -c $< -o $@
    
    Main.o: Main.c Header.h
    $(CC) -c $< -o $@
    
    Main_toto.o: Main_toto.c Header.h
    $(CC) -c $< -o $@
    
    Portal+Totem.o: Portal+Totem.c Header.h
    $(CC) -c $< -o $@
    
    Score.o: Score.c Header.h
    $(CC) -c $< -o $@
    
    Structures_player.o: Structures_player.c Header.h
    $(CC) -c $< -o $@
    
    Victory_condition.o: Victory_condition.c Header.h
    $(CC) -c $< -o $@
    
exec: $(OBJ)
$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS) je ne sais pas si cest pas spécifique à ncurses du coup
  
  %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
    clean:
	rm -f $(OBJS) $(EXECUTABLE)*/
	
	
	
	//correction de chatGPT
	/*CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXECUTABLE = exec

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c Header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)
*/
