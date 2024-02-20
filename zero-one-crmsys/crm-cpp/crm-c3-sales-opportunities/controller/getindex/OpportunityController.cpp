#include "stdafx.h"
#include "OpportunityController.h"
#include "../../service/salesopportunity/OpportunityService.h"

StringJsonVO::Wrapper OpportunityController::execQueryExportSalOpp(const OpportunityQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 构建返回对象
	auto jvo = StringJsonVO::createShared();
	// 无需数据校验条件可以为空

	listExportSalOppService  service;
	std::string downloadUrl = service.exportSalOpportunity(query);

	jvo->success(downloadUrl);
	return jvo;

	//return StringJsonVO::createShared();
}
