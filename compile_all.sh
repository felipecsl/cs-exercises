#!/bin/sh

for f in *.cpp; do
	./go.sh "$f"
	echo
	echo "$f"
	sleep 1
done
