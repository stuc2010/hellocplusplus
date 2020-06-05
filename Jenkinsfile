pipeline{
    agent any
    options {
        buildDiscarder(logRotater(numToKeepStr: '10'))
        skipDefaultCheckout(true)
        disableConcurrentBuilds()
    }

    stages {
        stage('Build') {
            steps{
                cmake arguments: '-G "Unix Makefiles" -d CMAKE_BUILD_TYPE=Release -H ./ -B ./build', installation: 'AutoInstall'
                cmakeBuild buildType: 'Release', cleanBuild: true, installation: 'AutoInstall', steps[[withCmake: true]] 
            }
        }

        stage('Test') {
            steps {
                ctest arguments: '-T test --no-compress-output', installation: 'AutoInstall'
            }
        }
    }

    post {
        always {
            archiveArtifacts(
                artifacts: 'build/Testing/**/*.xml', 'build/Hello', fingerprint: true
            )
        }
    }
}