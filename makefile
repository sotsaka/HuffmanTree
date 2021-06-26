SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include/
TESTDIR=tests
DOCDIR=doc
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -std=c99  -I $(INCLUDEDIR)
LDFLAGS=-lhuffman
EXEC=huffman
EXECTEST=test
DOXY=doxygen Doxyfile

all :  exe tests doc

exe: $(BINDIR)/$(EXEC)

tests : $(TESTDIR)/$(EXECTEST)

$(TESTDIR)/$(EXECTEST) : $(SRCDIR)/testTDC.o $(LIBDIR)/libtesting.a
	$(CC) -o $@ $^ -lcunit -L$(LIBDIR) -ltesting

$(LIBDIR)/libtesting.a: $(SRCDIR)/listechainee.o $(SRCDIR)/octet.o $(SRCDIR)/bitAllocationDynamique.o $(SRCDIR)/codebinaire.o $(SRCDIR)/tabledecodage.o
	$(AR) -r $@ $^

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libhuffman.a
	$(CC)  -o $@ $< -L$(LIBDIR) $(LDFLAGS)

$(LIBDIR)/libhuffman.a: $(SRCDIR)/listechainee.o $(SRCDIR)/octet.o $(SRCDIR)/bitAllocationDynamique.o $(SRCDIR)/codebinaire.o $(SRCDIR)/tabledecodage.o $(SRCDIR)/statistiques.o $(SRCDIR)/arbrebinaire.o $(SRCDIR)/arbrehuffman.o $(SRCDIR)/filedepriorite.o $(SRCDIR)/arbreAllocationDynamique.o $(SRCDIR)/statAllocationDynamique.o $(SRCDIR)/creationArbre.o $(SRCDIR)/compression.o $(SRCDIR)/decompression.o
	$(AR) -r $@ $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

doc: documentation
	cd $(DOCDIR)/latex/ ; make pdf
	cp  $(DOCDIR)/latex/refman.pdf doc/ArbreHuffman.pdf
	rm -rf $(DOCDIR)/*.tmp

documentation :
		$(DOXY)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*
	rm -rf $(DOCDIR)/*
