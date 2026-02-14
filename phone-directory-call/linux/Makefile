# Build folder
BUILD_DIR = build

# Source files
SOURCES := \
  main/main.c \
  main/file/file-manager.c

# Output target name
OUTPUT := phone-directories-call

# Compiler and flags
CC = gcc
CCFLAGS = -Wall -Wextra -std=c17
LDFLAGS =

# Include directories
INCLUDE_DIRS =

# Change output location
OUTPUT := $(BUILD_DIR)/$(OUTPUT)

# Deduce objects
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)

# Verbose mode
ifeq ($(VERBOSE), 1)
Q :=
else
Q := @
endif

# Colors
GREEN  := \033[0;32m
YELLOW := \033[1;33m
RESET  := \033[0m

# Current file nb to process
CURRENT_FILE := 0

# Default targets
all: count_build build_dir end

# Create build directory
build_dir:
	$(Q)mkdir -p $(dir $(OBJECTS))

# Link target
$(OUTPUT): $(OBJECTS)
	@echo "[100%] $(YELLOW)Linking $(OUTPUT)$(RESET)"
	$(Q)$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

# Build .o files from .c
$(BUILD_DIR)/%.o: %.c
	$(eval CURRENT_FILE := $(shell echo $$(($(CURRENT_FILE)+1))))
	$(eval PERCENTAGE := $(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
	@echo "[$(PERCENTAGE)%] $(GREEN)Building C object $@$(RESET)"
	$(Q)$(CC) $(CCFLAGS) $(INCLUDE_DIRS:%=-I%) -MMD -MP -c $< -o $@

# Source files dependencies
-include $(OBJECTS:.o=.d)

count_build:
	$(eval export TOTAL_FILES := $(shell echo $$(($$(make -n $(OBJECTS) 2>/dev/null | grep -c "Building") + 1))))

# Print ending message
end: $(OUTPUT)
	@echo "Built target $(OUTPUT)"

# Clean
.PHONY: clean
clean:
	$(Q)rm -rf $(BUILD_DIR)

# Run executable
.PHONY: run
run:
	$(Q)./$(OUTPUT)
