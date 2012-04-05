#!/bin/sh

clear
set -e

if [ ! -f "$1" ]; then
	echo "Source $1 not found"
	exit 1
fi

bname="`basename "$1" .cpp`.bin"
iname="`basename "$1" .cpp`.input"

g++ -Wall -std=c++0x -o "$bname" "$1" 2>&1 | more

if [ -x "$bname" ]; then
	shift
	echo "args = $@"

	if [ -e "$iname" ]; then
		echo "Using $iname as stdin"
		"./$bname" "$@" < "$iname"
	else
		"./$bname" "$@"
	fi

	rm -f "$bname"
fi
