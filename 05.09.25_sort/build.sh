CPP_FILES="io.cpp merge_sort.cpp main.cpp"
APP=bin/example

if [ -f $APP ]; then rm $APP
fi

g++ $CPP_FILES -o $APP

./$APP
