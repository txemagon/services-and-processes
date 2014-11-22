#!/bin/bash
# binarize.sh

relative_path="`dirname "$0"`"


if [ $# -ne 1 ]; then
  for f in "$@"
  do
    echo "$f: " 
    $relative_path/visualize.sh $1 █ 1 | head -`"$relative_path"/height_of "$1"` | tr ' ' 0
    echo 
  done
else
  $relative_path/visualize.sh $1 █ 1 | head -`"$relative_path"/height_of "$1"` | tr ' ' 0
fi
