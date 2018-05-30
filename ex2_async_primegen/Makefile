NODE102 = node102.node

binding:
	node-gyp configure build
	mkdir node_modules
	cp build/Release/$(NODE102) node_modules/.

clean:
	rm -Rf build
	rm -f $(NODE102)
	rm -rf node_modules
