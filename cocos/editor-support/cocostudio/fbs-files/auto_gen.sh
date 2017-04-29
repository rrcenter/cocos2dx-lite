#!/bin/sh

# 2017-04-30 Jimmy Yin

./flatc -o ../WidgetReader/SkeletonReader/ -c CSBoneBinary.fbs
./flatc -o ../WidgetReader/TabControlReader -c CSTabControl.fbs
./flatc -o ../WidgetReader/ArmatureNodeReader/ -c CSArmatureNode.fbs

./flatc -o .. -c CSLanguageDataBinary.fbs CSParseBinary.fbs
#./flatc -o .. -c CSParse3DBinary.fbs


