#!/bin/bash

NUM=4
if [ $# != 0 ]
then
	NUM=$1
fi

make bonus -j8
./so_long_bonus map/bonus_map/map.ber $NUM

