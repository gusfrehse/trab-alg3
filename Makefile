MODULOS = main \
	arvore_binaria

OBJETOS = $(addsuffix .o,$(MODULOS))

.PHONY : all clean

all : main
	./$<

main : $(OBJETOS)

clean : 
	$(RM) $(OBJETOS)
