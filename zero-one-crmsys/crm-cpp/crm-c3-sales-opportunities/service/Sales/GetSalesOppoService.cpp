#include "stdafx.h"
#include "GetSalesOppoService.h"


GetSalesOppoNameDTO::Wrapper GetSalesOppoService::getName(const GetSalesOppoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetSalesOppoNameDTO::createShared();

    SalesOppoDAO dao;
	// 通过name查询数据
	list<Cst_chanceDO> result = dao.selectByName(query);
	// 将DO转换成DTO
	for (Cst_chanceDO sub : result)
	{
		auto dto = GetSalesOppoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, chance_id, Chance_id)
			pages->addData(dto);
	}
	return pages;
}