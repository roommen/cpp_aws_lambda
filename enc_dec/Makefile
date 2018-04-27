ROOT := .

all: install

install:
	make -C genPP install
	make -C customerEncDec install

clean:
	make -C genPP clean
	make -C customerEncDec clean
	cd sampleFiles; rm -f *.enc
