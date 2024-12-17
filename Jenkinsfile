pipeline {
    agent any

    stages {
stage('Checkout'){
steps{

echo "cloning repo  fro m  branch \n"
git branch : 'smartpointers',
url :  'git@github.com:pashi44/cpptemp.git'

}


}


        stage('Build') {
            steps {
                script {
                    // Run the build command
                    sh '''
        
./scripr.sh

   
'''
        }
    }
}

  post {
        success {
            echo 'Build completed successfully!'
        }
        failure {
            echo 'Build failed. Check the logs for details.'
        }
    }


}




