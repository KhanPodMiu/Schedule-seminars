CXX         := g++
CXX_FLAGS   := -Wall -Wextra -ggdb -MMD -MP

BIN         := bin
SRC         := src
LIB         := lib
INCLUDE     := include

EXECUTABLE  := main

SRC_EXT     := cpp
OBJ_EXT     := o
DEP_EXT     := d

# 🔥 Get all source files from src/ and lib/
SOURCES := $(wildcard $(SRC)/*.$(SRC_EXT)) \
           $(wildcard $(LIB)/*.$(SRC_EXT))

# 🔥 Convert to object files in bin/
OBJECTS := $(patsubst %.$(SRC_EXT),$(BIN)/%.$(OBJ_EXT),$(notdir $(SOURCES)))

DEPS := $(OBJECTS:.$(OBJ_EXT)=.$(DEP_EXT))

.PHONY: all clean run

# ===== BUILD =====
all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

# ===== COMPILE src =====
$(BIN)/%.$(OBJ_EXT): $(SRC)/%.$(SRC_EXT)
	@mkdir -p $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -c $< -o $@

# ===== COMPILE lib =====
$(BIN)/%.$(OBJ_EXT): $(LIB)/%.$(SRC_EXT)
	@mkdir -p $(BIN)
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -c $< -o $@

# ===== RUN =====
run: all
	./$(BIN)/$(EXECUTABLE)

# ===== CLEAN =====
clean:
	rm -rf $(BIN)

# ===== AUTO DEPENDENCIES =====
-include $(DEPS)