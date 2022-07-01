#!/bin/bash

#argument needed
if [ $# -eq 0 ]
  then
      echo " Specify where to store traces "
else
    #clean existing repository
    rm -r $1
    #copy trace to a local area to be analyzed
    scp -r root@192.168.0.16:/out ./$1
fi