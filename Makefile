# MUUTA ALKUOSA PROJEKTIN MUKAAN

# määrittely kääntäjä
CC 		= gcc

# listaa kääntäjän parametrit (flags)
CFLAGS		= -std=c11 -Wall -fmax-errors=10 -Wextra

# listaa erillisten kirjastojen polut (muut kuin /usr/lib )
# esim. LFLAGS	= -L.
LFLAGS		=

#  listaa käytettävät kirjastot
# esim. LIBS	= -lmyextrafunctions
LIBS		= -lm

# listaa "binary object files" .o tiedostot joita projekti vaatii
# esim. OBJFILES= program.o extrafunction.o
OBJFILES	= program.o

# nimeä valmis ohjelma
MAIN		= matriisiLaskin



# ÄLÄ MUUTA ALLA OLEVIA YLEISIÄ SÄÄNTÖJÄ

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) $(LFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: $(MAIN)
	./$(MAIN)

clean:
	rm -f $(OBJFILES) $(MAIN)
