#!/bin/sh

for f in *; do
	if [ -d "$f" ]; then
		./go.sh "$f"
		echo
		echo "$f"
		sleep 1
	fi
done
