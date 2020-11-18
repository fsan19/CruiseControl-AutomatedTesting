#!/bin/sh

# Dont want to delete created .o files
make clean

cp ../cruise* ./

/opt/esterelv6_01/bin/esterel -simul cruise.strl
# Dont need thsi as already built by make cruise
gcc -m32 -c cruise.c cruise_data.c

# Replace the middle stage with the makefile command
# make cruise
# Use it to build the simulator
gcc -m32 -o cruise cruise.o cruise_data.o /opt/esterelv6_01/lib/libcsimul.a

./cruise

make clean

rm cruise*