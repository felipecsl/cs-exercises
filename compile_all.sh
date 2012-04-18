#!/bin/sh

for f in *; do
	if [ "`basename "$f"`" != "partial" ] && [ "`basename "$f"`" != "tmp" ] && [ -d "$f" ]; then
		./go.sh "$f"
		echo
		echo "$f"
		sleep 1
	fi
done
