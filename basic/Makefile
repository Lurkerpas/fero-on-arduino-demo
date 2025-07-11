.PHONY=all

all: work\build\node_1\partition_1

work\build\node_1\partition_1:
	arduino-cli compile --fqbn arduino:avr:uno \
	--output-dir binaries \
	--build-property "compiler.c.extra_flags= \
	-I../fero\src \
	-Iwork/dataview/C \
	-Iwork/build \
	-Iwork/build/system_spec \
	-Iwork/build/node_1/partition_1 \
	-Iwork/function1/implem/default/C/src \
	-Iwork/function1/implem/default/C/wrappers \
	" \
	work/build/node_1/partition_1