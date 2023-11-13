#!/bin/bash

#include colors lib
source $HOME/source/applegame/lib/colors.sh

bin_name=applegame
FILE=$HOME/source/applegame/build/bin/$bin_name
#remove old bin file
clear
echo -e "${LYELLOW} remove bin files ${NORMAL}"
rm $HOME/source/applegame/build/bin/$bin_name
if test -f $HOME/source/applegame/build/bin/applegame
then
echo -e "${GREEN} $bin_name deleted. ${NORMAL}"
else
echo -e "${BGRED}${BLACK} $bin_name don't exists!${NORMAL}"
fi 
#build new version
cd $HOME/source/applegame/build/
cmake --build .
if test -f $HOME/source/applegame/build/bin/applegame
then
echo -e "${GREEN} $FILE exists.${NORMAL}"
cp -f $HOME/source/applegame/build/bin/applegame $HOME/source/applegame/bin/latest/
# execute build version
cd $HOME/source/applegame/build/bin/ 
./applegame
else
echo -e "${BGRED}${BLACK}Programs not compiling!!! $FILE NOT exists!!!${NORMAL}"
fi

