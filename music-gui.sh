#!/bin/sh

musicgui="/home/root/buttonGUI"
GUI_OPTS="-qws"
PIDFILE="/var/run/music-gui.pid"

test -x "$musicgui" || exit 0

if [ -e $PIDFILE ]; then
      PIDDIR=/proc/$(cat $PIDFILE)
      if [ -d ${PIDDIR} -a  "$(readlink -f ${PIDDIR}/exe)" = "${matrixgui}" ]; then
        echo "$DESC already started; not starting."
      else
        echo "Removing stale PID file $PIDFILE."
        rm -f $PIDFILE
      fi
fi

echo -n "Starting Music GUI application"
start-stop-daemon --start --quiet --background -m --pidfile $PIDFILE --exec $musicgui -- $GUI_OPTS 
echo "."
exit 0