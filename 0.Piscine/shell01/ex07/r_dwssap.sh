#!/bin/sh

cat /etc/passwd | sed 's/:.*//' | sed -n 'n;p'| rev | sort -r | sed -n "7,15p" | tr '\n' ", " | sed 's/.$/./'
