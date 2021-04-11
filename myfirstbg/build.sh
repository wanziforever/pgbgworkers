#!/bin/bash

if [ ! $(which pg_config) ]; then
    echo "ERROR: pg_config not found"
    exit 1
fi

CC="gcc"
BUILDDIR=".build"

[ -d ${BUILDDIR} ] || mkdir ${BUILDDIR}

INCLUDEDIR=$(pg_config --includedir-server)
LIBDIR=$(pg_config --pkglibdir)
LIBNAME="mytestbgworker.so"
LIBOUTPUT="${BUILDDIR}/${LIBNAME}"

echo ${INCLUDEDIR}
echo ${LIBDIR}
gcc -c -Wall -Werror -fpic -I${INCLUDEDIR} -I. -L${LIBDIR} -L. main.c

gcc -shared -o ${LIBNAME} main.o
