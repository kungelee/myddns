# myddns
windres ddns.rc -O coff -o my.res
gcc ddns.c my.res -o ddns
