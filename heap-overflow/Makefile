CPP=		gcc $(CCFLAGS)
HEAP=		heap-overflow.c
HEAP2=		heap-overflow2.c

OBJS =		$(HEAP) $(HEAP2)

LIBS=		-fno-stack-protector -no-pie

CCFLAGS= -g


 
all: heap heap2

heap:	$(HEAP)
		$(CPP) -fno-stack-protector -no-pie $^ -o $@

heap2:	$(HEAP2)
		$(CPP) -fno-stack-protector -no-pie $^ -o $@

clean:
		rm -f *.o


