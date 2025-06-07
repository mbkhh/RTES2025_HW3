#!/bin/bash

# Configuration
SSID="MySSID"
WIFI_PASSWORD="qwertyuiop"
INTERFACE="wlan0"
LOGFILE="/home/orangepi/emb/auto-connect.log"  # Absolute path for cron
timestamp=$(date)

if nmcli -t -f GENERAL_STATE device show "wlan0" | grep -q "(disconnected)"; then
    nmcli device wifi connect "$ssid" password "$pass"
fi

# Log WiFi status information
{
    echo "=== WiFi Status Report - $timestamp ==="
    echo "=== Current Status ==="
    nmcli device status

    echo "=== Available Networks ==="
    nmcli device wifi list
} >> "$LOGFILE"

