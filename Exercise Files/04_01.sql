use AdventureWorksDW2014;

select OrderDate, sum(SalesAmount)
from FactInternetSales
group by OrderDate
order by OrderDate

-- simple aggregations
-- Use additional aggregations to understand more about product sales such as distribution of sales etc..
SELECT 
		cat.EnglishProductCategoryName 'Category'
    ,	sub.EnglishProductSubcategoryName 'SubCategory'
	,	count(1) 'Count' -- How many sales where there?
	,	sum(s.SalesAmount) 'Sales' -- How much sales did we have?
    ,	avg(s.SalesAmount) 'Avg_SalesAmount' -- What was the Avg sale amount?
    ,	min(s.SalesAmount) 'Min_SaleAmount' -- What was the Min sale amount?
    ,	max(s.SalesAmount) 'Max_SaleAmount' -- What was the Max sale amount
FROM FactInternetSales s
LEFT JOIN DimProduct p ON s.ProductKey = p.ProductKey
LEFT JOIN DimProductSubcategory sub ON p.ProductSubcategoryKey = sub.ProductSubcategoryKey
LEFT JOIN DimProductCategory cat ON sub.ProductCategoryKey = cat.ProductCategoryKey
-- must use group by in order for aggregation to work properly
GROUP BY
		cat.EnglishProductCategoryName -- column aliases aren't allowed
    ,	sub.EnglishProductSubcategoryName
ORDER BY
		cat.EnglishProductCategoryName
	,	sub.EnglishProductSubcategoryName

-- filter to 2013 with WHERE
SELECT 
		YEAR(s.OrderDate) 'Year'
	,	cat.EnglishProductCategoryName 'Category'
    ,	sub.EnglishProductSubcategoryName 'SubCategory'	
	,	count(1) 'Count' -- use 1 instead of a field for faster performance
	,	sum(s.SalesAmount) 'Sales'
    ,	avg(s.SalesAmount) 'Avg_Quantity'
    ,	min(s.SalesAmount) 'Min_SaleAmount'
    ,	max(s.SalesAmount) 'Max_SaleAmount'

FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
INNER JOIN DimProductSubcategory sub ON p.ProductSubcategoryKey = sub.ProductSubcategoryKey
INNER JOIN DimProductCategory cat ON sub.ProductCategoryKey = cat.ProductCategoryKey
-- filter
WHERE YEAR(s.OrderDate) = 2013 --use date function to parse year
-- must use group by in order for aggregation to work properly
GROUP BY
		YEAR(s.OrderDate)
	,	cat.EnglishProductCategoryName -- column aliases aren't allowed
    ,	sub.EnglishProductSubcategoryName
ORDER BY
		cat.EnglishProductCategoryName
	,	sub.EnglishProductSubcategoryName

-- Only show products in 2013 that sold more than $1M USD
SELECT 
		cat.EnglishProductCategoryName 'Category'
    ,	sub.EnglishProductSubcategoryName 'SubCategory'	
	,	count(1) 'Count' -- use 1 instead of a field for faster performance
	,	sum(s.SalesAmount) 'Sales'
    ,	avg(s.SalesAmount) 'Avg_Quantity'
    ,	min(s.SalesAmount) 'Min_SaleAmount'
    ,	max(s.SalesAmount) 'Max_SaleAmount'
FROM FactInternetSales s
INNER JOIN DimProduct p ON s.ProductKey = p.ProductKey
INNER JOIN DimProductSubcategory sub ON p.ProductSubcategoryKey = sub.ProductSubcategoryKey
INNER JOIN DimProductCategory cat ON sub.ProductCategoryKey = cat.ProductCategoryKey
-- filter
WHERE YEAR(s.OrderDate) = 2013 --use date function to parse year
-- must use group by in order for aggregation to work properly
GROUP BY
		cat.EnglishProductCategoryName -- column aliases aren't allowed
    ,	sub.EnglishProductSubcategoryName	
-- use HAVING to filter after the aggregate is computed
HAVING
		sum(s.SalesAmount) > 1000000
ORDER BY
		cat.EnglishProductCategoryName
	,	sub.EnglishProductSubcategoryName