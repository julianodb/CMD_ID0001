#******************************************************************************
#
# Makefile - Rules for building the Project Zero Example.
#
# Copyright (c) 2012 Texas Instruments Incorporated.  All rights reserved.
# Software License Agreement
# 
# Texas Instruments (TI) is supplying this software for use solely and
# exclusively on TI's microcontroller products. The software is owned by
# TI and/or its suppliers, and is protected under applicable copyright
# laws. You may not combine this software with "viral" open-source
# software in order to form a larger program.
# 
# THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
# NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
# NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
# CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
# DAMAGES, FOR ANY REASON WHATSOEVER.
# 
# This is part of revision 9453 of the EK-LM4F120XL Firmware Package.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=LM4F120H5QR

#
# Set the processor variant.
#
VARIANT=cm4f

#
# The base directory for StellarisWare.
#
ROOT=../../StellarisWare

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=../../StellarisWare/utils

#
# Where to find header files that do not live in the source directory.
#
IPATH=../../StellarisWare

#
# The default rule, which causes the Project Zero Example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/proto02.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER} ${wildcard *~}

#
# The rule to create the target directory.
#
${COMPILER}:
	@mkdir -p ${COMPILER}

#
# Rules for building the Project Zero Example.
#
${COMPILER}/proto02.axf: ${COMPILER}/proto02.o
${COMPILER}/proto02.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/proto02.axf: ${COMPILER}/uartstdio.o
${COMPILER}/proto02.axf: ${COMPILER}/board_stellaris.o
${COMPILER}/proto02.axf: ${ROOT}/driverlib/${COMPILER}-cm4f/libdriver-cm4f.a
${COMPILER}/proto02.axf: proto02.ld
SCATTERgcc_proto02=proto02.ld
ENTRY_proto02=ResetISR
CFLAGSgcc=-DTARGET_IS_BLIZZARD_RA2

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
