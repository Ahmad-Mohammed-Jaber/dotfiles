#!/bin/bash

CURR_LANG="$(setxkbmap -print | grep xkb_symbols | awk '{print $4}' | awk -F"+" '{print $2}')"
US="us"

if [ $CURR_LANG == $US ]
then
	setxkbmap ara
else
	setxkbmap us
fi