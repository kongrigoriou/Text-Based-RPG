#
# In order to execute this "Makefile" just type "make"
#
#

OBJS     = main.o Heroes.o Monsters.o Market.o Grid.o Spells.o Items.o Squad.o
SOURCE    = src/main.cpp src/Heroes.cpp src/Monsters.cpp src/Market.cpp src/Grid.cpp src/Spells.cpp src/Items.cpp src/Squad.cpp
HEADER  = include/Heroes.h include/Monsters.h include/Market.h include/Grid.h include/Spells.h include/Items.h
OUT      = project
CC    = g++
FLAGS   = -g -c 
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

# create/compile the individual files >>separately<< 
Monsters.o: src/Monsters.cpp
	$(CC) $(FLAGS) src/Monsters.cpp

Heroes.o: src/Heroes.cpp
	$(CC) $(FLAGS) src/Heroes.cpp

Items.o: src/Items.cpp
	$(CC) $(FLAGS) src/Items.cpp

Spells.o: src/Spells.cpp
	$(CC) $(FLAGS) src/Spells.cpp

Market.o: src/Market.cpp
	$(CC) $(FLAGS) src/Market.cpp

Grid.o: src/Grid.cpp
	$(CC) $(FLAGS) src/Grid.cpp

Squad.o: src/Squad.cpp
	$(CC) $(FLAGS) src/Squad.cpp

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp

# clean house
clean:
	rm -f $(OBJS) $(OUT)

# do a bit of accounting
count:
	wc $(SOURCE) $(HEADER)

run:
	./project