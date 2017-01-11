timestamps {

parallel 'unit-tests' : {
  node ('remote') {
    stage('SCM (tests)') {
      checkout scm
    }

    stage('Build (tests)') {
      dir ('build') {
        sh "cmake .."
        sh "make -j\$((2*\$(getconf _NPROCESSORS_ONLN)))"
      }
    }

    stage('Unit tests') {
      dir ('build') {
        sh "make test"
        junit 'tests/unittests/test_detail.xml'
      }
    }
  }
}, 'doc' : {
  node ('local') {
    stage('SCM (doc)') {
      checkout scm
    }

    stage('Docs') {
      dir ('build')  {
        sh "cmake -DBUILD_DOCUMENTATION=on .."
        sh "make doc"
        archiveArtifacts artifacts: 'doc/', fingerprint: false
      }
    }
  }
}, 'coverage' : {
  node ('remote') {
    stage('SCM (cov)') {
      checkout scm
    }

    stage('Build (cov)') {
      dir ('build') {
        sh "cmake -DCMAKE_VERBOSE_MAKEFILE=on -DBUILD_COVERAGE=on .."
        sh "make -j\$((2*\$(getconf _NPROCESSORS_ONLN)))"
      }
    }

    stage('Coverage') {
      dir ('build') {
        sh "make coverage"
        junit 'tests/unittests/test_detail.xml'
        archiveArtifacts artifacts: 'unit_test_coverage/', fingerprint: false
      }
    }
  }
}

}
