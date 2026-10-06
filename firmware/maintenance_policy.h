#pragma once
#include <cmath>
#include <cstdint>
struct MaintenancePolicy {
 float baseline=0;uint16_t samples=0;uint8_t rising=0;bool warning=false;
 void feed(float amps){
  if(!std::isfinite(amps)||amps<0||amps>0.5f){warning=true;return;}
  if(samples<20){baseline+=amps/20.0f;samples++;return;}
  if(amps>0.25f&&amps>baseline*1.5f){if(rising<3)rising++;if(rising>=3)warning=true;}
  else rising=0;
 }
 bool ready()const{return samples>=20&&!warning;}
 void reset(){baseline=0;samples=0;rising=0;warning=false;}
};

inline MaintenancePolicy& maintenancePolicy(){static MaintenancePolicy policy;return policy;}
