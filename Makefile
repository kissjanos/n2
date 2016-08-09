ifneq ($(shell which gcc),)
  CXX ?= g++
else
  CXX = g++
endif


LDFLAGS :=  -std=c++11 

all : nev2

OBJS := main.o 

nev2 : $(OBJS)
	$(CXX) -o nev2 $(OBJS) $(LDFLAGS)

$(OBJS) : %.o : %.cpp
	$(CXX)  -o $@ -c $< $(LDFLAGS) 

clean:
	rm -f $(OBJS) nev2
