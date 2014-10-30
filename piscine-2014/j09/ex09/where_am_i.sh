#!/bin/sh
ifconfig | grep "inet " | cut -d\  -f 2 | sed 1,1d | grep . || echo 'Je suis perdu!'
