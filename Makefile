# Defines
include $(ROOT)/usr/include/make/PRdefs

# Directories
LIB = $(ROOT)/usr/lib
LPR = $(LIB)/PR
INC = $(ROOT)/usr/include
NUSYSINCDIR  = /usr/include/n64/nusys
NUSYSLIBDIR  = /usr/lib/n64/nusys

# Compilation flags
LCDEFS =  -DF3DEX_GBI_2
LCINCS =  -I. -I$(NUSYSINCDIR) -I$(ROOT)/usr/include/PR
LCOPTS =  -G 0
LDIRT =   $(APP)
LDFLAGS = $(MKDEPOPT) -L$(LIB) -L$(NUSYSLIBDIR) -s -lnusys -lultra -L$(N64_LIBGCCDIR) -lgcc -lnustd
OPTIMIZER = -O2

# Target directory
APP =     cave.out
TARGETS = cave.n64

# Source files
CODEFILES = \
	main.c \
	mem.c \
	draw.c \
	input.c \
	sound.c \
	triangle.c \
	rand.c \
	keycontrol.c \
	game.c \
	mode_opening.c \
	mode_title.c \
	mode_action.c \
	profile.c \
	textscr.c \
	flags.c \
	mychar.c \
	mycparam.c \
	mychit.c \
	npchar.c \
	npchit.c \
	npctbl.c \
	npc000.c \
	npc020.c \
	npc040.c \
	npc060.c \
	npc100.c \
	npc200.c \
	npc340.c \
	bullet.c \
	bullets.c \
	caret.c \
	carets.c \
	armsitem.c \
	selstage.c \
	stage.c \
	map.c \
	mapname.c \
	fade.c \
	frame.c \
	flash.c \

# Output objects
CODEOBJECTS = $(CODEFILES:.c=.o)  $(NUSYSLIBDIR)/nusys.o

DATAFILES   = 
DATAOBJECTS = $(DATAFILES:.c=.o)

CODESEGMENT = codesegment.o

OBJECTS = $(CODESEGMENT) $(DATAOBJECTS)

# Compilation
default:        $(TARGETS)

include $(COMMONRULES)

$(CODESEGMENT):	$(CODEOBJECTS) Makefile
		$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(TARGETS):	$(OBJECTS)
		$(MAKEROM) spec -s 9 -I$(NUSYSINCDIR) -r $(TARGETS) -e $(APP)
		makemask $(TARGETS)
