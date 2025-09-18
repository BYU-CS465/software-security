CPP=		g++ $(CCFLAGS)
STACK=		stack-overflow.cc

OBJS =		$(STACK)

LIBS=		-fno-stack-protector -no-pie

CCFLAGS= -g 


 
all: stack

stack:	$(STACK)
		$(CXX) $(CCFLAGS) -fno-stack-protector -no-pie $^ -o $@

clean:
		rm -f *.o


