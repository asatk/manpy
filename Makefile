.RECIPEPREFIX := :
manpy: manpy.c
:cc $^ -o ~/bin/$@

clean: manpy
:rm ~/bin/$^
