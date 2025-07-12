.PHONY=all clean qemu

all: work\build\node_1\partition_1

clean:
	rm -r -f binaries

work\build\node_1\partition_1:
	arduino-cli compile --fqbn arduino:avr:uno \
	--output-dir binaries \
	--build-property "compiler.c.extra_flags= \
	-I../fero/src \
	-Iwork/dataview/C \
	-Iwork/build \
	-Iwork/build/system_spec \
	-Iwork/build/node_1/partition_1 \
	-Iwork/function1/implem/default/C/src \
	-Iwork/function1/implem/default/C/wrappers \
	" \
	--build-property "build.extra_flags= \
	-I../fero/src \
	-Iwork/dataview/C \
	-Iwork/build \
	-Iwork/build/system_spec \
	-Iwork/build/node_1/partition_1 \
	-Iwork/function1/implem/default/C/src \
	-Iwork/function1/implem/default/C/wrappers \
	" \
	work/build/node_1/partition_1

qemu: work\build\node_1\partition_1
	qemu-system-avr -machine uno -nographic -bios binaries/partition_1.ino.with_bootloader.bin
