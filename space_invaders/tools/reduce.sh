#!/bin/bash
# reduce.sh

relative_path="`dirname "$0"`"

if [ $# -ne 1 ]; then
  for f in "$@"
  do
  width=`"$relative_path"/width_of "$f"`
    echo "$f: " 
    $relative_path/reduce `"$relative_path"/hexadecimalize.sh "$f"` $width
  done
else
  width=`"$relative_path"/width_of "$1"`
    $relative_path/reduce `"$relative_path"/hexadecimalize.sh "$1"` $width
fi
