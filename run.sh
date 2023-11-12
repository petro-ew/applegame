#!/bin/sh
cd ~/source/applegame/bin/
rm applegame
cd ~/source/applegame/build/
cmake --build ..
cd ~/source/applegame/bin/
./applegame
