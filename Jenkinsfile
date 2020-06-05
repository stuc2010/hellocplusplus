pipeline{
    agent any

    stages {
        stage('Configure') {
            steps{
                // cmake(
                //     arguments: '-B build',
                //     installation: 'AutoInstall'
                // )
                cmakeBuild(
                    generator: 'Unix Makefiles',
                    buildDir: 'build',
                    buildType: 'Release',
                    sourceDir: '.',
                    cleanBuild: true,
                    steps: [[args: '-B build'], [withCmake: true]],
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