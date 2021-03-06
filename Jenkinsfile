#!/usr/bin/env groovy

properties([
        [$class: 'ParametersDefinitionProperty', parameterDefinitions: [
                [$class: 'BooleanParameterDefinition', defaultValue: false, description: 'Build Integration Tests', name: 'integrationTests']
        ]]
])
def integrationTests = (env.integrationTests == "true")

def compilers = ['g++-9', 'clang++-9']
def create_unittest_build(String compiler, String buildSubdir) {
  return {
    node ('ubuntu64' && 'gcc9' && 'clang9') {
      stage("Unit Tests (${compiler})") {
        checkout scm

        dir (buildSubdir) {
          sh "cmake -DCMAKE_CXX_COMPILER=${compiler} .."
          sh "make -j\$((2*\$(getconf _NPROCESSORS_ONLN)))"
          sh "make test"
          junit 'tests/unittests/test_detail.xml'
        }
      }
    }
  }
}

def executions = [:]
for(int i = 0; i < compilers.size(); i++) {
  executions['unittest-' + compilers[i]] = create_unittest_build(compilers[i], 'build')
}
executions['doc'] = {
  node ('ubuntu64' && 'gcc9' && 'clang9') {
    stage('Documentation') {
      checkout scm

      dir ('build') {
        sh "cmake -DBUILD_DOCUMENTATION=on -DCMAKE_CXX_COMPILER=g++-9 .."
        sh "make doc"
        archiveArtifacts artifacts: 'doc/', fingerprint: false
      }
    }
  }
}
executions['coverage'] = {
  node ('ubuntu64' && 'gcc9' && 'clang9') {
    stage('Coverage') {
      checkout scm

      dir ('build') {
        sh "cmake -DBUILD_COVERAGE=on -DCMAKE_CXX_COMPILER=g++-9 .."
        sh "make -j\$((2*\$(getconf _NPROCESSORS_ONLN)))"
        sh "make coverage"
        archiveArtifacts artifacts: 'unit_test_coverage/', fingerprint: false
      }
    }
  }
}
if (integrationTests) {
  executions['integration'] = {
    node ('ubuntu64' && 'gcc9' && 'clang9') {
      stage('Integration Tests') {
        checkout scm

        dir ('build') {
          try {
            sh "qpidd -q"
            sh "cmake -DBUILD_SYSTEM_TESTS=on -DCMAKE_CXX_COMPILER=g++-9 .."
            sh "make -j12 test cxxsystemtest"
          } finally {
            junit "tests/systemtests/test_detail.xml"
            sh "qpidd -q"
          }
        }
      }
    }
  }
}

timestamps {
  parallel executions
}
