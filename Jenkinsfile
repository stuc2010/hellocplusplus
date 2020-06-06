pipeline {

    agent any
    
    stages {
        stage('Build') {
            steps{
                // [SC 13:43 05-06-2020]: Can't get the plugin module to create the files into the build directory properly and reference it so manually invoking cmake twice.
                // cmakeBuild(
                //     generator: 'Unix Makefiles',
                //     buildDir: 'build',
                //     buildType: 'Release',
                //     cleanBuild: true,
                //     steps: [[args: '-B build'], [withCmake: true]],
                //     installation: 'AutoInstall'
                // )
                cmake(
                    installation: 'AutoInstall',
                    arguments: '-G "Unix Makefiles" -d CMAKE_BUILD_TYPE=Release -S .. -B .',
                    workingDir: 'build'
                )
                cmake(
                    installation: 'AutoInstall',
                    arguments: '--build .',
                    workingDir: 'build'
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

    post {
        always {
            archiveArtifacts(
                artifacts: 'build/Hello', 
                fingerprint: true
            )
            rtUpload(
                serverId: 'ArtifactoryPlayground',
                spec: """{
                    "files": [
                        {
                            "pattern": "build/Hello",
                            "target": "generic-local/CPlusPlus/Hello"
                        }
                    ]}"""
            )
            archiveArtifacts(
                artifacts: 'build/Testing/**/*.xml',
                fingerprint: true
            )

            xunit(
                testTimeMargin: '3000',
                thresholdMode: 1,
                thresholds: [
                    skipped(failureThreshold: '0'),
                    failed(failureThreshold: '0')
                ],
                tools: [CTest(
                    pattern: 'build/Testing/**/*.xml',
                    deleteOutputFiles: true,
                    failIfNotNew: false,
                    skipNoTestFiles: true,
                    stopProcessingIfError: true
                )]
            )
        }
    }
}