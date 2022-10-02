use AdventureWorksDW2014;


-- inner join
-- returns results only where the join condition is true
select top 1000 *
from FactInternetSales s
inner join DimProduct p on s.ProductKey = p.ProductKey

-- left join
-- returns all rows from sales, regardless of the join condition
select distinct EnglishProductName
from FactInternetSales s
left join DimProduct p on s.ProductKey = p.ProductKey
order by 1

-- add filter conditions to join
select *
from FactInternetSales s
inner join DimProduct p 
	on	s.ProductKey = p.ProductKey 
	and	p.StartDate > '2013-01-01'