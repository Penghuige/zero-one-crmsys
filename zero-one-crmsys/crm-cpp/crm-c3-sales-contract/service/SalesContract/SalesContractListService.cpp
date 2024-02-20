#include "stdafx.h"
#include "SalesContractListService.h"
#include "SnowFlake.h"
#include "dao/SalesContract/SalesContractListDAO.h"
#include "domain/do/SalesContract/SalesContractDo.h"

SalesContractListPageDTO::Wrapper querySalesContractListService::listAll(const SalesContractPageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SalesContractListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	querySalesContractListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<sal_contractDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (sal_contractDO sub : result)
	{
		auto dto = SalesContractListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			title, Title, customer_id, Customer_id, start_date, Start_date,
			end_date, End_date, money, Money, back_money, Back_money, back_status, Back_status,
			invoice_money, Invoice_money, invoice_status, Invoice_status, status, Status, deliver_status, Deliver_status)
			pages->addData(dto);
	}
	return pages;
}

