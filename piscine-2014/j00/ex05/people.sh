#!/bin/sh
ldapsearch -xLLL objectClass=apple-user uid | grep '^uid: .*$' | cut -d\  -f 2 | sort -rf
