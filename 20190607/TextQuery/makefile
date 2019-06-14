# executable files for this directoryc
CPP:= g++
OBJECTS = andQueryTest.exe and_orQueryTest.exe \
          wordQueryTest.exe \

LOCFLAGS = -I.

#get_print.o andQueryTest.o and_orQueryTest.o \
#wordQueryTest.o Query.o: Query.h TextQuery.h

all:$(OBJECTS) 

wordQueryTest.exe: Query.o wordQueryTest.o TextQuery.o get_print.o
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) -o $@ $^

andQueryTest.exe: Query.o andQueryTest.o TextQuery.o get_print.o
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) -o $@ $^ 

and_orQueryTest.exe: and_orQueryTest.o Query.o TextQuery.o \
		get_print.o
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) -o $@ $^
%.o:%.cpp
	$(CPP) $(CPPFLAGS) $(LOCFLAGS) -o $@ -c $< 

clean:
	rm -rf *.o *.exe
