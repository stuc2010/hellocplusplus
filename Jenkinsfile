pipeline{
    agent any

    stages {
        stage('Build') {
            steps{
                cmakeBuild(
                    generator: 'Unix Makefiles',
                    buildDir: 'build',
                    buildType: 'Release',
                    steps: [[withCmake: true]],
                    installation: 'AutoInstall'
                )
            }
        }

        stage('Test') {
            steps{
                ctest(
                    arguments: '-T test --no-compress-output',
                    installation: 'AutoInstall',
                    workingDir: 'build'
                )
            }
        }
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