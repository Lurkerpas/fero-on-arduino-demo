.PHONY=all clean qemu

PARTITION_NAME=partition_1
SKETCH_DIR=work/sketch/partition_1
BINARIES_DIR=work/binaries
BINARY=${BINARIES_DIR}/partition_1.ino.with_bootloader.bin

all: ${BINARY}

clean:
	rm -r -f ${BINARIES_DIR}
	rm -r -f ${SKETCH_DIR}

${SKETCH_DIR}:
	mkdir -p ${SKETCH_DIR}
	cp ../fero/src/*.* ${SKETCH_DIR}
	cp work/dataview/C/*.* ${SKETCH_DIR}
	cp work/function1/implem/default/C/src/*.* ${SKETCH_DIR}
	cp work/function1/implem/default/C/wrappers/*.* ${SKETCH_DIR}
	cp work/build/node_1/partition_1/*.* ${SKETCH_DIR}
	cp work/build/system_spec/*.* ${SKETCH_DIR}
	cp work/build/*.* ${SKETCH_DIR}
	sed -i 's|../../||g' ${SKETCH_DIR}/*.h

${BINARIES_DIR}:
	mkdir -p ${BINARIES_DIR}

${BINARY}: ${SKETCH_DIR} ${BINARIES_DIR}
	arduino-cli compile --fqbn arduino:avr:uno \
	--output-dir ${BINARIES_DIR} \
	--build-property "build.extra_flags= \
	-I${SKETCH_DIR} \
	" \
	${SKETCH_DIR}
	

qemu: ${BINARY}
	qemu-system-avr -machine uno -nographic -bios ${BINARY}
