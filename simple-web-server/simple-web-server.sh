#!/bin/bash

PORT=8080

echo "Listening on port $PORT"

while true; do
    	current_time=$(date)
	echo -e "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello! time is: $current_time" | nc -l -n -p "$PORT" -q 1 >/dev/null 
    	echo "Request received at $current_time"
done
