/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "GetSalesOppoDAO.h"
#include "GetSalesOppoMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND name LIKE CONCAT('%',?,'%')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} 

std::list<Cst_chanceDO> SalesOppoDAO::selectByName(const GetSalesOppoQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT name,chance_id FROM cst_chance";
	SAMPLE_TERAM_PARSE(query, sql);
	GetSalesOppoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<Cst_chanceDO, GetSalesOppoMapper>(sqlStr, mapper, params);
}

//std::list<Cst_chanceDO> GetSalesOppoDAO::selectByName(const GetSalesOppoQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT name,chance_id FROM cst_chance";
//	GetSalesOppoMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<Cst_chanceDO, GetSalesOppoMapper>(sqlStr, mapper);
//}
