#!/bin/bash
# visualize.sh

char_orig=`echo -ne $2 | xxd -ps | sed 's/\(..\)/\\\\x\1/g'`
char_new=`echo -ne $3 | xxd -ps | sed 's/\(..\)/\\\\x\1/g'`
sed "s/${char_orig}/${char_new}/g" < $1
