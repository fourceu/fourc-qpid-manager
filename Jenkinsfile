def compilers = ['g++', 'clang++']
def create_unittest_build(String compiler, String buildSubdir) {
  return {
    node ('ubuntu64') {
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
  node {
    stage('Documentation') {
      checkout scm

      dir ('build') {
        sh "cmake -DBUILD_DOCUMENTATION=on .."
        sh "make doc"
        archiveArtifacts artifacts: 'doc/', fingerprint: false
      }
    }
  }
}
executions['coverage'] = {
  node ('ubuntu64') {
    stage('Coverage') {
      checkout scm

      dir ('build') {
        sh "cmake -DBUILD_COVERAGE=on .."
        sh "make -j\$((2*\$(getconf _NPROCESSORS_ONLN)))"
        sh "make coverage"
        archiveArtifacts artifacts: 'unit_test_coverage/', fingerprint: false
      }
    }
  }
}

timestamps {
  parallel executions
}
