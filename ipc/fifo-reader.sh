#!/bin/bash

# Configuration
FIFO_PATH="/tmp/myfifo"

while true
do
	read -r line < $FIFO_PATH
	if [ -n "$line" ]
	then
		echo "Recived message: $line"
		sed -i -e "1d" $FIFO_PATH
	fi 

done
