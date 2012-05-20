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
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Tree.o \
	${OBJECTDIR}/ExtensionClassificator.o \
	${OBJECTDIR}/Entry.o \
	${OBJECTDIR}/RegularFileStreamFactory.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/RegularFileStream.o \
	${OBJECTDIR}/ShellCommandStreamFactory.o \
	${OBJECTDIR}/Cache.o \
	${OBJECTDIR}/Dispatcher.o \
	${OBJECTDIR}/WindowsNamesFilter.o \
	${OBJECTDIR}/ShellCommandStream.o \
	${OBJECTDIR}/FS.o \
	${OBJECTDIR}/EntryFactory.o \
	${OBJECTDIR}/AnyClassificator.o \
	${OBJECTDIR}/ConvertFilter.o \
	${OBJECTDIR}/Descriptor.o \
	${OBJECTDIR}/IgnoreFilter.o


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
LDLIBSOPTIONS=-lfuse -lboost_thread -lboost_filesystem -lxml2 -lboost_system

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/convertfs

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/convertfs: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/convertfs ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Tree.o: Tree.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tree.o Tree.cpp

${OBJECTDIR}/ExtensionClassificator.o: ExtensionClassificator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ExtensionClassificator.o ExtensionClassificator.cpp

${OBJECTDIR}/Entry.o: Entry.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Entry.o Entry.cpp

${OBJECTDIR}/RegularFileStreamFactory.o: RegularFileStreamFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/RegularFileStreamFactory.o RegularFileStreamFactory.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/RegularFileStream.o: RegularFileStream.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/RegularFileStream.o RegularFileStream.cpp

${OBJECTDIR}/ShellCommandStreamFactory.o: ShellCommandStreamFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ShellCommandStreamFactory.o ShellCommandStreamFactory.cpp

${OBJECTDIR}/Cache.o: Cache.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Cache.o Cache.cpp

${OBJECTDIR}/Dispatcher.o: Dispatcher.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Dispatcher.o Dispatcher.cpp

${OBJECTDIR}/WindowsNamesFilter.o: WindowsNamesFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/WindowsNamesFilter.o WindowsNamesFilter.cpp

${OBJECTDIR}/ShellCommandStream.o: ShellCommandStream.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ShellCommandStream.o ShellCommandStream.cpp

${OBJECTDIR}/FS.o: FS.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/FS.o FS.cpp

${OBJECTDIR}/EntryFactory.o: EntryFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/EntryFactory.o EntryFactory.cpp

${OBJECTDIR}/AnyClassificator.o: AnyClassificator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/AnyClassificator.o AnyClassificator.cpp

${OBJECTDIR}/ConvertFilter.o: ConvertFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ConvertFilter.o ConvertFilter.cpp

${OBJECTDIR}/Descriptor.o: Descriptor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/Descriptor.o Descriptor.cpp

${OBJECTDIR}/IgnoreFilter.o: IgnoreFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64 -I/usr/include/libxml2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/IgnoreFilter.o IgnoreFilter.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/convertfs

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
