/* File generated by kazoo for TASTE - do not edit */

#include "routing.h"

#include <RoutingHelper.h>

void initialize_routing() {
    
    
    // Initialize routing table of function corecomponent
    
    corecomponent_computep_set_all_routes_enabled(true);
    corecomponent_computeup_set_all_routes_enabled(true);
    corecomponent_tm_set_all_routes_enabled(true);
    
    
    
    // Initialize routing table of function orchestratorcomponent
    
    orchestratorcomponent_tc_set_all_routes_enabled(true);
    
    
    
    
    
}
