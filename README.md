Protocol Buffer
============

	    $ mkdir build
	    $ cd build
	    $ cmake ..
	    $ make

console decode
============
	    protoc --decode lm.helloworld -I. $(find . -name '*.proto') < build/log.pb 
	    
generate .h &.cc
============
	protoc -I=. --cpp_out=. helloworld.proto
	

