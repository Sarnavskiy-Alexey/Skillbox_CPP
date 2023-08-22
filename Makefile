CC = g++
CFLAGS = -g3 -Wall -c 
SRCDIR = ./
SOURCES := $(wildcard $(SRCDIR)*.cpp)
SOURCES += $(wildcard $(SRCDIR)*/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS := $(wildcard $(SRCDIR)*.hpp)
HEADERS += $(wildcard $(SRCDIR)*/*.hpp)
EXECUTABLE = main
XCFLAGS =  -D __MODULE_02__ 
XCFLAGS += -D __MODULE_03__ 
XCFLAGS += -D __MODULE_04__ 
XCFLAGS += -D __MODULE_05__ 
XCFLAGS += -D __MODULE_06__ 
XCFLAGS += -D __MODULE_07__ 
XCFLAGS += -D __MODULE_08__ 
XCFLAGS += -D __MODULE_09__ 
XCFLAGS += -D __MODULE_10__ 
XCFLAGS += -D __MODULE_11__ 
XCFLAGS += -D __MODULE_12__ 
XCFLAGS += -D __MODULE_13__ 
XCFLAGS += -D __MODULE_14__ 
XCFLAGS += -D __MODULE_15__ 
XCFLAGS += -D __MODULE_16__ 
XCFLAGS += -D __MODULE_17__ 
XCFLAGS += -D __MODULE_18__ 
XCFLAGS += -D __MODULE_19__ 
XCFLAGS += -D __MODULE_20__ 
XCFLAGS += -D __MODULE_21__ 
XCFLAGS += -D __MODULE_22__ 
XCFLAGS += -D __MODULE_23__ 
XCFLAGS += -D __MODULE_24__ 

all: $(SOURCES) $(EXECUTABLE)
	del SkillBox_HomeWorks.exe
	rename $(EXECUTABLE).exe SkillBox_HomeWorks.exe

$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(OBJECTS) $(HEADERS) -o $@ $(XCFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -MD $(XCFLAGS) $< -o $@

include $(wildcard $(SRCDIR)*.d)
include $(wildcard $(SRCDIR)*/*.d)

clean:
	del /s /q *.o
	del /s /q *.d
