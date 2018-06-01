PRIMEGEN = primegen.node

binding:
	node-gyp configure build
	mkdir node_modules
	cp build/Release/$(PRIMEGEN) node_modules/.

clean:
	rm -Rf build
	rm -f $(PRIMEGEN)
	rm -rf node_modules
