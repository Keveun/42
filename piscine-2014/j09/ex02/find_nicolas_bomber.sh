#!/bin/sh
cat $1 | grep -iE "^nicolas" | grep -iE ".*\tbomber" | cut -d$'\t' -f 3 | sed -n 1p
