CPP=		gcc $(CCFLAGS)
STACK=		stack-overflow.c
SHELLCODE=	shellcode-loader.c

OBJS =		$(STACK)

CCFLAGS= -g -m32 -mpreferred-stack-boundary=2

all: stack shellcode-loader

stack:	$(STACK)
	$(CPP) -fno-stack-protector -z execstack -no-pie $^ -o $@

shellcode-loader: $(SHELLCODE)
	$(CPP) -fno-stack-protector -z execstack $^ -o $@

clean:
	rm -f stack shellcode-loader *.o


