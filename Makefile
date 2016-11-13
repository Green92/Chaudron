APP = Chaudron

include $(SDK_DIR)/Makefile.defs

OBJS = $(ASSETS).gen.o main.o
ASSETDEPS += assets/*.png $(ASSETS).lua

#Definit la variable globale CUBE_ALLOCATION
CCFLAGS += -DCUBE_ALLOCATION=12

# build assets.html to proof stir-processed assets.
# comment out to disable.
ASSETS_BUILD_PROOF := yes

include $(SDK_DIR)/Makefile.rules

run: $(APP).elf
		Siftulator.exe -n 6 $(APP).elf
