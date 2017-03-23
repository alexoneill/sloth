#  Makefile
#  aoneill - 01/22/16

CXX = gcc
CXXFLAGS = -Wall -fPIC -DPIC

LIBS = -lX11 -lXext

# Top level
SRC = src
OBJ = obj

################################################################################

EXEC_NAME = sloth

################################################################################

SUPPORT_C = $(shell cd $(SRC)/ && find * -name "*.c" -type f)
SUPPORT_O = $(addprefix $(OBJ)/,$(SUPPORT_C:%.c=%.o))

all: CXXFLAGS += -Ofast
all: init $(LIB_NAME) $(EXEC_NAME)
debug: CXXFLAGS += -DDEBUG -g -pg
debug: init $(LIB_NAME) $(EXEC_NAME)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p "$(dir $@)"
	$(CXX) $(CXXFLAGS) -c $^ -o $@

################################################################################

$(EXEC_NAME): $(SUPPORT_O) main.c 
	$(CXX) $(CXXFLAGS) $(LIBS) $^ -o $@

################################################################################

init:
	mkdir -p "$(OBJ)"

clean:
	rm -rf ./$(OBJ)/
	rm -rf $(EXEC_NAME) gmon.out
