plot.png: Archivo.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: Main30.cpp
	g++ Main30.cpp
