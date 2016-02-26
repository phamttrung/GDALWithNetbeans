#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/MinGW/bin -L/C/MinGW/lib -L/C/OSGeo4W/bin -L/C/OSGeo4W/lib /C/OSGeo4W/lib/gdal_i.lib /C/OSGeo4W/lib/geos_c.lib /C/OSGeo4W/lib/hdf5.lib /C/OSGeo4W/lib/proj_i.lib /C/OSGeo4W/lib/spatialite_i.lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe: /C/OSGeo4W/lib/gdal_i.lib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe: /C/OSGeo4W/lib/geos_c.lib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe: /C/OSGeo4W/lib/hdf5.lib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe: /C/OSGeo4W/lib/proj_i.lib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe: /C/OSGeo4W/lib/spatialite_i.lib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans ${OBJECTFILES} ${LDLIBSOPTIONS} -static-libgcc -static-libstdc++

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/MinGW/Include -I/C/OSGeo4W/Include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gdalwithnetbeans.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
