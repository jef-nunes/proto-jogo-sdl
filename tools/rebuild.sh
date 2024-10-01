#!/bin/bash

# Set the local project path
project_dir=$(dirname "$0")/..
bin_dir="$project_dir/bin"
src_dir="$project_dir/src"

# Compile the project
gcc "$src_dir/main.c" "$src_dir/player.c" "$src_dir/renderer.c" "$src_dir/physics.c"  "$src_dir/level.c" -o "$project_dir/game.bin" -lSDL2 -lSDL2_image

if [ $? -eq 0 ]; then
    echo "Successful compilation"

    if [ "$1" == "run" ]; then
        echo "Running game"
        "$project_dir/game.bin"  # Execute the binary directly
    fi
else
    echo "Compilation failed."
fi
