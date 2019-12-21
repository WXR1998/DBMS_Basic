#!/bin/bash

if [ $# -gt 0 ]; then
    if [ $1 = "all" ]; then
        cd src/parser
        make
        cd ../..
        cd build
        cmake ..
        make
        ./database
    elif [ $1 = "run" ]; then
        cd build
        ./database
    elif [ $1 = "clean" ]; then
        rm -r build/*
    elif [ $1 = "help" ]; then
        echo "Parameter must be 'help', 'all', 'run' or 'clean'."
        echo "Sample: >> ./run.sh run"
        echo "ALL means compile full project and run the database. This command REQUIRES yacc and flex installed."
        echo "RUN means only run the database."
        echo "CLEAN means delete all the files generated."
    else
        echo "Parameter must be 'help', 'run' or 'clean'."
    fi
fi