###########################################################################
## Makefile generated for component 'autoquet_simulink'. 
## 
## Makefile     : autoquet_simulink.mk
## Generated on : Sun Mar 15 19:12:40 2026
## Final product: $(RELATIVE_PATH_TO_ANCHOR)/autoquet_simulink.elf
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = autoquet_simulink
MAKEFILE                  = autoquet_simulink.mk
MATLAB_ROOT               = C:/PROGRA~1/MATLAB/R2023b
MATLAB_BIN                = C:/PROGRA~1/MATLAB/R2023b/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/win64
START_DIR                 = C:/Users/doria/Desktop/FILE_S~1/McMaster/FIFTH_~1/Capstone/REPOSI~1/EXPOMO~1
SOLVER                    = 
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
TGT_FCN_LIB               = None
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 0
RELATIVE_PATH_TO_ANCHOR   = ..
SLIB_PATH                 = C:/Users/doria/DOCUME~1/MATLAB/R2023b/ARDUIN~1/ARDUIN~4/FASTER~1
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Arduino AVR
# Supported Version(s):    
# ToolchainInfo Version:   2023b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# ARDUINO_ROOT
# ARDUINO_PORT
# ARDUINO_MCU
# ARDUINO_BAUD
# ARDUINO_PROTOCOL
# ARDUINO_F_CPU

#-----------
# MACROS
#-----------

SHELL            = %SystemRoot%/system32/cmd.exe
PRODUCT_HEX      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).hex
PRODUCT_BIN      = $(RELATIVE_PATH_TO_ANCHOR)/$(PRODUCT_NAME).eep
ARDUINO_TOOLS    = $(ARDUINO_ROOT)/hardware/tools/avr/bin
ELF2EEP_OPTIONS  = -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0
DOWNLOAD_ARGS    =  >tmp.trash 2>&1 -P$(ARDUINO_PORT) -V -q -q -q -q -F -C$(ARDUINO_ROOT)/hardware/tools/avr/etc/avrdude.conf -p$(ARDUINO_MCU) -c$(ARDUINO_PROTOCOL) -b$(ARDUINO_BAUD) -D -Uflash:w:

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = -lm -lcomm -lcore

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# Assembler: Arduino AVR Assembler
AS_PATH = $(ARDUINO_TOOLS)
AS = "$(AS_PATH)/avr-gcc"

# C Compiler: Arduino AVR C Compiler
CC_PATH = $(ARDUINO_TOOLS)
CC = "$(CC_PATH)/avr-gcc"

# Linker: Arduino AVR Linker
LD_PATH = $(ARDUINO_TOOLS)
LD = "$(LD_PATH)/avr-gcc"

# C++ Compiler: Arduino AVR C++ Compiler
CPP_PATH = $(ARDUINO_TOOLS)
CPP = "$(CPP_PATH)/avr-g++"

# C++ Linker: Arduino AVR C++ Linker
CPP_LD_PATH = $(ARDUINO_TOOLS)
CPP_LD = "$(CPP_LD_PATH)/avr-gcc"

# Archiver: Arduino AVR Archiver
AR_PATH = $(ARDUINO_TOOLS)
AR = "$(AR_PATH)/avr-ar"

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Binary Converter: Binary Converter
OBJCOPY_PATH = $(ARDUINO_ROOT)/hardware/tools/avr/bin
OBJCOPY = "$(OBJCOPY_PATH)/avr-objcopy"

# Hex Converter: Hex Converter
OBJCOPY_PATH = $(ARDUINO_ROOT)/hardware/tools/avr/bin
OBJCOPY = "$(OBJCOPY_PATH)/avr-objcopy"

# Download: Download
DOWNLOAD_PATH = $(ARDUINO_TOOLS)
DOWNLOAD = "$(DOWNLOAD_PATH)/avrdude"

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: Make Tool
MAKE_PATH = %MATLAB%\bin\win64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

ASDEBUG             = -g
AS_OUTPUT_FLAG      = -o
CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  =
ECHO                = echo
MV                  =
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = rcs
ASFLAGS              = -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Wall \
                       -x assembler-with-cpp \
                       $(ASFLAGS_ADDITIONAL) \
                       $(DEFINES) \
                       $(INCLUDES) \
                       -c
OBJCOPYFLAGS_BIN     = $(ELF2EEP_OPTIONS) $(PRODUCT) $(PRODUCT_BIN)
CFLAGS               = -std=gnu11  \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -MMD \
                       -DARDUINO=10801  \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Os
CPPFLAGS             = -std=gnu++11 -fpermissive -fno-exceptions -fno-threadsafe-statics  \
                       -c \
                       -w \
                       -ffunction-sections \
                       -fdata-sections  \
                       -MMD \
                       -DARDUINO=10801  \
                       -MMD -MP -MF"$(@:%.o=%.dep)" -MT"$@"  \
                       -Os
CPP_LDFLAGS          =  -w -Os -Wl,--gc-sections,--relax
CPP_SHAREDLIB_LDFLAGS  =
DOWNLOAD_FLAGS       = $(DOWNLOAD_ARGS)$(PRODUCT_HEX):i
EXECUTE_FLAGS        =
OBJCOPYFLAGS_HEX     = -O ihex -R .eeprom $(PRODUCT) $(PRODUCT_HEX)
LDFLAGS              =  -w -Os -Wl,--gc-sections,--relax
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    =



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(RELATIVE_PATH_TO_ANCHOR)/autoquet_simulink.elf
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Top-Level Standalone Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/toolbox/target/SUPPOR~1/ARDUIN~2/include -I$(MATLAB_ROOT)/toolbox/target/shared/svd/common/include -I$(START_DIR)/autoquet_simulink_ert_rtw -I$(MATLAB_ROOT)/extern/include -I$(MATLAB_ROOT)/simulink/include -I$(MATLAB_ROOT)/rtw/c/src -I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common -I$(MATLAB_ROOT)/rtw/c/ert -I$(MATLAB_ROOT)/toolbox/dsp/include -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include/src -I$(MATLAB_ROOT)/toolbox/dsp/extern/src/export/include -I$(MATLAB_ROOT)/toolbox/shared/dsp/vision/matlab/include -I$(ARDUINO_ROOT)/hardware/arduino/avr/cores/arduino -I$(ARDUINO_ROOT)/hardware/arduino/avr/variants/leonardo -I$(ARDUINO_ROOT)/libraries/Servo/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/toolbox/target/SUPPOR~1/ARDUIN~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/toolbox/target/SUPPOR~1/ARDUIN~1/SCHEDU~1/include -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/aIDE/hardware/arduino/avr/LIBRAR~1/Wire/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/aIDE/hardware/arduino/avr/LIBRAR~1/Wire/src/utility -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/aIDE/hardware/arduino/avr/LIBRAR~1/SPI/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/aIDE/LIBRAR~1/Servo/src -IC:/PROGRA~3/MATLAB/SUPPOR~1/R2023b/aIDE/LIBRAR~1/Servo/src/avr

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_ = -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DMW_TIMERID=1 -DMW_PRESCALAR=64 -DMW_TIMERCOUNT=65511 -DMW_SCHEDULERCOUNTER=1 -DARDUINO_NUM_SERIAL_PORTS=2 -D_RTT_BAUDRATE_SERIAL0_=115200 -D_RTT_BAUDRATE_SERIAL1_=9600 -D_RTT_CONFIG_SERIAL0_=SERIAL_8N1 -D_RTT_CONFIG_SERIAL1_=SERIAL_8N1 -D_RTT_ANALOG_REF_=0 -D_RTT_PWM_BLOCKS_
DEFINES_BUILD_ARGS = -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=1
DEFINES_CUSTOM = 
DEFINES_OPTS = -DTID01EQ=0
DEFINES_SKIPFORSIL = -DXCP_CUSTOM_PLATFORM -DEXIT_FAILURE=1 -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -DSTACK_SIZE=64 -DRT
DEFINES_STANDARD = -DMODEL=autoquet_simulink -DNUMST=4 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0

DEFINES = $(DEFINES_) $(DEFINES_BUILD_ARGS) $(DEFINES_CUSTOM) $(DEFINES_OPTS) $(DEFINES_SKIPFORSIL) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_SerialRead.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_SerialWrite.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_arduinoI2C.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp $(START_DIR)/autoquet_simulink_ert_rtw/autoquet_simulink.c $(START_DIR)/autoquet_simulink_ert_rtw/autoquet_simulink_data.c $(START_DIR)/autoquet_simulink_ert_rtw/rt_zcfcn.c $(START_DIR)/blood_flow_detector_2_wrapper.c $(START_DIR)/button_control_logic_wrapper.c $(START_DIR)/clock_counter_wrapper.c $(START_DIR)/custom_demux_wrapper.c $(START_DIR)/dec_to_sev_seg_wrapper.c $(START_DIR)/display_pressures_signal_wrapper.c $(START_DIR)/disruption_activity_monitor_wrapper.c $(START_DIR)/limb_movement_detector_wrapper.c $(START_DIR)/motor_drive_control_wrapper.c $(START_DIR)/pressure_display_wrapper.c $(START_DIR)/process_raw_sensor_reading_wrapper.c C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinotarget/src/MW_ArduinoHWInit.cpp C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinotarget/scheduler/src/arduinoAVRScheduler.cpp

MAIN_SRC = $(START_DIR)/autoquet_simulink_ert_rtw/ert_main.c

ALL_SRCS = $(SRCS) $(MAIN_SRC)

###########################################################################
## OBJECTS
###########################################################################

OBJS = MW_SerialRead.o MW_SerialWrite.o MW_arduino_digitalio.o MW_arduinoI2C.o io_wrappers.o MW_PWM.o MW_PWMDriver.o ArduinoPinHandleMap.o autoquet_simulink.o autoquet_simulink_data.o rt_zcfcn.o blood_flow_detector_2_wrapper.o button_control_logic_wrapper.o clock_counter_wrapper.o custom_demux_wrapper.o dec_to_sev_seg_wrapper.o display_pressures_signal_wrapper.o disruption_activity_monitor_wrapper.o limb_movement_detector_wrapper.o motor_drive_control_wrapper.o pressure_display_wrapper.o process_raw_sensor_reading_wrapper.o MW_ArduinoHWInit.o arduinoAVRScheduler.o

MAIN_OBJ = ert_main.o

ALL_OBJS = $(OBJS) $(MAIN_OBJ)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = $(SLIB_PATH)/MW_RebuildSrc_Comm.o $(SLIB_PATH)/MW_RebuildSrc_Core.o

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_SKIPFORSIL = -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO_AVR_MICRO -DARDUINO_ARCH_AVR -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_LEONARDO_ -DUSB_VID=0x2341 -DUSB_PID=0x8037 -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Micro\""
CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_SKIPFORSIL) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_SKIPFORSIL = -mmcu=atmega32u4 -DF_CPU=16000000L -DARDUINO_AVR_MICRO -DARDUINO_ARCH_AVR -D_RUNONTARGETHARDWARE_BUILD_ -D_ROTH_LEONARDO_ -DUSB_VID=0x2341 -DUSB_PID=0x8037 -DUSB_MANUFACTURER=\""Unknown\"" -DUSB_PRODUCT=\""Arduino Micro\""
CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_SKIPFORSIL) $(CPPFLAGS_BASIC)

#---------------
# C++ Linker
#---------------

CPP_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_LDFLAGS_SKIPFORSIL = -mmcu=atmega32u4 

CPP_LDFLAGS += $(CPP_LDFLAGS_) $(CPP_LDFLAGS_SKIPFORSIL)

#------------------------------
# C++ Shared Library Linker
#------------------------------

CPP_SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL = -mmcu=atmega32u4 

CPP_SHAREDLIB_LDFLAGS += $(CPP_SHAREDLIB_LDFLAGS_) $(CPP_SHAREDLIB_LDFLAGS_SKIPFORSIL)

#-----------
# Linker
#-----------

LDFLAGS_ = -L"$(SLIB_PATH)"
LDFLAGS_SKIPFORSIL = -mmcu=atmega32u4 

LDFLAGS += $(LDFLAGS_) $(LDFLAGS_SKIPFORSIL)

#--------------------------
# Shared Library Linker
#--------------------------

SHAREDLIB_LDFLAGS_ = -L"$(SLIB_PATH)"
SHAREDLIB_LDFLAGS_SKIPFORSIL = -mmcu=atmega32u4 

SHAREDLIB_LDFLAGS += $(SHAREDLIB_LDFLAGS_) $(SHAREDLIB_LDFLAGS_SKIPFORSIL)

###########################################################################
## INLINED COMMANDS
###########################################################################


DERIVED_SRCS = $(subst .o,.dep,$(OBJS))

build:

%.dep:



-include codertarget_assembly_flags.mk
-include *.dep


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild postbuild download execute


all : build postbuild
	echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS) $(LIBS)
	echo "### Successfully generated all binary outputs."


prebuild : 


postbuild : $(PRODUCT)
	echo "### Invoking postbuild tool "Binary Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_BIN)
	echo "### Done invoking postbuild tool."
	echo "### Invoking postbuild tool "Hex Converter" ..."
	$(OBJCOPY) $(OBJCOPYFLAGS_HEX)
	echo "### Done invoking postbuild tool."


download : postbuild
	echo "### Invoking postbuild tool "Download" ..."
	$(DOWNLOAD) $(DOWNLOAD_FLAGS)
	echo "### Done invoking postbuild tool."


execute : download
	echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS) $(LIBS) $(MAIN_OBJ)
	echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(CPP_LD) $(CPP_LDFLAGS) -o $(PRODUCT) $(subst /,\,$(OBJS)) $(subst /,\,$(MAIN_OBJ)) $(subst /,\,$(LIBS)) $(subst /,\,$(SYSTEM_LIBS)) $(subst /,\,$(TOOLCHAIN_LIBS))
	echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : %.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : %.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(RELATIVE_PATH_TO_ANCHOR)/%.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(START_DIR)/%.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(START_DIR)/%.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


%.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/%.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/%.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/%.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(START_DIR)/autoquet_simulink_ert_rtw/%.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(START_DIR)/autoquet_simulink_ert_rtw/%.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(START_DIR)/autoquet_simulink_ert_rtw/%.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(START_DIR)/autoquet_simulink_ert_rtw/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(MATLAB_ROOT)/rtw/c/src/%.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(MATLAB_ROOT)/simulink/src/%.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(MATLAB_ROOT)/simulink/src/%.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.s
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.S.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.S
	$(AS) $(ASFLAGS) -o "$@" $(subst /,\,"$<")


%.o : $(MATLAB_ROOT)/toolbox/simulink/blocks/src/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


MW_SerialRead.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_SerialRead.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


MW_SerialWrite.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_SerialWrite.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


MW_arduino_digitalio.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_arduino_digitalio.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


MW_arduinoI2C.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_arduinoI2C.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


io_wrappers.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/io_wrappers.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


MW_PWM.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_PWM.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


MW_PWMDriver.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/MW_PWMDriver.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


ArduinoPinHandleMap.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinobase/src/ArduinoPinHandleMap.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


autoquet_simulink.o : $(START_DIR)/autoquet_simulink_ert_rtw/autoquet_simulink.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


autoquet_simulink_data.o : $(START_DIR)/autoquet_simulink_ert_rtw/autoquet_simulink_data.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


ert_main.o : $(START_DIR)/autoquet_simulink_ert_rtw/ert_main.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


rt_zcfcn.o : $(START_DIR)/autoquet_simulink_ert_rtw/rt_zcfcn.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


blood_flow_detector_2_wrapper.o : $(START_DIR)/blood_flow_detector_2_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


button_control_logic_wrapper.o : $(START_DIR)/button_control_logic_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


clock_counter_wrapper.o : $(START_DIR)/clock_counter_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


custom_demux_wrapper.o : $(START_DIR)/custom_demux_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


dec_to_sev_seg_wrapper.o : $(START_DIR)/dec_to_sev_seg_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


display_pressures_signal_wrapper.o : $(START_DIR)/display_pressures_signal_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


disruption_activity_monitor_wrapper.o : $(START_DIR)/disruption_activity_monitor_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


limb_movement_detector_wrapper.o : $(START_DIR)/limb_movement_detector_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


motor_drive_control_wrapper.o : $(START_DIR)/motor_drive_control_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


pressure_display_wrapper.o : $(START_DIR)/pressure_display_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


process_raw_sensor_reading_wrapper.o : $(START_DIR)/process_raw_sensor_reading_wrapper.c
	$(CC) $(CFLAGS) -o "$@" $(subst /,\,"$<")


MW_ArduinoHWInit.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinotarget/src/MW_ArduinoHWInit.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


arduinoAVRScheduler.o : C:/ProgramData/MATLAB/SupportPackages/R2023b/toolbox/target/supportpackages/arduinotarget/scheduler/src/arduinoAVRScheduler.cpp
	$(CPP) $(CPPFLAGS) -o "$@" $(subst /,\,"$<")


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	echo "### PRODUCT = $(PRODUCT)"
	echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	echo "### BUILD_TYPE = $(BUILD_TYPE)"
	echo "### INCLUDES = $(INCLUDES)"
	echo "### DEFINES = $(DEFINES)"
	echo "### ALL_SRCS = $(ALL_SRCS)"
	echo "### ALL_OBJS = $(ALL_OBJS)"
	echo "### LIBS = $(LIBS)"
	echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	echo "### ASFLAGS = $(ASFLAGS)"
	echo "### CFLAGS = $(CFLAGS)"
	echo "### LDFLAGS = $(LDFLAGS)"
	echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	echo "### CPPFLAGS = $(CPPFLAGS)"
	echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	echo "### ARFLAGS = $(ARFLAGS)"
	echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	echo "### OBJCOPYFLAGS_BIN = $(OBJCOPYFLAGS_BIN)"
	echo "### OBJCOPYFLAGS_HEX = $(OBJCOPYFLAGS_HEX)"
	echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(RM) *.dep
	$(ECHO) "### Deleted all derived files."


