pipeline{
    agent any
    tools {
        CMake
    }
    options {
        buildDiscarder(logRotater(numToKeepStr: '10'))
        skipDefaultCheckout(true)
        disableConcurrentBuilds()
    }

    stages {
        stage('Configure') {
            steps{
                dir('build') {
                    sh 'cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Release ../'
                }
            }
        }

        stage('build') {
            steps{
                dir('build') {
                    sh 'ctest -T test --no-compress-output'
                }
            }
        }
    }

    post {
        always {
            archiveArtifacts(
                artifacts: 'build/Hello', 
                fingerprint: true
            )
            archiveArtifacts(
                artifacts: 'build/Testing/**/*.xml',
                fingerprint: true
            )
        }
    }
}