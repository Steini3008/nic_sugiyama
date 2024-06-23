#include <LEDA/graphics/graphwin.h>

#include "SUGIPROJ/sugiyama.h"
#include "SUGIPROJ/steps/step.h"
#include "SUGIPROJ/steps/leveling.h"
#include "SUGIPROJ/steps/cycle_breaking.h"

int main() {
    leda::GraphWin gw {};
    gw.display();

	while (gw.edit()) {
		sugi::sugiyama sg {gw};    
        sg.add(new sugi::cycle_breaking{});
        sg.add(new sugi::leveling{});
        sg.run();
	}
    
    return 0;
}