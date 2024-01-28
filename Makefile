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

# Choose the name of the executable
NAME = app

# Full path to the output executable
APP = $(OUT_DIR)/$(NAME)

#					-- 'make' build executable file 'app' --
# run cmd option :: make run <NAME=app_name>
run: sdl
	@echo 
	@./$(APP)
	@echo 
	@echo --- Executing 'run: app' complete ! ---
	@echo -n "Press Enter to continue..." & read -r

# app > run
app:
	@$(CC) $(SRC_DIR) -o $(APP)
	@echo --- Executing 'app' build complete ! ---
	@echo -n "Press Enter to continue..." & read -r

# sdl > run
sdl:
	@$(CC) $(SRC_DIR) -o $(APP) $(CFLAG1)
	@echo --- Executing 'app' build complete ! ---
	@echo -n "Press Enter to continue..." & read -r

# move option :: make move <NAME=app_name>
move:
	@echo --- Moving "$(NAME).exe" from "$(OUT_DIR)" to "bin\release" ---
	@mv "bin\debug\$(NAME).exe" "bin\release"
	@echo --- Moving complete ! ---
	@echo -n "Press Enter to continue..." & read -r

# clean option :: make clean <NAME=app_name> <OUT_DIR=path>
clean:
	@echo --- Deleting "$(NAME).exe" from "$(OUT_DIR)" ---
	@rm "$(APP).exe"
	@echo --- Cleanup complete ! ---
	@echo -n "Press Enter to continue..." & read -r

# cleanDir option ::: make cleanDir <OUT_DIR=path>
cleanDir:
	@echo --- Deleting all files in "$(OUT_DIR)" ---
	@rm -r "$(OUT_DIR)"
	@echo --- All_Cleanup complete ! ---
	@echo -n "Press Enter to continue..." & read -r