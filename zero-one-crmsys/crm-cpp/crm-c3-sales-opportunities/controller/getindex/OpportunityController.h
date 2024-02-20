#ifndef _OPPORTUNITYCONTROLLER_H_
#define _OPPORTUNITYCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/getindex/OpportunityDTO.h"
#include "domain/vo/getindex/OpportunityVO.h"
#include "domain/query/getindex/OpportunityQuery.h"
#include "ApiHelper.h"
#include "Macros.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

//导出销售机会接口实现
class OpportunityController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(OpportunityController);
public:     //定义接口

	//导出销售机会
	// 定义导出销售机会接口描述
	ENDPOINT_INFO(queryExportSalOpp) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.export-sales-opportunity"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义销售机会查询参数描述
		API_DEF_ADD_QUERY_PARAMS(Int16, "chance_id", ZH_WORDS_GETTER("opportunities.field.cst_chance.chance_id"), 1, false);
	}

	ENDPOINT(API_M_GET, "/sales-opportunities/export-sales-opportunity", queryExportSalOpp, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数queryParams为ExportSupLinkmanQuery类型
		API_HANDLER_QUERY_PARAM(query, OpportunityQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryExportSalOpp(query, authObject->getPayload()));
	}

private:    //定义执行函数
	StringJsonVO::Wrapper execQueryExportSalOpp(const OpportunityQuery::Wrapper& query, const PayloadDTO& payload);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_OPPORTUNITYCONTROLLER_H_
