# Makefile wrapper for PSoC Creator Projects (MinGW)

SHELL = /bin/bash

ifeq ($(CYPRESS),)
CYPRESS     := /c/cypress
endif

ifeq ($(CREATOR_VER),)
CREATOR_VER := 3.2
endif

ifeq ($(CREATOR_BIN),)
CREATOR_BIN := $(CYPRESS)/PSoC\ Creator/$(CREATOR_VER)/PSoC\ Creator/bin
endif

ifeq ($(PROGRAMMER_BIN),)
PROGRAMMER_BIN := $(CYPRESS)/Programmer
endif

CYPRJMGR     = /usr/bin/env PATH=$(PATH):$(CREATOR_BIN) cyprjmgr
CYCREATOR    = /usr/bin/env PATH=$(PATH):$(CREATOR_BIN) psoc_creator
CYPROGRAMMER = /usr/bin/env PATH=$(PATH):$(PROGRAMMER_BIN) PSoCProgrammer

PROJECT_NAME = $(basename $(notdir $(wildcard ../*.cywrk)))
PROJECT      = $(realpath $(wildcard ../*.cywrk))

CONFIGURATION= Debug
OBJDIR       = ./CortexM3/ARM_GCC_484/$(CONFIGURATION)
HEXFILE      = $(realpath $(OBJDIR)/$(PROJECT_NAME).hex)

build:
	$(CYPRJMGR) -w $(PROJECT) -build

rebuild:
	$(CYPRJMGR) -w $(PROJECT) -rebuild

clean:
	$(CYPRJMGR) -w $(PROJECT) -clean

list:
	$(CYPRJMGR) -w $(PROJECT) -list

ide:
	$(CYCREATOR) $(PROJECT) &

flash:
	$(CYPROGRAMMER) $(HEXFILE) &
