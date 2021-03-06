// This file is auto-generated from recommender.idl
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>

#include <glog/logging.h>

#include "jubatus/core/common/exception.hpp"
#include "../../server/framework/aggregators.hpp"
#include "../../server/framework/keeper.hpp"
#include "recommender_types.hpp"

namespace jubatus {

int run_keeper(int argc, char* argv[]) {
  try {
    jubatus::server::framework::keeper k(
        jubatus::server::framework::keeper_argv(argc, argv, "recommender"));
    k.register_async_random<std::string>("get_config");
    k.register_async_cht<2, bool>("clear_row", pfi::lang::function<bool(bool,
         bool)>(&jubatus::server::framework::all_and));
    k.register_async_cht<2, bool, jubatus::core::fv_converter::datum>(
        "update_row", pfi::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_broadcast<bool>("clear", pfi::lang::function<bool(bool,
         bool)>(&jubatus::server::framework::all_and));
    k.register_async_cht<2, jubatus::core::fv_converter::datum>(
        "complete_row_from_id",
         pfi::lang::function<jubatus::core::fv_converter::datum(
        jubatus::core::fv_converter::datum,
         jubatus::core::fv_converter::datum)>(
        &jubatus::server::framework::pass<jubatus::core::fv_converter::datum>));
    k.register_async_random<jubatus::core::fv_converter::datum,
         jubatus::core::fv_converter::datum>("complete_row_from_datum");
    k.register_async_cht<2, similar_result, uint32_t>("similar_row_from_id",
         pfi::lang::function<similar_result(similar_result, similar_result)>(
        &jubatus::server::framework::pass<similar_result>));
    k.register_async_random<similar_result, jubatus::core::fv_converter::datum,
         uint32_t>("similar_row_from_datum");
    k.register_async_cht<2, jubatus::core::fv_converter::datum>("decode_row",
         pfi::lang::function<jubatus::core::fv_converter::datum(
        jubatus::core::fv_converter::datum,
         jubatus::core::fv_converter::datum)>(
        &jubatus::server::framework::pass<jubatus::core::fv_converter::datum>));
    k.register_async_broadcast<std::vector<std::string> >("get_all_rows",
         pfi::lang::function<std::vector<std::string>(std::vector<std::string>,
         std::vector<std::string>)>(
        &jubatus::server::framework::concat<std::string>));
    k.register_async_random<float, jubatus::core::fv_converter::datum,
         jubatus::core::fv_converter::datum>("calc_similarity");
    k.register_async_random<float, jubatus::core::fv_converter::datum>(
        "calc_l2norm");
    k.register_async_broadcast<bool, std::string>("save",
         pfi::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_broadcast<bool, std::string>("load",
         pfi::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_broadcast<std::map<std::string, std::map<std::string,
         std::string> > >("get_status",
         pfi::lang::function<std::map<std::string, std::map<std::string,
         std::string> >(std::map<std::string, std::map<std::string,
         std::string> >, std::map<std::string, std::map<std::string,
         std::string> >)>(&jubatus::server::framework::merge<std::string,
         std::map<std::string, std::string> >));
    return k.run();
  } catch (const jubatus::core::common::exception::jubatus_exception& e) {
    LOG(FATAL) << e.diagnostic_information(true);
    return -1;
  }
}

}  // namespace jubatus

int main(int argc, char* argv[]) {
  jubatus::run_keeper(argc, argv);
}
