CPP=		gcc $(CCFLAGS)
STACK=		stack-overflow.c

OBJS =		$(STACK)

LIBS=		-fno-stack-protector -no-pie

CCFLAGS= -g


 
all: stack

stack:	$(STACK)
		$(CPP) -fno-stack-protector -z execstack -no-pie $^ -o $@

clean:
		rm -f *.o


