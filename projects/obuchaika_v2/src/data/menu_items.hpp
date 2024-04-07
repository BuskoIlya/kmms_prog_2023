#pragma once

#include "exit_item.hpp"
#include "goback_item.hpp"
#include "long_number_division_item.hpp"

namespace IBusko {
    extern const MenuItem MAIN;

    extern const MenuItem STUDY;
    extern const ExitItem EXIT;
	
	extern const MenuItem STUDY_LONG_NUMBER;
	extern const MenuItem STUDY_COMPLEX_NUMBER;
    extern const GoBackItem STUDY_GO_BACK;
	
	extern const LongNumberDivisionItem LONG_NUMBER_DIVISION;
    extern const GoBackItem LONG_NUMBER_GO_BACK;
	
    extern const GoBackItem COMPLEX_NUMBER_GO_BACK;
}
