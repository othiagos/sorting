NAME = sorting
CC = g++
SRC_DIR = ./src
INC_DIR = ./include
BIN_DIR = ./bin
BUILD_DIR = ./build
CFLAGS = --std=c++20 -O3 -Wall
EXE = $(BIN_DIR)/$(NAME)

OBJS = \
	$(BUILD_DIR)/main.o

all: mkdir $(EXE)

# $(EXE) command vector_size seed
run: all
	$(EXE) B 10 45
	$(EXE) H 10 45
	$(EXE) I 10 45
	$(EXE) M 10 45
	$(EXE) Q 10 45
	$(EXE) S 10 45

mkdir:
	mkdir -p $(BIN_DIR)
	mkdir -p $(BUILD_DIR)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $(EXE)

$(BUILD_DIR)/%.o: $(SRC_DIR)/**/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INC_DIR) -o $@

clean:
	rm -f $(OBJS)
	rm -f $(EXE)