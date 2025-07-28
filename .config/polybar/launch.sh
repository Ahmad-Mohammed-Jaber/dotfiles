#!/usr/bin/env bash

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -u $UID -x polybar >/dev/null; do sleep 1; done

dir="$HOME/.config/polybar"

echo "---" | tee -a /tmp/polybar.log 

# Launch Polybar on all connected monitors
if type "xrandr" >/dev/null; then
  for monitor in $(xrandr --query | grep " connected" | cut -d" " -f1); do
    echo "Launching Polybar on monitor: $monitor" | tee -a /tmp/polybar.log
    
    # Assign different workspace ranges based on monitor
    if [ "$monitor" = "HDMI-1" ]; then
      MONITOR="$monitor" polybar -q main -c "$dir/config.ini" 2>&1 | tee -a /tmp/polybar.log & disown
    elif [ "$monitor" = "eDP-1" ]; then
      MONITOR="$monitor" polybar -q main -c "$dir/config.ini" 2>&1 | tee -a /tmp/polybar.log & disown
    else
      # Fallback for other monitors (if any)
      MONITOR="$monitor" polybar -q main -c "$dir/config.ini" 2>&1 | tee -a /tmp/polybar.log & disown
    fi
  done
else
  # Fallback if xrandr is not available (single monitor)
  polybar -q main -c "$dir/config.ini" 2>&1 | tee -a /tmp/polybar.log & disown
fi

echo "Bars launched..."