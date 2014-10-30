#!/bin/sh
FT_USER=kperreau | groups $FT_USER | sed 's/ /,/g' | tr -d "\n"
