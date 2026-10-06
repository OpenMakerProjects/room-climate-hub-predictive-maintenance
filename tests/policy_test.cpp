#include <cassert>
#include <limits>
#include "../firmware/maintenance_policy.h"
int main(){
 MaintenancePolicy p;for(int i=0;i<19;i++){p.feed(0.2f);}assert(!p.ready());p.feed(0.2f);assert(p.ready());
 p.feed(0.31f);p.feed(0.31f);assert(!p.warning);p.feed(0.2f);p.feed(0.31f);assert(!p.warning);
 p.feed(0.31f);p.feed(0.31f);assert(p.warning&&!p.ready());p.feed(0.1f);assert(p.warning);
 p.reset();assert(!p.warning&&p.samples==0);p.feed(std::numeric_limits<float>::quiet_NaN());assert(p.warning);
 p.reset();p.feed(-0.1f);assert(p.warning);p.reset();p.feed(0.51f);assert(p.warning);
}
