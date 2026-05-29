#! /bin/bash



BUILD_DIR="build"

if [ ! -d "$BUILD_DIR" ]; then
    echo "Directory '$BUILD_DIR' does not exist. Creating it now."
    mkdir "$BUILD_DIR"
else
    echo "Directory '$BUILD_DIR' already exists."
fi

cd "$BUILD_DIR" || { echo "Failed to enter directory '$BUILD_DIR'"; exit 1; }




cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -S  .. -B .


make

if [ $? -eq 0 ]; then
    echo "Build completed successfully."
else
    echo "Build failed. Check the output for errors."
    exit 1
fi
