#pragma once
#ifndef _SALESCONTRACTQUERY_H_
#define _SALESCONTRACTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class SalesContractPageQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(SalesContractPageQuery, PageQuery);
	//销售合同ID
	//API_DTO_FIELD_DEFAULT(Int64, contract_id, ZH_WORDS_GETTER("SalesContract.field.contract_id"));

	//合同主题
	API_DTO_FIELD_DEFAULT(String, title, ZH_WORDS_GETTER("SalesContract.field.title"));
	//客户ID（客户名称）
	API_DTO_FIELD_DEFAULT(Int64, customer_id, ZH_WORDS_GETTER("SalesContract.field.customer_id"));
	//合同金额
	API_DTO_FIELD_DEFAULT(Float32, money, ZH_WORDS_GETTER("SalesContract.field.money"));
	//回款金额
	API_DTO_FIELD_DEFAULT(Float32, back_money, ZH_WORDS_GETTER("SalesContract.field.back_money"));
	//回款状态，1=未付，2=部分，3=全部
	API_DTO_FIELD_DEFAULT(Int8, back_status, ZH_WORDS_GETTER("SalesContract.field.back_status"));
	//开票金额
	API_DTO_FIELD_DEFAULT(Float32, invoice_money, ZH_WORDS_GETTER("SalesContract.field.invoice_money"));
	//开票状态， 0=不需要，1=需要，2=部分，3=全部
	API_DTO_FIELD_DEFAULT(Int8, invoice_status, ZH_WORDS_GETTER("SalesContract.field.invoice_status"));
	//开始时间
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("SalesContract.field.start_date"));
	//结束时间
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("SalesContract.field.end_date"));
	//合同状态 1=临时单，2=执行，3=完成，4=撤消
	API_DTO_FIELD_DEFAULT(Int8, status, ZH_WORDS_GETTER("SalesContract.field.status"));
	//交付状态，-1=不需要，1=需要，2=录入明细，3=待出库，4=部分，5=全部
	API_DTO_FIELD_DEFAULT(Int8, deliver_status, ZH_WORDS_GETTER("SalesContract.field.deliver_status"));

};

#include OATPP_CODEGEN_END(DTO)

#endif 