CPP_FILES="menu_functions.cpp menu_items.cpp main.cpp"
APP=bin/example

if [ ! -d "bin" ]; then
    mkdir -p bin
fi

if [ -f $APP ]; then 
    rm $APP
fi

g++ $CPP_FILES -o $APP

./$APP