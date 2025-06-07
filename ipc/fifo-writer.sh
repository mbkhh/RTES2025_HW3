#!/bin/bash

# Configuration
FIFO_PATH="/tmp/myfifo"

[ -p "$FIFO_PATH" ] || touch "$FIFO_PATH"

while true
do
	read userText
	echo $userText>>$FIFO_PATH
done
