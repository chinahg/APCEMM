if(EXISTS "/home/chinahg/GCresearch/APCEMM/Code.v05-00/tests/unittest_tests-b12d07c.cmake")
  include("/home/chinahg/GCresearch/APCEMM/Code.v05-00/tests/unittest_tests-b12d07c.cmake")
else()
  add_test(unittest_NOT_BUILT-b12d07c unittest_NOT_BUILT-b12d07c)
endif()