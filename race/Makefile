CXX=		g++ $(CCFLAGS)
INVENTORY=	inventory.o
FIXED= 		inventory-fixed.o
MONITOR= 	inventory-monitor.o
EXAMPLE=	threads-example.o
OBJS =		$(INVENTORY) $(FIXED) $(MONITOR) $(EXAMPLE)

LIBS=		-pthread

CCFLAGS= -g

all:		inventory inventory-fixed inventory-monitor threads-example

inventory:	$(INVENTORY)
		$(CXX) -o inventory $(INVENTORY) $(LIBS)

inventory-fixed:	$(FIXED)
		$(CXX) -o inventory-fixed $(FIXED) $(LIBS)

inventory-monitor:	$(MONITOR)
		$(CXX) -o inventory-monitor $(MONITOR) $(LIBS)

threads-example:	$(EXAMPLE)
		$(CXX) -o threads-example $(EXAMPLE) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) inventory inventory-fixed inventory-monitor threads-example


# These lines ensure that dependencies are handled automatically.
%.d:	%.cc
	$(SHELL) -ec '$(CC) -M $(CPPFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'

include	$(OBJS:.o=.d)
