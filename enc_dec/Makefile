ROOT := .

all: install

install:
	make -C GeneratePP install
	make -C customerEncDec install

clean:
	make -C GeneratePP clean
	make -C customerEncDec clean
	cd sampleFiles; rm -f *.enc
