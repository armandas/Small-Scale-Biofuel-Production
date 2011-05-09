#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile

# Environment
MKDIR=mkdir -p
RM=rm -f 
CP=cp 
# Macros
CND_CONF=default

ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/firmware.${IMAGE_TYPE}.cof
else
IMAGE_TYPE=production
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/firmware.${IMAGE_TYPE}.cof
endif
# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}
# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files
OBJECTFILES=${OBJECTDIR}/LCD/HD44780.o ${OBJECTDIR}/thermocouples/thermocouples.o ${OBJECTDIR}/main.o ${OBJECTDIR}/ADC/ADC.o ${OBJECTDIR}/menu/menu.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

OS_ORIGINAL="Linux"
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC=/opt/microchip/mplabc18/v3.36/bin/mcc18
MP_AS=/opt/microchip/mplabc18/v3.36/bin/../mpasm/MPASMWIN
MP_LD=/opt/microchip/mplabc18/v3.36/bin/mplink
MP_AR=/opt/microchip/mplabc18/v3.36/bin/mplib
MP_CC_DIR=/opt/microchip/mplabc18/v3.36/bin
MP_AS_DIR=/opt/microchip/mplabc18/v3.36/bin/../mpasm
MP_LD_DIR=/opt/microchip/mplabc18/v3.36/bin
MP_AR_DIR=/opt/microchip/mplabc18/v3.36/bin
# This makefile will use a C preprocessor to generate dependency files
MP_CPP=/opt/microchip/mplab_ide/mplab_ide/modules/../../bin/mplab-cpp
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/firmware.${IMAGE_TYPE}.cof

# ------------------------------------------------------------------------------------
# Rules for buildStep: createRevGrep
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
__revgrep__:   nbproject/Makefile-${CND_CONF}.mk
	@echo 'grep -q $$@' > __revgrep__
	@echo 'if [ "$$?" -ne "0" ]; then' >> __revgrep__
	@echo '  exit 0' >> __revgrep__
	@echo 'else' >> __revgrep__
	@echo '  exit 1' >> __revgrep__
	@echo 'fi' >> __revgrep__
	@chmod +x __revgrep__
else
__revgrep__:   nbproject/Makefile-${CND_CONF}.mk
	@echo 'grep -q $$@' > __revgrep__
	@echo 'if [ "$$?" -ne "0" ]; then' >> __revgrep__
	@echo '  exit 0' >> __revgrep__
	@echo 'else' >> __revgrep__
	@echo '  exit 1' >> __revgrep__
	@echo 'fi' >> __revgrep__
	@chmod +x __revgrep__
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/LCD/HD44780.o: LCD/HD44780.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/LCD/HD44780.o.d 
	${MKDIR} ${OBJECTDIR}/LCD 
	${MP_CC}  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/LCD/HD44780.o LCD/HD44780.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/LCD/HD44780.o.temp LCD/HD44780.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/LCD > ${OBJECTDIR}/LCD/HD44780.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/LCD/HD44780.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/LCD/HD44780.o.d
else
	cat ${OBJECTDIR}/LCD/HD44780.o.temp >> ${OBJECTDIR}/LCD/HD44780.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/thermocouples/thermocouples.o: thermocouples/thermocouples.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/thermocouples/thermocouples.o.d 
	${MKDIR} ${OBJECTDIR}/thermocouples 
	${MP_CC}  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/thermocouples/thermocouples.o thermocouples/thermocouples.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/thermocouples/thermocouples.o.temp thermocouples/thermocouples.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/thermocouples > ${OBJECTDIR}/thermocouples/thermocouples.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/thermocouples/thermocouples.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/thermocouples/thermocouples.o.d
else
	cat ${OBJECTDIR}/thermocouples/thermocouples.o.temp >> ${OBJECTDIR}/thermocouples/thermocouples.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/main.o.d 
	${MKDIR} ${OBJECTDIR} 
	${MP_CC}  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/main.o main.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/main.o.temp main.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR} > ${OBJECTDIR}/main.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/main.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/main.o.d
else
	cat ${OBJECTDIR}/main.o.temp >> ${OBJECTDIR}/main.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/ADC/ADC.o: ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/ADC/ADC.o.d 
	${MKDIR} ${OBJECTDIR}/ADC 
	${MP_CC}  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/ADC/ADC.o ADC/ADC.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/ADC/ADC.o.temp ADC/ADC.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/ADC > ${OBJECTDIR}/ADC/ADC.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/ADC/ADC.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/ADC/ADC.o.d
else
	cat ${OBJECTDIR}/ADC/ADC.o.temp >> ${OBJECTDIR}/ADC/ADC.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/menu/menu.o: menu/menu.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/menu/menu.o.d 
	${MKDIR} ${OBJECTDIR}/menu 
	${MP_CC}  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/menu/menu.o menu/menu.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/menu/menu.o.temp menu/menu.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/menu > ${OBJECTDIR}/menu/menu.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/menu/menu.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/menu/menu.o.d
else
	cat ${OBJECTDIR}/menu/menu.o.temp >> ${OBJECTDIR}/menu/menu.o.d
endif
	${RM} __temp_cpp_output__
else
${OBJECTDIR}/LCD/HD44780.o: LCD/HD44780.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/LCD/HD44780.o.d 
	${MKDIR} ${OBJECTDIR}/LCD 
	${MP_CC}  -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/LCD/HD44780.o LCD/HD44780.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/LCD/HD44780.o.temp LCD/HD44780.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/LCD > ${OBJECTDIR}/LCD/HD44780.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/LCD/HD44780.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/LCD/HD44780.o.d
else
	cat ${OBJECTDIR}/LCD/HD44780.o.temp >> ${OBJECTDIR}/LCD/HD44780.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/thermocouples/thermocouples.o: thermocouples/thermocouples.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/thermocouples/thermocouples.o.d 
	${MKDIR} ${OBJECTDIR}/thermocouples 
	${MP_CC}  -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/thermocouples/thermocouples.o thermocouples/thermocouples.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/thermocouples/thermocouples.o.temp thermocouples/thermocouples.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/thermocouples > ${OBJECTDIR}/thermocouples/thermocouples.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/thermocouples/thermocouples.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/thermocouples/thermocouples.o.d
else
	cat ${OBJECTDIR}/thermocouples/thermocouples.o.temp >> ${OBJECTDIR}/thermocouples/thermocouples.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/main.o.d 
	${MKDIR} ${OBJECTDIR} 
	${MP_CC}  -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/main.o main.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/main.o.temp main.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR} > ${OBJECTDIR}/main.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/main.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/main.o.d
else
	cat ${OBJECTDIR}/main.o.temp >> ${OBJECTDIR}/main.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/ADC/ADC.o: ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/ADC/ADC.o.d 
	${MKDIR} ${OBJECTDIR}/ADC 
	${MP_CC}  -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/ADC/ADC.o ADC/ADC.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/ADC/ADC.o.temp ADC/ADC.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/ADC > ${OBJECTDIR}/ADC/ADC.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/ADC/ADC.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/ADC/ADC.o.d
else
	cat ${OBJECTDIR}/ADC/ADC.o.temp >> ${OBJECTDIR}/ADC/ADC.o.d
endif
	${RM} __temp_cpp_output__
${OBJECTDIR}/menu/menu.o: menu/menu.c  nbproject/Makefile-${CND_CONF}.mk
	${RM} ${OBJECTDIR}/menu/menu.o.d 
	${MKDIR} ${OBJECTDIR}/menu 
	${MP_CC}  -p18F66K22  -I ${MP_CC_DIR}/../h  -fo ${OBJECTDIR}/menu/menu.o menu/menu.c 
	${MP_CPP}  -MMD ${OBJECTDIR}/menu/menu.o.temp menu/menu.c __temp_cpp_output__ -D __18F66K22 -I /opt/microchip/mplabc18/v3.36/bin/../h  -D__18F66K22
	printf "%s/" ${OBJECTDIR}/menu > ${OBJECTDIR}/menu/menu.o.d
ifneq (,$(findstring MINGW32,$(OS_CURRENT)))
	cat ${OBJECTDIR}/menu/menu.o.temp | sed -e 's/\\\ /__SPACES__/g' -e's/\\$$/__EOL__/g' -e 's/\\/\\\\/g' -e 's/__SPACES__/\\\ /g' -e 's/__EOL__/\\/g' >> ${OBJECTDIR}/menu/menu.o.d
else
	cat ${OBJECTDIR}/menu/menu.o.temp >> ${OBJECTDIR}/menu/menu.o.d
endif
	${RM} __temp_cpp_output__
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/firmware.${IMAGE_TYPE}.cof: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD}   -p18f66k22  -w -x  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1  -l ${MP_CC_DIR}/../lib  -odist/${CND_CONF}/${IMAGE_TYPE}/firmware.${IMAGE_TYPE}.cof ${OBJECTFILES}     
else
dist/${CND_CONF}/${IMAGE_TYPE}/firmware.${IMAGE_TYPE}.cof: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD}   -p18f66k22  -w   -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}/../lib  -odist/${CND_CONF}/${IMAGE_TYPE}/firmware.${IMAGE_TYPE}.cof ${OBJECTFILES}     
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist
# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
