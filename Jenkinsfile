pipeline {
    agent any

    stages {
stage('Checkout'){
steps{

echo "cloning repo  fro m  branch \n"

deleteDir()
git branch : 'smartpointers',
url :  'git@github.com:pashi44/cpptemp.git'

}


}


stage('Build') {
steps {
script {
                    // Run the build command
sh '''
 chmod +x script.sh
./script.sh

   
'''
        }
    }
}

}
}
