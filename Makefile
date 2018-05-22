# Define Root Directories for the Project
ROOT_SRC = src
ROOT_BUILD = build
BIN = bin

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
$(MESSAGE_BUILD)/MessageParser.o: $(MESSAGE_SRC)/MessageParser.cc \
    $(MESSAGE_SRC)/MessageParser.h
	g++ $(FLAGS) -c $(MESSAGE_SRC)/MessageParser.cc -o $(MESSAGE_BUILD)/MessageParser.o
$(BIN)/i3wl-msg: $(MESSAGE_BUILD)/Messenger.o $(MESSAGE_BUILD)/Message.o
	g++ $(MESSAGE_BUILD)/Messenger.o $(MESSAGE_BUILD)/Message.o -o $(BIN)/i3wl-msg

# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Package: Core
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
CORE_SRC = $(ROOT_SRC)/core
CORE_BUILD = $(ROOT_BUILD)/core
$(CORE_BUILD)/i3wl.o: $(CORE_SRC)/i3wl.cc $(MESSAGE_SRC)/Message.h \
    $(MESSAGE_SRC)/MessageParser.h $(ACTION_SRC)/Action.h $(ACTION_SRC)/ActionRegistry.h
	g++ $(FLAGS) -c $(CORE_SRC)/i3wl.cc -o $(CORE_BUILD)/i3wl.o
$(BIN)/i3wl: $(CORE_BUILD)/i3wl.o $(MESSAGE_BUILD)/Message.o \
    $(MESSAGE_BUILD)/MessageParser.o $(ACTION_BUILD)/ActionRegistry.o \
    $(ACTION_BUILD)/ActionShow.o $(ACTION_BUILD)/ActionHide.o $(ACTION_BUILD)/ActionSelect.o
	g++ $(FLAGS) $(CORE_BUILD)/i3wl.o $(MESSAGE_BUILD)/Message.o \
	    $(MESSAGE_BUILD)/MessageParser.o $(ACTION_BUILD)/ActionRegistry.o \
	    $(ACTION_BUILD)/ActionShow.o $(ACTION_BUILD)/ActionHide.o \
	    $(ACTION_BUILD)/ActionSelect.o -o $(BIN)/i3wl

# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Directories
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
directories: 
	mkdir -p $(ROOT_BUILD)
	mkdir -p $(BIN)
	mkdir -p $(ACTION_BUILD)
	mkdir -p $(MESSAGE_BUILD)
	mkdir -p $(CORE_BUILD)

# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Build
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
binaries = $(BIN)/i3wl-msg $(BIN)/i3wl
build: directories $(binaries) \
    $(ACTION_BUILD)/ActionShow.o $(ACTION_BUILD)/ActionHide.o \
    $(ACTION_BUILD)/ActionSelect.o $(ACTION_BUILD)/ActionRegistry.o 

# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
# Clean
# ~~~~~ ~~~~~ ~~~~~ ~~~~~ ~~~~~
clean: 
	rm -r -f $(ROOT_BUILD) $(BIN)
