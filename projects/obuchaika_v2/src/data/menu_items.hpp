#pragma once

#include "exit_item.hpp"
#include "goback_item.hpp"
#include "long_division_item.hpp"

namespace IBusko {
    extern const MenuItem MAIN;

    extern const MenuItem STUDY;
    extern const ExitItem EXIT;
	
	extern const MenuItem STUDY_LONG;
	extern const MenuItem STUDY_COMPLEX;
    extern const GoBackItem STUDY_GO_BACK;
	
	extern const LongDivisionItem LONG_DIVISION;
    extern const GoBackItem LONG_GO_BACK;
	
    extern const GoBackItem COMPLEX_GO_BACK;
}
