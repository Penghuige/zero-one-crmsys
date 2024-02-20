#include "stdafx.h"
#include "GetSalesOppoController.h"

GetSalesOppoJsonVO::Wrapper GetSalesOppoController::execQuerySalOppoNameList(const GetSalesOppoQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GetSalesOppoService service;
	// ��ѯ����
	auto result = service.getName(query);
	// ��Ӧ���
	auto jvo = GetSalesOppoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
