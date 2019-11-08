USE_G413229_XLIB_RAWMOUSE ?= FALSE ## Set this to TRUE if you want to use the new Xlib RawMouse class
USE_G413229_MWF_WORKAROUNDS ?= TRUE ## Set this to FALSE to not apply 413229's workarounds

## [gdm413229] for building those Visplane Explorer natives!

VPO_NAME:= Build/libvpo_dll.so
VPO_CXXFLAGS := -O3 -fPIC -DLINUX -g3 -I $(VPO_SRCPREFIX)
VPO_LDFLAGS := --shared -ldl
VPO_SRCPREFIX :=Source/Plugins/vpo_dll
VPO_INCLUDE := $(wildcard Source/Plugins/vpo_dll/*.h)
VPO_SRC := $(wildcard Source/Plugins/vpo_dll/*.cc)
VPO_OBJS := $(VPO_SRC:.cc=.o)

all: builder native

builder:
	msbuild -p:Configuration=Debug BuilderMono.sln

## Makefile targets for Visplane Explorer natives, added by gdm413229

$(VPO_OBJS): $(VPO_INCLUDE) $(VPO_SRC)
	g++ $(VPO_CXXFLAGS) -c $(VPO_SRC)

$(VPO_NAME): $(VPO_OBJS)
	g++ $(VPO_LDFLAGS) $(VPO_OBJS) -o $(VPO_NAME)

vpo_natives: $(VPO_OBJS) $(VPO_NAME)

native:
	g++ -O2 --shared -g3 -o Build/libBuilderNative.so -fPIC -I Source/Native Source/Native/*.cpp Source/Native/gl_load/*.c -lX11 -ldl

.PHONY: vpo_natives
.NOTPARALLEL: vpo_natives