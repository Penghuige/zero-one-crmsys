#include "stdafx.h"
#include "GetSalesOppoController.h"

GetSalesOppoJsonVO::Wrapper GetSalesOppoController::execQuerySalOppoNameList(const GetSalesOppoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetSalesOppoService service;
	// 查询数据
	auto result = service.getName(query);
	// 响应结果
	auto jvo = GetSalesOppoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
