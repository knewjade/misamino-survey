# File defines
set(misamino_survey_test_SOURCE_DIR ${misamino_survey_SOURCE_DIR}/test)

file(GLOB misamino_survey_test_SRC
        ${misamino_survey_test_SOURCE_DIR}/main.cpp
        ${misamino_survey_test_SOURCE_DIR}/*/*.cpp
        ${misamino_survey_test_SOURCE_DIR}/*/*/*.cpp
        )