# =========================
# Toolchain
# =========================
CC      := arm-none-eabi-gcc
OBJCOPY := arm-none-eabi-objcopy
SIZE    := arm-none-eabi-size
OBJDUMP := arm-none-eabi-objdump

# =========================
# OS detection
# =========================
ifeq ($(OS),Windows_NT)
    MKDIR_P = if not exist "$(1)" mkdir "$(1)"
    RM_RF   = rmdir /s /q
else
    MKDIR_P = mkdir -p "$(1)"
    RM_RF   = rm -rf
endif

# =========================
# Build dir
# =========================
BUILD_DIR := build

# =========================
# Target
# =========================
TARGET := TM4C-SSI-Multichannel-Audio

# =========================
# Defines
# =========================
DEFS := \
 -DPART_TM4C123GH6PM \
 -DTARGET_IS_TM4C123_RB1 \
 -D__FPU_PRESENT=1 \
 -Dgcc \
 -DARM_MATH_CM4

# =========================
# Includes
# =========================
INCLUDES := \
 -I"C:/Lukas/SourceCode/TivaWare_C_Series-2.1.4.178" \
 -I"C:/GIT/tm4c-ssi-multichanel-audio/cmsis" \
 -I"C:/GIT/tm4c-ssi-multichanel-audio"

# =========================
# C flags
# =========================
CFLAGS := \
 $(DEFS) $(INCLUDES) \
 -O0 -g3 -Wall \
 -fmessage-length=0 \
 -mthumb -mcpu=cortex-m4 \
 -mfpu=fpv4-sp-d16 -mfloat-abi=hard \
 -ffunction-sections -fdata-sections \
 -MMD -MP

# =========================
# Linker flags
# =========================
LDFLAGS := \
 -Wl,--static,--gc-sections \
 -Tlinker.ld \
 -mthumb -mcpu=cortex-m4 \
 -mfpu=fpv4-sp-d16 -mfloat-abi=hard \
 --specs=nano.specs \
 -L"C:/Lukas/SourceCode/TivaWare_C_Series-2.1.4.178/driverlib/gcc"

LIBS := -ldriver -lm

# =========================
# Source files (FIXNÍ – z linkování)
# =========================
SRCS := \
 ADAU1772/AudioADDAControl-ADAU1772.c \
 AudioADDAControl_test.c \
 SSIAudio.c \
 main.c \
 startup_tm4c.c

# =========================
# Objects & deps
# =========================
OBJS := $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

# =========================
# Default target
# =========================
all: $(BUILD_DIR)/$(TARGET).elf post-build

# =========================
# Build dir
# =========================
$(BUILD_DIR):
	@$(call MKDIR_P,$(BUILD_DIR))

# =========================
# Compile rule
# =========================
$(BUILD_DIR)/%.o: %.c
	@echo 'Building file: ../$<'
	@echo 'Invoking: Cross GCC Compiler'
	@$(call MKDIR_P,$(dir $@))
	$(CC) $(CFLAGS) -c $< -o $@
	@echo 'Finished building: ../$<'

# =========================
# Link
# =========================
$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	@echo 'Building target: $(TARGET).elf'
	@echo 'Invoking: Cross GCC Linker'
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)
	@echo 'Finished building target: $(TARGET).elf'

# =========================
# Post build
# =========================
post-build:
	@echo 'binary'
	$(OBJCOPY) -O binary $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).bin
	$(SIZE) $(BUILD_DIR)/$(TARGET).elf
	$(OBJDUMP) -d -S $(BUILD_DIR)/$(TARGET).elf > $(BUILD_DIR)/$(TARGET).lst

# =========================
# Clean
# =========================
clean:
	$(RM_RF) $(BUILD_DIR)

# =========================
# Include deps
# =========================
-include $(DEPS)

