# Define Root Directories for the Project
ROOT_SRC = src
ROOT_BUILD = build
BIN = bin
TEST_BIN = $(BIN)/test

# Define the Compilation Flags
# 1. Include the Root Source Directory
# 2. Show all Warnings
FLAGS = -I $(ROOT_SRC) -Wall
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# All
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
all: build

# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Package: Action
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
ACTION_SRC = $(ROOT_SRC)/action
ACTION_BUILD = $(ROOT_BUILD)/action
$(ACTION_BUILD)/ActionShow.o: $(ACTION_SRC)/ActionShow.cc $(ACTION_SRC)/ActionShow.h
	g++ $(FLAGS) -c $(ACTION_SRC)/ActionShow.cc -o $(ACTION_BUILD)/ActionShow.o
$(ACTION_BUILD)/ActionHide.o: $(ACTION_SRC)/ActionHide.cc $(ACTION_SRC)/ActionHide.h
	g++ $(FLAGS) -c $(ACTION_SRC)/ActionHide.cc -o $(ACTION_BUILD)/ActionHide.o
$(ACTION_BUILD)/ActionSelect.o: $(ACTION_SRC)/ActionSelect.cc $(ACTION_SRC)/ActionSelect.h
	g++ $(FLAGS) -c $(ACTION_SRC)/ActionSelect.cc -o $(ACTION_BUILD)/ActionSelect.o
$(ACTION_BUILD)/ActionRegistry.o: $(ACTION_SRC)/ActionRegistry.cc \
    $(ACTION_SRC)/ActionRegistry.h $(ACTION_SRC)/ActionShow.h $(ACTION_SRC)/ActionHide.h \
    $(ACTION_SRC)/ActionSelect.h
	g++ $(FLAGS) -c $(ACTION_SRC)/ActionRegistry.cc -o $(ACTION_BUILD)/ActionRegistry.o

# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Package: Message
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
MESSAGE_SRC = $(ROOT_SRC)/message
MESSAGE_BUILD = $(ROOT_BUILD)/message
$(MESSAGE_BUILD)/Message.o: $(MESSAGE_SRC)/Message.cc $(MESSAGE_SRC)/Message.h
	g++ $(FLAGS) -c $(MESSAGE_SRC)/Message.cc -o $(MESSAGE_BUILD)/Message.o
$(MESSAGE_BUILD)/Messenger.o: $(MESSAGE_SRC)/Messenger.cc $(MESSAGE_SRC)/Message.h
	g++ $(FLAGS) -c $(MESSAGE_SRC)/Messenger.cc -o $(MESSAGE_BUILD)/Messenger.o
$(MESSAGE_BUILD)/TestReceive.o: $(MESSAGE_SRC)/TestReceive.cc $(MESSAGE_SRC)/Message.h
	g++ $(FLAGS) -c $(MESSAGE_SRC)/TestReceive.cc -o $(MESSAGE_BUILD)/TestReceive.o
$(BIN)/i3wl-msg: $(MESSAGE_BUILD)/Messenger.o $(MESSAGE_BUILD)/Message.o
	g++ $(MESSAGE_BUILD)/Messenger.o $(MESSAGE_BUILD)/Message.o -o $(BIN)/i3wl-msg
$(TEST_BIN)/i3-msg-receive: $(MESSAGE_BUILD)/TestReceive.o $(MESSAGE_BUILD)/Message.o
	g++ $(MESSAGE_BUILD)/TestReceive.o $(MESSAGE_BUILD)/Message.o -o $(TEST_BIN)/i3wl-msg-receive
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Directories
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
directories: 
	mkdir -p $(ROOT_BUILD)
	mkdir -p $(BIN)
	mkdir -p $(TEST_BIN)
	mkdir -p $(ACTION_BUILD)
	mkdir -p $(MESSAGE_BUILD)

# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Build
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
binaries = $(BIN)/i3wl-msg
test_binaries = $(TEST_BIN)/i3-msg-receive
build: directories $(binaries) $(test_binaries) \
    $(ACTION_BUILD)/ActionShow.o $(ACTION_BUILD)/ActionHide.o \
    $(ACTION_BUILD)/ActionSelect.o $(ACTION_BUILD)/ActionRegistry.o 
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Clean
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
clean: 
	rm -r -f $(ROOT_BUILD) $(ROOT_BIN)
