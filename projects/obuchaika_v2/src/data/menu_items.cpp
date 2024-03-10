#include "menu_items.hpp"

namespace IBusko {
	const GoBackItem STUDY_GO_BACK("0 - Выйти в главное меню", &STUDY);
	
	namespace {
		const MenuItem* const study_children[] = {
			&STUDY_GO_BACK
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
