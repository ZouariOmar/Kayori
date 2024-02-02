# by_kayori_Nova_Grp
# 01/24/24
# kayori :: Makefile

# Define the C compiler to use
CC = gcc

# Specify any additional flags for the C compiler
CFLAG1 = -I inc -L lib -l mingw32 -l SDLmain -l SDL

# Define the source file
SRC_DIR = src/main.c

# Define the output directory
OUT_DIR = bin/debug

# Define the objects  directory
OBJ_DIR = bin/obj

# Choose the name of the executable
NAME = app

# Full path to the output executable
APP = $(OUT_DIR)/$(NAME)

# Unused variable
x = 0

#					-- 'make' build executable file 'app' --
# app cmd option :: make <NAME=app_name>
app: main.o
	@echo
	@$(CC) $(SRC_DIR) -o ${APP}
	@./$(APP)
	@echo 
	@echo --- Executing 'run: app' complete ! ---
	@echo -n "Press Enter to continue..." && read -r x

# main.o > app
main.o:
	@$(CC) $(SRC_DIR) -o ${OBJ_DIR}/main.o
	@echo --- Executing 'app' build complete ! ---
	@echo -n "Press Enter to continue..." && read -r x

# move option :: make move <NAME=app_name>
move:
	@echo --- Moving "$(NAME).exe" from ${OUT_DIR} to "bin/release" ---
	@cp ${APP} "bin/release"
	@echo --- Moving complete ! ---
	@echo -n "Press Enter to continue..." && read -r x

# clean option :: make clean <NAME=app_name> <OUT_DIR=path>
clean:
	@echo --- Deleting "$(NAME).exe" from "$(OUT_DIR)" ---
	@rm ${APP}
	@echo --- Cleanup complete ! ---
	@echo -n "Press Enter to continue..." && read -r x

# cleanDir option ::: make cleanDir <OUT_DIR=path>
cleanDir:
	@echo --- Deleting all files in "${OUT_DIR}" ---
	@rm -r "$(OUT_DIR)"
	@echo --- All_Cleanup complete ! ---
	@echo -n "Press Enter to continue..." && read -r x