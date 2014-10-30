
ldapsearch last-name | grep last-name: | cut -d\  -f 2 | grep -i '.*bon.*' | wc -l
