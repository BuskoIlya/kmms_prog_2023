#include "menu_items.hpp"

namespace IBusko {
	const GoBackItem LONG_NUMBER_GO_BACK("0 - Выйти в предыдущее меню", &STUDY_LONG_NUMBER);
	const LongNumberDivisionItem LONG_NUMBER_DIVISION("1 - Заниматься делением", &STUDY_LONG_NUMBER);
	namespace {
		const MenuItem* const long_number_children[] = {
			&LONG_NUMBER_GO_BACK,
			&LONG_NUMBER_DIVISION
		};
		const int long_number_size = sizeof(long_number_children) / sizeof(long_number_children[0]);
	}
	
	const GoBackItem COMPLEX_NUMBER_GO_BACK("0 - Выйти в предыдущее меню", &STUDY_COMPLEX_NUMBER);
	namespace {
		const MenuItem* const complex_number_children[] = {
			&COMPLEX_NUMBER_GO_BACK
		};
		const int complex_number_size = sizeof(complex_number_children) / sizeof(complex_number_children[0]);
	}
	
	const GoBackItem STUDY_GO_BACK("0 - Выйти в главное меню", &STUDY);
	const MenuItem STUDY_LONG_NUMBER(
		"1 - Заниматься длинной арифметикой", 
		&STUDY,
		long_number_children,
		long_number_size
	);
	const MenuItem STUDY_COMPLEX_NUMBER(
		"2 - Заниматься арифметикой комплексных чисел", 
		&STUDY,
		complex_number_children,
		complex_number_size
	);
	
	namespace {
		const MenuItem* const study_children[] = {
			&STUDY_GO_BACK,
			&STUDY_LONG_NUMBER,
			&STUDY_COMPLEX_NUMBER
		};
		const int study_size = sizeof(study_children) / sizeof(study_children[0]);
	}
	
	const MenuItem STUDY("1 - Хочу учиться математике!", &MAIN, study_children, study_size);
	const ExitItem EXIT("0 - Я лучше пойду полежу...", &MAIN);

	namespace {
		const MenuItem* const main_children[] = {
			&EXIT,
			&STUDY
		};
		const int main_size = sizeof(main_children) / sizeof(main_children[0]);
	}

	const MenuItem MAIN(main_children, main_size);	
}
