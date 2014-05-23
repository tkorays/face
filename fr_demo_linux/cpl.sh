#!/bin/sh

g++ -std=c++11 `pkg-config --cflags opencv`  -o fr \
	./fr.cpp ../ext/tinyxml/tinystr.cpp ../ext/tinyxml/tinyxml.cpp \
	../ext/tinyxml/tinyxmlerror.cpp ../ext/tinyxml/tinyxmlparser.cpp \
	`pkg-config --libs opencv`
