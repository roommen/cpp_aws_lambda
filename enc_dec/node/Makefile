NODEDEC = custDec.node

binding:
	node-gyp configure build
	mkdir node_modules
	cp build/Release/$(NODEDEC) node_modules/.

clean:
	rm -Rf build
	rm -f $(NODEDEC)
	rm -rf node_modules
