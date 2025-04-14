.PHONY: all build install uninstall clean dvi dist tests gcov_report valgrind flags_gcov check_clang format_clang environment

CC						= gcc
CFLAGS					= -g -Wall -Werror -Wextra -std=c11
LDFLAGS					= $(shell pkg-config --cflags --libs check)
GCOV_FLAGS				=
GCOV_IGNOR				= --exclude '/usr/*' --exclude '/src/include/*' --exclude '/src/unit_tests/*'
VALGRIND_OPT			= --log-file="valgrind.log" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med
CLANG_OPT 				= -iname '*.c' -o -iname '*.h' -o -iname '*.cc' -o -iname '*.cpp'

SRC_CODE_DIR			= code
SRC_TEST_DIR			= tests
BUILD_DIR				= build
INSTALL_DIR				?= install
DIST_DIR				= dist
REPORT_DIR				= report
OBJ_CODE_DIR			= obj_code
OBJ_TEST_DIR			= obj_tests

TARGET_EXE				= 3DViewer_v1
TEST_EXE				= test.exe
SRC_CODE				:= $(wildcard $(SRC_CODE_DIR)/*.c)
SRC_TEST				:= $(wildcard $(SRC_TEST_DIR)/*.c)
OBJ_CODE				:= $(patsubst $(SRC_CODE_DIR)/%.c,$(OBJ_CODE_DIR)/%.o,$(SRC_CODE))
OBJ_TEST				:= $(patsubst $(SRC_TEST_DIR)/%.c,$(OBJ_TEST_DIR)/%.o,$(SRC_TEST))

all: install

build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cd $(BUILD_DIR) && $(MAKE)

install: clean build
	mkdir -p $(INSTALL_DIR)
	cp $(BUILD_DIR)/$(TARGET_EXE) $(INSTALL_DIR)
#	cd $(INSTALL_DIR) && ./$(TARGET_EXE)

uninstall:
	rm -rf $(INSTALL_DIR)

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(OBJ_CODE_DIR)
	rm -rf $(OBJ_TEST_DIR)
	rm -rf $(DIST_DIR)
	rm -rf $(REPORT_DIR)
	rm -rf $(TARGET_EXE)
	rm -rf $(TEST_EXE)
	rm -rf *.a
	rm -rf *.info
	rm -rf *.log
	rm -rf *.out
	rm -rf *.bin

dvi:
	doxygen Doxyfile && open html/index.html

dist: build
		doxygen Doxyfile
		tar -cvf $(TARGET_EXE).tar $(BUILD_DIR)/$(TARGET_EXE) html
		gzip $(TARGET_EXE).tar
		mkdir -p $(DIST_DIR)
		mv $(TARGET_EXE).tar.gz $(DIST_DIR)
 
test: clean $(TEST_EXE)
	./$(TEST_EXE) 

gcov_report: clean flags_gcov $(TEST_EXE)
	./$(TEST_EXE)
	lcov -t "suite" -o gcov.info -c -d $(OBJ_CODE_DIR) $(GCOV_IGNOR)
	genhtml -o $(REPORT_DIR) gcov.info
	open $(REPORT_DIR)/index.html

$(TEST_EXE): $(OBJ_TEST) $(OBJ_CODE)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

valgrind: clean $(TEST_EXE)
	valgrind $(VALGRIND_OPT) ./$(TEST_EXE)
	@echo "================================================================================="
	@grep -E "allocs|frees" valgrind.log || true;
	@grep -A 5 "LEAK SUMMARY:" valgrind.log || true;
	@grep "ERROR SUMMARY:" valgrind.log || true
	@echo "================================================================================="

flags_gcov:
	$(eval CFLAGS += --coverage)

$(OBJ_CODE_DIR)/%.o: $(SRC_CODE_DIR)/%.c
	mkdir -p $(OBJ_CODE_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_TEST_DIR)/%.o: $(SRC_TEST_DIR)/%.c
	mkdir -p $(OBJ_TEST_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

check_clang:
	find . \( $(CLANG_OPT) \) -exec clang-format -n --style=Google --Werror {} \;

format_clang:
	find . \( $(CLANG_OPT) \) -exec clang-format -i --style=Google {} \;

environment:
	sudo apt update && sudo apt upgrade -y
	sudo apt install -y cmake qmake6
	sudo apt install -y qt6-base-dev
	sudo apt-get install -y libglu1-mesa-dev freeglut3-dev mesa-common-dev mesa-utils
	sudo apt-get install -y libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev libglfw3-dev
	sudo apt install -y imagemagick