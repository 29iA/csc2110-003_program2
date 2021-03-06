AutomatedMakefile = am
CC = g++
CXXFLAGS = -Wno-deprecated-declarations -g -O0

PROJECT_PATH = $(PROJECT_DIR)
GUI_PATH = $(DRIVE_LETTER)/TDM-GCC-64/wxWidgets-3.1.0

INC_DIRS = -I./2110/CSC2110 -I$(PROJECT_PATH)/2110/GUI -I$(GUI_PATH)/include -I$(GUI_PATH)/lib/gcc510TDM_x64_dll/mswu
LIB_DIRS = -L./2110/CSC2110 -L$(PROJECT_PATH)/2110/GUI -L$(GUI_PATH)/lib/gcc510TDM_x64_dll
LDFLAGS = -Wl,-Bstatic
LIBS = $(LDFLAGS) -lCSC2110 -lrandom -lwxmsw31u_core -lwxbase31u -lgdi32

COMPILE = $(CC) $(CXXFLAGS) $(INC_DIRS) -c 
LINK = $(CC) $(CXXFLAGS) $(LIB_DIRS)

FILES =InventoryDriver.o InventoryManager.o Widget.o
EXECUTABLE = Inventory.exe

all: Inventory

Inventory: $(FILES)
	 $(LINK) $(FILES) $(LIBS) -o $(EXECUTABLE)

InventoryDriver.o:	
	$(COMPILE) InventoryDriver.cpp

InventoryManager.o:
	$(COMPILE) InventoryManager.cpp

Widget.o:
	$(COMPILE) Widget.cpp
