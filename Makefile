
SRC_DIR = examples
TEST_SRC = $(wildcard tests/*.cpp)
LDFLAGS += 
CXXFLAGS += -std=c++11 -Iinclude -fPIC

color_red=$(shell echo "\033[0;31m")
color_green=$(shell echo "\033[0;32m")
color_blue=$(shell echo "\033[0;34m")
color_default=$(shell echo "\033[0;0m")

ifeq (${debug}, yes)
$(info $(color_blue))
$(info *** Debug Version ***)
$(info $(color_default))
CXXFLAGS += -DDEBUG -g -O0
endif

define print_info_msg
$(info [INFO]: ${1})
endef

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
TESTS_DIR = $(BUILD_DIR)/tests
LIB_DIR = $(BUILD_DIR)/lib
BIN_DIR = $(BUILD_DIR)/bin
EXAMPELS_DIR = $(BUILD_DIR)/examples

MODULES := $(notdir $(wildcard $(SRC_DIR)/*.cpp))
OBJECTS := $(MODULES:.cpp=.o)

.PHONY: all
all: examples unit_tests

%.o: $(SRC_DIR)/%.cpp
	$(call print_info_msg, Building source file: $<)
	@$(CXX) $(CXXFLAGS) -Iinclude $(LDFLAGS) -o $(EXAMPELS_DIR)/$(basename $@) $<

.PHONY: examples
examples: make_dirs $(OBJECTS)

#Tests
.PHONY: unit_tests
unit_tests: make_dirs
	$(call print_info_msg, Building unit tests)
	@$(CXX) $(TEST_SRC) $ $(CXXFLAGS) $(LDFLAGS) -lgtest -lgtest_main -lpthread -o $(TESTS_DIR)/$@

.PHONY: run_tests
run_tests: unit_tests
	clear
	@./$(TESTS_DIR)/$<


#prepare all directories for build artifacts
make_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(TESTS_DIR)
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(EXAMPELS_DIR)

.PHONY: clean
clean:
	$(call print_info_msg, Cleaning)
	@rm -fr $(BUILD_DIR)

.PHONY: memcheck
memcheck:
	valgrind --tool=memcheck --leak-check=full build/examples/example_1

.PHONY: run_example_1
run_example_1: examples
	@clear
	./build/examples/example_1

.PHONY: run_example_2
run_example_2: examples
	@clear
	./build/examples/example_2