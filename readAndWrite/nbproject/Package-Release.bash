#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_PLATFORM=Cygwin-Windows
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build
CND_DLIB_EXT=dll
NBTMPDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
<<<<<<< HEAD:C++ Connect 4/nbproject/Package-Release.bash
OUTPUT_PATH=${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/c___connect_4
OUTPUT_BASENAME=c___connect_4
PACKAGE_TOP_DIR=c++connect4/
=======
OUTPUT_PATH=${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/readandwrite
OUTPUT_BASENAME=readandwrite
PACKAGE_TOP_DIR=readandwrite/
>>>>>>> 0d66699745f3b5c74ba2b47106c7a217e08ced6c:readAndWrite/nbproject/Package-Release.bash

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package
rm -rf ${NBTMPDIR}
mkdir -p ${NBTMPDIR}

# Copy files and create directories and links
cd "${TOP}"
<<<<<<< HEAD:C++ Connect 4/nbproject/Package-Release.bash
makeDirectory "${NBTMPDIR}/c++connect4/bin"
=======
makeDirectory "${NBTMPDIR}/readandwrite/bin"
>>>>>>> 0d66699745f3b5c74ba2b47106c7a217e08ced6c:readAndWrite/nbproject/Package-Release.bash
copyFileToTmpDir "${OUTPUT_PATH}.exe" "${NBTMPDIR}/${PACKAGE_TOP_DIR}bin/${OUTPUT_BASENAME}.exe" 0755


# Generate tar file
cd "${TOP}"
<<<<<<< HEAD:C++ Connect 4/nbproject/Package-Release.bash
rm -f ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/c++connect4.tar
cd ${NBTMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/c++connect4.tar *
=======
rm -f ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/readandwrite.tar
cd ${NBTMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/readandwrite.tar *
>>>>>>> 0d66699745f3b5c74ba2b47106c7a217e08ced6c:readAndWrite/nbproject/Package-Release.bash
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${NBTMPDIR}
