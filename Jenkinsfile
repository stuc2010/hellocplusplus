pipeline{
    agent any
    options {
        buildDiscarder(logRotater(numToKeepStr: '10'))
        skipDefaultCheckout(true)
        disableConcurrentBuilds()
    }

    stages {
        stage('Configure') {
            steps{
                cmakeBuild(
                    installation: 'AutoInstall'
                )
            }
        }

        // stage('build') {
        //     steps{
        //         dir('build') {
        //             sh 'cmake --build .'
        //         }
        //     }
        // }
    }

    // post {
    //     always {
    //         archiveArtifacts(
    //             artifacts: 'build/Hello', 
    //             fingerprint: true
    //         )
    //         archiveArtifacts(
    //             artifacts: 'build/Testing/**/*.xml',
    //             fingerprint: true
    //         )
    //     }
    // }
}