#!/bin/sh
cat /etc/passwd | grep '^[^+#]' | sed -n 'n;p' | cut -d: -f 1 | sed -n "$FT_LINE1, $FT_LINE2 p" | rev | sort -r | tr "\n" "," | sed 's/,$/./'
