use AdventureWorksDW2014;

-- Sub Queries

-- Use a sub-query to aggregate an underlying Table
select *
from (
	select sum(SalesAmount) as 'Sales', YEAR(OrderDate) as 'Yr'
	from FactInternetSales
	group by YEAR(OrderDate)
) YrSales

-- Create new aggregates on to of derived
select avg(Sales) as 'AvgSales'
from (
	select sum(SalesAmount) as 'Sales', YEAR(OrderDate) as 'Yr'
	from FactInternetSales
	group by YEAR(OrderDate)
) YrSales

-- Use a subquery to test if values are IN another table
SELECT EnglishProductName 'Product'
FROM DimProduct p
WHERE p.ProductSubcategoryKey IN
    (SELECT sc.ProductSubcategoryKey
     FROM DimProductSubcategory sc
     WHERE sc.EnglishProductSubcategoryName = 'Wheels')

-- Re-write this as a Join instead
SELECT	p.EnglishProductName
FROM	DimProduct p
JOIN	DimProductSubcategory sc ON p.ProductSubcategoryKey = sc.ProductSubcategoryKey
WHERE	sc.EnglishProductSubcategoryName = 'Wheels'

-- Use EXISTS to test if the outer queries value is present in the sub-query
-- Somtimes this is the only way to express this join type
SELECT EnglishProductName 'Product'
FROM DimProduct p
WHERE EXISTS
    (SELECT * -- no data is returned, only a boolean true/false 
     FROM DimProductSubcategory sc
     WHERE	p.ProductSubcategoryKey = sc.ProductSubcategoryKey
	 AND	sc.EnglishProductSubcategoryName = 'Wheels')



