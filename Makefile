MODULOS = arvore_binaria

OBJETOS = main.o $(addsuffix .o,$(MODULOS))

HEADERS = $(addsuffix .h,$(MODULOS))

.PHONY : all clean

all : main
	./$<

main : $(OBJETOS)

$(OBJETOS): $(HEADERS)

clean : 
	$(RM) $(OBJETOS)
