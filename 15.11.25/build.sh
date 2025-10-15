MAIN=after_refractoring.cpp
APP=bin/example

if [ -f $APP ]; then rm $APP
fi

g++ $MAIN -o $APP

./$APP