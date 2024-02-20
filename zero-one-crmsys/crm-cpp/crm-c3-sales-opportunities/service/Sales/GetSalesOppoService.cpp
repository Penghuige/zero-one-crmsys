#include "stdafx.h"
#include "GetSalesOppoService.h"


GetSalesOppoNameDTO::Wrapper GetSalesOppoService::getName(const GetSalesOppoQuery::Wrapper& query)
{
	// �������ض���
	auto pages = GetSalesOppoNameDTO::createShared();

    SalesOppoDAO dao;
	// ͨ��name��ѯ����
	list<Cst_chanceDO> result = dao.selectByName(query);
	// ��DOת����DTO
	for (Cst_chanceDO sub : result)
	{
		auto dto = GetSalesOppoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, chance_id, Chance_id)
			pages->addData(dto);
	}
	return pages;
}