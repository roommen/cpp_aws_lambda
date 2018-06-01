SAYHELLO = sayhello.node

binding:
	node-gyp configure build
	mkdir -p node_modules
	cp build/Release/$(SAYHELLO) node_modules/.

clean:
	rm -Rf build
	rm -f $(SAYHELLO)
	rm -rf node_modules
