#!/bin/sh

clear
set -e

ename="$1"

if [ -z "$ename" ] || [ ! -d "$ename" ]; then
	echo "Exercise $ename not found"
	exit 1
fi

tmpdir="tmp/$ename"

if [ -d "$tmpdir" ]; then
	rm -rf "$tmpdir"
fi
mkdir -p "$tmpdir"

bname="$tmpdir/$ename.bin"
g++ -Wall -std=c++0x -O0 -g -o "$bname" $ename/*.cpp 2>&1 | more

set +e
if [ -x "$bname" ]; then
	shift
	echo "args = $@"

	input_found=0
	for iname in $ename/*.input; do
		input_found=1
		echo "Using $iname as stdin"
		"./$bname" "$@" < "$iname"
	done

	if [ ! "$input_found" ]; then
		"./$bname" "$@"
	fi
fi
