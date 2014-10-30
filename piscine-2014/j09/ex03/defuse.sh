#!/bin/sh
stat -r bomb.txt | cut -d\  -f 9 | awk '{ print $0 - 1; }'
