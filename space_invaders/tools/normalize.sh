#!/bin/bash
# normalize.sh

relative_path="`dirname "$0"`"
# 
# echo  " `"$relative_path"/width_of "$1"` * `"$relative_path"/height_of "$1"` / 4 " | bc | xargs $relative_path/norma `"$relative_path"/hexadecimalize.sh "$1"` 
# 

echo "$1 * $2 / 4" | bc | xargs $relative_path/norma $3
