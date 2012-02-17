// this program is automatically generated. do not edit. 
#include "keeper.hpp"
#include "stat_types.hpp"

using namespace jubatus;

using namespace jubatus::framework;

int main(int args, char** argv){
  keeper k(keeper_argv(args, argv));
  k.register_broadcast_update<config_data>("set_config");
  k.register_cht_update<double>("push");
  k.register_cht_analysis<double, int>("sum");
  k.register_cht_analysis<double, int>("stddev");
  k.register_cht_analysis<double, int>("max");
  k.register_cht_analysis<double, int>("min");
  k.register_cht_analysis<double, int>("entropy");
  k.register_cht_analysis<double, std::pair<int, double> >("moment");
  k.register_broadcast_analysis<int, std::string>("save");
  k.register_broadcast_update<std::string>("load");
  k.register_broadcast_analysis<std::map<std::string, std::map<std::string, std::string> > , int>("get_status");
  k.run();
}
