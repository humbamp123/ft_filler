#!/bin/bash
filler_vm=resources/filler_vm
maps=resources/maps
map0=map00
map1=map01
map2=map02
players=resources/players
abanlin=abanlin.filler
carli=carli.filler
grati=grati.filler
hcao=hcao.filler
super=superjeannot.filler
fill=./filler
fightlist=(
  $abanlin
  $carli
  $grati
  $hcao
  $super
  )
function fight {
  M=0
while [  $M -lt 3 ]; do
  if [  $M == 2  ]; then
    MAXNUM=5
  else
    MAXNUM=10
  fi
  COUNTER=0
  WINCOUNTER=0
  while [  $COUNTER -lt $MAXNUM ]; do
    $filler_vm -f $maps/map0$M -p1 $fill -p2 $players/$1 2>&1 | grep "=="
    wait
    x=$( cat filler.trace | grep "won" )
    if [ "$x" == "./filler won" ]; then
      echo -e "\x1B[32mFiller Won\x1B[0m"
    let WINCOUNTER=WINCOUNTER+1
    else
      echo -e "\033[31mFiller lost\x1B[0m"
    fi
    let COUNTER=COUNTER+1 
  done
  echo -e "\x1B[32mFiller Won " $WINCOUNTER " / " $COUNTER " against " $1 " on " map0$M " as p1\x1B[0m"
  COUNTER=0
  WINCOUNTER=0
  while [  $COUNTER -lt $MAXNUM ]; do
    $filler_vm -f $maps/map0$M -p1 $players/$1 -p2 $fill 2>&1 | grep "=="
    wait
    x=$( cat filler.trace | grep "won" )
    if [ "$x" == "./filler won" ]; then
      echo -e "\x1B[32mFiller Won\x1B[0m"
    let WINCOUNTER=WINCOUNTER+1
    else
      echo -e "\033[31mFiller lost\x1B[0m"
    fi
    let COUNTER=COUNTER+1 
  done
  echo -e "\x1B[32mFiller Won " $WINCOUNTER " / " $COUNTER " against " $1 " on " map0$M " as p2\x1B[0m"
  let M=M+1
done
}
COUNT=0
while [[ COUNT -lt 5 ]]; do
  fight ${fightlist[COUNT]}
  let COUNT=COUNT+1
done
