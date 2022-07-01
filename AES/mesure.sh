#!/bin/bash

victime=victimeProcess
spy=spyProcess
client=clientProcess

#cleaning directory containing the trace
rm -rf out
mkdir out

#other clients for realistic attack
#for i in $(seq 1 2);
#do
#      ./$client &
#      echo "Client start "
#done

#spy program
./$spy > ./out/mesure.txt
echo "End probing"