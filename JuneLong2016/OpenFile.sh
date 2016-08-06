#!/bin/bash

cp ~/Documents/CodeJam16/LIB/template.cpp $1.cpp
echo "$1.cpp created"
gedit $1.cpp &

exit 0
