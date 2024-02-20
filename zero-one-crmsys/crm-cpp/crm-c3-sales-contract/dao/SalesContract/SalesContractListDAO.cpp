#include "stdafx.h"
#include "SalesContractListDAO.h"
#include "dao/mapper/SalesContractMapper.h"

#define FINCAPREC_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->start_date) { \
	sql << " AND `start_date` >= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue("")); \
} \
if (query->end_date) { \
	sql << " AND `end_date` <= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->end_date.getValue("")); \
} \


uint64_t querySalesContractListDAO::count(const SalesContractPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM sal_contract";
	FINCAPREC_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	std::cout << "Query_sql:" << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<sal_contractDO> querySalesContractListDAO::selectWithPage(const SalesContractPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT sal.title,sal.customer_id,sal.money,sal.back_money,sal.back_status,sal.invoice_money,sal.invoice_status,sal.start_date,sal.end_date,sal.status,sal.deliver_status "
		"FROM sal_contract sal ";
	FINCAPREC_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SalesContractMapper mapper;
	std::string sqlStr = sql.str();
std:cout << "selectWithPage_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<sal_contractDO, SalesContractMapper>(sqlStr, mapper, params);
}

