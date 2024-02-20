#ifndef _SALESOPPOCONTROLLER_H_
#define _SALESOPPOCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include"domain/dto/getindex/GetSalesOppoDTO.h"
#include "domain/query/getindex/GetSalesOppoQuery.h"
#include "domain/vo/getindex/GetSalesOppoVo.h"
#include "service/Sales/GetSalesOppoService.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) 

/**
 * 获取客户名称列表操作接口实现
 */
class GetSalesOppoController : public oatpp::web::server::api::ApiController //继承控制器
{
	// 定义控制器访问入口
	API_ACCESS_DECLARE(GetSalesOppoController);

public: //定义接口
	//获取销售机会名称列表

	ENDPOINT_INFO(querySalOppoNameList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("opportunities.controller.querySalOppoNameList"));	//目录名.controller.接口名称
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式	
		API_DEF_ADD_RSP_JSON_WRAPPER(GetSalesOppoJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("opportunities.field.cst_chance.name"), "lt", false);
	}
	ENDPOINT(API_M_GET, "/sales-opportunities/sales-oppo-name-list", querySalOppoNameList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, GetSalesOppoQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQuerySalOppoNameList(userQuery, authObject->getPayload()));
	}
private:
	// 在此添加定义
	GetSalesOppoJsonVO::Wrapper execQuerySalOppoNameList(const GetSalesOppoQuery::Wrapper& query, const PayloadDTO& payload);
};

//取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) 
#endif // _SALESOPPOCONTROLLER_H_

