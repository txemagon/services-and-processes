#!/bin/bash
# hexadecimalize.sh

relative_path="`dirname "$0"`"

if [ $# -ne 1 ]; then
  for f in "$@"
  do
  width=`"$relative_path"/width_of "$f"`
  height=`"$relative_path"/height_of "$f"`
    echo -n "$f: " 
    echo "obase=16; ibase=2; `$relative_path/binarize.sh "$f" | tr -d "\n"` " | bc | xargs $relative_path/normalize.sh $width $height 
  done
else
  width=`"$relative_path"/width_of "$1"`
  height=`"$relative_path"/height_of "$1"`
    echo "obase=16; ibase=2; `$relative_path/binarize.sh "$1" | tr -d "\n"` " | bc | xargs $relative_path/normalize.sh $width $height
fi
