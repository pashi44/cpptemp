pipeline {

  agent any
  stages {
    stage('build') {
      steps {
        sh '''

  agent {
    node {
      label 'mac'
    }

  }
  stages {
    stage('build') {
      steps {
        sh '''
        
        #! /bin/bash



# Define the directory name
BUILD_DIR="build"

# Check if the directory exists, if not, create it
if [ ! -d "$BUILD_DIR" ]; then
    echo "Directory \'$BUILD_DIR\' does not exist. Creating it now."
    mkdir "$BUILD_DIR"
else
    echo "Directory \'$BUILD_DIR\' already exists."
fi

# Change to the build directory
cd "$BUILD_DIR" || { echo "Failed to enter directory \'$BUILD_DIR\'"; exit 1; }




cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -S  .. -B .

# Build the project
echo "Building the project..."
make

# Check if make was successful
if [ $? -eq 0 ]; then
    echo "Build completed successfully."
else
    echo "Build failed. Check the output for errors."
    exit 1
fi
'''
      }
    }

  }
}
