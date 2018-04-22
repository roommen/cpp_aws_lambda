NODE101 = node101.node

binding:
	node-gyp configure build
	mkdir node_modules
	cp build/Release/$(NODE101) node_modules/.

clean:
	rm -Rf build
	rm -f $(NODE101)
	rm -rf node_modules
