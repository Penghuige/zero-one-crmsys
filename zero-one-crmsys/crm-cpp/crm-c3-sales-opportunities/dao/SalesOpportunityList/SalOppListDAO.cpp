#include "stdafx.h"
#include "SalOppListDAO.h"
#include "SalOppListMapper.h"

#define FINCAPREC_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->find_date) { \
	sql << " AND `find_date` >= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->find_date.getValue("")); \
} \
if (query->bill_date) { \
	sql << " AND `bill_date` <= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->bill_date.getValue("")); \
} \
if (query->salestage) { \
	sql << " AND `salestage` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->salestage.getValue(0)); \
} \

uint64_t querySalOppListDAO::count(const SaleopportPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM cst_chance ";
	FINCAPREC_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	std::cout << "Query_sql:" << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<Cst_chanceDO> querySalOppListDAO::selectWithPage(const SaleopportPageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT cst.name , cst.customer_id , cst.find_date , cst.bill_date , cst.money , cst.salestage , cst.intro ,cst.create_time "
		"FROM cst_chance cst ";
	FINCAPREC_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	SalOppListMapper mapper;
	std::string sqlStr = sql.str();
std:cout << "selectWithPage_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<Cst_chanceDO, SalOppListMapper>(sqlStr, mapper, params);
}

